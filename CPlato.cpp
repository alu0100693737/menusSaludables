#include "CPlato.h"
#include <iostream>
using namespace std;

CPlato::CPlato(string nombre, int valornutricional, int punt) {
  
  nombrePlato = nombre;
  valorNutricional = valornutricional;
  puntuacion = punt;
  
}

CPlato::~CPlato() {}

string CPlato::getNombrePlato() {
  return nombrePlato;
}

int CPlato::getValorNutricional() {
  return valorNutricional;
}

int CPlato::getPuntuacion() {
  return puntuacion;
}

void CPlato::mostrarPlato() {
  cout << "Plato: " << getNombrePlato() << "\t\tValor nutricional: " << getValorNutricional() << "\t\tContenido en nutrientes " << getPuntuacion() << endl;
}