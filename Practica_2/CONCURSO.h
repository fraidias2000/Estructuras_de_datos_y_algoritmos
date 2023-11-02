#ifndef CONCURSO_H_INCLUDED
#define CONCURSO_H_INCLUDED
#include "ronda_seleccion.h"
#include "pila.h"
#include "cmt.h"
#include "PREGUNTAS.h"

 using namespace std;

 struct Concurso;
 void crearConcurso(int pmax, int fmax, int numGmax, Concurso& c);
 int maximoPasesPermitidos(const Concurso& c);
 int maximoFallosPermitidos(const Concurso& c);
 int maximoNumeroGanadores(const Concurso& c);
 bool enDocumentacion(const Concurso& c);
 bool enInscripcion(const Concurso& c);
 bool enJuego(const Concurso& c);
 bool anyadirPregunta(Concurso& c, int idp, const Pregunta& p);
 bool borrarPregunta(Concurso& c, int idp);
 int totalPreguntas(const Concurso& c);
 bool existePregunta(const Concurso& c, int id);
 bool obtenerPregunta(const Concurso& c, int id, Pregunta& p);
 bool esPreguntaUtilizada(const Concurso& c, int id, bool& utilizada);
 int obtenerUltimoUsoPregunta(const Concurso& c, int id, string& t);
 bool marcarPregunta(Concurso& c, int id, const string& t);
   /*Fase inscripcion*/
 void iniciarInscripcion(Concurso& c);
 bool anyadirConcursante(Concurso& c, const string& id, const Participante& p);
 bool borrarConcursante(Concurso& c, const string& id);
 bool existeConcursante(const Concurso& c, const string& id);
 bool obtenerInfoConcursante(const Concurso& c, string id, Participante& p);

