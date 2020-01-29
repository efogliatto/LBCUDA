#ifndef NBREDUCTION_H
#define NBREDUCTION_H

/**
 * @file nbReduction.h
 * @author Ezequiel O. Fogliatto
 * @date 28 Ene 2020
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


__global__ void nbReduction(cuscalar* field, cuscalar* sum, int* nb, uint np, uint Q );


#endif // NBREDUCTION_H
