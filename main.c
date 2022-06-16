//Contiene las funciones para guardar los datos al comenzar el programa
#include "guardarDatos.h" //Incluye todas las librerias usadas, que estan en global.h

int main(){
	HashMap *questionsHash = GuardarPreguntas("./Datos/Preguntas.txt",100);
	Dificultad *dif;

	int SAVE = ExistePartida("./Save/Partida.txt"); // Resive 0 si no existe partida guardada y 1 en caso contrario

	if (SAVE == 0){dif->easy = false; dif->hard = false; dif->normal = true;}
	
	return EXIT_SUCCESS;
}