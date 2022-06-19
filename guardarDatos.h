#include "global.h"

HashMap *GuardarPreguntas(char *archive, int capacidad);

Dificultad *leerDificult(char *archive);

VerdaderoFalso *GuardarToF(char *archive);

void saveDificult(char *archive, Dificultad *guardar);

bool existePartida(char *archive);

List *guardarMinijuegoAhorcado(char *file);