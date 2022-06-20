#include "quiz.h"

Usuario *crearUsuario(char *user, Dificultad *dif){
	Usuario *new = (Usuario*) malloc (sizeof(Usuario));
	new->cantQuestion = 0;
	new->pts = 0;
	strcpy(new->user,user);
	new->questionsSelected = createHashMap(25);
	new->comodines = (Comodin*) malloc (sizeof(Comodin));
	new->life = true;

	if (dif->hard){
		new->secondLife = false;
		new->comodines->alternativeChange = false;
		new->comodines->HelpTeacher = false;
		new->comodines->questionChange = false;
	}
	else{
		new->secondLife = true;
		new->comodines->alternativeChange = true;
		new->comodines->HelpTeacher = true;
		new->comodines->questionChange = true;
	}
	
	return new;
}

char *azarOfList(List *lista, int azar){
	char *retornar = firstList(lista);
	if (azar == 0){return retornar;}

	while (azar != 0)
	{
		retornar = nextList(lista);
		azar--;
	}
	
	return azarOfList(lista, azar);
}

Alternativa **crearAlternativas(List *T, List *F){
	Alternativa **new = (Alternativa**) calloc (4, sizeof(Alternativa*));
	int Tpos = rand() % 4;
	for (size_t i = 0; i < 4; i++)
	{
		if (i == Tpos){
			new[i]->answer = true;
			new[i]->alternative = azarOfList(T, rand() % 20);
		}
		else{
			new[i]->answer = false;
			new[i]->alternative = azarOfList(F, rand() % 20);
		}
	}
	
	return new;
}