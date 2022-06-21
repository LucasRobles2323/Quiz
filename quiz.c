#include "quiz.h"

void mostrarUsuario(Usuario *new, Dificultad *D){
	printf("Nombre de Usuario:         %s\n", new->user);
	printf("Dificultad seleccionada:   ");
	if (D->easy){printf("Facil\n");}
	else if (D->normal){printf("Normal\n");}
	else{printf("Dificil\n");}
	printf("Puntaje Total del Usuario: %.3f", new->pts);
	return ;
}

void comodinesDificultad(Comodin *cambiar, Dificultad *condicion){
	if(condicion->hard)
	{
		cambiar->alternativeChange = false;
		cambiar->HelpTeacher = false;
		cambiar->questionChange = false;
	}
	else{
		cambiar->alternativeChange = true;
		cambiar->HelpTeacher = true;
		cambiar->questionChange = true;
	}
}

int is_valid(Pregunta* preg, Usuario* user){
	
	Pregunta* preguntasUsuario = firstList(user->selectedQuestions);

	while(preguntasUsuario != NULL)
	{
		if(is_equal_string(preg->id, preguntasUsuario->id) == 1){return 1;}
		else{preguntasUsuario = nextList(user->selectedQuestions);}
	}

	return 0;
	
}

void azarQuestion(Usuario* user, HashMap* map){
	Pregunta* preg;

	int cont = 15;

	while(cont != 0)
	{
		int azar = rand() % 30;
		preg = firstHashMap(map);
		while(azar != 0)
		{
			preg = nextHashMap(map);
			azar--;
		}
		if(is_valid(preg, user) == 0){
			pushBack(user->selectedQuestions, preg);
			cont--;
		}
	}
	
}