#ifndef CUDAMOMENTOVELOCITY_H
#define CUDAMOMENTOVELOCITY_H

/**
 * @file cudaMomentoVelocity.h
 * @author Thomas Coronel
 * @date 20 Feb 2020
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
 * @param delta_t Paso de tiempo
 */

#include <dataTypes.h>

#include <cudaBasicMesh.h>


extern "C" __global__ void cudaMomentoVelocity(cuscalar* field, cuscalar* rho, cuscalar* U, cuscalar* lvel, int np, int Q, cuscalar delta_t );


#endif // CUDAMOMENTOVELOCITY_H
