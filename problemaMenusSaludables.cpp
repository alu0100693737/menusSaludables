#include "problemaMenusSaludables.h"
#define INF 99999

problemaMenusSaludables::problemaMenusSaludables(string nombreFichero) {
  menu =  new CMenu(nombreFichero);
  cout << "La solucion es: " << resolverRecursivo(getMenu()->getNumPlatosDisponibles() - 1, getMenu()->getUmbralMaximo());
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