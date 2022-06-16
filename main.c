#include <windows.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "list.h"
#include <conio.h>
//Contiene las funciones para guardar los datos al comenzar el programa
#include "guardarDatos.h" //Incluye todas las librerias usadas, que estan en global.h

#define MenuInicio 3
#define MenuFin 9
#define LineaDeInicio 1
#define TemaInicio 3
#define TemaFin 9
#define ROJO_T     "\x1b[31m"
#define VERDE_T        "\x1b[32m"
#define RESET_COLOR    "\x1b[0m"
#define MAGENTA_T  "\x1b[35m"
#define AZUL_T     "\x1b[34m"

typedef struct {
	bool easy;
	bool normal;
	bool hard;
}Dificultad;

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
	centrar ("QUIEN QUIERE PASAR EL RAMO!!!!!!!!!!",24,0);
	printf ("\n");
	centrar ("Comenzar Juego", 30,3);
	printf ("\n");
	centrar ("Cargar Juego", 30,5);
	printf ("\n");
	centrar ("Dificultad", 30,7);
	printf ("\n");
	centrar ("Salir", 30,9);
	printf ("\n\n");
}

void descripcionDificultad(Dificultad *d){
	if (d->easy){
		centrar ("Dificultad: EASY", 1, 12);
		centrar ("En esta dificultad habran solo habran 2 de los 7 temas presentes.", 1, 13);
		centrar ("- Punteros y Struct", 3, 14);
		centrar ("- TDAs, Listas y Listas Enlazadas", 3, 15);
		centrar ("Las preguntas valdran 1 puntos (c/u)", 1, 17);
	}

	if (d->normal){
		centrar ("Dificultad: NORMAL", 1, 12);
		centrar ("En esta dificultad habran solo habran 5 de los 7 temas presentes.", 1, 13);
		centrar ("- Punteros y Struct", 3, 14);
		centrar ("- TDAs, Listas y Listas Enlazadas", 3, 15);
		centrar ("- Implementacion de listas y arreglos", 3, 16);
		centrar ("- Complejidad temporal y Tabla Hash", 3, 17);
		centrar ("- Arbol binarios de busqueda", 3, 18);
		centrar ("Las preguntas valdran 3 puntos (c/u)", 1, 20);
	}

	if (d->hard){
		centrar ("Dificultad: HARD", 1, 12);
		centrar ("En esta dificultad estan todos los temas.", 1, 13);
		centrar ("- Punteros y Struct", 3, 14);
		centrar ("- TDAs, Listas y Listas Enlazadas", 3, 15);
		centrar ("- Implementacion de listas y arreglos", 3, 16);
		centrar ("- Complejidad temporal y Tabla Hash", 3, 17);
		centrar ("- Arbol binarios de busqueda", 3, 18);
		centrar ("- Monticulo Binario y arbol B/B++", 3, 19);
		centrar ("- Grafos", 3, 20);
		centrar ("Las preguntas valdran 5 puntos (c/u)", 1, 22);
	}
}

void temasMostrar (Dificultad *d){
	centrar (MAGENTA_T "Eliga la dificultad :", 8, 1);
	if (d->easy){
		centrar (VERDE_T "EASY", 30, 3);
	    printf ("\n");
	}else{
		centrar (ROJO_T "EASY", 30, 3);
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
		centrar (VERDE_T "HARD", 30, 7);
	    printf ("\n");
	}else{
		centrar (ROJO_T "HARD", 30, 7);
	    printf ("\n");
	}
	centrar (MAGENTA_T "Volver", 30, 9);
	descripcionDificultad(d);
	printf ("\n\n");
}

void temaMenu (Dificultad *d){
	int menu = 3;

	while (menu != 10){
		temasMostrar (d);

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

Dificultad *dificultBegins (Dificultad *d){
	Dificultad *newHere = (Dificultad*) malloc (sizeof(Dificultad));
    newHere->easy = false;
	newHere->normal = true;
	newHere->hard = false;
	return newHere;
}


int main(){
	int menu = 3;
	HashMap *questionsHash = GuardarPreguntas("./Datos/Preguntas.txt",100);
	Dificultad *d;
    d = dificultBegins(d);

	system ("COLOR 7D");
	bienvenida();
	Sleep (1000);
	system ("cls");
	
    
	while (menu != 9){
		mostrarMenu();

		menu = movimiento ();

		if (menu == 9) break;

		switch (menu){
		case 3:
		       system ("cls");
			   printf ("\n anashe \n");
			   system ("pause");
			   break;

		case 5:
		       system ("cls");
			   int SAVE = ExistePartida("./Save/Partida.txt"); // Resive 0 si no existe partida guardada y 1 en caso contrario

			   if (SAVE == 0){dif->easy = false; dif->hard = false; dif->normal = true;}

			   break;

		case 7:
		       system ("cls");
			   temaMenu (d);
			   break;   	   	   
	    }

		system ("cls");
		
	}
	//sndPlaySound ("C:\\Users\\Dante\\Desktop\\intento de menu\\menusound", 0);
	//PlaySound ("C:\\Users\\Dante\\Desktop\\intento de menu\\menusound", NULL, SND_FILENAME);
	return EXIT_SUCCESS;
}