#ifndef CMT_H_INCLUDED
#define CMT_H_INCLUDED
#include <iostream>
#include <sstream>
#include <string.h>
#include "pila.h"

using namespace std;

template<typename K, typename V, typename T> struct ColeccionMT;
template<typename K, typename V, typename T> void crear(ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> bool esVacia(const ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> bool existeClave(const ColeccionMT<K,V,T>& c, const K& k);
template<typename K, typename V, typename T> void insertar(ColeccionMT<K,V,T>& c, const K& k, const V& v);
template<typename K, typename V, typename T> int tieneTiempo(const ColeccionMT<K,V,T>& c, const K& k);
template<typename K, typename V, typename T> bool obtenerDato(const ColeccionMT<K,V,T>& c, const K& k, V& v);
template<typename K, typename V, typename T> int obtenerTiempo(const ColeccionMT<K,V,T>& c, const K& k, T& t);
template<typename K, typename V, typename T> bool marcarTiempo(ColeccionMT<K,V,T>& c, const K& k, const T& t);
template<typename K, typename V, typename T> void borrar(ColeccionMT<K,V,T>& c, const K& k);
template<typename K, typename V, typename T> int tamanyo(const ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> void vaciar(ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> string listar(ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> void iniciarIterador(ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> bool existeSiguiente(const ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> bool siguiente(ColeccionMT<K,V,T>& c, K& k, V& v, T& t, bool& tienemarca);
template<typename K, typename V, typename T> bool mayorClave(ColeccionMT<K,V,T>& c, K& mayor);

/**OPERACIONES INTERNAS*/
template<typename K, typename V, typename T> void insertarRec(typename ColeccionMT<K,V,T>::NodoBinario*& nodo, const K& k, const V& v, bool& metido);
template<typename K, typename V, typename T> typename ColeccionMT<K,V,T>::NodoBinario* buscarNodo(typename ColeccionMT<K,V,T>::NodoBinario* nodo, const K& k);
template<typename K, typename V, typename T> void borrarRec(typename ColeccionMT<K,V,T>::NodoBinario*& nodo, const K& k, bool& borrado);
template<typename K, typename V, typename T> typename ColeccionMT<K,V,T>::NodoBinario* max(typename ColeccionMT<K,V,T>::NodoBinario*& nodo);

template<typename K, typename V, typename T>
struct ColeccionMT{
 friend void crear<K,V,T>(ColeccionMT<K,V,T>& c);
 friend bool esVacia<K,V,T>(const ColeccionMT<K,V,T>& c);
 friend bool existeClave<K,V,T>(const ColeccionMT<K,V,T>& c, const K& k);
 friend void insertar<K,V,T> (ColeccionMT<K,V,T>& c, const K& k, const V& v);
 friend int tieneTiempo<K,V,T>(const ColeccionMT<K,V,T>& c, const K& k);
 friend bool obtenerDato<K,V,T>(const ColeccionMT<K,V,T>& c, const K& k, V& v);
 friend int obtenerTiempo<K,V,T>(const ColeccionMT<K,V,T>& c, const K& k, T& t);
 friend bool marcarTiempo<K,V,T>(ColeccionMT<K,V,T>& c, const K& k, const T& t);
 friend void borrar<K,V,T>(ColeccionMT<K,V,T>& c, const K& k);
 friend int tamanyo<K,V,T>(const ColeccionMT<K,V,T>& c);
 friend void vaciar<K,V,T>(ColeccionMT<K,V,T>& c);
 friend string listar<K,V,T>(ColeccionMT<K,V,T>& c);
 friend void iniciarIterador<K,V,T>(ColeccionMT<K,V,T>& c);
 friend bool existeSiguiente<K,V,T>(const ColeccionMT<K,V,T>& c);
 friend bool siguiente<K,V,T>(ColeccionMT<K,V,T>& c, K& k, V& v, T& t, bool& tienemarca);
 friend bool mayorClave<K,V,T>(ColeccionMT<K,V,T>& c, K& mayor);
/**OPERACIONES INTERNAS*/

private:
 struct NodoBinario {
   K clave;
   V valor;
   T marca;
   bool tieneMarca;
   NodoBinario* izqda;
   NodoBinario* drcha;
 };
 NodoBinario* raiz = nullptr ;
 PilaDinamica<NodoBinario*> itrPila;
 int numDatos = 0;
 friend void insertarRec<K,V,T>(typename ColeccionMT<K,V,T>::NodoBinario*& nodo, const K& k, const V& v, bool& metido);
 friend typename ColeccionMT<K,V,T>::NodoBinario* buscarNodo<K,V,T>(typename ColeccionMT<K,V,T>::NodoBinario* nodo, const K& k);
 friend void borrarRec<K,V,T>(typename ColeccionMT<K,V,T>::NodoBinario*& nodo, const K& k, bool& borrado);
friend typename ColeccionMT<K,V,T>::NodoBinario* max<K,V,T>(typename ColeccionMT<K,V,T>::NodoBinario*& nodo);
};


 template<typename K, typename V, typename T>
 void crear(ColeccionMT<K,V,T>& c){ ///Inicializamos los parametros de nuestro TAD
   c.numDatos = 0;
   c.raiz = nullptr;
   crear(c.itrPila); ///Iniciamos la pila

 }

 template<typename K, typename V, typename T>
  bool esVacia(const ColeccionMT<K,V,T>& c){
   if (c.numDatos == 0) {
    return true;
   } else if (c.numDatos > 0 ){
       return false;
   }
  }

 template<typename K, typename V, typename T>
 bool existeClave(const ColeccionMT<K,V,T>& c, const K& k){
         typename ColeccionMT<K,V,T>::NodoBinario* paux;

   if (esVacia(c)){
    return false;

   }else{

    paux = buscarNodo<K,V,T>(c.raiz,k);
    if (paux != nullptr){ return true;}
    else{ return false;}
  }
 }

 /// Llamada recursiva de la funcion Insertar, pasandole un puntero a nodoBinario
template<typename K, typename V, typename T>
void insertarRec(typename ColeccionMT<K,V,T>::NodoBinario*& nodo, const K& k, const V& v, bool& metido) {

 if (nodo == nullptr) {
  nodo = new typename ColeccionMT<K,V,T>::NodoBinario;
  nodo->clave = k;
  nodo->valor = v;
  nodo->tieneMarca = false;
  nodo->izqda = nullptr;
  nodo->drcha = nullptr;
  metido = true;
 } if (k == nodo->clave) {
    nodo->valor = v;
    nodo->tieneMarca = false;
  } else if (k <= nodo->clave) {
    insertarRec<K,V,T>(nodo->izqda, k, v, metido); ///Llamadas recursivas para recorrer el arbol en función de los valores que va tomando nodo
  } else{
   insertarRec<K,V,T>(nodo->drcha, k, v, metido);
  }
}

template<typename K, typename V, typename T>
void insertar(ColeccionMT<K,V,T>& c, const K& k, const V& v) {
 bool metido = false;
 insertarRec<K,V,T>(c.raiz, k, v, metido);
 if (metido) c.numDatos++;
}

template<typename K, typename V, typename T>
typename ColeccionMT<K,V,T>::NodoBinario* buscarNodo(typename ColeccionMT<K,V,T>::NodoBinario* nodo, const K& k){

    typename ColeccionMT<K,V,T>::NodoBinario* paux;

  if( nodo != nullptr){ /// Si el nodo no esta vacio comprobar el valor que tiene para ir a un lado u otro del arbol
    if(nodo->clave == k){
        return nodo;
    }else if (k < nodo->clave){
      buscarNodo<K,V,T>(nodo->izqda,k);
    }else if(k > nodo->clave){
      buscarNodo<K,V,T>(nodo->drcha, k);
    }

  }else{ return false;}

}


template<typename K, typename V, typename T>
int tieneTiempo(const ColeccionMT<K,V,T>& c, const K& k){
    typename ColeccionMT<K,V,T>::NodoBinario* paux;
    paux = c.raiz;
 if( esVacia(c) ){
    return 0;
 }else{
     paux = buscarNodo<K,V,T>(c.raiz,k);
     if(paux->tieneMarca){ return 1;}
     else if (paux->tieneMarca == false){ return 0;}

 }
 return 0;
}

template<typename K, typename V, typename T>
 bool obtenerDato(const ColeccionMT<K,V,T>& c, const K& k, V& v){ ///Utilizamos la funcion buscarNodo para saber si existe, y si existe encontrar el nodo
   typename ColeccionMT<K,V,T>::NodoBinario* paux;
   paux = c.raiz;
   if ( esVacia(c) ){
    return false;
   }else{
       paux = buscarNodo<K,V,T>(c.raiz,k);
       if (paux != nullptr){
         v = paux->valor;
         return true;
       }else{ return false;}
   }
 }

template<typename K, typename V, typename T>
int obtenerTiempo(const ColeccionMT<K,V,T>& c, const K& k, T& t){
  typename ColeccionMT<K,V,T>::NodoBinario* paux;
  if ( esVacia(c) || !existeClave(c,k) ){ return 0;}
  else{
    paux = buscarNodo<K,V,T>(c.raiz,k);
    if ( paux != nullptr && tieneTiempo(c,k) == 1){
        t = paux->marca;
        return 1;
    } else {return 0;}
  }

}

template<typename K, typename V, typename T>
 bool marcarTiempo(ColeccionMT<K,V,T>& c, const K& k, const T& t){
   typename ColeccionMT<K,V,T>::NodoBinario* paux;
   if( esVacia(c) || existeClave(c,k) == false ){
    return false;
   }else{
     paux = buscarNodo<K,V,T>(c.raiz,k);
     if ( paux != nullptr){
        paux->marca = t;
        paux->tieneMarca = true;
        return true;
     }
   }
 }

 template<typename K, typename V, typename T> /// Devuelve el puntero que apunta al nodo de mayor clave
 typename ColeccionMT<K,V,T>::NodoBinario* max(typename ColeccionMT<K,V,T>::NodoBinario*& nodo){

      if( nodo != nullptr ){
        if ( nodo->drcha == nullptr){
            return nodo;
        }else{
          return max<K,V,T>(nodo->drcha);
        }
      }

 }


 template<typename K, typename V, typename T>
 void borrar(ColeccionMT<K,V,T>& c, const K& k){
    typename ColeccionMT<K,V,T>::NodoBinario* paux;
    bool borrado = false;
    if( !esVacia(c) ){
      borrarRec<K,V,T>(c.raiz,k,borrado); ///Llamamos a la funcion recursiva
      if( borrado ){ c.numDatos--;}

    }



 }

 template<typename K, typename V, typename T>
void borrarRec(typename ColeccionMT<K,V,T>::NodoBinario*& nodo, const K& k, bool& borrado){
     typename ColeccionMT<K,V,T>::NodoBinario* paux;

 if(nodo == nullptr){ borrado = false;}
 else{ ///Va buscando el nodo recursivamente hacia un lado o otro del arbol en base a los valores de k que va tomando

    if( k < nodo->clave  ){ borrarRec<K,V,T>(nodo->izqda,k,borrado);}
    else if ( k > nodo->clave ) { borrarRec<K,V,T>(nodo->drcha,k,borrado); }
    else if ( nodo->clave == k ) {
      if( nodo->izqda == nullptr){ ///Si encontramos el nodo y no tiene hijos a la izquierda ( y puenteamos el enlace)

        paux = nodo;
        nodo = nodo->drcha;
        delete paux;
        borrado = true;
      }else{
        paux = max<K,V,T>(nodo->izqda); /// Con esto rehacemos enlaces
        nodo->clave = paux->clave;
        nodo->valor = paux->valor;
        nodo->marca = paux->marca;
        nodo->tieneMarca = paux->tieneMarca;
        borrarRec<K,V,T>(nodo->izqda,nodo->clave,borrado);

      }
    }
 }
}

template<typename K, typename V, typename T>
int tamanyo(const ColeccionMT<K,V,T>& c){
  return c.numDatos;
}

template<typename K, typename V, typename T>
 void vaciar(ColeccionMT<K,V,T>& c){
   while (c.raiz != nullptr){
     borrar(c,c.raiz->clave);
   }
 }

 template<typename K, typename V, typename T>
  void iniciarIterador(ColeccionMT<K,V,T>& c){
    typename ColeccionMT<K,V,T>::NodoBinario* paux;
    liberar(c.itrPila); ///Deja la pila vacia
    paux = c.raiz;
    while (paux != nullptr){
        push(c.itrPila,paux);
        paux= paux->izqda;
    }
  }

template<typename K, typename V, typename T>
 string listar(ColeccionMT<K,V,T>& c){
     K clave;
     V valor;
     T tiempo;
     bool marca;
     ostringstream cadena;
     iniciarIterador(c);

     typename ColeccionMT<K,V,T>::NodoBinario* paux;
     while (existeSiguiente<K,V,T>(c)){ ///Mientras exista siguiente recorrer todos los nodos del arbol en inorden
      if (siguiente<K,V,T>(c, clave, valor, tiempo, marca)){
       cadena << "[" << "K: " << clave;
       cadena << ", V: " << PreguntaCompleta(valor);
       cadena << ", T: " << tiempo;
       cadena << ", tieneMarca: "<< marca << " ]" << endl;
      }
     }
   return cadena.str();
 }

 template<typename K, typename V, typename T>
  bool existeSiguiente(const ColeccionMT<K,V,T>& c){
    return (!esVacia(c.itrPila)); ///Si la pila no esta vacia devueleve verdadero
  }

template<typename K, typename V, typename T>
bool siguiente(ColeccionMT<K,V,T>& c, K& k, V& v, T& t, bool& tienemarca){
  typename ColeccionMT<K,V,T>::NodoBinario* paux;
  if ( existeSiguiente<K,V,T>(c) ){ ///Si existe siguiente saca de la pila el ultimo elemento y lo guarda en un puntero auxiliar
    paux = pop(c.itrPila);
    k = paux->clave; /// Este elemento es el que queremos devolver y se lo pasamos al parametro de E/S k,v,t
    v = paux->valor;
    if (paux->tieneMarca){
     t = paux->marca;
     tienemarca = paux->tieneMarca;
    }else{
     t = "-";
     tienemarca = false;
    }
    paux = paux->drcha;
    while(paux != nullptr){
        push(c.itrPila,paux);
        paux= paux->izqda;
    }
    return true;
  }else{
    return false;
  }
}

template<typename K, typename V, typename T>
 bool mayorClave(ColeccionMT<K,V,T>& c, K& mayor){
     typename ColeccionMT<K,V,T>::NodoBinario* paux;
   if(!esVacia(c)){
     paux = max<K,V,T>(c.raiz);
     mayor = paux->clave;
     return true;
   }else{return false;}
 }

#endif // CMT_H_INCLUDED
