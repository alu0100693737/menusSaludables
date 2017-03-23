#include "problemaMenusSaludables.h"
#define INF 99999
#define N 128

problemaMenusSaludables::problemaMenusSaludables(string nombreFichero) {
  menu =  new CMenu(nombreFichero);
  
  matriz = new int*[N];
  for(int i = 0; i < N; i++)
      matriz[i] = new int[N];
  
  for(int i = 0; i <= getMenu()->getNumPlatosDisponibles(); i++)
      for(int j = 0; j <= getMenu()->getUmbralMaximo(); j++)
        matriz[i][j] = -1;
  
  cout << "Puntuacion: " << getMenu()->getUmbralMaximo() << " \t Num de platos: " << getMenu()->getNumPlatosDisponibles() << endl; 
  cout << "Recursivo: " << resolverRecursivo(getMenu()->getNumPlatosDisponibles(), getMenu()->getUmbralMaximo()) << endl;
  cout << "Recursivo Top Down" << resolverTopDown(getMenu()->getNumPlatosDisponibles(), getMenu()->getUmbralMaximo()) << endl;
  mostrarMatriz();
  reconstruccionSolucion(getMenu()->getNumPlatosDisponibles(), getMenu()->getUmbralMaximo());
  cout << "\n\n\tRecursivo Bottom Up" << endl;
  resolverBottomUp(getMenu()->getNumPlatosDisponibles() - 1, getMenu()->getUmbralMaximo());
  mostrarMatriz();
}

CMenu* problemaMenusSaludables::getMenu() {
  return menu;
}

//Recursivo
  
int problemaMenusSaludables::resolverRecursivo(int nPlatos, int umbralMaximo) {
  if((nPlatos == 0) && (umbralMaximo >= 0))
    return 0;
  
  if(umbralMaximo < 0)
    return -INF;
  
  int v1 = resolverRecursivo(nPlatos - 1, umbralMaximo);
  int v2 = resolverRecursivo(nPlatos -1, umbralMaximo - getMenu()->getPlatosDisponibles().at(nPlatos - 1).getPuntuacion())  + getMenu()->getPlatosDisponibles().at(nPlatos - 1).getValorNutricional();
 
  return max(v1, v2);
}
  
//Utilizado para el TopDown

int problemaMenusSaludables::resolverTopDown(int nPlatos, int umbralMaximo) {
  
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


void problemaMenusSaludables::resolverBottomUp(int nPlatos, int umbralMaximo){
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

void problemaMenusSaludables::reconstruccionSolucion(int nPlatos, int umbralMaximo) {
  cout << "HOLA que hace" << endl;
    int j = umbralMaximo;
    for(int i = nPlatos - 1; i > 1; --i)
      if((getMenu()->getPlatosDisponibles().at(i - 1).getPuntuacion() <= j) && 
	(getDatoMatriz(i - 1, j - getMenu()->getPlatosDisponibles().at(i - 1).getPuntuacion()) + getMenu()->getPlatosDisponibles().at(i - 1).getValorNutricional() == getDatoMatriz(i, j) )) {
	  cout << "El objeto " << i << " ha sido elegido con valor " << getMenu()->getPlatosDisponibles().at(i).getValorNutricional() << endl;
	  j = j - getMenu()->getPlatosDisponibles().at(i - 1).getPuntuacion();
	  cout << " j vale: " << j << endl;
	}
}
void problemaMenusSaludables::mostrarMatriz() {
    for(int i = 0; i <= getMenu()->getNumPlatosDisponibles(); i++) {
        cout << endl;
        for(int j = 0; j <= getMenu()->getUmbralMaximo(); j++)
            cout << matriz[i][j] << " ";
    }
    cout << endl;
}

int problemaMenusSaludables::getDatoMatriz(int i, int j) {
    return matriz[i][j];
}

void problemaMenusSaludables::setDatoMatriz(int i, int j, int dato) {
    matriz[i][j] = dato;
}
