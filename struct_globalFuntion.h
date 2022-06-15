#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "hashmap.h"

//------------------STRUCT-------------------------//
typedef struct{
	char *user;
	float pts;
	HashMap *questionsList;
	int cantQuestion;
	bool secondLife;
	List *comodines;
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
	int id;
	char *ID;
	char *question;
	List *answerTrue;
	List *answerFalse;
	Alternativa **alternatives;
}Pregunta;

//------------------FUNCIONES-------------------------//
int is_equal_string(void * key1, void * key2);

int lower_than_string(void * key1, void * key2);

int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);

long is_equal_long(void * key1, void * key2);

long lower_than_long(void * key1, void * key2);

int compare(void * key1, void * key2);

char * _strdup(const char * str);