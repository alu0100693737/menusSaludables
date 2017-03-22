#include "problemaMenusSaludables.h"
#define INF 99999
#define N 128

problemaMenusSaludables::problemaMenusSaludables(string nombreFichero) {
  menu =  new CMenu(nombreFichero);
  //cout << "La solucion es: " << resolverRecursivo(getMenu()->getNumPlatosDisponibles() - 1, getMenu()->getUmbralMaximo());
  matriz = new int*[N];
  for(int i = 0; i < N; i++)
      matriz[i] = new int[N];
  
  for(int i = 0; i <= getMenu()->getNumPlatosDisponibles(); i++)
      for(int j = 0; j <= getMenu()->getUmbralMaximo(); j++)
        matriz[i][j] = -1;
  
  cout << "Puntuacion: " << getMenu()->getUmbralMaximo() << " \t Num de platos: " << getMenu()->getNumPlatosDisponibles() << endl; 
  cout << "Recursivo: " << resolverRecursivo(getMenu()->getNumPlatosDisponibles(), getMenu()->getUmbralMaximo()) << endl;
  cout << "Recursivo Top Down" << resolverTopDown(getMenu()->getNumPlatosDisponibles(), getMenu()->getUmbralMaximo()) << endl;
  //resolverTopDown(getMenu()->getNumPlatosDisponibles() - 1, getMenu()->getUmbralMaximo());
  mostrarMatriz();
}

CMenu* problemaMenusSaludables::getMenu() {
  return menu;
}

//Recursivo
  
int problemaMenusSaludables::resolverRecursivo(int nPlatos, int umbralMaximo) {
  //cout << "nPlatos" << nPlatos << " umbral: " << umbralMaximo << endl;
  if(nPlatos == 0 || umbralMaximo == 0)
    return 0;
  
  if (getMenu() -> getPlatosDisponibles().at(nPlatos).getPuntuacion() > umbralMaximo)
    return resolverRecursivo(nPlatos -1, umbralMaximo);
  
  else
    return max(
      resolverRecursivo(nPlatos - 1, umbralMaximo), 
      resolverRecursivo(nPlatos - 1, umbralMaximo - getMenu()->getPlatosDisponibles().at(nPlatos).getPuntuacion()) + getMenu()->getPlatosDisponibles().at(nPlatos).getValorNutricional());
}

//Utilizado para el TopDown

int problemaMenusSaludables::resolverTopDown(int nPlatos, int umbralMaximo) {
  
  if(nPlatos == 0 && umbralMaximo == 0)
    return 0;
  
  if (getMenu() -> getPlatosDisponibles().at(nPlatos).getPuntuacion() > umbralMaximo) {
    setDatoMatriz(nPlatos, umbralMaximo, resolverTopDown(nPlatos - 1, umbralMaximo));
    cout << "Estoy en el if" << endl;
  }
  
  else {
    setDatoMatriz(nPlatos, umbralMaximo, 
		  max(resolverRecursivo(nPlatos - 1, umbralMaximo), 
		      resolverRecursivo(nPlatos - 1, umbralMaximo - getMenu()->getPlatosDisponibles().at(nPlatos).getPuntuacion()) + getMenu()->getPlatosDisponibles().at(nPlatos).getValorNutricional()));
    cout << "Estoy en el else" << endl;
  }

  return getDatoMatriz(nPlatos, umbralMaximo);
}
/*
void problemaMenusSaludables::resolverBottomUp(int nPlatos, int umbralMaximo){
    for(int j = 0; j < getMenu()->getPlatosDisponibles().at(nPlatos).getPuntuacion(); j++)
        setDatoMatriz(0, j, 0); //valor introducido 0
    cout << "HOLA" << endl;
    for(int i = 0; i < getMenu()->getPlatosDisponibles().at(nPlatos).getValorNutricional(); i++)
        for(int j = 0; j < getMenu()->getPlatosDisponibles().at(nPlatos).getPuntuacion(); j++) 
            if(getMenu()->getPlatosDisponibles().at(i).getPuntuacion() <= j) {
                cout << "SII" << endl;
                setDatoMatriz(i, j, 
                              max(getDatoMatriz(i - 1, j), 
                                  getDatoMatriz(i - 1, 
                                                j - getMenu()->getPlatosDisponibles().at(i).getPuntuacion()) + getMenu()->getPlatosDisponibles().at(i).getValorNutricional())); 
            }else {
                cout << "NO" << endl;
                setDatoMatriz(i, j, getDatoMatriz(i - 1, j));
            }
}*/
    

void problemaMenusSaludables::mostrarMatriz() {
    for(int i = 0; i <= getMenu()->getNumPlatosDisponibles(); i++) {
        cout << endl;
        for(int j = 0; j <= getMenu()->getUmbralMaximo(); j++)
            cout << matriz[i][j] << " ";
    }
}

int problemaMenusSaludables::getDatoMatriz(int i, int j) {
    return matriz[i][j];
}

void problemaMenusSaludables::setDatoMatriz(int i, int j, int dato) {
    cout << "Metiendo dato: " << dato << endl;
    matriz[i][j] = dato;
}
