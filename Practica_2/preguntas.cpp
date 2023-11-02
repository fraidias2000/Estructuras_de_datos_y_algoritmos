#include "PREGUNTAS.h"
#include <iostream>
#include <sstream>

using namespace std;


void CrearPregunta(Pregunta& p/*, string datoPreg, string r1, string r2, string r3, int rCorrecta*/){
  string datoAux;
  datoAux ="";
  cout << "Escribe la pregunta a anyadir: (sin interrogantes) ";
  cin >> ws;
  getline(cin,datoAux);
  p.datosPreg = datoAux;
  cout << "Escribe la primera respuesta: ";

  getline(cin,datoAux);
  p.r1 = datoAux;
  cout << "Escribe la segunda respuesta: ";
  getline(cin,datoAux);
  p.r2 = datoAux;
  cout << "Escribe la tercera respuesta: ";
  getline(cin,datoAux);
  p.r3 = datoAux;
  cout << "Indica con 1, 2 o 3 cual es la respuesta correcta para A, B o C: " ;
  cin >>p.respuestaCorrecta;

}

 int respuestaCorrecta(Pregunta& p){
  return p.respuestaCorrecta;
 }

string PreguntaCompleta(Pregunta& p){
 ostringstream cadena;
 cadena << "<*" << char(168) << p.datosPreg << " ?*> \n";
 cadena << "<A)" << p.r1 << "<B)" << p.r2 << "<C)" << p.r3 << "\n";
 return cadena.str();
}
