#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED
#include <iostream>

using namespace std;

 struct Participante;
 void crearParticipante(Participante& p ,string dato);
 int numAciertos(Participante& p);
 void ponerAciertos(Participante& p, int aciertos);
 int numFallos(Participante& p);
 void ponerFallos(Participante& p, int fallos);
 int numPasos(Participante& p);
 void ponerPasos(Participante& p, int pasos);
 string infoParticipante(Participante& p);

 struct Participante{
   friend void crearParticipante(Participante& p ,string dato);
   friend int numAciertos(Participante& p);
   friend void ponerAciertos(Participante& p, int aciertos);
   friend int numFallos(Participante& p);
   friend void ponerFallos(Participante& p, int fallos);
   friend int numPasos(Participante& p);
   friend void ponerPasos(Participante& p, int pasos);
   friend string infoParticipante(Participante& p);
   private:
       string datos;
       int aciertos;
       int fallos;
       int pasos;
 };

#endif // PARTICIPANTE_H_INCLUDED
