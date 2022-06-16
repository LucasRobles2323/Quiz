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
		centrar ("En esta dificultad estaran disponibles para el usuario los 3 comodines y una segunda oportunidad.", 1, 13);
		centrar ("Solo estaran los temas 1,2,3,4 presentes en el quiz . El quiz contendra solo 6 preguntas.", 1, 14);
		centrar ("Las preguntas valdran 1 puntos (c/u) por el multiplicador de dificultad dicho en las reglas", 1, 16);
	}

	if (d->normal){
		centrar ("Dificultad: NORMAL", 1, 12);
		centrar ("En esta dificultad estaran disponibles para el usuario los 3 comodines y una segunda oportunidad.", 1, 13);
		centrar ("Solo estaran los 7 temas presentes en el quiz. El quiz contendra 15 preguntas.", 1, 14);
		centrar ("Las primeras 6 preguntas serna de los temas 1,2,3,4 y el resto seran de los temas 5,6,7", 1, 15);
		centrar ("Las preguntas valdran 1 puntos (c/u) por el multiplicador de dificultad dicho en las reglas", 1, 17);
	}

	if (d->hard){
		centrar ("Dificultad: HARD", 1, 12);
		centrar ("En esta dificultad no estaran disponibles para el usuario los comodines y el usuario no contara con una segunda oportunidad.", 1, 13);
		centrar ("Solo estaran los 7 temas presentes en el quiz. El quiz contendra 15 preguntas.", 1, 14);
		centrar ("Las primeras 6 preguntas serna de los temas 1,2,3,4 y el resto seran de los temas 5,6,7", 1, 15);
		centrar ("Las preguntas valdran 1 puntos (c/u) por el multiplicador de dificultad dicho en las reglas", 1, 17);
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
	VerdaderoFalso *comodinToF = GuardarToF("./Datos/TrueOrFalse.txt");
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

			   if (SAVE == 0){d->easy = false; d->hard = false; d->normal = true;}

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