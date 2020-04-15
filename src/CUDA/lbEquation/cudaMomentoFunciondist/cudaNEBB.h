#ifndef CUDANEBB_H
#define CUDANEBB_H

/**
 * @file cudaNEBB.h
 * @author Ezequiel Fogliatto
 * @date 15 Apr 2020
 * @brief Condición de no deslizamiento
 */

/**
 * Condición de contorno de no deslizamiento
 *
 * @param field Campo a colisionar
 */


#include <dataTypes.h>

#include <cudaLatticeMesh.h>

extern "C" __global__ void cudaNEBB( cuscalar* field,
				     cuscalar* Ft,
				     int* bdPoints,
				     uint bid,
				     uint bndNormal,
				     uint maxNbd,
				     uint Q );

#endif // CUDANEBB_H
