#ifndef CUDAEXAMPLEDENSITY_H
#define CUDAEXAMPLEDENSITY_H

/**
 * @file cudaExampleDensity.h
 * @author Ezequiel O. Fogliatto
 * @date 19 Feb 2020
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


extern "C" __global__ void cudaExampleDensity(cuscalar* field, cuscalar* rho, int np, int Q );


#endif // CUDAEXAMPLEDENSITY_H
