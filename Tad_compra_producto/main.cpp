#include <iostream>
#include "producto.h"
#include "compra.h"

using namespace std;

int main()
{
    producto nar;
    crear("naranjas", 1, nar);

    compra miCompra;
    iniciar(miCompra);

    for(int i = 0; i < 50; i++){
        if(anyadir(miCompra,nar)){
                cout << "El producto " << totalCompra(miCompra) << " se ha anyadido correctamente y es unas "<< miCompra.lacompra[i].nombre<<endl;
        }else if (anyadir(miCompra,nar)==false){
            cout << "No se puede anyadir el producto" << endl;
        }
    }
    cout << "\nPRODUCTOR TOTALES: " << totalCompra(miCompra) << endl;



    return 0;
}
