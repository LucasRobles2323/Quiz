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
#include "list.h"
#include "hashmap.h"
#include "treemap.h"

//------------------STRUCT-------------------------//
typedef struct{
	bool questionChange;
	bool alternativeChange;
	bool HelpTeacher;
}Comodin;

typedef struct{
	char *user;
	float pts;
	bool life;
	List *selectedQuestions;
	int cantQuestion;
	Comodin *comodines;
}Usuario;

typedef struct{
	bool easy;
	bool normal;
	bool hard;
}Dificultad;

typedef struct{
	char *alternative;
	bool answer;
}Alternativa;

typedef struct{
	char *id;
	char *question;
	List *answerTrue;
	List *answerFalse;
	Alternativa **alternatives;
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

void deleteLineBreak(char *beta);

List *separateLine(char *line, char* excluir);

void cronometro(int segundos);