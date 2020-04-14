#ifndef CUDAEXAMPLEVELOCITY_H
#define CUDAEXAMPLEVELOCITY_H

/**
 * @file cudaExampleVelocity.h
 * @author Ezequiel O. Fogliatto
 * @date 19 Feb 2020
 * @brief C\'alculo de velocidad para arreglo unidimensional
 */


/**
 * C\'alculo de densidad para arreglo unidimensional
 * @param field Arreglo unidimensional de la funcion de distribucion
 * @param rho Arreglo unidimensional para densidad macroscópica
 * @param U Arreglo unidimensional para velocidad macroscópica
 * @param lvel Velocidades de grilla
 * @param np Cantidad de puntos
 * @param Q Cantidad de vecinos
 */

#include <dataTypes.h>

#include <cudaBasicMesh.h>


extern "C" __global__ void cudaExampleVelocity(cuscalar* field, cuscalar* rho, cuscalar* U, int* lvel, int np, int Q );


#endif // CUDAEXAMPLEVELOCITY_H
