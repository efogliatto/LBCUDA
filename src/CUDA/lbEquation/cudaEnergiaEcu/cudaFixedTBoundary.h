#ifndef CUDAFIXEDTBOUNDARY_H
#define CUDAFIXEDTBOUNDARY_H

/**
 * @file cudaFixedTBoundary.h
 * @author Ezequiel Fogliatto
 * @date 14 Apr 2020
 * @brief Condición de contorno de temperatura fija
 */

/**
 * Condición de contorno para temperatura fija
 *
 * @param field Campo a colisionar
 */


#include <dataTypes.h>

#include <cudaLatticeMesh.h>

extern "C" __global__ void cudaFixedTBoundary( cuscalar* field,
					       cuscalar* T,
					       cuscalar* U,
					       int* bdPoints,
					       int* nb,
					       cuscalar* invM,
					       cuscalar alpha_1,
					       cuscalar alpha_2,
					       cuscalar bdval,
					       uint bid,
                                               uint nbd,
					       uint maxNbd,
					       uint Q );

#endif // CUDAFIXEDTBOUNDARY_H
