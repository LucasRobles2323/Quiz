#include "global.h"

HashMap *GuardarPreguntas(char *archive, int capacidad); // Guarda todas las preguntas en un HashMap

Dificultad *leerDificult(char *archive); // Lee la dificultad guardada

char *nombreUsuario(char *fileName); // Lee el nombre de usuario del Usuario.txt

Usuario *crearUsuario(char *fileName, Dificultad *dif); // Crea el usuario para los casos de guardar partida y top

void saveDificult(char *archive, Dificultad *guardar); // Guarda la dificultad

bool noExistePartida(char *archive); // comprueba si existo o no partida

void partidaExiste(char *archive, bool existe); // escribe en el txt si existe o no partida

void guardarPartida(Usuario *USER, Dificultad *dif, char *archive); // Guarda la partida para poder cargarla

void cargarPartida(char *fileName, Usuario *user, Dificultad *d); // Carga la partida

TreeMap *crearTop(char *file); // Crea un treeMap para el top con los datos de un txt

void saveTop(char *file, TreeMap *top); // Guarda los 5 mayores puntajes del top en el txt