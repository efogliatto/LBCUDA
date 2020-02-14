#ifndef CUDALATTICEMODELINFO_H
#define CUDALATTICEMODELINFO_H

/**
 * @file cudaLatticeModelInfo.h
 * @author Ezequiel O. Fogliatto
 * @date 14 Feb 2020
 * @brief Información sobre el modelo de grilla
 */


#include <dataTypes.h>

#include <latticeModelInfo.h>


typedef struct {

    
    /** Modelo de grilla general */
    
    DdQq model;
    

    /** Dimension */

    uint d;


    /** Cantidad de vecinos */

    uint q;
    

    /** Velocidades de grilla */

    int* vel;


    /** Direcciones inversas */

    int* reverse;


    /** Matriz de transformacion MRT */

    cuscalar* M;


    /** Inversa de matriz de transformacion MRT */

    cuscalar* invM;
    

} cudaLatticeModelInfo;


#endif // CUDALATTICEMODELINFO_H
