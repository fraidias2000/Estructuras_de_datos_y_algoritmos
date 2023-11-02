#include <iostream>
#include "ronda_seleccion.h"
#include <string>
#include "PARTICIPANTE.h"
#include "PREGUNTAS.h"
#include "cmt.h"
#include "CONCURSO.h"


using namespace std;

int main()
{
     int opcion;
     ColeccionMT<int,Pregunta,string> col;
     Concurso miConcurso;
     crearConcurso(3,2,1,miConcurso);
     Pregunta pregCreada,pregBuscada;
     Participante parCreado;
     int idp,respuesta;
     string marca;
     string aliasConcursante,datosConcursante,aliasbuscado;




     do{
     cout << "Fase: ";
     if (enInscripcion(miConcurso)){ cout << "Inscripcion" << endl;}
     if (enDocumentacion(miConcurso)){ cout << "Documentacion"<< endl;}
     if (enJuego(miConcurso)){ cout << "en Juego" << endl;}
     cout << "*****************************" << endl;
     cout << "*************MENU************" << endl;
     cout << "1.- Introducir pregunta" << endl;
     cout << "2.- Listar una pregunta" << endl;
     cout << "3.- Borrar pregunta" << endl;
     cout << "4.- Listar todas las preguntas" << endl;
     cout << "5.- Marcar tiempo con una pregunta" << endl;
     cout << "6.- Inscribir concursante" << endl;
     cout << "7.- Borrar concursante" << endl;
     cout << "8.- Mostrar concursante" << endl;
     cout << "9.- Obtener Concursante actual" << endl;
     cout << "10.- Listar concursantes" << endl;
     cout << "11.- Iniciar inscripcion" << endl;
     cout << "12.- Iniciar juego" << endl;
     cout << "13.- Probar concursante actual" << endl;
     cout << "14.- Hay ganadores" << endl;
     cout << "15.- Listar concurso" << endl;
     cout << "16.- Salir" << endl;
     cout << "17.- Vaciar (Durante la inscripcion no se puede)" << endl;
     cout << "*****************************" << endl;
     cout << "*****************************" << endl;
     cout << "Selecciona una opcion: " << endl;
     cin >> opcion;

     switch(opcion){
  case 1:
      if (enDocumentacion(miConcurso)){
       CrearPregunta(pregCreada);
       cout << "Escribe un numero identificador de pregunta: " << endl;
       cin >> idp;
       if (anyadirPregunta(miConcurso,idp,pregCreada)){
             cout << "Insercion realizada" << endl;
       }else{ cout << "Insercion descartada" << endl;}
      }else{ cout << "No estas en documentacion " << endl;}
    break;
  case 2:
      cout << "Escribe el identificador de la pregunta" << endl;
      cin >> idp;
      if (existePregunta(miConcurso,idp)){
       obtenerPregunta(miConcurso,idp,pregBuscada);
       cout <<PreguntaCompleta(pregBuscada);
      }else{
       cout << "Pregunta no encontrada" << endl;
      }
      break;
  case 3:
    cout << "Escribe identificador de la pregunta a borrar" << endl;
    cin >> idp;
    if (enDocumentacion(miConcurso)){
     if (existePregunta(miConcurso,idp)){
       if ( borrarPregunta(miConcurso,idp)){
         cout << "Pregunta borrada: " << idp << endl;
       }else{
        cout << "Borrado descartado: " << idp << endl;
       }
     }else{
       cout << "Pregunta no encontrada" << endl;
     }

    }else{
      cout << "No estas en documentacion" << endl;
    }
   break;
  case 4:
    cout << listarPreguntas(miConcurso);
    break;
  case 5:
    cout << "Escribe el identificador: ";
    cin >> idp;
    cout << "Escribe la marca de tiempo: ";
    cin >> ws;
    getline(cin,marca);
    if ( marcarPregunta(miConcurso,idp,marca) ){
        cout << "Pregunta Marcada: " << idp << ", " << marca << endl;
    }else{
      cout << "Marca descartada" << endl;
    }
    break;
  case 6:
      if ( enInscripcion(miConcurso)){

        cout << "Escribe el alias del concursante: ";
        cin >> aliasConcursante;
        cout <<"Nombre y apellidos del participante: ";
        cin >> ws;
        getline(cin,datosConcursante);
        crearParticipante(parCreado,datosConcursante);
        if (anyadirConcursante(miConcurso,aliasConcursante,parCreado)){
            cout << "participante INSCRITO" << endl;
            cout << aliasConcursante << ", " << infoParticipante(parCreado) << endl;
        }else if (!anyadirConcursante(miConcurso,aliasConcursante,parCreado)){
            cout << "Pariticpante descartado" << endl;
        }else { cout << "Inscricpion CERRADA" << endl;}
      }else{
        cout << "No estas en inscripcion" << endl;
      }
    break; ///mirar si existe ya o no
  case 7:
    cout << "Escribe el alias del participante: ";
    cin >>aliasConcursante;
    if (existeConcursante(miConcurso,aliasConcursante)){
     if ( borrarConcursante(miConcurso,aliasConcursante) ) {
         cout << "participante BORRADO" << endl;
     }else{ cout << "No se pudo borrar" << endl;}
    }else{
      cout << "Participante NO ENCONTRADO" << endl;
    }
    break;
  case 8: /// mostrar concurante
    cout << "Pedir alias del concursante a mostrar: ";
    cin >>aliasConcursante;
     if (obtenerInfoConcursante(miConcurso,aliasConcursante,parCreado) ){
        cout << "participante ENCONTRADO: " << infoParticipante(parCreado) << endl;

     }else{
      cout << "Participante DESCONOCIDO" << endl;
     }
     break;
  case 9: /// obtener concursante actual
    if (enJuego(miConcurso)){
        cout << "Candidato a evaluar: ";
       if ( obtenerConcursanteActual(miConcurso,aliasbuscado)  == 1){
         obtenerInfoConcursante(miConcurso,aliasbuscado,parCreado);
         cout << infoParticipante(parCreado) << endl;
       }else{
          cout << "Ronda vacia" << endl;
       }
    }else{
      cout << "No estas en juego" << endl;
    }
    break;
  case 10:
      cout << listarConcursantes(miConcurso) << endl;
    break;
  case 11:
     iniciarInscripcion(miConcurso);
     if (enInscripcion(miConcurso)){
        cout << "Inscripcion ABIERTA" << endl;
     }else{
       cout << "Inscripcion CAANCELADA" << endl;
     }
     break;
  case 12:
    iniciarJuego(miConcurso);
    if (enJuego(miConcurso)){
        cout << "INICIANDO JUEGO" << endl;
    }else{
      cout << "No es posible iniciar juego" << endl;
    }
    break;
  case 13: // probar concursante actual
    if (enJuego(miConcurso)){
     cout << "Escribe el identificador de la pregunta: ";
     cin >> idp;
     obtenerPregunta(miConcurso,idp,pregBuscada);
     cout << "Pregunta: " << PreguntaCompleta(pregBuscada);
     cout << "Escribe la marca de tiempo que quieres poner(horas:minutos): ";
     cin >>ws;
     getline(cin,marca);
     marcarPregunta(miConcurso,idp,marca);
     cout << "Escribe la respuesta para la pregunta (numero): ";
     cin >> respuesta;
     cout << "+++RESPONDE CONCURSANTE" << endl;
     obtenerConcursanteActual(miConcurso,aliasbuscado);
     obtenerInfoConcursante(miConcurso,aliasbuscado,parCreado);
     cout << "Concursante: " << infoParticipante(parCreado) << endl;
     cout << "RESPUESTA DADA: " << respuesta << "TIEMPO: " << marca << endl;
     probarConcursanteActual(miConcurso,idp,marca,respuesta);
     if (!existeConcursante(miConcurso,aliasbuscado)){
         cout << "Participante eliminado" << endl;
     }
     cout << "+++++++++++++" << endl;
    }else{
      cout << "Probar concursante DESCARTADO" << endl;
    }
    break;
  case 14:
      if (hayGanadores(miConcurso)){
        cout << "Los ganadores son: " << endl;
        listarConcursantes(miConcurso);

      }else{
       cout << "NO hay ganadores" << endl;
      }
    break;
  case 15:
    cout << listarConcurso(miConcurso);
    break;
  case 16:
    return 0;
  case 17:

   if ( vaciar(miConcurso) ) {
    cout << "Concurso vaciado" << endl;
   }else{
     cout << "No se ha podido, estas en fase de inscripcion" << endl;
   }

  default:
    break;
     }
  }while(1);
}



