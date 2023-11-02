#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED
#include <iostream>

using namespace std;

/*///Diseñar e implementar un TAD Participante que defina un nuevo tipo participante y que deberá poder utilizarse para
///representar toda la información que corresponda a un concepto de participante que incluya: una sola cadena con sus
///3 datos de contacto, y sendos contadores naturales con: su número de aciertos, número de fallos, y número de veces que
///ha optado por pasar. El tipo participante se deberá implementar como un TAD, de acuerdo a las indicaciones dadas en
///la asignatura, y ser diseñado con las operaciones y propiedades que se consideren adecuadas. El TAD deberá contar
///con una operación que dado un participante devuelva una cadena que contenga la información del participante con el
///siguiente formato: una cadena “OK: ”, seguida del número de aciertos del participante, seguida de la cadena “||F: ”
///seguida del número de fallos del participante, seguida de la cadena “||P: ” seguida del número de veces que ha optado
///por pasar, seguida de la cadena “||D: ”, y seguida de la cadena con los datos de contacto del participante.
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
