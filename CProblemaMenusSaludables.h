#include "CMenu.h"
#include <algorithm>    // std::max
#include <iostream>

/*
 * Dado un conjunto de platos predeterminado, cada uno de ellos con un  valor
 * nutricional(entero positivo) asociado, se desea crear un menú cuyo valor
 * nutricional sea máximo dado un umbral maximo. Los platos no se pueden racionar.
 * Los platos cuentan con un formato:
 * Nombre, valor nutricional y puntuacion.*/
class CProblemaMenusSaludables {
private:
    CMenu* menu;
    int** matriz;//matriz que almacena soluciones parciales para resolver el problema de menus saludables, utilizado en topdown y bottom up

    /**
         * @brief Método que retorna el dato que se desee de matriz
         * @param  int i, valor en la fila, int j, valor en la columna
         * @return int dato de la matriz
         */
    int getDatoMatriz(int i, int j);
    /**
         * @brief Método que guarda un valor en la posicion de matriz que se desee
         * @param  int i, valor en la fila, int j, valor en la columna, int dato, valor a introducir
         * @return int dato de la matriz
         */
    void setDatoMatriz(int i, int j, int dato); //pos i j y dato*/
    
public:
    /**
         * @brief Constructor que se encarga de inicializar el menu que llama al fichero especificado por parametro
         * @param string nombre del fichero a leer
         */
    CProblemaMenusSaludables(string nombreFichero);
    /**
         * @brief Destructor
         */
    ~CProblemaMenusSaludables();
    
    /**
         * @brief Metodo que devuelve el menu con los platos disponibles
         * @return CMenu* menu
         */
    CMenu* getMenu();

    /**
         * @brief Metodo recursivo para resolver el problema de menus saludables
         * @param numero de platos y umbral maximo
         * @return int valor maximo estrategia recursiva
         */
    int resolverRecursivo(int, int);

    /**
         * @brief Metodo Top Down para resolver el problema de menus saludables
         * @param numero de platos y umbral maximo
         * @return int valor maximo estrategia top down
         */
    int resolverTopDown(int nPlatos, int umbralMaximo);//estrategia top down
    
    
    /**
         * @brief Metodo Bottom up para resolver el problema de menus saludables
         * @param numero de platos y umbral maximo
         * @return int valor maximo estrategia bottom up
         */
    void resolverBottomUp(int nPlatos, int umbralMaximo);//estrategia bottom up
    
    /**
         * @brief Metodo para la reconstruccion de la solucion del algoritmo top down y bottom up
         * @param numero de platos y umbral maximo
         */
    void reconstruccionSolucion(int nPlatos, int umbralMaximo);
    
    /**
         * @brief Metodo para mostrar la matriz
         */
    void mostrarMatriz();
};
