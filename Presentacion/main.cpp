#include <iostream>
#include "ronda_seleccion.h"
#include <string>
#include "PARTICIPANTE.h"


using namespace std;

int main()
{
     char opcion;
     RondaSeleccion<string,Participante>ronda1;
     crear(ronda1);
     string alias, datosParticipante, cadena;
     Participante participantes, valor;
     Participante parBuscado,parTurno,parActualizado,parEliminar;
     int valorDatos;


     do{
     cout << "*****************************" << endl;
     cout << "*************MENU************" << endl;
     cout << "1.- Inscribir participante" << endl;
     cout << "2.- Borrar participante" << endl;
     cout << "3.- Mostrar participante" << endl;
     cout << "4.- Cerrar instripcion" << endl;
     cout << "5.- Obtener candidato" << endl;
     cout << "6.- Descartar candidato" << endl;
     cout << "7.- Actualizar candidato" << endl;
     cout << "8.- Pasar turno" << endl;
     cout << "9.- Listar ronda" << endl;
     cout << "S.- Salir" << endl;
     cout << "V.- Vaciar (Se necesita tener la ronda cerrada)" << endl;
     cout << "*****************************" << endl;
     cout << "*****************************" << endl;
     cout << "Selecciona una opcion: " << endl;
     cin >> opcion;

     switch(opcion){

  case '1': //Pedimos datos al usuario para crear un participante y si no estamos en ronda seleccion y no existe dicho participante en la ronda, creamos y añadimos un participante a una ronda
        if( !enSeleccion(ronda1) ){
            cout << "Alias del participante: " ;
            cin >> alias;
            if( pertenece(ronda1,alias) ){
                cout << "El candidato ya existe" << endl;
            }else{
                cout <<"Nombre y apellidos del participante: ";
                cin >> ws;
                getline(cin,datosParticipante);
                crearParticipante(participantes,datosParticipante);
                anyadir(ronda1,alias,participantes);
            }
            }else{
                cout << "No esta en inscripcion, por lo tanto no puede inscribir al participante" << endl;
            }

      break;

  case '2': //Nos pide un nombre y si esta en la ronda lo borra
      cout << "Alias del participante a borrar: " ;
      cin >> alias;
      if(pertenece(ronda1,alias)){
            quitar(ronda1,alias);
            pasarTurno(ronda1);
            if ( pertenece(ronda1,alias) ){
                    cout << "No se pudo eliminar" << endl;
            }else{ cout << "Eliminado correctamente" << endl;}
      }else{
            cout << "El alias no coincide con ningun participante" << endl;
      }
      break;

  case '3': //Nos pide un alias y mostramos los datos del participante que coincida con esa clave
    if(esVacia(ronda1) == false){
        cout << "Alias del participante a mostrar info: ";
        cin >> alias;
        obtenerValor(ronda1,alias,parBuscado);
        if( pertenece(ronda1,alias) ){
            cout << infoParticipante(parBuscado) << endl;;
        }else{
            cout << "El alias no pertenece a ningun participante" << endl;
        }
    }else {
        cout << "No se puede mostrar nada porque la ronda esta vacia" << endl;
    }
      break;

  case '4': //Cierra la inscipcion y pasa a seleccion
    cerrarInscripcion(ronda1);
    if ( enSeleccion(ronda1) ){
       cout << "Inscripcion cerrada" << endl;
    } else{ cout << "Cierre de inscripcion descartado" << endl;}
    break;

  case '5': //Muestra el participante que tiene el turno
     if( !enSeleccion(ronda1) ){
            cout << "Consulta candidato descartada" << endl;

     }else if (!esVacia(ronda1) ){
            obtenerCandidatoSuValor(ronda1,parTurno);
            cout << "Candidato a evaluar..." << infoParticipante(parTurno) << endl;

     }else{ cout << "Ronda vacia" << endl;
     }
     break;

  case '6': //Elimina el participante que tiene el turno
      if( esVacia(ronda1) ){ cout << "Ronda vacia" << endl;
      }else if( !enSeleccion(ronda1) ){
            cout << "Descartar candidato no se puede realizar" << endl;
      }else{
            obtenerCandidatoSuValor(ronda1,parEliminar);
            cout << "Candidato a eliminar... " << infoParticipante(parEliminar) << " ";

            if (eliminarCandidato(ronda1) == 1 ){
                cout << "Candidato descartado" << endl;
            }else{ cout << "No se pudo eliminar" << endl;
            }
      }
     break;

  case '7': //Añade los fallos,aciertos y pasos al participante que tiene el turno
    if( enSeleccion(ronda1) && !esVacia(ronda1) ){
        obtenerCandidatoSuValor(ronda1,parActualizado);
        cout << "Poner aciertos: ";
        cin >> valorDatos;
        ponerAciertos(parActualizado,valorDatos);
        valorDatos = 0;
        cout << "Poner fallos: ";
        cin >> valorDatos;
        ponerFallos(parActualizado,valorDatos);
        valorDatos = 0;
        cout << "Poner pasos: ";
        cin >> valorDatos;
        ponerPasos(parActualizado,valorDatos);
        actualizarCandidato(ronda1,parActualizado);
        if (actualizarCandidato(ronda1, parActualizado) == 1){
            cout  << "Candidato actualizado " << infoParticipante(parActualizado) << "\n" << endl;
    }else{
        cout << "Actualizacion candidato cancelada" << endl;
    }
    break;

  case '8': //Pasa el turno y tambien nos muestra quien tiene el turno
    if( esVacia(ronda1) ){
        cout << "RONDA VACIA " << endl;
    }else if( !enSeleccion(ronda1) ){
        cout << "No estas en seleccion" << endl;
    }else if( enSeleccion(ronda1)){
        pasarTurno(ronda1);
        obtenerCandidatoSuValor(ronda1, valor);
        obtenerCandidatoSuClave(ronda1,alias);
        cout << "Turno en..." << infoParticipante(valor) << " ||Alias: " << alias << endl;
    }
    break;

  case '9': //Lista todos los participantes que hay en una ronda
     cadena = "***** Ronda en fase: ";
     cout << "Total: " << cardinal(ronda1) << endl;
     if( enSeleccion(ronda1) ){
            cout << " SELECCION" << endl;
     }else{ cout << "INSCRIPCION " << endl; }
            cout << "Turno en candidato... ";
            obtenerCandidatoSuClave(ronda1,alias);
     if( obtenerCandidatoSuClave(ronda1,alias) == 1){
            cout << alias << endl;
     }else{
            cout << "---" << endl;
     }
     cout << listar(ronda1);
     cout << "*****" << endl;
     break;

  case 'V': //Vaciamos toda la ronda y volvemos a inscripcion
      if(vaciar(ronda1)){
            cout << "Ronda vaciada " << endl;
      }else{
          cout << "Vaciar ronda descartado" << endl;
      }
     break;

  case 'S': //Sale del programa
     return 0;
      break;

  default:
      cout << "No ha escogido una de las opciones disponibles" << endl;
      break;
  }
     }while(1);

    return 0;
}
