#include "PARTICIPANTE.h"
#include <iostream>
#include <sstream>
using namespace std;

void crearParticipante(Participante& p ,string dato){
   p.datos = dato;
   p.aciertos = 0;
   p.fallos = 0;
   p.pasos = 0;
}


 int numAciertos(Participante& p){
   return p.aciertos;
 }
 void ponerAciertos(Participante& p, int aciertos){
   p.aciertos = aciertos;

 }
  void ponerPasos(Participante& p, int pasos){
   p.pasos = pasos;

 }
  void ponerFallos(Participante& p, int fallos){
   p.fallos = fallos;

 }

 int numFallos(Participante& p){
  return p.fallos;
 }

 int numPasos(Participante& p){
  return p.pasos;
 }

 string infoParticipante(Participante& p){
     ostringstream cadena;
     cadena << "OK: " << p.aciertos;
     cadena << " ||F: " << p.fallos;
     cadena << " ||P: " << p.pasos;
     cadena << "||Datos: "  << p.datos;
   return cadena.str();
 }

