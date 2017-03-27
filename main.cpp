///////////////////////////////////////////////////////////////
//            main.cpp      Programa Principal               //
//                                                           //
//      Autor:   Iván García Campos                          //
//                                                           //
//               Fecha: 25/03/2017                           //
///////////////////////////////////////////////////////////////

#include "CPlato.h"
#include "CMenu.h"
#include "CProblemaMenusSaludables.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << argc << endl;
        cout << "Error ejecutando el programa \n";
        cerr << "Recuerde que debe ejecutar la aplicación incluyendo el fichero de entrada. \n\n";
        return -1;
    } else {
        CProblemaMenusSaludables* prueba = new CProblemaMenusSaludables(argv[1]);
        prueba->ejecutar();
    }

}
