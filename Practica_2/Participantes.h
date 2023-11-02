#ifndef PARTICIPANTES_H_INCLUDED
#define PARTICIPANTES_H_INCLUDED
#include <iostream>
using namespace std;
struct Participante;
string listarDatos(Participante& p);
void crearParticipante(string datos, Participante& p);
int numAciertos(Participante& p);
void ponerAciertos(Participante& p, int aciertos);
void ponerPasos(Participante& p, int pasos);
void ponerFallos(Participante& p, int fallos);
int numFallos(Participante& p);
int numPasos(Participante& p);
string infoParticipante(Participante& p);

struct Participante{
    friend string listarDatos(Participante& p);
    friend void crearParticipante(string datos, Participante& p);
    friend int numAciertos(Participante& p);
    friend void ponerAciertos(Participante& p, int aciertos);
    friend void ponerPasos(Participante& p, int pasos);
    friend void ponerFallos(Participante& p, int fallos);
    friend int numFallos(Participante& p);
    friend int numPasos(Participante& p);
    friend string infoParticipante(Participante& p);

public:
    string datos;
    int aciertos;
    int fallos;
    int pasos;

};


#endif // PARTICIPANTES_H_INCLUDED
