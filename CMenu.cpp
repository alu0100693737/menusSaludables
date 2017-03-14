#include "CMenu.h"
#include <stdlib.h>

CMenu::CMenu(string nombreFichero) {
  leerFichero(nombreFichero);
}

CMenu::~CMenu(){}


void CMenu::leerFichero(string nombreFichero) {
    int value;
    //convertimos a char* y leemos el fichero
    ifstream in(nombreFichero.c_str());
    
    if(!in) {
        cout << "\n\t\t*No se pudo abrir el fichero indicado" << endl;
    }else { //guardamos el numero de platos y el umbral maximo
	in >> value;
        numPlatosDisponibles = value;      //asignamos el numero de platos que contiene el fichero
	in >> value;
	umbralMaximo = value;		//asignamos el umbral maximo de nutrientes que puede tener el menu
	string nombre; int nutrientes, puntuacion;
	char* aux;
	for(int i = 0; i < numPlatosDisponibles; i++) {
	  in >> nombre;
	  in >> aux;
	  if('0' <= atoi(aux) && aux <= '9') 
	    nutrientes = atoi(aux);
	  else {
	    nombre.append(aux);
	  }
	  in >> nutrientes;
	  in >> puntuacion;
	  CPlato aux(nombre, nutrientes, puntuacion);
	  getPlatosDisponibles().push_back(aux);
	}  
    }
}

int CMenu::getUmbralMaximo() {
  return umbralMaximo;
}

int CMenu::getNumPlatosDisponibles() {
  return numPlatosDisponibles;
}

vector<CPlato>& CMenu::getPlatosDisponibles() {
  return platosDisponibles;
}

void CMenu::mostrarPlatosDisponibles() {
  cout << "\n\t\t\tPLATOS DISPONIBLES\n\n";
  for(int i = 0; i< getPlatosDisponibles().size(); i++) {
    getPlatosDisponibles().at(i).mostrarPlato();
  }
}