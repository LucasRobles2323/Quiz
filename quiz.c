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

void comodinesDificultad(Usuario *user, Dificultad *condicion){
	Comodin *cambiar = user->comodines;
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

int is_valid(char *pregId, Usuario* user){
	
	char* idPregUsuario = firstList(user->selectedQuestions);

	while(idPregUsuario != NULL)
	{
		if(is_equal_string(pregId, idPregUsuario) == 1){return 1;}
		else{idPregUsuario = nextList(user->selectedQuestions);}
	}

	return 0;
	
}

void azarQuestion(Usuario* user, HashMap* map){
	Pregunta* preg;

	int cont = 15;
	user->selectedQuestions = createList();

	while(cont >= 0)
	{
		int azar = rand() % 37; azar = azar % 37;
		preg = firstHashMap(map);
		while(azar != 0)
		{
			preg = nextHashMap(map);
			azar--;
		}
		if(is_valid(preg->id, user) == 0){
			pushBack(user->selectedQuestions, preg->id);
			cont--;
		}
	}
	
}

int randomNumber(int lowerbound, int upperbound)
{
    return (rand() % (upperbound - lowerbound + 1) + lowerbound);
}

void SelectPlace(Pregunta* preg, char* Altt)
{	
	int huachipato_value = 3;
	while(huachipato_value >= 0)
	{ 
		switch(huachipato_value)
		{
			case 0:
			if(preg->A->alternative == NULL)
			{
				preg->A->alternative = _strdup(Altt);
				preg->A->answer = false;	
				return;
			}
			break;
			
			case 1:
			if(preg->B->alternative == NULL)
			{
				preg->B->alternative = _strdup(Altt);
				preg->B->answer = false;	
				return;
			}

			break;
			case 2:

			if(preg->C->alternative == NULL)
			{
				preg->C->alternative = _strdup(Altt);
				preg->C->answer = false;	
				return;
			}

			break;
			case 3:
			if(preg->D->alternative == NULL)
			{
				preg->D->alternative = _strdup(Altt);
				preg->D->answer = false;	
				return;
			}

			break;
		}

		huachipato_value--;
	}
}

int is_valid_alt(int* repe, int azar)
{

	if(repe[azar] == -1)
	{return 1;}
	else{return 0;}


}

void AzarAlternatives(Pregunta* preg)
{
	// cuenta numero de respuestas presentes según la pregunta
	preg->A = (Alternativa*) calloc (1,sizeof(Alternativa));
	preg->B = (Alternativa*) calloc (1,sizeof(Alternativa));
	preg->C = (Alternativa*) calloc (1,sizeof(Alternativa));
	preg->D = (Alternativa*) calloc (1,sizeof(Alternativa));

	preg->contFalse = 0;
	preg->contTrue = 0;
	char* Altt;
	int cont = 2; 
	while(cont != 0){
		if(cont == 1){Altt = firstList(preg->answerFalse); }
		if(cont == 2){Altt = firstList(preg->answerTrue);}
		while(Altt != NULL)
		{
			if(cont == 1){Altt = nextList(preg->answerFalse); preg->contFalse++;}
			if(cont == 2){Altt = nextList(preg->answerTrue); preg->contTrue++;}
		}
		cont--;
	}

	//Seccion para true //
	Altt = firstList(preg->answerTrue); 
	int azar = randomNumber(0, preg->contTrue); azar = azar % (preg->contTrue);

	while(azar != 0)
	{
		Altt = nextList(preg->answerTrue);
		azar--;
		if(!Altt){Altt = firstList(preg->answerTrue);}
	}

	azar = rand() % 4; azar = azar % 3;

	switch(azar)
	{	
		case 0:
			preg->A->alternative = _strdup(Altt);
			preg->A->answer = true;	
			break;
		case 1:
			preg->B->alternative = _strdup(Altt);
			preg->B->answer = true;	
	
			break;
		case 2:
			preg->C->alternative = _strdup(Altt);
			preg->C->answer = true;	
			
			break;
		case 3:
			preg->D->alternative = _strdup(Altt);
			preg->D->answer = true;	
			break;
	}

	//Fin seccion true //
	//Sección para falsas//
	int j;
	int *repe = (int*) calloc (preg->contFalse, sizeof(int));
	for(j = 0; j < preg->contFalse; j++)
	{repe[j] = -1;}

	cont = 3;
	while(cont != 0 && Altt != NULL)
	{

		Altt = firstList(preg->answerFalse);
		bool pasa = false;

		while(pasa != true)
		{
			azar = randomNumber(0, preg->contFalse); 
		
			int comprobador;
			if(is_valid_alt(repe, azar) == 1)
			{
				comprobador = is_valid_alt(repe, azar);
		
				repe[azar] = azar; 
				while(azar != 0)
				{	
					pasa = true;
					Altt = nextList(preg->answerFalse);
					azar--;	
					if(!Altt){Altt = firstList(preg->answerTrue);}
				}			
			}
		}
		int i = 0;
		SelectPlace(preg, Altt);
		cont--;
	}
}
	