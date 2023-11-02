#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED
#include <iostream>

using namespace std;

/*///Dise�ar e implementar un TAD Participante que defina un nuevo tipo participante y que deber� poder utilizarse para
///representar toda la informaci�n que corresponda a un concepto de participante que incluya: una sola cadena con sus
///3 datos de contacto, y sendos contadores naturales con: su n�mero de aciertos, n�mero de fallos, y n�mero de veces que
///ha optado por pasar. El tipo participante se deber� implementar como un TAD, de acuerdo a las indicaciones dadas en
///la asignatura, y ser dise�ado con las operaciones y propiedades que se consideren adecuadas. El TAD deber� contar
///con una operaci�n que dado un participante devuelva una cadena que contenga la informaci�n del participante con el
///siguiente formato: una cadena �OK: �, seguida del n�mero de aciertos del participante, seguida de la cadena �||F: �
///seguida del n�mero de fallos del participante, seguida de la cadena �||P: � seguida del n�mero de veces que ha optado
///por pasar, seguida de la cadena �||D: �, y seguida de la cadena con los datos de contacto del participante.
*/
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
