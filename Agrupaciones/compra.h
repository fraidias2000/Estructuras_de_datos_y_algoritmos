#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "producto.h"
const int MAX_COMPRA = 40;
struct compra;
void iniciar (compra& c);
bool anyadir (compra& c, const producto& p);
bool borrarUltimo (compra& c);
int totalCompra(compra& c);



struct compra{
    friend void iniciar (compra& c);
    friend bool anyadir (compra& c, const producto& p);
    friend bool borrarUltimo (compra& c);
    friend int totalCompra(compra& c);
    public:
        producto lacompra[MAX_COMPRA];
        int total;
};

#endif // COMPRA_H_INCLUDED
