#include "guardarDatos.h"

Pregunta *crearPregunta(char *lineaPregunta, char *lineTrue, char *lineFalse){
	Pregunta *new = (Pregunta*) malloc (sizeof(Pregunta));
	
	List *aux = separateLine(lineaPregunta, ";");
	new->ID = _strdup(firstList(aux));
	new->id = atoi(new->ID);
	new->question = _strdup(nextList(aux));

	new->answerTrue = separateLine(lineTrue,";");
	new->answerFalse = separateLine(lineFalse,";");
	
	new->alternatives = (Alternativa**) calloc (4, sizeof(Alternativa*));
	return new;
}

HashMap *GuardarPreguntas(char *archive, int capacidad){
	
	FILE *F = fopen(archive, "r"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return NULL;}// Si no existe el archivo, cierra el programa


	HashMap *new = createHashMap(capacidad);
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

int ExistePartida(char *archive){
	
	FILE *F = fopen(archive, "r"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return 3;}// Si no existe el archivo, cierra el programa
	
	char partida[6]; // Cadena de caracter para guardar una linea del archivo

	fgets(partida, 6, F);
	deleteLineBreak(partida);
	fclose(F);

	if(strcmp(partida,"false") == 0){return 0;}
	else if (strcmp(partida,"true") == 0){return 1;}
	return 2;
}