#include <iostream>
#include "agrupaciones.h"
#include "producto.h"
#include "compra.h"
using namespace std;
int main()
{
    agrupacion<producto> compra;
    iniciar(compra);

    producto nar;
    crear("naranja", 2, nar);
    anyadir(compra,nar);

    producto per;
    crear("peras", 4, per);
    anyadir(compra,per);


    bool error;
    producto p;
    iniciarIterador(compra);
while (existeSiguiente(compra)) {
        error = siguiente(compra, p);
}
    return 0;
}




