#ifndef CUDAENERGYCOEFFS_H
#define CUDAENERGYCOEFFS_H

/**
 * @file cudaEnergyCoeffs.h
 * @author Thomás Coronel
 * @date 24 Mar 2020
 * @brief Coeficientes de relajacion diagonal para la ecuacion de energia
 */

#include <dataTypes.h>

typedef struct {

    /** Coeficientes de relajacion */

    cuscalar Tau[9];    
    

} cudaEnergyCoeffs;


#endif // CUDAENERGYCOEFFS_H
