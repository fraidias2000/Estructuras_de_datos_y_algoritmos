#include <iostream>
#include "agenda.h"
#include "contacto.h"
using namespace std;

int main()
{   contacto persona1;
    crear("alvaro","calle_1", 654537243, persona1);
    cout << persona1.direccion;

    contacto persona2;
    crear("carlos","calle_2", 654537243, persona2);

    contacto persona3;
    crear("martin","calle_3", 654537243, persona3);

    agenda miAgenda;
    iniciar (miAgenda);
    anyadir(miAgenda,persona1);
    anyadir(miAgenda,persona2);
    anyadir(miAgenda,persona3);

    return 0;
}
