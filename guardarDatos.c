#include "guardarDatos.h"

Pregunta *crearPregunta(char *lineaPregunta, char *lineTrue, char *lineFalse){
	Pregunta *new = (Pregunta*) malloc (sizeof(Pregunta));
	
	List *aux = separateLine(lineaPregunta, ";");
	new->id = _strdup(firstList(aux));
	new->question = _strdup(nextList(aux));

	new->answerTrue = separateLine(lineTrue,";");
	new->answerFalse = separateLine(lineFalse,";");
	
	new->contFalse = 0;
	new->contTrue = 0;
	
	new->A = (Alternativa*) malloc (sizeof(Alternativa));
	new->B = (Alternativa*) malloc (sizeof(Alternativa));
	new->C = (Alternativa*) malloc (sizeof(Alternativa));
	new->D = (Alternativa*) malloc (sizeof(Alternativa));
	
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
	new->questionSaw = 0;
	new->user = _strdup(userName);
	new->comodines = (Comodin*) malloc (sizeof(Comodin));

	if (dif->hard){
		new->comodines->alternativeChange = false;
		new->comodines->HelpTeacher = false;
		new->comodines->questionChange = false;
	}
	else{
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
	fprintf(F, "%.3f\n", USER->pts);

	fprintf(F, "%d;", USER->cantQuestion);
	fprintf(F, "%d\n", USER->questionSaw);

	if(dif->easy){fprintf(F, "true;");}
	else{fprintf(F, "false;");}
	if(dif->normal){fprintf(F, "true;");}
	else{fprintf(F, "false;");}
	if(dif->hard){fprintf(F, "true\n");}
	else{fprintf(F, "false\n");}

	if(USER->comodines->questionChange){fprintf(F, "true;");}
	else{fprintf(F, "false;");}
	if(USER->comodines->alternativeChange){fprintf(F, "true;");}
	else{fprintf(F, "false;");}
	if(USER->comodines->HelpTeacher){fprintf(F, "true\n");}
	else{fprintf(F, "false\n");}

	char *id = firstList(USER->selectedQuestions);
	id = nextList(USER->selectedQuestions);
	fprintf(F, "%s", id);
	while (id)
	{
		fprintf(F, ";%s", id);
		id = nextList(USER->selectedQuestions);
	}

	fclose(F);// Se cierra el archivo
}

void cargarPartida(char *fileName, Usuario *user, Dificultad *d){
	FILE *F = fopen(fileName, "r"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return ;}// Si no existe el archivo, cierra el programa

	char linea[1024];
	List *aux;

	//nombre ; puntos del usuario
	fgets(linea, 1023, F);
	aux = separateLine(linea, ";");
	// guarda el nombre de usuario, las cantidad de respondidas y el puntaje obtenido
	user->user = _strdup(firstList(aux));
	List *ptj = separateLine(nextList(aux), ".");
	user->pts = atoi(firstList(ptj));
	user->pts += ( (float)atoi(nextList(ptj)) / 1000);

	//pregunta en la que esta el usuario; preguntas ya leidas de las preparadas
	fgets(linea, 1023, F);
	aux = separateLine(linea, ";");
	//guarda la pregunta en la que esta el usuario y la cantidad de preguntas ya leidas de las preparadas
	user->cantQuestion = atoi(firstList(aux));
	user->questionSaw = atoi(firstList(aux));


	//dificultad: 	facil ; normal ; dificil
	fgets(linea, 1023, F);
	aux = separateLine(linea, ";");
	// Guarda la dificultad de la partida guardada
	if (strcmp(firstList(aux), "true") == 0){d->easy = true;}
	else{d->easy = false;}
	if (strcmp(nextList(aux), "true") == 0){d->normal = true;}
	else{d->normal = false;}
	if (strcmp(nextList(aux), "true") == 0){d->hard = true;}
	else{d->hard = false;}

	// Comodines: Cambiar pregunta ; Cambiar alternativas ; Ayuda Profe
	fgets(linea, 1023, F);
	aux = separateLine(linea, ";");
	// Guarda si el usuario tiene disponible una segunda vida
	if (strcmp(firstList(aux), "true") == 0){user->comodines->questionChange = true;}
	else{user->comodines->questionChange = false;}
	if (strcmp(nextList(aux), "true") == 0){user->comodines->alternativeChange = true;}
	else{user->comodines->alternativeChange = false;}
	if (strcmp(nextList(aux), "true") == 0){user->comodines->HelpTeacher = true;}
	else{user->comodines->HelpTeacher = false;}

	// id Pregunta ; id Pregunta ; id Pregunta ; ... ; id Pregunta
	fgets(linea, 1023, F);
	aux = separateLine(linea, ";");
	// Guarda las id de las preguntas hechas y por hacer al usuario
	user->selectedQuestions = createList(); //Para vaciar la lista
	char *id = firstList(aux);
	while (id)
	{
		pushBack(user->selectedQuestions, id);
		id = nextList(aux);
	}
	
	fclose(F);// Se cierra el archivo
}

TreeMap *crearTop(char *file){
	TreeMap *new = createTreeMap(lower_than_float);
	List *aux;
	Top *top;
	List *ptj;

	FILE *F = fopen(file, "r"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return NULL;}// Si no existe el archivo, cierra el programa

	char linea[1024];
	while (fgets(linea, 1023, F))
	{
		aux = separateLine(linea, ";");
		top = (Top*) malloc (sizeof(Top));
		top->usuario = _strdup(firstList(aux));

		ptj = separateLine(nextList(aux), ".");
		top->puntaje = atoi(firstList(ptj));
		top->puntaje += ( (float)atoi(nextList(ptj)) / 1000);

		insertTreeMap(new, (void*)(&top->puntaje), top);
	}
	
	fclose(F);

	return new;
}

void saveTop(char *file, TreeMap *top){
	FILE *F = fopen(file, "w"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return;}// Si no existe el archivo, cierra el programa


	int pos = 1;
	Pair *auxiliar = firstTreeMap(top);
	Top *aux = auxiliar->value;
	while (aux)
	{
		fprintf(F, "%s;", aux->usuario);
		fprintf(F, "%.3f\n", aux->puntaje);
		pos++;
		if (pos == 6){break;}
		auxiliar = nextTreeMap(top);
		aux = auxiliar->value;
	}
	
	fclose(F);
}