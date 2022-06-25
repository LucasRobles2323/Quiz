#include "global.h"

HashMap *GuardarPreguntas(char *archive, int capacidad);

Dificultad *leerDificult(char *archive);

VerdaderoFalso *GuardarToF(char *archive);

char *nombreUsuario(char *fileName);

Usuario *crearUsuario(char *fileName, Dificultad *dif);

void saveDificult(char *archive, Dificultad *guardar);

bool noExistePartida(char *archive);

List *guardarMinijuegoAhorcado(char *file);

void partidaExiste(char *archive, bool existe);

void guardarPartida(Usuario *USER, Dificultad *dif, char *archive);