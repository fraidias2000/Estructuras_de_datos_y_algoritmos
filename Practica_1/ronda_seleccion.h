#ifndef RONDA_SELECCION_H_INCLUDED
#define RONDA_SELECCION_H_INCLUDED
#include <iostream>
using namespace std;

template<typename K, typename V> struct RondaSeleccion;
template<typename K, typename V> struct elemento;
template<typename K, typename V> void crear(RondaSeleccion<K,V>& c);
template<typename K, typename V> int cardinal(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool esVacia(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool pertenece(const RondaSeleccion<K,V>& c, const K& k);
template<typename K, typename V> bool obtenerValor(const RondaSeleccion<K,V>& c, const K& k, V& v);
template<typename K, typename V> bool enSeleccion(const RondaSeleccion<K,V>& c);
//inscripcion
template<typename K, typename V> bool anyadir(RondaSeleccion<K,V>& c, const K& k, const V& v);
template<typename K, typename V> bool buscar (RondaSeleccion<K,V>& c, const K& k);
template<typename K, typename V> bool quitar(RondaSeleccion<K,V>& c, const K& k);
template<typename K, typename V> void cerrarInscripcion(RondaSeleccion<K,V>& c);
//Seleccion
template<typename K, typename V> int pasarTurno(RondaSeleccion<K,V>& c);
template<typename K, typename V> int obtenerCandidatoSuClave(RondaSeleccion<K,V>& c, K& k);
template<typename K, typename V> int obtenerCandidatoSuValor(RondaSeleccion<K,V>& c, V& v);
template<typename K, typename V> int actualizarCandidato(RondaSeleccion<K,V>& c, const V& v);
template<typename K, typename V> int eliminarCandidato(RondaSeleccion<K,V>& c);
template<typename K, typename V> string listar(RondaSeleccion<K,V>& c);
//Iterador
template<typename K, typename V> void iniciarIterador(RondaSeleccion<K,V>& c);
template<typename K, typename V> bool existeSiguiente(const RondaSeleccion<K,V>& c);
//template<typename K, typename V> bool siguienteClave(const RondaSeleccion<K,V>& c);
//template<typename K, typename V> bool siguienteValor(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool siguiente(RondaSeleccion<K,V>& c,K& k, V& v);
template<typename K, typename V> bool vaciar(RondaSeleccion<K,V>& c);


template<typename K, typename V>
struct RondaSeleccion{

    friend void crear<K,V>(RondaSeleccion<K,V>& c);
    friend int cardinal<K,V>(const RondaSeleccion<K,V>& c);
    friend bool esVacia<K,V>(const RondaSeleccion<K,V>& c);
    friend  bool pertenece<K,V>(const RondaSeleccion<K,V>& c, const K& k);
    friend bool obtenerValor<K,V>(const RondaSeleccion<K,V>& c, const K& k, V& v);
    friend bool enSeleccion<K,V>(const RondaSeleccion<K,V>& c);
    friend bool anyadir<K,V>(RondaSeleccion<K,V>& c, const K& k, const V& v);
    friend bool buscar (RondaSeleccion<K,V>& c, const K& k);
    friend bool quitar<K,V>(RondaSeleccion<K,V>& c, const K& k);
    friend void cerrarInscripcion<K,V>(RondaSeleccion<K,V>& c);
    friend int pasarTurno<K,V>(RondaSeleccion<K,V>& c);
    friend int obtenerCandidatoSuClave<K,V>(RondaSeleccion<K,V>& c, K& k);
    friend int obtenerCandidatoSuValor<K,V>(RondaSeleccion<K,V>& c, V& v);
    friend int actualizarCandidato<K,V>(RondaSeleccion<K,V>& c, const V& v);
    friend int eliminarCandidato<K,V>(RondaSeleccion<K,V>& c);
    friend string listar<K,V>(RondaSeleccion<K,V>& c);
    friend void iniciarIterador<K,V>(RondaSeleccion<K,V>& c);
    friend bool existeSiguiente<K,V>(const RondaSeleccion<K,V>& c);
    //friend bool siguienteClave(const RondaSeleccion<K,V>& c);
    //friend bool siguienteValor(const RondaSeleccion<K,V>& c);
   friend bool siguiente<K,V>(RondaSeleccion<K,V>& c,K& k, V& v);
   friend bool vaciar<K,V>(RondaSeleccion<K,V>& c);

public:
    struct elemento{
        K clave;
        V valor;
        elemento* sig;
    };
    int numDatos;
    elemento* primero;
    elemento* iterador;
    elemento* elegido;
    bool seleccion;
};


template<typename K, typename V>
void crear(RondaSeleccion<K,V>& c){ //Inicializa los punteros a nil
  c.numDatos = 0;
  c.primero = nullptr;
  c.iterador = nullptr;
  c.elegido = nullptr;
  c.seleccion = false;

}
template<typename K, typename V>
int cardinal(const RondaSeleccion<K,V>& c){ // Retorna el numero de participantes que hay en una ronda
    return c.numDatos;
}
template<typename K, typename V>
bool esVacia(const RondaSeleccion<K,V>& c){ //Comprueba si esta vacia la ronda
    if(c.numDatos == 0){
        return true;
    }else{
        return false;
    }
}
template<typename K, typename V>
bool pertenece(const RondaSeleccion<K,V>& c, const K& k){//Le pasamos una clave y nos dice si esta dentro de la ronda
   typename RondaSeleccion<K,V>::elemento* pAux; //Definimos un puntero auxiliar que apunta a elemento
    pAux = c.primero;
    while(pAux != nullptr){//Mientras el puntero sea distinto de nil va comparando la clave que le hemos pasado con cada clave de la ronda
           if(k.compare(pAux->clave)==0){
                return true;
            }else{
                pAux= pAux->sig; //itera el puntero
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
template<typename K, typename V>
bool enSeleccion(const RondaSeleccion<K,V>& c){//Nos dice si estamos o no en seleccion
    return c.seleccion;
}

//INSCRIPCION

template<typename K, typename V>
bool anyadir(RondaSeleccion<K,V>& c, const K& k, const V& v) {
    if (enSeleccion(c)) return true;
    typename RondaSeleccion<K,V>::elemento* nodo;
    typename RondaSeleccion<K,V>::elemento* paux;
    if (c.primero == nullptr) { //Si no hay todavia un participante
        c.primero = new typename RondaSeleccion<K,V>::elemento;
        c.primero->clave = k;
        c.primero->valor = v;
        c.primero->sig = nullptr;
        c.numDatos++;
    }else if (c.primero->clave > k) {//Que la clave sea menor que la primera posicion
        paux = c.primero;
        c.primero = new typename RondaSeleccion<K,V>::elemento;
        c.primero->clave = k;
        c.primero->valor = v;
        c.primero->sig = paux;
        c.numDatos++;
    }else if (k == c.primero->clave){//Si la primera posicion es igual a la clave se actualiza el valor
        c.primero->valor = v;
    }else{
        paux = c.primero;
        while (paux->sig != nullptr && k > paux->sig->clave) paux = paux->sig;
        if(paux->sig != nullptr && k == paux->sig->clave) paux->sig->valor = v;
        else{
            nodo = new typename RondaSeleccion<K,V>::elemento;
            nodo->clave = k;
            nodo->valor = v;
            nodo->sig = paux->sig;
            paux->sig = nodo;
            c.numDatos++;
        }
    }
    return false;
}
template<typename K, typename V>
bool buscar(RondaSeleccion<K,V>& c, const K& k){
    typename RondaSeleccion<K,V>::elemento* pAux;
    pAux = c.primero;
    while(pAux != nullptr && pAux->clave < k){ //Iterador
            pAux = pAux->sig;
    }
    if(pAux->clave == k){
            cout << pAux->clave;
            return true;
    }
    if(pAux == nullptr || pAux->clave > k){ //Si llega el final o la clave es menor a la primera
        return false;
    }

}
template<typename K, typename V>
bool quitar(RondaSeleccion<K,V>& c, const K& k){
    typename RondaSeleccion<K,V>::elemento* anterior;
    typename RondaSeleccion<K,V>::elemento* paux;
    bool parar = false;

   if( c.primero!= nullptr ){
        if(c.primero->clave <= k){
            if(c.primero->clave == k){//Si la primera posicion es la que queremos eliminar
                paux = c.primero;
                c.primero = c.primero->sig;//Primero itera
                delete paux;
                c.total--;
                return true;
            }else{
                parar = false;
                paux = c.primero->sig;
                anterior = c.primero;
                while(paux != nullptr && !parar){
                    if( k < paux->clave){
                        parar = true;
                    }else if( paux->clave == k){
                        anterior->sig = paux->sig;//Rehacemos los enlaces
                        delete paux;
                        parar= true;
                        c.total--;
                        return true;
                    }else{
                        anterior=paux;//itera una posicion menos que pAux
                        paux= paux->sig;
                    }
                }
            }
            return false;
        }
   }
}
template<typename K, typename V>
void cerrarInscripcion(RondaSeleccion<K,V>& c){//Cierra la ronda inscripcion y la pone a seleccion
    c.seleccion = true;
    cout << "INSCRIPCION CERRADA" << endl;
}

//SELECCION

template<typename K, typename V>
int obtenerCandidatoSuClave(RondaSeleccion<K,V>& c, K& k){
      if( !enSeleccion(c) || esVacia(c) ){
        return 0;
      }else if( enSeleccion(c)){
            k = c.elegido->clave;
            return 1;
      }
  }
template<typename K, typename V>
int obtenerCandidatoSuValor(RondaSeleccion<K,V>& c, V& v){
    if(c.seleccion){
        if(esVacia(c)== false){
            c.elegido->valor = v;
            return 1;
        }else{
            cout << "La ronda esta vacia" << endl;
            return 0;
        }
    }else{
        cout << "No estamos en seleccion";
        return 0;
    }
}
template<typename K, typename V>
int actualizarCandidato(RondaSeleccion<K,V>& c, const V& v){
    if(enSeleccion(c)== true){
            if(!esVacia(c)){
                    c.elegido->valor = v;
                    cout << "Participante actualizado" << endl;
            }else{
                cout << "La ronda esta vacia" << endl;
            }
    }else{
        cout << "No estamos en seleccion";
    }
}
template<typename K, typename V>
int eliminarCandidato(RondaSeleccion<K,V>& c){
    if(enSeleccion(c)){
        typename RondaSeleccion<K,V>::elemento* pAux;
        pAux = c.elegido;
        c.elegido = c.elegido->sig;
        delete pAux;
        if(c.elegido->sig == nullptr){
                c.elegido->sig = c.primero;
        }
    }else{
        cout << "No se puede eliminar porque no estamos en seleccion" << endl;
    }
}
template<typename K, typename V>
string listar(RondaSeleccion<K,V>& c){
    typename RondaSeleccion<K,V>::elemento* pAux;
    string cadena = "";
    while(pAux != nullptr){
        //cadena = cadena + "[" + obtenerCandidatoSuClave(miRonda,pAux->clave) + ":::" + obtenerCandidatoSuValor(miRonda,pAux->valor) + "] \n";
        pAux = pAux->sig;
    }

    return cadena;
}
template<typename K, typename V>
int pasarTurno(RondaSeleccion<K,V>& c){
    if(enSeleccion(c)== true){
            if(esVacia(c) == false){
                c.elegido = c.primero;
                if(c.elegido->sig != nullptr){ //Si el puntero elegido no esta al final que vaya iterando
                    c.elegido= c.elegido->sig;
                    return 0;
                }else{
                    c.elegido = c.primero; }//Cuando llega al final vuelve a apuntar al principio
            }else{
                cout << "La ronda esta vacia" << endl;
            }
    }else{
        cout << "No estamos en seleccion" << endl;
    }
}

//OPERACIONES DEL ITERADOR

template<typename K, typename V>
void iniciarIterador(RondaSeleccion<K,V>& c){ //Apunta el iterador al principio de la ronda
    c.iterador = c.primero;
}
template<typename K, typename V>
bool existeSiguiente(const RondaSeleccion<K,V>& c){//Comprueba si el puntero de la caja que apunta el iterador apunta a otra caja o no
    if(c.iterador->sig == nullptr){
            return false;
    }else{
        return true;
    }
}
template<typename K, typename V>
bool siguiente(RondaSeleccion<K,V>& c,K& k, V& v){ //En esta funcion juntamos siguienteClave, siguienteValor y avanza.
    if(existeSiguiente(c)){
        c.iterador->clave = k;
        c.iterador->valor = v;
        c.iterador = c.iterador->sig;
        return true;
    }else{
        return false;
    }

}
template<typename K, typename V>
bool vaciar(RondaSeleccion<K,V>& c){
    if( enSeleccion(c) ){
        while( !esVacia(c) ){
            eliminarCandidato(c);
        }
    }else{
        return false;
    }
    if( esVacia(c) ){
        c.seleccion = false;
        return true;
    }else{
        return false;
    }
}
#endif // RONDA_SELECCION_H_INCLUDED
