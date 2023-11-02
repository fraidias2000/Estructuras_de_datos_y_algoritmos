#include "agenda.h"
void iniciar (agenda& c) {
    c.total = 0;
}
bool anyadir (agenda& c, const contacto& p) {
    bool sePuede = c.total < MAX_AGENDA;
    if (sePuede) {
    c.laagenda[c.total] = p;
    c.total++;
    }
    return sePuede;
}
bool borrarUltimo (agenda& c) {
    bool sePuede = c.total > 0;
    if (sePuede) {
        c.total--;
    }
    return sePuede;
}
