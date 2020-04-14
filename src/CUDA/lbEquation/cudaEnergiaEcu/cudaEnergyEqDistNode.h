#ifndef CUDAENERGYEQDISTNODE_H
#define CUDAENERGYEQDISTNODE_H

/**
 * @file cudaEnergyEqDistNode.h
 * @author Ezequiel Fogliatto
 * @date 14 Apr 2020
 * @brief Distribucion de equilibrio por nodo
 */

/**
 * Distribucion de equilibrio por nodo
 *
 * @param field Campo a colisionar
 */


#include <dataTypes.h>

#include <cudaLatticeMesh.h>

extern "C" __device__ void cudaEnergyEqDistNode( cuscalar* eq,
						 cuscalar* T,
						 cuscalar* U,
						 uint id,
						 uint Q,
						 cuscalar* invM,
						 cuscalar alpha_1,
						 cuscalar alpha_2 );

#endif // CUDAENERGYEQDISTNODE_H
