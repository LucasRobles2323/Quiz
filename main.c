//Contiene las funciones para guardar los datos al comenzar el programa
#include "quiz.h" //Incluye todas las librerias usadas, que estan en global.h

#define MenuInicio 3
#define MenuFin 13
#define LineaDeInicio 1
#define TemaInicio 3
#define TemaFin 9
#define QuizFin 16
#define QuizComodinFin 13
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
	centrar (AZUL_T "      PUCV", 20, 7);
	Sleep (300);
	centrar (MAGENTA_T"Se recomienda bajar el volumen para que el sonido no le moleste", 20, 9);
	centrar ("Se recomienda agrandar la consola para leer mejor las preguntas", 20, 10);
	Sleep (2000);
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
		centrar ("Cada pregunta respondida donde se use un comodin, vera reducido su puntaje en 0.15 puntos.", 4, 16);
		centrar ("El usuario tendra disponible para un unico uso lo siguiente:", 4, 18);
		centrar ("- Los 3 comodines: Ayuda Profesor!!!  ,  Cambiar Pregunta,  Cambiar Alternativa.", 6, 19);
	}

	if (d->normal){
		centrar ("NORMAL", 1, 12);
		centrar ("En esta dificultad el usuario recibira 15 preguntas.", 4, 13);
		centrar ("Cada pregunta respondida correctamente equivale a 2 puntos.", 4, 14);
		centrar ("Cada pregunta respondida donde se use un comodin, vera reducido su puntaje en 0.25 puntos.", 4, 16);
		centrar ("El usuario tendra disponible para un unico uso lo siguiente:", 4, 18);
		centrar ("- Los 3 comodines: Ayuda Profesor Araya!!!,  Cambiar Pregunta,  Cambiar Alternativa.", 6, 19);
	}

	if (d->hard){
		centrar ("DIFICIL", 1, 12);
		centrar ("En esta dificultad el usuario recibira 15 preguntas.", 4, 13);
		centrar ("Cada pregunta respondida correctamente equivale a 3 puntos.", 4, 14);
		centrar ("El usuario NO tendra disponible para su uso lo siguiente:", 4, 16);
		centrar ("- Los 3 comodines: Ayuda Profesor Araya!!!  ,  Cambiar Pregunta,  Cambiar Alternativa.", 6, 17);
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
	int y=1, x=2;
	while (fgets(linea, 2000, F) != NULL) { 
    		// Recorre el archivo leyendo linea por linea e imprimiendolas en pantalla.
			gotoxy(x, y);
			printf(AZUL_T "%s", linea);
			y++;
	}
	fclose(F);// Se cierra el archivo
	y+= 10; x += 25;
	gotoxy(x, y);
	printf(MAGENTA_T "Salir");
	int menu = y, inicio, final=y;

	while (1)
	{
		Sleep(200);

		if (GetAsyncKeyState(VK_UP)){
			menu = menu == inicio ? final: menu;
			printf ("\r            ");
			gotoxy (x-3, LineaDeInicio + menu - 1);
			printf ("->");
		} else if (GetAsyncKeyState(VK_DOWN)){
			menu = menu == inicio ? final: menu;
			printf ("\r            ");
			gotoxy (x-3, LineaDeInicio + menu - 1);
			printf ("->");
		 } else if (GetAsyncKeyState(VK_RETURN)){
			break;
		}
	}
}

int quizWCom(){
	int menu = 4;
	while (1)
	{
		Sleep(200);

		if (GetAsyncKeyState(VK_UP)){
			menu = menu == QuizInicio ? QuizComodinFin: menu-3;
			printf ("\r                    ");
			gotoxy (15, LineaDeInicio + menu - 1);
			printf ("->");
		} else if (GetAsyncKeyState(VK_DOWN)){
			menu = menu == QuizComodinFin ? QuizInicio: 3+menu;
			printf ("\r                    ");
			gotoxy (15, LineaDeInicio + menu - 1);
			printf ("->");
		 } else if (GetAsyncKeyState(VK_RETURN)){
			break;
		}
	}

	return menu;
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
	centrar (questionForNow->A->alternative, 25, 4);
	centrar ("B.", 20, 7);
	centrar (questionForNow->B->alternative, 25, 7);
	centrar ("C.", 20, 10);
	centrar (questionForNow->C->alternative, 25, 10);
	centrar ("D.", 20, 13);
	centrar (questionForNow->D->alternative, 25, 13);
	
	centrar ("Comodin", 25, 16);
}

