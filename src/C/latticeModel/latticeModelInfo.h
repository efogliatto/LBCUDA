#ifndef LATTICEMODELINFO_H
#define LATTICEMODELINFO_H

/**
 * @file latticeModelInfo.h
 * @author Ezequiel O. Fogliatto
 * @date 14 Feb 2020
 * @brief Información sobre el modelo de grilla
 */


#include <dataTypes.h>

typedef enum {
    D2Q9,
    D3Q15
} DdQq;

typedef struct {

    
    /** Modelo de grilla general */
    
    DdQq model;
    

    /** Dimension */

    uint d;


    /** Cantidad de vecinos */

    uint q;


    /** Velocidad del sonido */

    scalar cs2;
    

    /** Velocidades de grilla */

    int* vel;


    /** Direcciones inversas */

    int* reverse;


    /** Matriz de transformacion MRT */

    scalar* M;


    /** Inversa de matriz de transformacion MRT */

    scalar* invM;
    

} latticeModelInfo;


#endif // LATTICEMODELINFO_H
