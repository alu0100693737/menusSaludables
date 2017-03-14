/** Ivan Garcia Campos   alu0100693737@ull.edu.es
 * 14/03/2017
 * Diseño y Análisis de Algoritmos
 * 1.0v 
 * Clase para la elaboracion de un menu optimo con un máximo contenido de nutrientes
 */

#ifndef _CMENU_H
#define _CMENU_H
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class CMenu {
  private:
    vector<CPlato> platosDisponibles;
    int numPlatosDisponibles;
    int umbralMaximo;
    void leerFichero(string nombreFichero);
  public:
    CMenu(string nombreFichero); //fichero con los tipos de plato disponibles en formato nombre, valor nutricional y puntuacion
    ~CMenu();
    
    vector<CPlato> getPlatosDisponibles(); 
};
#endif