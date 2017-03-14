#include "CMenu.h"

CMenu::CMenu(string nombreFichero) {
  leerFichero(nombreFichero);
}

CMenu::~CMenu(){}


void CMenu::leerFichero(string nombreFichero) {
  
    //convertimos a char* y leemos el fichero
    ifstream in(nombreFichero.c_str());
    
    if(!in) {
        cout << "\n\t\t*No se pudo abrir el fichero indicado" << endl;
    }else { //guardamos el numero de platos y el umbral maximo
	in >> value;
        numPlatosDisponibles = value;
	in >> value;
	umbralMaximo = value;
	string nombre; int nutrientes, puntuacion;
	for(int i = 0; i < numPlatosDisponibles; i++) {
	  in >> nombre;
	  in >> nutrientes;
	  in >> puntuacion;
	  CPlato* aux = new CPlato(nombre, nutrientes, puntuacion);
	  getPlatosDisponibles().add(aux);
	}
        /*tima linea, eliminamos
        getVectorInstrucciones().pop_back(); getVectorDireccionamientos().pop_back();
    }*/
}

vector<CPlato> CMenu::getPlatosDisponibles() {
  return platosDisponibles;
}