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