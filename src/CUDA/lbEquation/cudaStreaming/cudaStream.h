#ifndef CUDASTREAM_H
#define CUDASTREAM_H

/**
 * @file cudaStream.h
 * @author Ezequiel O. Fogliatto
 * @date 07 May 2020
 * @brief Streaming a nodos vecinos
 */


/**
 * C\'alculo de densidad para arreglo unidimensional
 * @param field Arreglo unidimensional de la funcion de distribucion
 * @param rho Arreglo unidimensional resultante
 * @param np Cantidad de puntos
 * @param Q Cantidad de vecinos
 */

#include <dataTypes.h>

#include <cudaBasicMesh.h>


extern "C" __global__ void cudaStream(cuscalar* field, cuscalar* swap, int* nb, int np, int Q );


#endif // CUDASTREAM_H
