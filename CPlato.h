///////////////////////////////////////////////////////////////
//  CPlato.h       - Delaracion de la clase CPlato           //
//                                                           //
//      Autor:   Iván García Campos                          //
//                                                           //
//               Fecha: 25/03/2017                           //
///////////////////////////////////////////////////////////////

/**
 * A mayor puntuacion, el plato es menos saludable, pudiendo
 * ser un plato muy nutritivo pero poco saludable
 */

#ifndef _CPLATO_H
#define _CPLATO_H
#include <iostream>
using namespace std;
/**Clase para la definicion de platos con nombre, su valor nutricional y su contenido en nutrientes (puntuacion)*/
class CPlato {
private:
    string nombrePlato;             //nombre del plato
    unsigned int valorNutricional;  //valor nutricional del plato
    unsigned int puntuacion;        //contenido en nutrientes
    
public:
    /**
         * @brief Constructor que asigna un nombre, un valor nutricional y una puntuacion
         * @param size Tamaño del vector
         */
    CPlato(string, int, int);
    /**
         * @brief Destructor
         */
    ~CPlato();
    /**
         * @brief Método que retorna el nombre del plato
         * @return string nombrefichero
         */
    string getNombrePlato();
    /**
         * @brief Método que retorna el valor nutricional del plato
         * @return int valor nutricional
         */
    int getValorNutricional();
    /**
         * @brief Método que retorna la puntuacion, contenido en nutrientes
         * @return int valor nutricional, puntuacion
         */
    int getPuntuacion();
    /**
         * @brief Método que muestra el nombre, valor nutricional y puntuacion del plato

         */
    void mostrarPlato();
};

#endif
