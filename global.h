#include <windows.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <conio.h>
#include <time.h>
#include "list.h"
#include "hashmap.h"
#include "treemap.h"

//------------------STRUCT-------------------------//
typedef struct{
	bool questionChange;
	bool alternativeChange;
	bool HelpTeacher;
}Comodin; // Si son true, los comodines estan disponibles

typedef struct{
	char *user;
	float pts;
	bool life; // Para saber si termino el juego para el usuario
	List *selectedQuestions; // Lista con id de 16 preguntas para el quiz
	int cantQuestion; // Numero de la pregunta hecha 
	int questionSaw; // El numero de pregunta que han aparecido en pantalla.
	Comodin *comodines;
}Usuario;

typedef struct{
	bool easy;
	bool normal;
	bool hard;
}Dificultad;

typedef struct{
	char *alternative; // Es una alternativa
	bool answer; // bool para saber si la alternativa es correcta o incorrecta
}Alternativa;

typedef struct{
	char *id; // Forma de identificar la pregunta.
	char *question; // Es la pregunta
	List *answerTrue; // Lista de respuestas correctas
	List *answerFalse; //Lista de respuestas incorrectas
	int contTrue; // Contiene la cantidad de respuestas correctas en la pregunta
	int contFalse; // Contiene la cantidad de respuestas incorrectas en la pregunta
	Alternativa* A;
	Alternativa* B;
	Alternativa* C;
	Alternativa* D;
}Pregunta;


typedef struct{
	char *usuario;
	float puntaje;
}Top;

//------------------FUNCIONES-------------------------//
int is_equal_string(void * key1, void * key2);

int lower_than_string(void * key1, void * key2);

int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);

int is_equal_float(void * key1, void * key2);

int lower_than_float(void * key1, void * key2);

int compare(void * key1, void * key2);

char * _strdup(const char * str);

void deleteLineBreak(char *beta); // Elimina salto de linea de un string

List *separateLine(char *line, char* excluir); // Separa un string de acuerdo a un caracter recibido