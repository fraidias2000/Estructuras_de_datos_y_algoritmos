#include "compra.h"
void iniciar(compra& c){
    c.total = 0;
    }
int totalCompra(compra& c){
    return c.total;

    }
bool anyadir(compra& c, const producto& p){
    bool sePuede = c.total < MAX_COMPRA;
    if(sePuede){
        c.lacompra[c.total] = p;
        c.total++;
    }
    return sePuede;
}

bool borrarUltimo(compra& c){
    bool sePuede = c.total > 0;
    if(sePuede){
        c.total--;
    }
    return sePuede;
}
