#include "problemaMenusSaludables.h"
#define INF 99999

problemaMenusSaludables::problemaMenusSaludables(string nombreFichero) {
  menu =  new CMenu(nombreFichero);
  //cout << "La solucion es: " << resolverRecursivo(getMenu()->getNumPlatosDisponibles() - 1, getMenu()->getUmbralMaximo());
  matriz = new int*[getMenu()->getNumPlatosDisponibles()];
  for(int i = 0; i < getMenu()->getNumPlatosDisponibles(); i++)
      matriz[i] = new int[getMenu()->getUmbralMaximo()];
  
  for(int i = 0; i < getMenu()->getNumPlatosDisponibles(); i++)
      for(int j = 0; j < getMenu()->getUmbralMaximo(); j++)
        matriz[i][j] = -1;
  //cout << "La solucion es: " << 
  resolverBottomUp(getMenu()->getNumPlatosDisponibles() - 1, getMenu()->getUmbralMaximo() - 1);
  mostrarMatriz();
}

CMenu* problemaMenusSaludables::getMenu() {
  return menu;
}

int problemaMenusSaludables::resolverRecursivo(int nPlatos, int umbralMaximo) {
  cout << "Datos : " << nPlatos << " " << umbralMaximo << endl;
  if(nPlatos == 0 && umbralMaximo >= 0)
    return 0;
  
  if (umbralMaximo < 0) {//no deberia ocurrir nunca
    cout << "No deberia ocurrir nunca" << endl;
    return -INF;
  }
  
  v1 = resolverRecursivo(nPlatos - 1, umbralMaximo);
  v2 = resolverRecursivo(nPlatos - 1, umbralMaximo - getMenu()->getPlatosDisponibles().at(nPlatos).getPuntuacion()) + getMenu()->getPlatosDisponibles().at(nPlatos).getValorNutricional();
  cout << "v1 y v2 vale: " << v1 << " " << v2 << endl;
  return max(v1, v2);
}


//Utilizado para el TopDown
int problemaMenusSaludables::resolverTopDown(int nPlatos, int umbralMaximo) {
    cout << "Datos : " << nPlatos << " " << umbralMaximo << endl;
    if(nPlatos == 0 && umbralMaximo >= 0)
        return 0;
    
    if (umbralMaximo < 0) {//no deberia ocurrir nunca
        cout << "No deberia ocurrir nunca" << endl;
        return -INF;
    }
    if(getDatoMatriz(nPlatos, umbralMaximo) != -1) {
        cout << "PEPE" << getDatoMatriz(nPlatos, umbralMaximo);
        return getDatoMatriz(nPlatos, umbralMaximo);
    }
    
    v1 = resolverTopDown(nPlatos - 1, umbralMaximo);
    v2 = resolverTopDown(nPlatos - 1, umbralMaximo - getMenu()->getPlatosDisponibles().at(nPlatos).getPuntuacion()) + getMenu()->getPlatosDisponibles().at(nPlatos).getValorNutricional();
    cout << "v1 y v2 vale: " << v1 << " " << v2 << endl;
    setDatoMatriz(nPlatos, umbralMaximo, max(v1, v2)); //pos i j y dato
}

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
}
    

void problemaMenusSaludables::mostrarMatriz() {
    for(int i = 0; i < getMenu()->getNumPlatosDisponibles(); i++) {
        cout << endl;
        for(int j = 0; j < getMenu()->getUmbralMaximo(); j++)
            cout << matriz[i][j] << " ";
    }
}

int problemaMenusSaludables::getDatoMatriz(int i, int j) {
    int aux = matriz[i][j];
    return aux;
}

void problemaMenusSaludables::setDatoMatriz(int i, int j, int dato) {
    matriz[i][j] = dato;
}
