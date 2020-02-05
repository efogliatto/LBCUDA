#ifndef THOMASREDUCTION_H
#define THOMASREDUCTION_H

/**
 * @file nbReduction.h
 * @author Thomas Coronel
 * @date 5 Feb 2020
 * @brief C\'alculo de momento de orden cero en vecinos y suma en nodo local
 */


/**
 * C\'alculo de momento de orden cero en vecinos y suma en nodo local
 * @param field Arreglo unidimensional de la funcion de distribucion
 * @param sum Arreglo unidimensional resultante
 * @param mesh Malla
 */

#include <dataTypes.h>

#include <cudaBasicMesh.h>


extern "C" __global__ void thomasReduction(cuscalar* field, cuscalar* sum, int* nb, int np, int Q );


#endif // THOMASREDUCTION_H
