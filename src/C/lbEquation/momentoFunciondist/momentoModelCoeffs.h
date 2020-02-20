#ifndef MOMENTOMODELCOEFFS_H
#define MOMENTOMODELCOEFFS_H

/**
 * @file momentoModelCoeffs.h
 * @author Ezequiel O. Fogliatto
 * @date 19 Feb 2020
 * @brief Coeficientes para modelo de ejemplo
 */

#include <dataTypes.h>

typedef struct {

    /** Coeficientes de relajacion */

    scalar Tau[9];    
    

} momentoModelCoeffs;


#endif // MOMENTOMODELCOEFFS_H
