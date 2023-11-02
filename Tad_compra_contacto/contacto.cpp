#include "contacto.h"
void crear(string nombre,string direccion, int telefono, contacto& p){
    p.nombre = nombre;
    p.direccion = direccion;
    p.telefono = telefono;
}

string nombre(const contacto& p){
    return p.nombre;
}

string direccion(const contacto& p){
    return p.direccion;
}
int telefono (const contacto& p){
    return p.telefono;
}