void preguntaConComodin(int contador, Pregunta *questionForNow){
	gotoxy(0,0);
	printf ("Pregunta : %i", contador);
	centrar (questionForNow->question, 15, 0);

	
	centrar ("A.", 20, 4);
	centrar (questionForNow->A->alternative, 25, 4);
	centrar ("B.", 20, 7);
	centrar (questionForNow->B->alternative, 25, 7);
	centrar ("C.", 20, 10);
	centrar (questionForNow->C->alternative, 25, 10);
	centrar ("D.", 20, 13);
	centrar (questionForNow->D->alternative, 25, 13);
	centrar ("Comodin (bloqueado)", 25, 16);
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

int comodin (Comodin *com){
	int menu = 3, wildcard = 0;

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

		if (menu == 9)return 10;

		switch (menu){
			case 3://Ayuda profe araya
			    if (!com->HelpTeacher)break;
				com->HelpTeacher = false;
				wildcard = 1;
			    menu = 0;
			    break;

			case 5://50/50
			    if (!com->alternativeChange)break;
				com->alternativeChange = false;
				wildcard = 2;
			    menu = 0;
			    break;

			case 7://pregunta nueva
			    if (!com->questionChange)break;
				com->questionChange = false;
				wildcard = 3;
			    menu = 0;
			    break;

		}
        system("cls");
		if (menu == 0)return wildcard;
		
	}

	system ("cls");
}

