#include "producto.h"
void crear(string nom, int can, producto& p){
    p.nombre = nom;
    p.cantidad = can;
}

string nombre(const producto& p){
    return p.nombre;
}

int cantidad(const producto& p){
    return p.cantidad;
}
string get_nombre(producto& p){
    return p.nombre;
}
