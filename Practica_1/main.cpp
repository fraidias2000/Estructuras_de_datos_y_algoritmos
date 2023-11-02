#include <iostream>
#include "Participantes.h"
#include "ronda_seleccion.h"
using namespace std;

int main()
{
  char opcion;
     RondaSeleccion<string,Participante>miRonda;
     crear(miRonda);
     string alias;
     string datosParticipante;
     Participante participantes,parActualizado;
     Participante parBuscado,parTurno;
     Participante valor;
     Participante parEliminar;
     int valorDatos;
     string cadena;
    do{
     cout << "**************************" << endl;
     cout << "***********MENU***********" << endl;
     cout << "1.- Inscribir participante" << endl;
     cout << "2.- Borrar participante" << endl;
     cout << "3.- Mostrar participante" << endl;
     cout << "4.- Cerrar instripcion" << endl;
     cout << "5.- Obtener candidato" << endl;
     cout << "6.- Descartar candidato" << endl;
     cout << "7.- Actualizar candidato" << endl;
     cout << "8.- Pasar turno" << endl;
     cout << "9.- Listar ronda" << endl;
     cout << "10.- Salir" << endl;
     cout << "**************************" << endl;
     cout << "**************************" << endl;
     cout << "Selecciona una opcion: ";
            cin >> opcion;

    switch(opcion){
            case '1':
                cout << "Alias del participante: " ;
                cin >> alias;
                if( pertenece(miRonda,alias) ){
                        cout << "El candidato ya existe" << endl;
                }else{
                        cout <<"Nombre y apellidos del participante: ";
                        cin >> ws;
                        getline(cin,datosParticipante);

                        crearParticipante(datosParticipante,participantes);
                        if( !enSeleccion(miRonda) ){
                                anyadir(miRonda,alias,participantes);
                                if( pertenece(miRonda, alias) ){
                                        cout << "Participante anyadido correctamente" << endl;
                                }else{ cout << "Error al anyadirlo" << endl;}
                        }else{ cout << "No esta en inscripcion, por lo tanto no puede inscribir al participante" << endl;
                        }
                }
                break;
            case '2':
                    cout << "Dime el alias del participante que quieres borrar: ";
                    cin >> alias;
                    if(pertenece(miRonda,alias)==true){
                        quitar(miRonda,alias);
                    }else{
                        cout << "No se pudo eliminar" <<endl;
                    }
                    break;

            case '3':
                cout << "Alias del participante a mostrar info: ";
                cin >> alias;
                obtenerValor(miRonda,alias,parBuscado);
                cout << infoParticipante(parBuscado) << endl;;
                break;
        case '4':
                if(enSeleccion(miRonda)==false){
                        cerrarInscripcion(miRonda);
                }else{
                        cout << "CIERRE DE INSCRIPCIÓN DESCARTADO" << endl;
                }
               break;

        case '5':
                if( !enSeleccion(miRonda) ){ //si no estamos en seleccion
                        cout << "Consulta candidato descartada" << endl;
                }else if ( !esVacia(miRonda) ){ //Si no esta vacía la ronda
                        obtenerCandidatoSuValor(miRonda,parTurno);
                        cout << "Candidato a evaluar: " << infoParticipante(parTurno);
                }else{
                    cout << "Ronda vacia" << endl;
                }
                break;
        case '6':
                if( esVacia(miRonda) ){
                        cout << "Ronda vacia" << endl;
                }else if( !enSeleccion(miRonda) ){
                    cout << "Descartar candidato no se puede realizar" << endl;
                }else{
                    obtenerCandidatoSuValor(miRonda,parEliminar);
                    cout << "Candidato a eliminar... " << infoParticipante(parEliminar) << " ";
                    if (eliminarCandidato(miRonda) == 1 ){
                        cout << "Candidato descartado" << endl;
                    }else{ cout << "No se pudo eliminar" << endl;}
                }
                break;

        case '7':
                if( enSeleccion(miRonda) && !esVacia(miRonda) ){
                        obtenerCandidatoSuValor(miRonda,parActualizado);
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
                        actualizarCandidato(miRonda,parActualizado);
                        if (actualizarCandidato(miRonda, parActualizado) == 1){
                                cout  << "Candidato actualizado " << infoParticipante(parActualizado) << "\n" << endl;
                        }else{
                                cout << "Ronda vacia" << endl;
                        }
                }else{
                        cout << "Actualizacion candidato cancelada" << endl;}
                break;

        case '8':
                if( esVacia(miRonda) ){
                    cout << "RONDA VACIA " << endl;
                }else if( !enSeleccion(miRonda) ){
                    cout << "No estas en seleccion" << endl;
                }else if( enSeleccion(miRonda)){
                    pasarTurno(miRonda);
                    obtenerCandidatoSuValor(miRonda, valor);
                    obtenerCandidatoSuClave(miRonda,alias);
                    cout << "Turno en..." << infoParticipante(valor) << "Alias: " << alias << endl;
                }
                break;

        case '9':
                cadena = "***** Ronda en fase: ";
                cout << "Total: " << cardinal(miRonda) << endl;
                if( enSeleccion(miRonda) ){
                        cout << " SELECCION" << endl;
                }else{ cout << "INSCRIPCION " << endl; }
                        cout << "Turno en candidato... ";
                        obtenerCandidatoSuClave(miRonda,alias);
                        if( obtenerCandidatoSuClave(miRonda,alias) == 1){
                                cout << alias << endl;
                        }else{
                                cout << "---" << endl;
                        }
                        cout << listar(miRonda);
                break;
        case 'V':
                if(vaciar(miRonda)){
                    cout << "Ronda vaciada " << endl;
                }else{ cout << "Vaciar ronda descartado" << endl;}
                break;
        case 'S':
            return 0;
            break;

        default:
                cout << "No ha escogido una de las opciones disponibles" << endl;
        break;
  }




    }while(opcion != 10);
    return 0;
}
