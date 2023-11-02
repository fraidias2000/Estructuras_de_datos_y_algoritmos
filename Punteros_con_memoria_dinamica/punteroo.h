#ifndef PUNTEROO_H_INCLUDED
#define PUNTEROO_H_INCLUDED
#include<iostream>
using namespace std;
struct elemento;
void crear(string nombre, int cantidad, elemento &e);
void anyadir(elemento &e);


struct elemento{
    friend void crear(string nombre, int cantidad, elemento &e);
    friend void anyadir(elemento &e);

    private:
        string nombre;
        int cantidad;
        int *p;
};

#endif // PUNTEROO_H_INCLUDED
