#ifndef CUDAVECTORDIVERGENCE_H
#define CUDAVECTORDIVERGENCE_H

/**
 * @file cudaVectorDivergence.h
 * @author Ezequiel Fogliatto
 * @date 14 Apr 2020
 * @brief Divergencia de campo vectorial sobre nodo
 */

/**
 * Divergencia de campo vectorial sobre nodo
 *
 * @param d Divergencia
 * @param field Campo vectorial
 * @param nb Arreglo de vecinos
 * @param id Nodo sobre el cual se desea calcular la divergencia de field
 * @param Q Cantidad de vecinos
 */


#include <dataTypes.h>

#include <cudaLatticeMesh.h>

extern "C" __device__ void cudaVectorDivergence( cuscalar* d, cuscalar* field, int* nb, uint id, uint Q );

#endif // CUDAVECTORDIVERGENCE_H
