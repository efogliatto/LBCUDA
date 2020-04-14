#ifndef CUDASCALARGRADIENT_H
#define CUDASCALARGRADIENT_H

/**
 * @file cudaScalarGradient.h
 * @author Ezequiel Fogliatto
 * @date 14 Apr 2020
 * @brief Gradiente de campo escalar sobre nodo
 */

/**
 * Gradiente de campo escalar sobre nodo
 *
 * @param g Gradiente
 * @param field Campo escalar
 * @param nb Arreglo de vecinos
 * @param id Nodo sobre el cual se desea calcular el gradiente de field
 * @param Q Cantidad de vecinos
 */


#include <dataTypes.h>

#include <cudaLatticeMesh.h>

extern "C" __device__ void cudaScalarGradient( cuscalar g[3], cuscalar* field, int* nb, uint id, uint Q );

#endif // CUDASCALARGRADIENT_H
