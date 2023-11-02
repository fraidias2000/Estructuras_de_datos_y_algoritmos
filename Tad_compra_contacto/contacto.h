#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED
#include<iostream>
using namespace std;

struct contacto;
void crear(string nombre,string direccion, int telefono, contacto& p);
string nombre(const contacto& p);
int cantidad(const contacto& p);

struct contacto {
  friend void crear(string nombre, string direccion, int telefono, contacto& p);
  friend string nombre(const contacto& p);
  friend string direccion(const contacto& p);
  friend int telefono(const contacto& p);
  public:
        string nombre;
        string direccion;
        int telefono;
};

#endif // CONTACTO_H_INCLUDED
