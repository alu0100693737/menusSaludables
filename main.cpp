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

int main() {
    CProblemaMenusSaludables* prueba = new CProblemaMenusSaludables("ficheroPrueba");
    prueba->ejecutar();
    //prueba->mostrarMatriz();

}
