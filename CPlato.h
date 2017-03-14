/** Ivan Garcia Campos   alu0100693737@ull.edu.es
 * 14/03/2017
 * Diseño y Análisis de Algoritmos
 * 1.0v 
 * A mayor puntuacion, el plato es menos saludable, pudiendo
 * ser un plato muy nutritivo pero poco saludable
 */

#ifndef _CPLATO_H
#define _CPLATO_H
#include <iostream>
using namespace std;

class CPlato {
  private:
    string nombrePlato;
    unsigned int valorNutricional; //valor nutricional del plato
    unsigned int puntuacion; //contenido en nutrientes
    
  public:
    CPlato(string, int, int); // nombre del plato, valor nutricional y puntuacion
    ~CPlato();
    string getNombrePlato(); //devuelve el nombre del plato
    int getValorNutricional(); //devuelve el valor nutricional del plato
    int getPuntuacion(); //devuelve el contenido de nutrientes del plato
    void mostrarPlato(); //Muestra todos los datos de la clase, nombrePlato, valorNutricional y puntuacion
};

#endif