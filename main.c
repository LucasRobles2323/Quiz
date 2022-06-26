//Contiene las funciones para guardar los datos al comenzar el programa
#include "quiz.h" //Incluye todas las librerias usadas, que estan en global.h

#define MenuInicio 3
#define MenuFin 13
#define LineaDeInicio 1
#define TemaInicio 3
#define TemaFin 9
#define QuizFin 16
#define QuizInicio 4 
#define exitFin 5
#define ROJO_T     "\x1b[31m"
#define VERDE_T        "\x1b[32m"
#define RESET_COLOR    "\x1b[0m"
#define MAGENTA_T  "\x1b[35m"
#define AZUL_T     "\x1b[34m"

#pragma comment(lib,"winmm.lib")

void goy (int y){
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 22;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}

void gotoxy ( int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void centrar (const char *texto, int x, int y){
	int size_texto = strlen(texto);
	gotoxy (x, y);
	printf ("%s", texto);
}

int movimiento(){
	int menu = 3;
	while (1)
	{
		Sleep(200);

		if (GetAsyncKeyState(VK_UP)){
			menu = menu == MenuInicio ? MenuFin: menu-2;
			printf ("\r                           ");
			goy (LineaDeInicio + menu - 1);
			printf ("---->");
		} else if (GetAsyncKeyState(VK_DOWN)){
			menu = menu == MenuFin ? MenuInicio: 2+menu;
			printf ("\r                           ");
			goy (LineaDeInicio + menu - 1);
			printf ("---->");
		} else if (GetAsyncKeyState(VK_RETURN)){
			break;
		}
	}

	return menu;
}

void bienvenida(){

    printf ("@@####@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@####@@\n");
	printf ("@@#########@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#########@@\n");
	printf ("@@#########@@@@@@@@@#########@@@@@@@@@@#########@@@@@@@@@#########@@\n");
	printf ("@@#########@@@@@@@@@#########@@@@@@@@@@#########@@@@@@@@@#########@@\n");
	printf ("@@#########@@@@@@@@@###@@@@,            *@@@@###@@@@@@@@@#########@@\n");
	printf ("@@#########@@@@@@@@@@                          @@@@@@@@@@#########@@\n");
	printf ("@@#########@@@@@@                ..                @@@@@@#########@@\n");
	Sleep (500);
	printf ("@@#########@@@.                 ....                 ,@@@#########@@\n");
	printf ("@@########@@                 .........                  @&########@@\n");
	printf ("@@#######@@              ..................              &@#######@@\n");
	printf ("@@######@           (       ............                   @######@@\n");
	printf ("@@#####@            *          ......                       @#####@@\n");
	printf ("@@####@(           ***          ...                         @@####@@\n");
	printf ("@@###&@          *******         .                           @@###@@\n");
	printf ("@@###@@      .*************(        @(*  ( ( /  * ( (/  .  * @@###@@\n");
	Sleep (500);
	printf ("@@###@@     ,***************/       @(# * ,      . ,,(@ .  * @@###@@\n");
	printf ("@@###&@         ********#        *                           @&###@@\n");
	printf ("@@####@,          .***#          ##                         *@####@@\n");
	printf ("@@####&@            *.         ######                       @#####@@\n");
	printf ("@@#####@@           *       (##########,                   @&#####@@\n");
	printf ("@@#######@           ,/######################*            @#######@@\n");
	printf ("@@########@@                 ##########                 @@########@@\n");
	printf ("@@#########@@@                 #####*                 @@@#########@@\n");
	Sleep (500);
	printf ("@@#########@@@@@@                ##                &@@@@@#########@@\n");
	printf ("@@@&#######@@@@@@@@@             *              @@@@@@@@@#######@@@@\n");
	printf ("@@@@@######@@@@@@@@@#@@@@@                &@@@@#@@@@@@@@@######@@@@@\n");
	printf ("@@@@@@@####@@@@@@@@@#########@@@@@@@@@@#########@@@@@@@@@####@@@@@@@\n");
	printf ("@@@@@@@@###@@@@@@@@@#########@@@@@@@@@@#########@@@@@@@@@##&@@@@@@@@\n");
	printf ("@@@@@@@@@@#@@@@@@@@@#########@@@@@@@@@@#########@@@@@@@@@&@@@@@@@@@@\n");
	printf ("@@@@@@@@@@@@@@@@@@@@#########@@@@@@@@@@#########@@@@@@@@@@@@@@@@@@@@\n");
	printf ("@@@@@@@@@@@@@@@@@@@@#########@@@@@@@@@@#########@@@@@@@@@@@@@@@@@@@@\n");
	Sleep (500);
	printf ("@@@@@@@@@@@@@@@@@@@@#########@@@@@@@@@@#########@@@@@@@@@@@@@@@@@@@@\n");
	printf ("@@@@@@@@@@@@@@@@@@@@#########@@@@@@@@@@#########@@@@@@@@@@@@@@@@@@@@\n");
	printf ("@@@@@@@@@@@@@@@@@@@@@@@######@@@@@@@@@@######@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf ("@@@@@@@@@@@@@@@@@@@@@@@@@@###@@@@@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	Sleep (500);
	system ("cls");
	centrar (ROJO_T "Grande Huachipato", 20, 5);
	Sleep (200);
	centrar (AZUL_T "PUCV", 20, 7);
	Sleep (200);
} 




void mostrarMenu(){
	system ("COLOR 7D");
	sndPlaySound ("songs\\BetterCallSaul", SND_ASYNC | SND_LOOP);
	centrar ("QUIEN QUIERE PASAR EL RAMO!!!!!!!!!!",24,0);
	printf ("\n");
	centrar ("Comenzar Juego", 30,3);
	printf ("\n");
	centrar ("Cargar Juego", 30,5);
	printf ("\n");
	centrar ("Dificultad", 30,7);
	printf ("\n");
	centrar ("Top", 30,9);
	printf ("\n");
	centrar ("Reglas", 30,11);
	printf ("\n");
	centrar ("Salir", 30,13);
	printf ("\n\n");
}

void mostrarDatosUsuario(Usuario *user, Dificultad *d){
	gotoxy(10,5);
	printf("Usuario                   : %s", user->user);
	
	gotoxy(10,6);
	printf("Preguntas Respondidas     : %d", user->cantQuestion);
	
	gotoxy(10,7);
	printf("Puntaje Usuario           : %.3f", user->pts);
	
	gotoxy(10,8);
	if(d->easy){printf("Dificultad Quiz           : Facil");}
	else if(d->normal){printf("Dificultad Quiz           : Normal");}
	else if(d->hard){printf("Dificultad Quiz           : Dificil");}
	
	gotoxy(11,9);
	if(user->secondLife){printf("Segunda Oportunidad       : Si");}
	else {printf("Segunda Oportunidad       : No");}

	gotoxy(13,10);
	if(user->comodines->questionChange){printf("Cambiar Pregunta          : Si");}
	else {printf("Cambiar Pregunta          : No");}
	

	gotoxy(13,11);
	if(user->comodines->alternativeChange){printf("Cambiar Alternativas      : Si");}
	else {printf("Cambiar Alternativas      : No");}
	
	gotoxy(13,12);
	if(user->comodines->HelpTeacher){printf("Ayuda Profesor            : Si");}
	else {printf("Ayuda Profesor            : No");}

	char *id = firstList(user->selectedQuestions);
	gotoxy(10,13);
	while (id)
	{
		printf("%3s||", id);
		id = nextList(user->selectedQuestions);
	}
	
}

void descripcionDificultad(Dificultad *d){
	if (d->easy){
		centrar ("FACIL", 1, 12);
		centrar ("En esta dificultad el usuario solo recibira 6 preguntas.", 4, 13);
		centrar ("Cada pregunta respondida correctamente equivale a 1 punto.", 4, 14);
		centrar ("Cada pregunta respondida despues de usar su segunda oportunidad, vera reducido su puntaje en 0.3 puntos.", 4, 15);
		centrar ("Cada pregunta respondida donde se use un comodin, vera reducido su puntaje en 0.15 puntos.", 4, 16);
		centrar ("El usuario tendra disponible para un unico uso lo siguiente:", 4, 18);
		centrar ("- Los 3 comodines: Ayuda Profesor!!!  ,  Cambiar Pregunta,  Cambiar Alternativa.", 6, 19);
		centrar ("- La segunda oportunidad a traves de uno de los siguientes minijuegos:", 6, 20);
		centrar ("Ahorcado, Pregunta Flash, Verdadero y Falso, Adivina el numero.", 7, 21);
	}

	if (d->normal){
		centrar ("NORMAL", 1, 12);
		centrar ("En esta dificultad el usuario recibira 15 preguntas.", 4, 13);
		centrar ("Cada pregunta respondida correctamente equivale a 2 puntos.", 4, 14);
		centrar ("Cada pregunta respondida despues de usar su segunda oportunidad, vera reducido su puntaje en 0.5 puntos.", 4, 15);
		centrar ("Cada pregunta respondida donde se use un comodin, vera reducido su puntaje en 0.25 puntos.", 4, 16);
		centrar ("El usuario tendra disponible para un unico uso lo siguiente:", 4, 18);
		centrar ("- Los 3 comodines: Ayuda Profesor Araya!!!,  Cambiar Pregunta,  Cambiar Alternativa.", 6, 19);
		centrar ("- La segunda oportunidad a traves de uno de los siguientes minijuegos:", 6, 20);
		centrar ("Ahorcado, Pregunta Flash, Verdadero y Falso, Adivina el numero.", 7, 21);
	}

	if (d->hard){
		centrar ("DIFICIL", 1, 12);
		centrar ("En esta dificultad el usuario recibira 15 preguntas dificiles.", 4, 13);
		centrar ("Cada pregunta respondida correctamente equivale a 3 puntos.", 4, 14);
		centrar ("El usuario NO tendra disponible para su uso lo siguiente:", 4, 16);
		centrar ("- Los 3 comodines: Ayuda Profesor Araya!!!  ,  Cambiar Pregunta,  Cambiar Alternativa.", 6, 17);
		centrar ("- La segunda oportunidad a traves de uno de los siguientes minijuegos:", 6, 18);
	}
}

void DificultadMostrar (Dificultad *d){
	centrar (MAGENTA_T "Eliga la dificultad :", 8, 1);
	if (d->easy){
		centrar (VERDE_T "FACIL", 30, 3);
	    printf ("\n");
	}else{
		centrar (ROJO_T "FACIL", 30, 3);
	    printf ("\n");
	}
	if (d->normal){
		centrar (VERDE_T "NORMAL", 30, 5);
	    printf ("\n");
	}else{
		centrar (ROJO_T "NORMAL", 30, 5);
	    printf ("\n");
	}
	if (d->hard){
		centrar (VERDE_T "DIFICIL", 30, 7);
	    printf ("\n");
	}else{
		centrar (ROJO_T "DIFICIL", 30, 7);
	    printf ("\n");
	}
	centrar (MAGENTA_T "Volver", 30, 9);
	descripcionDificultad(d);
	printf ("\n\n");
}

void DificultadMenu (Dificultad *d){
	int menu = 3;

	while (menu != 10){
		DificultadMostrar (d);

		while (1)
		{
		    Sleep(200);

		   if (GetAsyncKeyState(VK_UP)){
			   menu = menu == TemaInicio ? TemaFin: menu-2;
			   printf ("\r                           ");
			   goy (LineaDeInicio + menu - 1);
			   printf ("---->");
		    } else if (GetAsyncKeyState(VK_DOWN)){
			   menu = menu == TemaFin ? TemaInicio: 2+menu;
			   printf ("\r                           ");
			   goy (LineaDeInicio + menu - 1);
			   printf ("---->");
		    } else if (GetAsyncKeyState(VK_RETURN)){
			   break;
		    }
	    }

		if (menu == 9)break;

		switch (menu){
		case 3:
		       system ("cls");
			   if (!d->easy){
				   d->easy = true;
				   d->normal = false;
				   d->hard = false;
			   }
			   break;

		case 5:
		       system ("cls");
			   if (!d->normal){
				   d->normal = true;
				   d->easy = false;
				   d->hard = false;
			   }
			   break;

		case 7:
		       system ("cls");
			   if (!d->hard){
				   d->hard = true;
				   d->easy = false;
				   d->normal = false;
			   }
			   break;   
	    }
		system ("cls");
	}

}

void PresentarUser(Usuario *user, Dificultad *d){
	gotoxy(10,10);
	printf("Nombre de Usuario:         %s\n", user->user);
	gotoxy(10,11);
	printf("Dificultad seleccionada:   ");
	if (d->easy){printf("Facil\n");}
	else if (d->normal){printf("Normal\n");}
	else{printf("Dificil\n");}
	return ;
}

void MostrarReglas(){
	FILE *F = fopen("./Datos/Reglas.txt", "r"); // Abre el archivo con el nombre recibido en modo lectura
	if (!F){return;}// Si no existe el archivo, cierra el programa

	char  linea[2001];
	int y=1, x=1;
	int cont = 0;
	while (fgets(linea, 2000, F) != NULL) { 
    		// Recorre el archivo leyendo linea por linea e imprimiendolas en pantalla.

			centrar (linea, x, y);
			y++;
			cont++;
			if(cont == 10){cronometro(2); cont = 0;}
	}
	fclose(F);// Se cierra el archivo

	cronometro(2);
	printf("\n\n\n\n\n Espere 5 segundos para salir ...");
	cronometro(5);
}

int quizMove(){
	int menu = 4;
	while (1)
	{
		Sleep(200);

		if (GetAsyncKeyState(VK_UP)){
			menu = menu == QuizInicio ? QuizFin: menu-3;
			printf ("\r                    ");
			gotoxy (15, LineaDeInicio + menu - 1);
			printf ("->");
		} else if (GetAsyncKeyState(VK_DOWN)){
			menu = menu == QuizFin ? QuizInicio: 3+menu;
			printf ("\r                    ");
			gotoxy (15, LineaDeInicio + menu - 1);
			printf ("->");
		 } else if (GetAsyncKeyState(VK_RETURN)){
			break;
		}
	}

	return menu;
}


void pregunta(int contador, Pregunta *questionForNow){
	gotoxy(0,0);
	printf ("Pregunta : %i", contador);
	centrar (questionForNow->question, 15, 0);
	
	centrar ("A.", 20, 4);
	centrar (firstList(questionForNow->answerTrue), 25, 4);
	centrar ("B.", 20, 7);
	centrar (firstList(questionForNow->answerFalse), 25, 7);
	centrar ("C.", 20, 10);
	centrar (nextList(questionForNow->answerFalse), 25, 10);
	centrar ("D.", 20, 13);
	centrar (nextList(questionForNow->answerFalse), 25, 13);
	
	centrar ("Comodin", 25, 16);
}

void menuEXIT (){
	centrar ("Punto seguro :) elija la opcion que desee :", 25,0);
	centrar ("Seguir Partida",30,3);
	centrar ("Guardar y Salir", 30, 5);
}

void comodinMenu(Comodin *com){
	centrar ("Comodines  (Si esta en rojo es que ya lo uso):", 15,0);
	if (com->HelpTeacher){
		centrar (VERDE_T"Ayuda Profe Araya",30,3);
	}else{
		centrar (ROJO_T"Ayuda Profe Araya",30,3);
	}

	if (com->alternativeChange){
		centrar (VERDE_T"Cambiar las alternativas",30,5);
	}else{
		centrar (ROJO_T"Cambiar las alternativas",30,5);
	}

	if (com->questionChange){
		centrar (VERDE_T"Cambiar la pregunta",30,7);
	}else{
		centrar (ROJO_T"Cambiar la pregunta",30,7);
	}
	
	centrar (MAGENTA_T"Volver", 30, 9);
}

void saveORexit (int *exit){
	int menu = 3;

	while (menu != 9){
		menuEXIT();

		while (1){
		    Sleep(200);

		   if (GetAsyncKeyState(VK_UP)){
			   menu = menu == TemaInicio ? exitFin: menu-2;
			   printf ("\r                           ");
			   goy (LineaDeInicio + menu - 1);
			   printf ("---->");
		    } else if (GetAsyncKeyState(VK_DOWN)){
			   menu = menu == exitFin ? TemaInicio: 2+menu;
			   printf ("\r                           ");
			   goy (LineaDeInicio + menu - 1);
			   printf ("---->");
		    } else if (GetAsyncKeyState(VK_RETURN)){
			   break;
		    }
	    }

		switch (menu){
			case 3://SeguirPartida
			system("cls");
			centrar ("ELEGISTE LA OPCION SEGUIR JUGANDO", 5,5);
			Sleep(1000);
			menu = 1;
			break;

			case 5://GuardarYsalir
			system ("cls");
			centrar ("ELEGISTE LA OPCION GUARDAR PARTIDA",5,5);
			Sleep (1000);
			menu = 0;
			break;

		}

		if (menu == 0){
			(*exit) = 1;
			break;
		}else{
			break;
		}
		
	}

	system ("cls");
}

void comodin (Comodin *com){
	int menu = 3;

	system ("cls");

	while (menu != 10){
		comodinMenu(com);

		while (1){
		    Sleep(200);

		   if (GetAsyncKeyState(VK_UP)){
			   menu = menu == TemaInicio ? TemaFin: menu-2;
			   printf ("\r                           ");
			   goy (LineaDeInicio + menu - 1);
			   printf ("---->");
		    } else if (GetAsyncKeyState(VK_DOWN)){
			   menu = menu == TemaFin ? TemaInicio: 2+menu;
			   printf ("\r                           ");
			   goy (LineaDeInicio + menu - 1);
			   printf ("---->");
		    } else if (GetAsyncKeyState(VK_RETURN)){
			   break;
		    }
	    }

		if (menu == 9)break;

		switch (menu){
			case 3://Ayuda profe araya
			    if (!com->HelpTeacher)break;
			    system("cls");
			    centrar ("Ayudeme profesor aaaaaaaaaaaaaa", 5,5);
				com->HelpTeacher = false;
			    Sleep(1000);
			    menu = 0;
			    break;

			case 5://50/50
			    if (!com->alternativeChange)break;
			    system ("cls");
			    centrar ("FIFTY FIFTY MAI BRUDA",5,5);
				com->alternativeChange = false;
			    Sleep (1000);
			    menu = 0;
			    break;

			case 7://pregunta nueva
			    if (!com->questionChange)break;
			    system ("cls");
			    centrar ("NEXT",5,5);
				com->questionChange = false;
			    Sleep (1000);
			    menu = 0;
			    break;

		}
        system("cls");
		if (menu == 0)break;
		
	}

	system ("cls");
}

void comenzarjuego(Usuario *quizUser, HashMap* preguntasQuiz){
	Sleep (1500);
	Comodin *com = quizUser->comodines;
	int menu = 5, contador = 0, exit = 0;
	system("cls");
	char *idQuestion = firstList(quizUser->selectedQuestions);
	if (quizUser->cantQuestion != 0)
	{
		int cont = 1;
		while (cont != quizUser->cantQuestion)
		{
			idQuestion = nextList(quizUser->selectedQuestions);
			cont++;
		}
	}
	
	Pregunta *aux;

	while (1){
		quizUser->cantQuestion++;
		contador++;
		aux = searchHashMap(preguntasQuiz, idQuestion);
		pregunta(quizUser->cantQuestion, aux);
		idQuestion = nextList(quizUser->selectedQuestions);
		
		menu = quizMove();

		switch(menu){
			case 4://Opcion A
			      //verificacion();
				  system ("cls");
                  centrar ("Eligio la opcion A", 10,5);
				  Sleep(1000);
				  centrar ("La alternativa correcta es la A", 10,7);
				  Sleep(1000);
				  break;
                  
			case 7://Opcion B
			      //verificacion();
				  system ("cls");
                  centrar ("Eligio la opcion B", 10,5);
				  Sleep(1000);
				  centrar ("La alternativa correcta es la A", 10,7);
				  Sleep(1000); quizUser->life = false;
				  break;

			case 10://Opcion C
			      //verificacion();
				  system ("cls");
                  centrar ("Eligio la opcion C", 10,5);
				  Sleep(1000);
				  centrar ("La alternativa correcta es la A", 10,7);
				  Sleep(1000); quizUser->life = false;
				  break;

			case 13://Opcion D
                  //verificacion();
				  system ("cls");
                  centrar ("Eligio la opcion D", 10,5);
				  Sleep(1000);
				  centrar ("La alternativa correcta es la A", 10,7);
				  Sleep(1000); quizUser->life = false;
				  break;

			case 16://Comodin
                  comodin (com);
				  break;

		}

		system ("cls");
		
		if (!quizUser->life){return;}

		if (contador == 5 & quizUser->cantQuestion != 15){
			contador = 0;
		    saveORexit(&exit);

			if (exit == 1) break;
		}

		if (quizUser->cantQuestion == 15)break;

	}
	quizUser->life = true;
}

int main(){
	int menu = 3;
	
	HashMap *questionsHash = GuardarPreguntas("./Datos/Preguntas.txt",100);
	VerdaderoFalso *comodinToF = GuardarToF("./Datos/TrueOrFalse.txt");
	Dificultad *d = leerDificult("./Save/DifSelec.txt");
	List *ahorcado = guardarMinijuegoAhorcado("./Datos/Ahorcado.txt");
	Usuario *user = crearUsuario(nombreUsuario("./Save/Usuario.txt"), d);
	Comodin *com;

	system ("COLOR 7D");
	bienvenida();
	Sleep (1000);
	system ("cls");

	while (menu != 14){
		mostrarMenu();

		menu = movimiento();

		if (menu == 13){// opcion Salir
			break; 
		}

		switch (menu){
		case 3://Comenzar partida
		    system ("cls");
			
			comodinesDificultad(user, d);
			azarQuestion(user, questionsHash);	
			user->user = _strdup(nombreUsuario("./Save/Usuario.txt"));
			user->life = true;
			
			PresentarUser(user, d);
			
			comodinesDificultad(user, d);
			
			user->cantQuestion = 0;
			comenzarjuego(user, questionsHash);
			
			if(user->life && user->cantQuestion != 15){
				partidaExiste("./Save/ExistePartida.txt", user->life);
				guardarPartida(user, d, "./Save/Partida.txt");
			}
			break;

		case 5://Cargar partida
		    system ("cls");
			if(noExistePartida("./Save/ExistePartida.txt"))
			{centrar ("No existe partida guardada", 10,5); Sleep (3000); break;}

			cargarPartida("./Save/Partida.txt", user, d);

			mostrarDatosUsuario(user, d);

			comenzarjuego(user, questionsHash);

			if(user->life && user->cantQuestion != 15){
				partidaExiste("./Save/ExistePartida.txt", user->life);
				guardarPartida(user, d, "./Save/Partida.txt");
			}
			else if (!user->life || user->cantQuestion == 15)
			{
				partidaExiste("./Save/ExistePartida.txt", false);
			}
			break;

		case 7://Dificultad
			system ("cls");
			DificultadMenu (d);
			saveDificult("./Save/DifSelec.txt", d);
			break;
               
		case 9://Top
			system ("cls");
			centrar ("Pronto estara hecho esta funcion", 10,5);
			Sleep (1000);
			break;

		case 11://Reglas
		    system ("cls");
			MostrarReglas();
			break;
		
		default:
				break;
	    }
		
		system ("cls");
		
	}
	return EXIT_SUCCESS;
}
