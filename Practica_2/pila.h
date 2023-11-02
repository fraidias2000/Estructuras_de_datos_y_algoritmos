#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

template<typename T> struct PilaDinamica;
template<typename T> void crear(PilaDinamica<T>& l);
template<typename T> void push(PilaDinamica<T>& l, const T& e);
template<typename T> T pop(PilaDinamica<T>& l);
template<typename T> bool esVacia(const PilaDinamica<T>& l);
template<typename T> int tamanyo(const PilaDinamica<T>& l);
template<typename T> void liberar(PilaDinamica<T>& l);

template<typename T>
struct PilaDinamica {
 friend void crear<T>(PilaDinamica<T>& l);
 friend void push<T>(PilaDinamica<T>& l, const T& e);
 friend T pop<T>(PilaDinamica<T>& l);
 friend bool esVacia<T>(const PilaDinamica<T>& l);
 friend int tamanyo<T>(const PilaDinamica<T>& l);
 friend void liberar<T>(PilaDinamica<T>& l);
 private:
     struct Nodo{
       T valor;
       Nodo* siguiente;
     };
     Nodo* elPrimero = nullptr;
     int numDatos;

};

template<typename T>
void crear(PilaDinamica<T>& l){
  l.numDatos = 0;
  l.elPrimero = nullptr;

}

template<typename T>
void push(PilaDinamica<T>& l, const T& e){
 typename PilaDinamica<T>::Nodo* aux= new typename PilaDinamica<T>::Nodo; ///Guardamos el dato tipo T (e) en la pila
  aux->valor = e;
  aux->siguiente = l.elPrimero;
  l.elPrimero = aux;
  l.numDatos++;

}

template<typename T> /// la funcion pop hace de cima y desapilar
T pop(PilaDinamica<T>& l){
   typename PilaDinamica<T>::Nodo* aux= new typename PilaDinamica<T>::Nodo;
   typename PilaDinamica<T>::Nodo* aux2= new typename PilaDinamica<T>::Nodo;
    T cima;
   if ( l.numDatos != 0){ ///Guardamos en un paux el dato que esta en la cima,lo puenteamos con el siguiente borramos ese dato y lo devolvemos en un dato creado
     aux = l.elPrimero;
     cima = l.elPrimero->valor;
     l.elPrimero = l.elPrimero->siguiente;
     l.numDatos--;
     delete aux;
   }
     return cima;
}

template<typename T>
bool esVacia(const PilaDinamica<T>& l){
 if (l.numDatos == 0){
    return true;
 } else { return false; }
}

template<typename T>
int tamanyo(const PilaDinamica<T>& l){
 return l.numDatos;
}

template<typename T>
 void liberar(PilaDinamica<T>& l){
   typename PilaDinamica<T>::Nodo* aux= new typename PilaDinamica<T>::Nodo;
   aux = l.elPrimero;
   while (aux != nullptr){
     l.elPrimero = l.elPrimero->siguiente;
     delete aux;
     aux = l.elPrimero;
   }
   l.numDatos = 0;
 }



#endif // PILA_H_INCLUDED
