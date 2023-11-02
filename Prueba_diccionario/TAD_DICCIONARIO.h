#ifndef TAD_DICCIONARIO_H_INCLUDED
#define TAD_DICCIONARIO_H_INCLUDED

template<typename clave, typename valor> struct diccionario;

template<typename clave, typename valor>void crear(diccionario<clave,valor>);
template<typename clave, typename valor> diccionario añadir(diccionario d, diccionario<clave,valor>);
template<typename clave, typename valor> bool pertene(diccionario d, diccionario<clave>);
template<typename clave, typename valor> int obtenerValor(diccionario d, diccionario<clave>);
template<typename clave, typename valor> diccionario quitar (diccionario<clave>, diccionario d);
template<typename clave, typename valor> int cardinal (diccionario d);
template<typename clave, typename valor> bool esVacio (diccionario d);

struct diccionario{

    friend void crear(diccionario<clave,valor>);
    friend diccionario añadir(diccionario d, diccionario<clave,valor>);
    friend bool pertene(diccionario d, diccionario<clave>);
    friend int obtenerValor(diccionario d, diccionario<clave>);
    friend diccionario quitar (diccionario<clave>, diccionario d);
    friend int cardinal (diccionario d);
    friend bool esVacio (diccionario d);




};

#endif // TAD_DICCIONARIO_H_INCLUDED
