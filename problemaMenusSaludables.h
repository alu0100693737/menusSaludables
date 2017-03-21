#include "CMenu.h"
#include <algorithm>    // std::max
#include <iostream>

/*
 * Dado un conjunto de platos predeterminado, cada uno de ellos con un  valor
 * nutricional(entero positivo) asociado, se desea crear un menú cuyo valor
 * nutricional sea máximo dado un umbral maximo. Los platos no se pueden racionar.
 * Los platos cuentan con un formato:
 * Nombre, valor nutricional y puntuacion.*/
class problemaMenusSaludables {
  private:
    CMenu* menu;
    int v1, v2; //estrategia recursiva
    int** matriz;//estrategia top down
    int maximoRecursivo;
    
    int getDatoMatriz(int i, int j);
    void setDatoMatriz(int i, int j, int dato); //pos i j y dato
    
  public:
    problemaMenusSaludables(string nombreFichero);
    CMenu* getMenu();
    
    void solucionRecursiva(int, int);
    int resolverRecursivo(int, int); // O(n²) //parametros: numero de platos disponible y umbral maximo
    int getMaximoRecursivo();
    //resolver TopDown
    int resolverTopDown(int nPlatos, int umbralMaximo);//estrategia top down
    void mostrarMatriz();
    
    void resolverBottomUp(int nPlatos, int umbralMaximo);//estrategia bottom up
};
