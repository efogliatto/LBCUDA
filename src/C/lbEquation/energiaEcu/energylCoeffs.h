#ifndef ENERGYCOEFFS_H
#define ENERGYCOEFFS_H

/**
 * @file energyCoeffs.h
 * @author Thomas Coronel
 * @date 12 Mar 2020
 * @brief Coeficientes de relajacion diagonal para la ecuacion de energia
 */

#include <dataTypes.h>

typedef struct {

    /** Coeficientes de relajacion */

    scalar Tau[9];    
    

} energyCoeffs;


#endif // ENERGYCOEFFS_H
