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
#include "struct_globalFuntion.h"


/*----------------- Lista con los text a abrir -----------------*/
List *separateLine(char *line){ 
	//Crea una lista con las palabras separadas por punto coma
	List *newList = createList();
    char *Text = strtok(line, ";");
	while (Text != NULL)
	{
        pushBack(newList, strdup(Text));
		Text = strtok(NULL, ";");
	}
	Text = lastList(newList);
	Text = strtok(Text, "\n");
    return newList;
}
//-----------------------------------------//

Pregunta *crearPregunta(char *lineaPregunta, char *lineTrue, char *lineFalse){
	Pregunta *new = (Pregunta*) malloc (sizeof(Pregunta));
	
	List *aux = separateLine(lineaPregunta);
	new->ID = _strdup(firstList(aux));
	new->id = atoi(new->ID);
	new->question = _strdup(nextList(aux));

	new->answerTrue = separateLine(lineTrue);
	new->answerFalse = separateLine(lineFalse);
	
	new->alternatives = (Alternativa**) calloc (4, sizeof(Alternativa*));
	return new;
}

HashMap *CrearHashMapPreguntas(){
	HashMap *new = createHashMap(100);
	FILE *F = fopen("./Temas/Preguntas.txt", "r"); // Abre el archivo con el nombre recibido en modo lectura
    
	if (!F){return NULL;}// Si no existe el archivo, cierra el programa

	char pregunta[1024]; // Cadena de caracter para guardar una linea del archivo
	char verdaderos[1024];
	char falsos[1024];
	Pregunta *QUESTION;

	while (fgets(pregunta, 1023, F) != NULL) { 
        // Recorre el archivo leyendo linea por linea
        // guardando los datos de cada linea en listas
		fgets(verdaderos, 1023, F);
		fgets(falsos, 1023, F);
		
		QUESTION = crearPregunta(pregunta,verdaderos,falsos);
		insertHashMap(new, QUESTION->ID, QUESTION);
	}
	
	fclose(F);// Se cierra el archivo

	return new;
}

int main(){
	HashMap *questionsHash = CrearHashMapPreguntas();
	Pregunta *aux = firstHashMap(questionsHash);
	while (aux)
	{
		printf("%d = %s --- %s\n", aux->id, aux->ID, aux->question);
		aux = nextHashMap(questionsHash);
	}
	
	return EXIT_SUCCESS;
}