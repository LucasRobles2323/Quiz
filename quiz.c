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