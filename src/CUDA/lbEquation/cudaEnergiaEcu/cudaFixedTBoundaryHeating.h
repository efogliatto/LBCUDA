#ifndef CUDAFIXEDTBOUNDARYHEATING_H
#define CUDAFIXEDTBOUNDARYHEATING_H

/**
 * @file cudaFixedTBoundaryHeating.h
 * @author Thomás Coronel
 * @date 15 May 2020
 * @brief Condición de contorno de temperatura fija y con una temperatura de calefacción 
 */

/**
 * Condición de contorno para temperatura fija
 *
 * @param field Campo a colisionar
 * @param bdval condición de temperatura fija en toda la superficies
 * @param bdheat condicion de temperatura fija, para simular una calefacción
 */


#include <dataTypes.h>

#include <cudaLatticeMesh.h>

extern "C" __global__ void cudaFixedTBoundaryHeating( cuscalar* field,
					       cuscalar* T,
					       cuscalar* U,
					       int* bdPoints,
					       int* nb,
					       cuscalar* invM,
					       cuscalar alpha_1,
					       cuscalar alpha_2,
						   cuscalar bdval,
						   cuscalar bdheat,
						   uint widthbd,
					       uint bid,
                           uint nbd,
					       uint maxNbd,
					       uint Q ) {

#endif // CUDAFIXEDTBOUNDARYHEATING_H
