#include "guardarDatos.h"

// cambia los comodines del usuario de acuerdo a la dificultad
void comodinesDificultad(Usuario *user, Dificultad *condicion);

// Selecciona y guarda 16 preguntas al azar sin repetir
void azarQuestion(Usuario* user, HashMap* map);

// Selecciona y guarda 4 alternativas al azar sin repetir con solo una correcta
// para una pregunta
void AzarAlternatives(Pregunta* preg);