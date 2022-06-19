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
	char pregunta[1024];
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

Dificultad *leerDificult(char *archive){
	Dificultad *new = (Dificultad*) malloc (sizeof(Dificultad));

	FILE *F = fopen(archive, "r"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return NULL;}// Si no existe el archivo, cierra el programa
	
	char linea[60];

	fgets(linea, 60, F);
	List *auxList = separateLine(linea, ";");

	char *aux = firstList(auxList);
	if(strcmp(aux,"false") == 0) {new->easy = false;}
	else{new->easy = true;}
	
	aux = nextList(auxList);
	if(strcmp(aux,"false") == 0) {new->normal = false;}
	else{new->normal = true;}
	
	aux = nextList(auxList);
	if(strcmp(aux,"false") == 0) {new->hard = false;}
	else{new->hard = true;}

	fclose(F);
	return new;
}

VerdaderoFalso *GuardarToF(char *archive){
	FILE *F = fopen(archive, "r"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return NULL;}// Si no existe el archivo, cierra el programa

	printf("open");
	VerdaderoFalso *new = (VerdaderoFalso*) malloc (sizeof(VerdaderoFalso));

	char verdaderos[1024];
	char falsos[1024];

	fgets(verdaderos, 1023, F);
	fgets(falsos, 1023, F);

	new->Verdadero = separateLine(verdaderos, ";");
	new->Falso = separateLine(falsos, ";");
	fclose(F);

	return new;
}

void saveDificult(char *archive, Dificultad *guardar){
	FILE *F = fopen(archive, "w"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return ;}// Si no existe el archivo, cierra el programa


	if(guardar->easy) {fprintf(F, "%s", "true;");}
	else{fprintf(F, "%s", "false;");}

	if(guardar->normal) {fprintf(F, "%s", "true;");}
	else{fprintf(F, "%s", "false;");}

	if(guardar->hard) {fprintf(F, "%s", "true");}
	else{fprintf(F, "%s", "false");}

	fclose(F);
}

bool existePartida(char *archive){
	FILE *F = fopen(archive, "w"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return false;}// Si no existe el archivo, cierra el programa

	char ToN[100];

	fgets(ToN, 99, F);
	deleteLineBreak(ToN);
	if (strcmp(ToN, "No") == 0){return false;}

	return true;
}