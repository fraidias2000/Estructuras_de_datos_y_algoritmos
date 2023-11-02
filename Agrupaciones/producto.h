
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include<iostream>
using namespace std;

struct producto;

void crear(string nombre, int cantidad, producto& p);
string nombre(const producto& p);
int cantidad(const producto& p);
string get_nombre(producto& p);

struct producto {
  friend void crear(string nombre, int cantidad, producto& p);
  friend string nombre(const producto& p);
  friend int cantidad(const producto& p);
  friend string get_nombre(producto& p);
  private:
   string nombre;
   int cantidad;
};

#endif // PRODUCTO_H_INCLUDED
