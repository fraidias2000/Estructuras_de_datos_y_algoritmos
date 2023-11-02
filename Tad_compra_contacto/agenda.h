#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include "contacto.h"
const int MAX_AGENDA = 40;
struct agenda;
void iniciar (agenda& c);
bool anyadir (agenda& c, const contacto& p);
bool borrarUltimo (agenda& c);

// Declaración:
struct agenda{
    friend void iniciar (agenda& c);
    friend bool anyadir (agenda& c, const contacto& p);
    friend bool borrarUltimo (agenda& c);
    private:
        contacto laagenda[MAX_AGENDA];
        int total;
};

#endif // AGENDA_H_INCLUDED
