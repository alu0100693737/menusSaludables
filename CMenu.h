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
#include "CPlato.h"

using namespace std;

class CMenu {
private:
    vector<CPlato> platosDisponibles; //Vector de platos, leido desde fichero
    int numPlatosDisponibles; //numero de platos almacenados
    int umbralMaximo; //maximo contenido en nutrientes permitido
    /**
         * @brief Método que lee desde fichero los platos que se desean almacenar
         * @param nombre del fichero
         */
    void leerFichero(string nombreFichero);
public:
    CMenu(string nombreFichero); //fichero con los tipos de plato disponibles en formato nombre, valor nutricional y puntuacion
    /**
         * @brief Destructor
         */
    ~CMenu();
    
    /**
         * @brief Método que retorna el umbral maximo permitido
         * @return int umbral maximo
         */
    int& getUmbralMaximo();
    /**
         * @brief Método que retorna el numero de platos almacenados
         * @return int umbral maximo
         */
    int& getNumPlatosDisponibles();
    /**
         * @brief Método que retorna el vector de platos de tipo CPlato
         * @return vector< CPlato > & platos disponibles
         */
    vector<CPlato>& getPlatosDisponibles();
    /**
         * @brief Método que muestra todos los platos disponibles, nombre, valor nutricional y puntuacion
         */
    void mostrarPlatosDisponibles();
};
#endif
