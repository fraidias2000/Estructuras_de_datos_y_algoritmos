/*
********************************
*******Roberto Jimenez**********
******Alvaro Fraidias **********
****** Ronda_Seleccion.h********
********Practica 2**************
********************************
*/
#ifndef RONDA_SELECCION_H_INCLUDED
#define RONDA_SELECCION_H_INCLUDED
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

template<typename K, typename V> struct RondaSeleccion;
template<typename K, typename V> void crear(RondaSeleccion<K,V>& c);
template<typename K, typename V> int cardinal(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool esVacia(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool pertenece(const RondaSeleccion<K,V>& c, const K& k);
template<typename K, typename V> bool obtenerValor(const RondaSeleccion<K,V>& c, const K& k, V& v);
template<typename K, typename V> bool enSeleccion(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool anyadir(RondaSeleccion<K,V>& c, const K& k, const V& v);
template<typename K, typename V> bool quitar(RondaSeleccion<K,V>& c, const K& k);
template<typename K, typename V> void cerrarInscripcion(RondaSeleccion<K,V>& c);
template<typename K, typename V> int pasarTurno(RondaSeleccion<K,V>& c);
template<typename K, typename V> int obtenerCandidatoSuClave(const RondaSeleccion<K,V>& c, K& k);
template<typename K, typename V> int obtenerCandidatoSuValor(const RondaSeleccion<K,V>& c, V& v);
template<typename K, typename V> int actualizarCandidato(RondaSeleccion<K,V>& c, const V& v);
template<typename K, typename V> int eliminarCandidato(RondaSeleccion<K,V>& c);
template<typename K, typename V> string listar(RondaSeleccion<K,V>&c);
template<typename K, typename V> void iniciarIterador(RondaSeleccion<K,V>& c);
template<typename K, typename V> bool existeSiguiente(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool siguiente(RondaSeleccion<K,V>& c, K& k, V& v);
template<typename K, typename V> bool vaciar(RondaSeleccion<K,V>& c);
template<typename K, typename V> bool operator== (const K& k, const K& k1);
template<typename K, typename V> bool operator< (const K& k, const K& k1);



  ///null ptr para inicializarlo a nil
template<typename K, typename V>
struct RondaSeleccion{
  friend void crear<K,V>(RondaSeleccion<K,V>& c);
  friend int cardinal<K,V>(const RondaSeleccion<K,V>& c);
  friend bool esVacia<K,V>(const RondaSeleccion<K,V>& c);
  friend bool pertenece<K,V>(const RondaSeleccion<K,V>& c, const K& k);
  friend bool obtenerValor<K,V>(const RondaSeleccion<K,V>& c, const K& k, V& v);
  friend bool enSeleccion<K,V>(const RondaSeleccion<K,V>& c);
  friend bool anyadir<K,V>(RondaSeleccion<K,V>& c, const K& k, const V& v);
  friend bool quitar<K,V>(RondaSeleccion<K,V>& c, const K& k);
  friend void cerrarInscripcion<K,V>(RondaSeleccion<K,V>& c);
  friend int pasarTurno<K,V>(RondaSeleccion<K,V>& c);
  friend int obtenerCandidatoSuClave<K,V>(const RondaSeleccion<K,V>& c, K& k);
  friend int obtenerCandidatoSuValor<K,V>(const RondaSeleccion<K,V>& c, V& v);
  friend int actualizarCandidato<K,V>(RondaSeleccion<K,V>& c, const V& v);
  friend int eliminarCandidato<K,V>(RondaSeleccion<K,V>& c);
  friend string listar<K,V>(RondaSeleccion<K,V>& c);
  friend void iniciarIterador<K,V>(RondaSeleccion<K,V>& c);
  friend bool existeSiguiente<K,V>(const RondaSeleccion<K,V>& c);
  friend bool siguiente<K,V>(RondaSeleccion<K,V>& c, K& k, V& v);
  friend bool operator==(const K& k, const K& k1);
  friend bool operator<(const K& k, const K& k1);
  friend bool vaciar<K,V>(RondaSeleccion<K,V>& c);

private:
  struct elemento{
    K clave;
    V valor;
    elemento* sig;
  };
    int total;
    elemento* primero;
    elemento* iterador;
    elemento* turno;
    bool seleccion;
};

template<typename K, typename V>
void crear(RondaSeleccion<K,V>& c){
  c.total = 0;
  c.iterador = nullptr;
  c.primero = nullptr;
  c.seleccion = false;
  c.turno = nullptr;
}

template<typename K, typename V>
int cardinal(const RondaSeleccion<K,V>& c){
    return c.total;
}

template<typename K, typename V>
 bool esVacia(const RondaSeleccion<K,V>& c){
  if(c.total == 0){
    return true;
  }else{ return false;}
 }

 template<typename K, typename V>
 bool pertenece(const RondaSeleccion<K,V>& c, const K& k){
     typename RondaSeleccion<K,V>::elemento* pAux;
     pAux = c.primero;
     while(pAux != nullptr ){
        if(pAux->clave == k){

            return true;
        }else{
            pAux=pAux->sig;

         }
        }

        return false;

 }

 template<typename K, typename V>
   bool obtenerValor(const RondaSeleccion<K,V>& c, const K& k, V& v){

     typename RondaSeleccion<K,V>::elemento* pAux;
     pAux = c.primero;
     if(pAux == nullptr){
        v = c.primero->valor;
        return true;
     }
     while(pAux != nullptr){
        if(pAux->clave == k){
            v = pAux->valor;
            return true;
        }else{
            pAux = pAux->sig;
        }
     }
     return false;

 }

 template<typename K,typename V>
 bool enSeleccion(const RondaSeleccion<K,V>& c){
   if( c.seleccion == true){
     return true;
   }else{ return false; }
 }

template<typename K, typename V>
 bool anyadir(RondaSeleccion<K,V>& c, const K& k, const V& v){
   if (enSeleccion(c)) return true;
   typename RondaSeleccion<K,V>::elemento* nodo;
   typename RondaSeleccion<K,V>::elemento* paux;
   if (c.primero == nullptr) {
      c.primero = new typename RondaSeleccion<K,V>::elemento;
      c.primero->clave = k;
      c.primero->valor = v;
      c.primero->sig = nullptr;
      c.total++;
      return true;
   } else if (c.primero->clave > k) {
      paux = c.primero;
      c.primero = new typename RondaSeleccion<K,V>::elemento;
      c.primero->clave = k;
      c.primero->valor = v;
      c.primero->sig = paux;
      c.total++;
      return true;
    } else if (k == c.primero->clave){
      c.primero->valor = v;
      return true;
    }else {
      paux = c.primero;
     while (paux->sig != nullptr && k > paux->sig->clave) paux = paux->sig;
     if (paux->sig != nullptr && k == paux->sig->clave) paux->sig->valor = v;
     else{
       nodo = new typename RondaSeleccion<K,V>::elemento;
       nodo->clave = k;
       nodo->valor = v;
       nodo->sig = paux->sig;
       paux->sig = nodo;
       c.total++;
       return true;
     }
  }
 return false;
}

template<typename K, typename V>
bool quitar(RondaSeleccion<K,V>& c, const K& k){

   typename RondaSeleccion<K,V>::elemento* nodo;
   typename RondaSeleccion<K,V>::elemento* paux;
   bool parar = false;

   if( c.primero!= nullptr ){
     if(c.primero->clave <= k){
        if(c.primero->clave == k){
            paux = c.primero;
            c.primero = c.primero->sig;
           // free(paux);
            delete paux;
            c.total--;
            return true;
        }else{
          parar = false;
          paux = c.primero->sig;
          nodo = c.primero;
          while(paux != nullptr && !parar){
            if( k < paux->clave){
                parar = true;
            }else if( paux->clave == k){
             nodo->sig = paux->sig;
            // free(paux);
             delete paux;
             parar= true;
             c.total--;
             return true;
            }else{
              nodo=paux;
              paux= paux->sig;
            }
          }
        }
     return false;
     }
   }

}

template<typename K, typename V>
 void cerrarInscripcion(RondaSeleccion<K,V>& c){
  if( !enSeleccion(c) || !esVacia(c)){ /// puede haber ronda vacia?
     c.seleccion = true;
     c.turno = c.primero;
  }
 }

 // si esta en seleccion no puedes inscribir

template<typename K, typename V>
int pasarTurno(RondaSeleccion<K,V>& c){

  if(!enSeleccion(c) || esVacia(c)){return 0;}
  else if (enSeleccion(c)){
    if(c.turno->sig == nullptr){
     c.turno = c.primero;
    }else {
     c.turno= c.turno->sig;
   }
    return 1;
  }
}

  template<typename K, typename V>
 int obtenerCandidatoSuClave(const RondaSeleccion<K,V>& c, K& k){
      if( !enSeleccion(c) || esVacia(c) ){
        return 0;
      }else if( enSeleccion(c)){
        k = c.turno->clave;
        return 1;
      }
  }

    template<typename K, typename V>
 int obtenerCandidatoSuValor(const RondaSeleccion<K,V>& c, V& v){
      if( !enSeleccion(c) || esVacia(c) ){
        return 0;
      }else if( enSeleccion(c)){
        v = c.turno->valor;
        return 1;
      }
  }

  template<typename K, typename V>
   int actualizarCandidato(RondaSeleccion<K,V>& c, const V& v){
       if(!enSeleccion(c) || esVacia(c)){
        return 0;
       }else if(enSeleccion(c)){
         c.turno->valor = v;
         return 1;
       }
   }

   // sobrecargamos los operadores == y < para poder comparar claves, para el caso generico
template<typename K, typename V>
 bool operator== (const K& k, const K& k1){
   if( k == k1 ){
     return true;
   }else{ return false;}
 }

template<typename K, typename V>
bool operator< (const K& k, const K& k1){
   if(k < k1){
    return true;
   }else { return false;}
}

 template<typename K, typename V>
 int eliminarCandidato(RondaSeleccion<K,V>& c){
     typename RondaSeleccion<K,V>::elemento* paux;
     typename RondaSeleccion<K,V>::elemento* paux2;
     int i = 0;
     bool parar = false;
      if(!enSeleccion(c) || esVacia(c)){
        return 0;
      }else if(enSeleccion(c)){
            paux = c.primero;
           while(paux != nullptr && !parar){
              if(paux->clave == c.turno->clave){
                parar = true;
                paux = c.primero;
                c.primero = c.primero->sig;
                pasarTurno(c);
                c.total--;
                delete paux;
                return 1;
              }else if(paux->sig->clave == c.turno->clave){
                parar = true;
                paux2 = paux->sig;
                paux2 = paux2->sig;
                paux->sig = paux2;
                paux = c.turno;
                pasarTurno(c);
                c.total--;
                delete paux;
                return 1;
             }else{
              paux = paux->sig;
             }
           }
       }
 }

 template<typename K, typename V>
string listar(RondaSeleccion<K,V>&c){
  string cadena;
  iniciarIterador(c);
  if(c.primero == nullptr){
    return "Lista vacia, no hay candidatos \n";
  }
  while( c.iterador != nullptr ){
    cadena = cadena + "[" + c.iterador->clave + ":::" + infoParticipante(c.iterador->valor) + "] \n";
    c.iterador = c.iterador->sig;
  }
  return cadena;
}

template<typename K, typename V>
void iniciarIterador(RondaSeleccion<K,V>& c){
   c.iterador = c.primero;
}

template<typename K, typename V>
 bool existeSiguiente(const RondaSeleccion<K,V>& c){
  if(c.iterador->sig == nullptr){
    return false;
  }else{ return true;}
}

template<typename K, typename V>
 bool siguiente(RondaSeleccion<K,V>& c, K& k, V& v){
  if(existeSiguiente(c)){
    k = c.iterador->clave;
    v = c.iterador->valor;
    c.iterador = c.iterado->sig;
    return true;
  }else{ return false;}

}

template<typename K, typename V>
bool vaciar(RondaSeleccion<K,V>& c){

 if( enSeleccion(c) ){
  while( !esVacia(c) ){
    eliminarCandidato(c); // vamos eliminando candidatos de 1 en 1 hasta que este vacia
  }
 }else{ return false;}
  if( esVacia(c) ){
    c.seleccion = false;
    return true;
  }
  else{return false;}

}


#endif // RONDA_SELECCION_H_INCLUDED
