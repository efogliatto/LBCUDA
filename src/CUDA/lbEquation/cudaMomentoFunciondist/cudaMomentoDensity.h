#ifndef CUDAMOMENTODENSITY_H
#define CUDAMOMENTODENSITY_H

/**
 * @file cudaMomentoDensity.h
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


extern "C" __global__ void cudaMomentoDensity(cuscalar* field, cuscalar* rho, int np, int Q );


#endif // CUDAMOMENTODENSITY_H