void preguntaCorrecta(Pregunta *questionForNow, int respuesta, bool correcto){

	//si la correcta es la A
	if (respuesta == 0){
		if (correcto){
	        centrar (VERDE_T"A.", 20, 4);
	        centrar (questionForNow->A->alternative, 25, 4);
	        centrar (ROJO_T "B.", 20, 7);
	        centrar (questionForNow->B->alternative, 25, 7);
	        centrar ("C.", 20, 10);
	        centrar (questionForNow->C->alternative, 25, 10);
	        centrar ("D.", 20, 13);
	        centrar (questionForNow->D->alternative, 25, 13);
			centrar (MAGENTA_T"LA RESPUESTA ES CORRECTA", 25, 16);
			Sleep (3000);
		}else{

			if (questionForNow->B->answer){
				centrar (ROJO_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar (VERDE_T "B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar (ROJO_T"C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar ("D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}

			if (questionForNow->C->answer){
				centrar (ROJO_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar ("B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar (VERDE_T"C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar (ROJO_T"D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}

			if (questionForNow->D->answer){
				centrar (ROJO_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar ("B.", 20, 7);
	            centrar (questionForNow->A->alternative, 25, 7);
	            centrar ("C.", 20, 10);
	            centrar (questionForNow->A->alternative, 25, 10);
	            centrar (VERDE_T"D.", 20, 13);
	            centrar (questionForNow->A->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}			
		}
	}

	//si la respusta es la B
	if (respuesta == 1){
		if (correcto){
			centrar (ROJO_T"A.", 20, 4);
	        centrar (questionForNow->A->alternative, 25, 4);
	        centrar (VERDE_T "B.", 20, 7);
	        centrar (questionForNow->B->alternative, 25, 7);
	        centrar (ROJO_T"C.", 20, 10);
	        centrar (questionForNow->C->alternative, 25, 10);
	        centrar ("D.", 20, 13);
	        centrar (questionForNow->D->alternative, 25, 13);
			centrar (MAGENTA_T"LA RESPUESTA ES CORRECTA", 25, 16);
			Sleep (3000);
			return;
		}else{

			if (questionForNow->A->answer){
				centrar (VERDE_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar (ROJO_T "B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar ("C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar ("D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}

			if (questionForNow->C->answer){
				centrar (ROJO_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar ("B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar (VERDE_T"C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar (ROJO_T"D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}

			if (questionForNow->D->answer){
				centrar (ROJO_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar ("B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar ("C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar (VERDE_T"D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}		
		}
	}

	//si la respuesta es la C
	if (respuesta == 2){
		if (correcto){
			centrar (ROJO_T "A.", 20, 4);
	        centrar (questionForNow->A->alternative, 25, 4);
	        centrar ("B.", 20, 7);
	        centrar (questionForNow->B->alternative, 25, 7);
	        centrar (VERDE_T"C.", 20, 10);
	        centrar (questionForNow->C->alternative, 25, 10);
	        centrar (ROJO_T"D.", 20, 13);
	        centrar (questionForNow->D->alternative, 25, 13);
			centrar (MAGENTA_T"LA RESPUESTA ES CORRECTA", 25, 16);
			Sleep (3000);
			return;
		}else{

			if (questionForNow->A->answer){
				centrar (VERDE_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar (ROJO_T "B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar ("C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar ("D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}

			if (questionForNow->B->answer){
				centrar (ROJO_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar (VERDE_T"B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar (ROJO_T"C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar ("D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}

			if (questionForNow->D->answer){
				centrar (ROJO_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar ("B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar ("C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar (VERDE_T"D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}
		}
	}

	//si la respuesta es la D
	if (respuesta == 3){
		if (correcto){
			centrar (ROJO_T "A.", 20, 4);
	        centrar (questionForNow->A->alternative, 25, 4);
	        centrar ( "B.", 20, 7);
	        centrar (questionForNow->B->alternative, 25, 7);
	        centrar ("C.", 20, 10);
	        centrar (questionForNow->C->alternative, 25, 10);
	        centrar (VERDE_T"D.", 20, 13);
	        centrar (questionForNow->D->alternative, 25, 13);
			centrar (MAGENTA_T"LA RESPUESTA ES CORRECTA", 25, 16);
			Sleep (3000);
			return;
		}else{

			if (questionForNow->A->answer){
				centrar (VERDE_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar (ROJO_T "B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar ("C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar ("D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}

			if (questionForNow->B->answer){
				centrar (ROJO_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar (VERDE_T"B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar (ROJO_T"C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar ("D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}

			if (questionForNow->C->answer){
				centrar (ROJO_T"A.", 20, 4);
	            centrar (questionForNow->A->alternative, 25, 4);
	            centrar ("B.", 20, 7);
	            centrar (questionForNow->B->alternative, 25, 7);
	            centrar (VERDE_T"C.", 20, 10);
	            centrar (questionForNow->C->alternative, 25, 10);
	            centrar (ROJO_T"D.", 20, 13);
	            centrar (questionForNow->D->alternative, 25, 13);
				centrar (MAGENTA_T"LA RESPUESTA ES INCORRECTA", 25, 16);
				Sleep (3000);
			    return;
			}
		}
	}
}

void comenzarjuego(Usuario *quizUser, HashMap* preguntasQuiz){
	Sleep (1500);
	Comodin *com = quizUser->comodines;
	int menu = 5, contador = 0, exit = 0, wildcard = 0, volver = 0;
	bool comodinUsando =
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
		
		if (volver == 0){
			quizUser->cantQuestion++;
		    contador++;
		    aux = searchHashMap(preguntasQuiz, idQuestion);
			AzarAlternatives(aux);
		    pregunta(quizUser->cantQuestion, aux);
			idQuestion = nextList(quizUser->selectedQuestions);
			menu = quizMove();
		    
		}else if (volver == 1 && comodinUsando == false){
			system ("cls");
			volver = 0;
			pregunta(quizUser->cantQuestion, aux);
			menu = quizMove();
		
		}else if (volver == 1 && comodinUsando == true){
			
			preguntaConComodin(quizUser->cantQuestion, aux);
			comodinUsando = false;
			volver = 0;
			menu = quizWCom();
		}

		switch(menu){
			case 4://Opcion A
				  preguntaCorrecta (aux, 0, aux->A->answer);
				  if(aux->A->answer == false)quizUser->life = false;
				  else{quizUser->life = true;}
				  break;
			case 7://Opcion B
                  preguntaCorrecta (aux, 1, aux->B->answer);
				  if(aux->B->answer == false)quizUser->life = false;
				  else{quizUser->life = true;}
				  break;

			case 10://Opcion C
                  preguntaCorrecta (aux, 2, aux->C->answer);
				  if(aux->C->answer == false)quizUser->life = false;
				  else{quizUser->life = true;}
				  break;

			case 13://Opcion D
                  preguntaCorrecta (aux, 3, aux->D->answer);
				  if(aux->D->answer == false)quizUser->life = false;
				  else{quizUser->life = true;}
				  break;

			case 16://Comodin
                  wildcard = comodin (com);

				   if (wildcard == 10){
					volver = 1;
					break;
				  }else if (wildcard == 1){//Caso ayudame profe araya
					int counter = 0, random = 0, pos = 23;
					bool a = true, b = true, c = true, d = true;
					srand(time(NULL));
					centrar ("Mensaje del profesor Araya :", 5, 20);
					Sleep (1000);
					sndPlaySound ("songs\\MSN", SND_ASYNC);
					centrar ("Estas alternativas son incorrectas :",5, 21);
					while (1){
						random = rand() % 22;

						if ( random >= 0 && random < 6){
							if (a){
								if (!aux->A->answer){
								   if (pos == 23){
									    centrar (aux->A->alternative, 5, pos);
									    pos = 25;
								    }else{
									     centrar (aux->A->alternative, 5, pos);
								    }
									counter++;
							    }
							    a = false;
							}
						}

						if ( random >= 6 && random < 11){
							if (b){
								if (!aux->B->answer){
								   if (pos == 23){
									    centrar (aux->B->alternative, 5, pos);
									    pos = 25;
								    }else{
									     centrar (aux->B->alternative, 5, pos);
								    }
									counter++;
							    }
								 b = false;
							    
							}
						}

						if ( random >= 11 && random < 16){
							if (c){
								if (!aux->C->answer){
								   if (pos == 23){
									    centrar (aux->C->alternative, 5, 22);
									    pos = 25;
								    }else{
									     centrar (aux->C->alternative, 5, 23);
								    }
									counter++;
							    }
							    c = false;
							}
						}

						if ( random >= 16 && random < 22){
							if (d){
								if (!aux->D->answer){
								   if (pos == 23){
									    centrar (aux->D->alternative, 5, pos);
									    pos = 25;
								    }else{
									     centrar (aux->D->alternative, 5, pos);
								    }
									counter++;
								}
							    d = false;
							}
						}

						if (counter == 2)break;
					}
					volver = 1;
					comodinUsando = true;
					break;
				  }else if (wildcard == 2){//cambio de alternativa
					system ("cls");
					centrar ("Cambio de alternativa", 5,5);
					comodinUsando = true;
					break;
				  }else if (wildcard == 3){//cambio de pregunta
					system ("cls");
					idQuestion = nextList(quizUser->selectedQuestions);
					aux = searchHashMap(preguntasQuiz, idQuestion);
					volver = 1;
					comodinUsando = true;
					break;
				  }

		}

		

		if (volver == 0){
			system ("cls");
			if (!quizUser->life){return;}

		    if (contador == 5 & quizUser->cantQuestion != 15){
			     contador = 0;
		         saveORexit(&exit);

			     if (exit == 1) break;
		     }

		    if (quizUser->cantQuestion == 15)break;
			
		}
	}
	quizUser->life = true;
}

void mostrarTop(TreeMap *top){
	int y = 5;
	int pos = 1;
	Pair *auxiliar = firstTreeMap(top);
	Top *aux = auxiliar->value;
	while (aux)
	{
		gotoxy(10, y);
		printf(AZUL_T "%d.- %s %.3f", pos, aux->usuario, aux->puntaje);
		y++;
		pos++;
		if (pos == 6){break;}
		auxiliar = nextTreeMap(top);
		aux = auxiliar->value;
		Sleep(250);
	}

	y+= 10; int x = 35;
	gotoxy(x, y);
	printf(MAGENTA_T "Salir");
	int menu = y, inicio, final=y;

	while (1)
	{
		Sleep(200);

		if (GetAsyncKeyState(VK_UP)){
			menu = menu == inicio ? final: menu;
			printf ("\r            ");
			gotoxy (x-3, LineaDeInicio + menu - 1);
			printf ("->");
		} else if (GetAsyncKeyState(VK_DOWN)){
			menu = menu == inicio ? final: menu;
			printf ("\r            ");
			gotoxy (x-3, LineaDeInicio + menu - 1);
			printf ("->");
		 } else if (GetAsyncKeyState(VK_RETURN)){
			break;
		}
	}
}

int main(){
	int menu = 3;
	srand(time(NULL));

	
	HashMap *questionsHash = GuardarPreguntas("./Datos/Preguntas.txt",100);
	Dificultad *d = leerDificult("./Save/DifSelec.txt");
	Usuario *user = crearUsuario(nombreUsuario("./Save/Usuario.txt"), d);
	TreeMap *top = crearTop("./Save/Top.txt");

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
			mostrarTop(top);
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
