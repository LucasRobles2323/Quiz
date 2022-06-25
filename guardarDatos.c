#include "guardarDatos.h"

Pregunta *crearPregunta(char *lineaPregunta, char *lineTrue, char *lineFalse){
	Pregunta *new = (Pregunta*) malloc (sizeof(Pregunta));
	
	List *aux = separateLine(lineaPregunta, ";");
	new->id = _strdup(firstList(aux));
	new->question = _strdup(nextList(aux));

	new->answerTrue = separateLine(lineTrue,";");
	new->answerFalse = separateLine(lineFalse,";");
	
	new->A = (Alternativa*) malloc (sizeof(Alternativa*));
	new->B = (Alternativa*) malloc (sizeof(Alternativa*));
	new->C = (Alternativa*) malloc (sizeof(Alternativa*));
	new->D = (Alternativa*) malloc (sizeof(Alternativa*));
	
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
	int indice = 0;

	while (fgets(pregunta, 1023, F) != NULL) { 
    	// Recorre el archivo leyendo linea por linea
        // guardando los datos de cada linea en listas
		fgets(verdaderos, 1023, F);
		fgets(falsos, 1023, F);

		QUESTION = crearPregunta(pregunta,verdaderos,falsos);
		insertHashMap(new, QUESTION->id, QUESTION);
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

char *nombreUsuario(char *fileName){
	FILE *F = fopen(fileName, "r");
	char userName[1024];
	fgets(userName, 1023, F);
	deleteLineBreak(userName);
	fclose(F);
	return _strdup(userName);
}

Usuario *crearUsuario(char *userName, Dificultad *dif){
	Usuario *new = (Usuario*) malloc (sizeof(Usuario));
	new->cantQuestion = 0;
	new->pts = 0;
	new->user = _strdup(userName);
	new->comodines = (Comodin*) malloc (sizeof(Comodin));

	if (dif->hard){
		new->secondLife = false;
		new->comodines->alternativeChange = false;
		new->comodines->HelpTeacher = false;
		new->comodines->questionChange = false;
	}
	else{
		new->secondLife = true;
		new->comodines->alternativeChange = true;
		new->comodines->HelpTeacher = true;
		new->comodines->questionChange = true;
	}
	
	new->life = true;
	
	new->selectedQuestions = createList();
	
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

bool noExistePartida(char *archive){
	FILE *F = fopen(archive, "r"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return true;}// Si no existe el archivo, cierra el programa

	char ToN[100];

	fgets(ToN, 99, F);
	deleteLineBreak(ToN);
	if (strcmp(ToN, "No") == 0){return true;}

	return false;
}



Ahorcado *createAhorcado(List *datos){
	Ahorcado *new = (Ahorcado*) malloc (sizeof(Ahorcado));

	new->id = atoi(firstList(datos));
	new->enunciado = nextList(datos);
	new->palabra = nextList(datos);
	new->time = atoi(nextList(datos));

	return new;
}

List *guardarMinijuegoAhorcado(char *file){
	List *new = createList();

	FILE *F = fopen(file, "r"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return NULL;}// Si no existe el archivo, cierra el programa
	
	Ahorcado *aux;
	char linea[1024];
	List *auxiliar; //Lista para las palabras de la linea

	while (fgets(linea, 1023, F) != NULL) { 
    	// Recorre el archivo leyendo linea por linea
        // guardando los datos de cada linea en listas
		
		auxiliar = separateLine(linea, ";");
		aux = createAhorcado(auxiliar);
		pushBack(new, aux);
	}
	
	fclose(F);// Se cierra el archivo


	return new;
}

void partidaExiste(char *archive, bool existe){
	FILE *F = fopen(archive, "w"); // Abre el archivo con el nombre recibido en modo escritura
	if (!F){return ;}// Si no existe el archivo, cierra el programa

	if(existe){
		fprintf(F, "Yes");
	}
	else{fprintf(F, "No");}
	
	fclose(F);// Se cierra el archivo
}

void guardarPartida(Usuario *USER, Dificultad *dif, char *archive){
	FILE *F = fopen(archive, "w"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return ;}// Si no existe el archivo, cierra el programa

	fprintf(F, "%s;", USER->user);
	fprintf(F, "%d;", USER->cantQuestion);
	fprintf(F, "%.3f\n", USER->pts);

	char *id = firstList(USER->selectedQuestions);
	fprintf(F, "%s", id);
	while (id)
	{
		fprintf(F, ";%s", id);
		id = nextList(USER->selectedQuestions);
	}
	fprintf(F, "\n");

	if(dif->easy){fprintf(F, "true;");}
	else{fprintf(F, "false;");}
	if(dif->normal){fprintf(F, "true;");}
	else{fprintf(F, "false;");}
	if(dif->hard){fprintf(F, "true\n");}
	else{fprintf(F, "false\n");}

	if(USER->secondLife){fprintf(F, "true\n");}
	else{fprintf(F, "false\n");}

	if(USER->comodines->questionChange){fprintf(F, "true;");}
	else{fprintf(F, "false;");}
	if(USER->comodines->alternativeChange){fprintf(F, "true;");}
	else{fprintf(F, "false;");}
	if(USER->comodines->HelpTeacher){fprintf(F, "true\n");}
	else{fprintf(F, "false\n");}

	fclose(F);// Se cierra el archivo
}