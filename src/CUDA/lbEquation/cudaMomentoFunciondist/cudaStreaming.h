#ifndef CUDASTREAMING_H
#define CUDASTREAMING_H

/**
 * @file cudaStreaming.h
 * @author Thomás Coronel
 * @date 20 Feb 2020
 * @brief C\'alculo de densidad para arreglo unidimensional
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


extern "C" __global__ void cudaStreaming(cuscalar* field, cuscalar* swap, int* nb, int np, int Q );


#endif // CUDASTREAMING_H
