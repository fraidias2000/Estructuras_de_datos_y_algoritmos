#include "Participantes.h"
#include <iostream>
#include <sstream>
using namespace std;

void crearParticipante(string datos, Participante& p){
    p.datos = datos;
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
  p.pasos;
 }

 string infoParticipante(Participante& p){
    string cadena = "OK: " + std::to_string(p.aciertos) + " ||F: " + std::to_string(p.fallos) + " ||P: " + std::to_string(p.pasos) + " ||D: "+ p.datos ;
   return cadena;
 }
