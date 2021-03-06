///////////////////////////////////////////////////////////////
//                 CProblemaMenusSaludables.cpp -            //
//     Implementación de la clase CProblemaMenusSaludables   //
//                                                           //
//      Autor:   Iván García Campos                          //
//                                                           //
//               Fecha: 25/03/2017                           //
///////////////////////////////////////////////////////////////

#include "CProblemaMenusSaludables.h"
#include <time.h>
#define INF 99999
#define N 128

CProblemaMenusSaludables::CProblemaMenusSaludables(string nombreFichero) {
    menu =  new CMenu(nombreFichero);

    matriz = new int*[N];
    for(int i = 0; i < N; i++)
        matriz[i] = new int[N];

    for(int i = 0; i <= getMenu()->getNumPlatosDisponibles(); i++)
        for(int j = 0; j <= getMenu()->getUmbralMaximo(); j++)
            matriz[i][j] = -1;
}

CMenu* CProblemaMenusSaludables::getMenu() {
    return menu;
}

//Recursivo

int CProblemaMenusSaludables::resolverRecursivo(int nPlatos, int umbralMaximo) {
    if((nPlatos == 0) && (umbralMaximo >= 0))
        return 0;

    if(umbralMaximo < 0)
        return -INF;

    int v1 = resolverRecursivo(nPlatos - 1, umbralMaximo);
    int v2 = resolverRecursivo(nPlatos -1, umbralMaximo - getMenu()->getPlatosDisponibles().at(nPlatos - 1).getPuntuacion())  + getMenu()->getPlatosDisponibles().at(nPlatos - 1).getValorNutricional();

    return max(v1, v2);
}

//Utilizado para el TopDown

int CProblemaMenusSaludables::resolverTopDown(int nPlatos, int umbralMaximo) {

    if((nPlatos == 0) && (umbralMaximo >= 0))
        return 0;

    if(umbralMaximo < 0)
        return -INF;

    if(getDatoMatriz(nPlatos, umbralMaximo) != -1)
        return getDatoMatriz(nPlatos, umbralMaximo);

    int v1 = resolverTopDown(nPlatos - 1, umbralMaximo);
    int v2 = resolverTopDown(nPlatos -1, umbralMaximo - getMenu()->getPlatosDisponibles().at(nPlatos - 1).getPuntuacion())  + getMenu()->getPlatosDisponibles().at(nPlatos - 1).getValorNutricional();

    setDatoMatriz(nPlatos, umbralMaximo, max(v1, v2));
}


void CProblemaMenusSaludables::resolverBottomUp(int nPlatos, int umbralMaximo){
    for(int j = 0; j <= umbralMaximo; j++)
        setDatoMatriz(0, j, 0); //valor introducido 0

    for(int i = 1; i <= nPlatos + 1; i++)
        for(int j = 0; j <= umbralMaximo; j++)
            if(getMenu()->getPlatosDisponibles().at(i - 1).getPuntuacion() <= j) {
                setDatoMatriz(i, j,
                              max(getDatoMatriz(i - 1, j),
                                  getDatoMatriz(i - 1,
                                                j - getMenu()->getPlatosDisponibles().at(i - 1).getPuntuacion()) + getMenu()->getPlatosDisponibles().at(i - 1).getValorNutricional()));
            }else {
                setDatoMatriz(i, j, getDatoMatriz(i - 1, j));
            }
}

void CProblemaMenusSaludables::reconstruccionSolucion(int nPlatos, int umbralMaximo) {
    for(int i = 0; i <= nPlatos; i++)
        for(int j = 0; j <= umbralMaximo; j++)
            if(getDatoMatriz(i, j) == -1)
                setDatoMatriz(i,j, 0);

    int j = umbralMaximo;
    for(int i = nPlatos; i >= 1; --i) {
        if((getMenu()->getPlatosDisponibles().at(i - 1).getPuntuacion() <= j) &&
                (getDatoMatriz(i - 1, j - getMenu()->getPlatosDisponibles().at(i - 1).getPuntuacion()) + getMenu()->getPlatosDisponibles().at(i - 1).getValorNutricional() == getDatoMatriz(i, j) )) {
            cout << "\n\tEl plato: " << getMenu()->getPlatosDisponibles().at(i - 1).getNombrePlato() << " ha sido elegido con valor nutricional: " << getMenu()->getPlatosDisponibles().at(i - 1).getValorNutricional() << endl;
            j = j - getMenu()->getPlatosDisponibles().at(i - 1).getPuntuacion();
        }
    }
}
void CProblemaMenusSaludables::mostrarMatriz() {
    for(int i = 0; i <= getMenu()->getNumPlatosDisponibles(); i++) {
        cout << "\n\t";
        for(int j = 0; j <= getMenu()->getUmbralMaximo(); j++)
            cout << matriz[i][j] << " ";
    }
    cout << endl;
}

int CProblemaMenusSaludables::getDatoMatriz(int i, int j) {
    return matriz[i][j];
}

void CProblemaMenusSaludables::setDatoMatriz(int i, int j, int dato) {
    matriz[i][j] = dato;
}

void CProblemaMenusSaludables::ejecutar() {
    cout << "\t PROBLEMA MENUS SALUDABLES\n\n" << endl;

    cout << "\tPuntuacion: " << getMenu()->getUmbralMaximo() << " \t Num de platos: " << getMenu()->getNumPlatosDisponibles() << endl;
    
    timespec t1;
    clock_gettime(CLOCK_REALTIME,&t1);
    
    cout << "\n\t*Recursivo: " << resolverRecursivo(getMenu()->getNumPlatosDisponibles(), getMenu()->getUmbralMaximo()) << endl;
    
    timespec b1;
    clock_gettime(CLOCK_REALTIME,&b1);
    cout << "El tiempo en ejecutarse fue de ";
    cout << b1.tv_nsec - t1.tv_nsec << endl << endl; 
    
    
    cout << "-----------------------------------------------------------------------------------" << endl;
    
    timespec t2;
    clock_gettime(CLOCK_REALTIME,&t2);
    cout << "\n\t*Recursivo Top Down: " << resolverTopDown(getMenu()->getNumPlatosDisponibles(), getMenu()->getUmbralMaximo()) << endl;
    timespec b2;
    clock_gettime(CLOCK_REALTIME,&b2);
    cout << "El tiempo en ejecutarse fue de ";
    cout << b2.tv_nsec - t2.tv_nsec << endl << endl;
    
    mostrarMatriz();
    reconstruccionSolucion(getMenu()->getNumPlatosDisponibles(), getMenu()->getUmbralMaximo());
    
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "\n\n\tRecursivo Bottom Up" << endl;
    
    timespec t3;
    clock_gettime(CLOCK_REALTIME,&t3);
    resolverBottomUp(getMenu()->getNumPlatosDisponibles() - 1, getMenu()->getUmbralMaximo());
    timespec b3;
    clock_gettime(CLOCK_REALTIME,&b3);
    cout << "El tiempo en ejecutarse fue de ";
    cout << b3.tv_nsec - t3.tv_nsec << endl << endl;
    
    mostrarMatriz();
   reconstruccionSolucion(getMenu()->getNumPlatosDisponibles(), getMenu()->getUmbralMaximo());
    
}
