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
	bool secondLife;
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
	Alternativa *A;
	Alternativa *B;
	Alternativa *C;
	Alternativa *D;
}Pregunta;

typedef struct{
	List *Verdadero;
	List *Falso;
}VerdaderoFalso;

typedef struct{
	int id;
	char *enunciado;
	char *palabra;
	int time;
}Ahorcado;

//------------------FUNCIONES-------------------------//
int is_equal_string(void * key1, void * key2);

int lower_than_string(void * key1, void * key2);

int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);

long is_equal_long(void * key1, void * key2);

long lower_than_long(void * key1, void * key2);

int compare(void * key1, void * key2);

char * _strdup(const char * str);

void deleteLineBreak(char *beta);

List *separateLine(char *line, char* excluir);

void cronometro(int segundos);