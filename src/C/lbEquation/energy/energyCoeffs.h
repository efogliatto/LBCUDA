#ifndef ENERGYCOEFFS_H
#define ENERGYCOEFFS_H

/**
 * @file energyCoeffs.h
 * @author Thomás Coronel
 * @date 12 Mar 2020
 * @brief Coeficientes de relajacion diagonal para la ecuacion de energia
 */

#include <dataTypes.h>

typedef struct {

    /** Coeficientes de relajacion */

    scalar Tau[9];


    /** Constantes libres para la distribucion en espacio de momento */

    scalar alpha_1;

    scalar alpha_2;


    /** Calor especifico */

    scalar Cv;
    

} energyCoeffs;


#endif // ENERGYCOEFFS_H
