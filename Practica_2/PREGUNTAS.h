#ifndef PREGUNTAS_H_INCLUDED
#define PREGUNTAS_H_INCLUDED
#include <iostream>

using namespace std;

struct Pregunta;
void CrearPregunta(Pregunta& p);
string PreguntaCompleta(Pregunta& p);
int respuestaCorrecta(Pregunta& p);
struct Pregunta{
 friend void CrearPregunta(Pregunta& p);
 friend string PreguntaCompleta(Pregunta& p);
 friend int respuestaCorrecta(Pregunta& p);
 private:
     string datosPreg;
     string r1;
     string r2;
     string r3;
     int respuestaCorrecta;
};

#endif // PREGUNTAS_H_INCLUDED