// bool hayMaxGanadores(const Concurso& c);
 int totalConcursantes(const Concurso& c);
  /*Fase en juego*/
 void iniciarJuego(Concurso& c);
 int obtenerConcursanteActual(const Concurso& c, string& id);
 bool hayGanadores(const Concurso& c);
 int probarConcursanteActual(Concurso& c, int idPrg, const string& t, int resp);
 bool vaciar(Concurso& c);
   /*Listados*/
 string listarPreguntas(Concurso& c);
 string listarConcursantes(Concurso& c);
 string listarConcurso(Concurso& c);

 struct Concurso{
  friend void crearConcurso(int pmax, int fmax, int numGmax, Concurso& c);
  friend int maximoPasesPermitidos(const Concurso& c);
  friend int maximoFallosPermitidos(const Concurso& c);
  friend int maximoNumeroGanadores(const Concurso& c);
  friend bool enDocumentacion(const Concurso& c);
  friend bool enInscripcion(const Concurso& c);
  friend bool enJuego(const Concurso& c);
  friend bool anyadirPregunta(Concurso& c, int idp, const Pregunta& p);
  friend bool borrarPregunta(Concurso& c, int idp);
  friend int totalPreguntas(const Concurso& c);
  friend bool existePregunta(const Concurso& c, int id);
  friend bool obtenerPregunta(const Concurso& c, int id, Pregunta& p);
  friend bool esPreguntaUtilizada(const Concurso& c, int id, bool& utilizada);
  friend int obtenerUltimoUsoPregunta(const Concurso& c, int id, string& t);
  friend bool marcarPregunta(Concurso& c, int id, const string& t);
   /*Fase inscripcion*/
  friend void iniciarInscripcion(Concurso& c);
  friend bool anyadirConcursante(Concurso& c, const string& id, const Participante& p);
  friend bool borrarConcursante(Concurso& c, const string& id);
  friend bool existeConcursante(const Concurso& c, const string& id);
  friend bool obtenerInfoConcursante(const Concurso& c, string id, Participante& p);
  //friend bool hayMaxGanadores(const Concurso& c);
  friend int totalConcursantes(const Concurso& c);
  /*Fase en juego*/
  friend void iniciarJuego(Concurso& c);
  friend int obtenerConcursanteActual(const Concurso& c, string& id);
  friend bool hayGanadores(const Concurso& c);
  friend int probarConcursanteActual(Concurso& c, int idPrg, const string& t, int resp);
  friend bool vaciar(Concurso& c);

  /*Listados*/
  friend string listarPreguntas(Concurso& c);
  friend string listarConcursantes(Concurso& c);
  friend string listarConcurso(Concurso& c);

  private:
   int pasesMax;
   int fallosMax;
   int ganadoresMax;
   bool enDocumentacion = true;
   ColeccionMT<int,Pregunta,string> preguntas;
   RondaSeleccion<string,Participante> ronda;
 };

 void crearConcurso(int pmax, int fmax, int numGmax, Concurso& c){
   c.fallosMax = fmax;
   c.enDocumentacion = true;
   c.pasesMax = pmax;
   c.ganadoresMax = numGmax;
   crear(c.ronda);
   crear(c.preguntas);

 }

 int maximoPasesPermitidos(const Concurso& c){
   return c.pasesMax;
 }

 int maximoFallosPermitidos(const Concurso& c){
  return c.fallosMax;
 }

 int maximoNumeroGanadores(const Concurso& c){
  return c.ganadoresMax;
 }

 bool enDocumentacion(const Concurso& c){
   if( c.enDocumentacion ){
    return true;
   } else{
    return false;
   }
 }

 bool enInscripcion(const Concurso& c){
     if( !enSeleccion(c.ronda) && !enDocumentacion(c) ){ /// Para saber la fase comprobamos que no este ni en seleccion ni en documentacion --> enInscripcion
        return true;
     }
     else{
       return false;
     }
 }

 bool enJuego(const Concurso& c){
   if (   enSeleccion(c.ronda) && !enInscripcion(c) ){

     return true;
   }else{
    return false;
   }
 }

 bool anyadirPregunta(Concurso& c, int idp, const Pregunta& p){
     if ( !enDocumentacion(c) ){ return false;} ///La condicion para anyadir es que esté en documentacion
     else{
         insertar(c.preguntas,idp,p);
         return true;
        }
 }

 bool borrarPregunta(Concurso& c, int idp){
   if ( !enDocumentacion(c) ){ return false;}
   else{
     borrar(c.preguntas,idp);
     return true;
   }
 }

 int totalPreguntas(const Concurso& c){
  return tamanyo(c.preguntas);
 }

 bool existePregunta(const Concurso& c, int id){
    if ( existeClave(c.preguntas,id) ){ return true;} ///Si existe una clave existirá una pregunta asociada a esa clave
    else{ return false;}
 }

 bool obtenerPregunta(const Concurso& c, int id, Pregunta& p){ ///Sabiendo que existe una pregunta obtenemos esa pregunta
    if ( existePregunta(c,id) ){
        if ( obtenerDato(c.preguntas,id,p) ){ return true;}
        else{ return false;}
    }else { return false;}
 }

 bool esPreguntaUtilizada(const Concurso& c, int id, bool& utilizada){ ///Devueleve verdad si la pregunta tiene tiempo
    if ( !existeClave(c.preguntas, id) ){
      utilizada = false;
      return false;
    }
    else{
        if ( tieneTiempo(c.preguntas,id) ){
            utilizada = true;
            return true;
        }else{
         utilizada = false;
         return false;
        }
    }
 }

 int obtenerUltimoUsoPregunta(const Concurso& c, int id, string& t){ ///Devuelve la marca de tiempo de una pregunta
   bool utilizada;
   if ( esPreguntaUtilizada(c,id,utilizada)){
      obtenerTiempo(c.preguntas,id,t);
      return 1;
   }else{ return 0;}
 }

 bool marcarPregunta(Concurso& c, int id, const string& t){ ///Poner tiempo a una pregunta
   if ( existePregunta(c, id) ){
     marcarTiempo(c.preguntas, id, t);
   }
 }

 void iniciarInscripcion(Concurso& c){
   if ( enDocumentacion(c) && totalPreguntas(c) > 0 ){
     c.enDocumentacion = false;
   }
 }

 bool anyadirConcursante(Concurso& c, const string& id, const Participante& p){ ///Si existe un concursante actualiza el candidato, sino, lo crea
  if ( !existeConcursante(c,id) && enInscripcion(c) ){
    return anyadir(c.ronda, id, p);
  }else if(existeConcursante(c,id) && enInscripcion(c)){
     if ( actualizarCandidato(c.ronda,p)  == 1) { return true;}
     else { return false;}
  }else{ return false;}

 }

 bool borrarConcursante(Concurso& c, const string& id){
   if ( existeConcursante(c, id) && enInscripcion(c)  || (existeConcursante(c,id) && enJuego(c)) ){
      return quitar(c.ronda,id);
   }else { return false;}
 }

 bool existeConcursante(const Concurso& c, const string& id){
   return pertenece(c.ronda,id);
 }

 bool obtenerInfoConcursante(const Concurso& c, string id, Participante& p){
   if (existeConcursante(c,id)){
     return obtenerValor(c.ronda,id,p);
   }else { return false;}
 }

 int totalConcursantes(const Concurso& c){
  return cardinal(c.ronda);
 }


 void iniciarJuego(Concurso& c){
   if( enInscripcion(c) && totalConcursantes(c) > maximoNumeroGanadores(c)){
     cerrarInscripcion(c.ronda);
     c.enDocumentacion = false;
   }
 }

 int obtenerConcursanteActual(const Concurso& c, string& id){
   if( enJuego(c) && totalConcursantes(c) > 0){
     return  obtenerCandidatoSuClave(c.ronda,id);
   }else { return 0;}
 }

 bool hayGanadores(const Concurso& c){
   if( enJuego(c) && totalConcursantes(c) <= maximoNumeroGanadores(c)) { return true;}
   else { return false;}
 }

 int probarConcursanteActual(Concurso& c, int idPrg, const string& t, int resp){
    Participante p;
    Pregunta preg;
    string clave;
   if( enJuego(c) && totalConcursantes(c) > 0){
        obtenerCandidatoSuValor(c.ronda,p);
        obtenerPregunta(c,idPrg,preg);
    switch (resp){
     case 0:
         if( numPasos(p) < maximoPasesPermitidos(c) ){
           ponerPasos(p,numPasos(p) + 1);
           actualizarCandidato(c.ronda,p);
         }
         break;
     case 1: case 2: case 3:
          if( respuestaCorrecta(preg) == resp){
            ponerAciertos(p,numAciertos(p) + 1);
            actualizarCandidato(c.ronda,p);
          }else{
            ponerFallos(p,numFallos(p) + 1);
            actualizarCandidato(c.ronda,p);
            if(numFallos(p) == maximoFallosPermitidos(c)){
                obtenerCandidatoSuClave(c.ronda,clave);
                borrarConcursante(c,clave);
            }
          }
            pasarTurno(c.ronda);
          break;
     default:
        cout << "No has puesto una opcion correcta" << endl;
        break;
    }
      return 1;



   }else{ return 0;}
 }

 string listarPreguntas(Concurso& c){
   ostringstream cadena;
   cadena << "---LISTADO DE PREGUNTAS---" << endl;
   cadena <<"TOTAL preguntas: " << totalPreguntas(c) << endl;
   cadena << listar(c.preguntas) << endl;
   cadena << "------" << endl;
   return cadena.str();
 }

 string listarConcursantes(Concurso& c){
  ostringstream cadena;
  cadena << "-*- LISTADO DE CONCURSANTES -*-" << endl;
  cadena << "TOTAL concursantes: " << totalConcursantes(c) << endl;
  cadena << listar(c.ronda) << endl;
  cadena << "-*-*-*-" << endl;
  return cadena.str();
 }

 string listarConcurso(Concurso& c){
  ostringstream cadena;
  string cad;
  cadena << "***********ESTADO DEL CONCURSO ***********" << endl;
  cadena << "FASE: ";
  if (enJuego(c)){
    cadena << "Juego" << endl;
    if (obtenerCandidatoSuClave(c.ronda,cad)  ){
    cadena << "JUGANDO concursante: " << cad << endl;
    }else { cadena << "JUGANDO concursante: " << "---" << endl;}
  }
  else if (enDocumentacion(c)){ cadena << "Documentacion" << endl;}
  else if (enInscripcion(c)){ cadena << "Inscripcion" << endl;}
  cadena << "LIMITES maximos-> Pases: " << maximoPasesPermitidos(c);
  cadena << "Fallos: " << maximoFallosPermitidos(c);
  cadena << "Ganadoress: " << maximoNumeroGanadores(c) << endl;
  cadena << listarConcursantes(c);
  cadena  << listarPreguntas(c);
  return cadena.str();
 }

 bool vaciar(Concurso& c){
    vaciar(c.preguntas);
    c.enDocumentacion = true;
    return vaciar(c.ronda);
 }



#endif // CONCURSO_H_INCLUDED
