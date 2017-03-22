#include "CMenu.h"
#include <stdlib.h>
#include <cstring>
#include <sstream>

CMenu::CMenu(string nombreFichero) {
   CPlato aux("Plato Vacio", 0, 0);
  getPlatosDisponibles().push_back(aux);
  leerFichero(nombreFichero);
}

CMenu::~CMenu(){}

void CMenu::leerFichero(string nombreFichero) {
  
    fstream ficheroEntrada;
    
    ficheroEntrada.open ( nombreFichero.c_str() , ios::in);
    if (ficheroEntrada.is_open()) {
	ficheroEntrada >> numPlatosDisponibles;
	ficheroEntrada >> umbralMaximo;
	
	cout << "Num platos: " << getNumPlatosDisponibles() << " Umbral: " << getUmbralMaximo() << endl;
	//Se permiten platos con mas de una palabra: ej: carne fiesta
	vector<string> palabras; //palabras de la linea
	string linea;
	
	for(int i = 0; i < numPlatosDisponibles; i++) {
	  
	    //leemos la linea y separamos por espacios introduciendo en el vector palabras
            getline(ficheroEntrada, linea);
	    
	    while(linea.size() == 0) 
	      getline(ficheroEntrada, linea);
	    
	    string word;
	    istringstream iss(linea);
	    while(iss >> word) {
	      palabras.push_back(word);
	    }
	    
	    //si son 3 palabras: nombre, valor nutricional y contenido nutrientes
	    //si son mas de 3 palabras el nombre del plato contendrá más de una palabra. Hay que tratarlo. Ej: Carne Fiesta 180 50
	    if(palabras.size() == 3) {
	      CPlato aux(palabras.at(0), atoi(palabras.at(1).c_str()), atoi(palabras.at(2).c_str()));
	      getPlatosDisponibles().push_back(aux);
	    }else {
	      string nombrePlato;
	      for(int i = 0; i < palabras.size() - 2; i++)
		nombrePlato += palabras.at(i) + " ";
	      CPlato aux(nombrePlato, atoi(palabras.at(palabras.size() - 2).c_str()), atoi(palabras.at(palabras.size() - 1).c_str()));
	      getPlatosDisponibles().push_back(aux);
	    }
	    palabras.clear();
        }

        ficheroEntrada.close();
    }
    else cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;  
    mostrarPlatosDisponibles();
}

int& CMenu::getUmbralMaximo() {
  return umbralMaximo;
}

int& CMenu::getNumPlatosDisponibles() {
  return numPlatosDisponibles;
}

vector<CPlato>& CMenu::getPlatosDisponibles() {
  return platosDisponibles;
}

void CMenu::mostrarPlatosDisponibles() {
  cout << "\n\t\t\tPLATOS DISPONIBLES\n\n";
  for(int i = 1; i< getPlatosDisponibles().size(); i++) {
    getPlatosDisponibles().at(i).mostrarPlato();
  }
}