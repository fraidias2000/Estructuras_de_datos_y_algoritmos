
#ifndef AGRUPACION_H
#define AGRUPACION_H
#include <iostream>
using namespace std;

// Interfaz del TAD agrupación genérico. Pre-declaraciones:
const int MAX = 40; //Límite tamaño de la agrupación, en esta implementación.
template<typename T> struct agrupacion;

//definir operaciones de agrupacion
template<typename T> void iniciar (agrupacion<T>& c);
template<typename T> bool anyadir (agrupacion<T>& c, const T& p);
template<typename T> bool borrarUltimo (agrupacion<T>& c);
template<typename T>void listar(agrupacion<T>& c);
template<typename T>void iniciarIterador(agrupacion<T>& c);
template<typename T>bool existeSiguiente(const agrupacion<T>& c);
template<typename T>bool siguiente (agrupacion<T>& c, T& p);

// Declaración:
template<typename T>
struct agrupacion{
    friend void iniciar<T> (agrupacion<T> &c);
    friend bool anyadir<T> (agrupacion<T>& c, const T& p);
    friend bool borrarUltimo<T> (agrupacion<T>& c);
    friend void listar<T>(agrupacion<T>& c);
    friend void iniciarIterador(agrupacion<T>& c);
    friend bool existeSiguiente(const agrupacion<T>& c);
    friend bool siguiente (agrupacion<T>& c, T& p);
    private:
    T datos[MAX];
    int total;
    int iter;
};

template<typename T>
void iniciar (agrupacion<T>& c) {
    c.total = 0;
}
template<typename T>
bool anyadir (agrupacion<T>& c, const T& p) {
    bool sePuede = c.total < MAX;
    if (sePuede) {
        c.datos[c.total] = p;
        c.total++;
    }
    return sePuede;
}

template<typename T>
bool borrarUltimo (agrupacion<T>& c) {
    bool sePuede = c.total > 0;
    if (sePuede) c.total--;
        return sePuede;
    }

template<typename T>
void iniciarIterador(agrupacion<T>& c){
    c.iter = 0;
}

template<typename T>
bool existeSiguiente(const agrupacion<T>& c){
    return c.iter != c.total;
}

template<typename T>
bool siguiente (agrupacion<T>& c, T& p){
    if(existeSiguiente(c)) {
        p = c.datos[c.iter];
        c.iter++;
        return true;
    }else{
        return false;
        }
}

#endif // AGRUPACIONES_H_INCLUDED
