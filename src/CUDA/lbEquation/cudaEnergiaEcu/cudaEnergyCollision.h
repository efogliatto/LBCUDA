#ifndef CUDAENERGYCOLLISION_H
#define CUDAENERGYCOLLISION_H

/**
 * @file cudaEnergyCollision.h
 * @author Thomás Coronel
 * @date 24 Mar 2020
 * @brief Colisión de la ecuación de energía.
 */

/**
 * Colision MRT
 *
 * Colisión en todos los nodos de la grilla, actualizando @p field por los valores de post-colisión de la ecuación de energía
 *
 * \f $ \mathbf{g^*}(\mathbf{x},t) = \mathbf{M}^{-1} \left[ \mathbf{n} - \mathbf{Q}(\mathbf{n} - \mathbf{n}^{(eq)}) + \delta_{t} \left( I - 0,5 Q \right) \hat{\Gamma}  \right]_{(\mathbf{x},t)} \f$
 *
 * @param field Campo a colisionar
 * @param gamma_0 Primer término de la fuente de espacios de momentos
 * @param relax Coeficientes de relajación ertenecientes a la diagonal de la matriz Q
 * @param delta_t Paso de tiempo
 * @param np Número de puntos
 * @param Q Cantidad de vecinos 
 * @param lvel Velocidades de grilla
 * @param nb Matriz de vecinos
 * @param Tau Factores de relajación (diagonal de la matriz Q)
 */


#include <dataTypes.h>

#include <cudaLatticeMesh.h>


extern "C" __global__ void cudaEnergyCollision( cuscalar* field,
						cuscalar* U,
						cuscalar* T,
						cuscalar* gamma_0,
                                                cuscalar* Tau,
						cuscalar  alpha_1,
						cuscalar  alpha_2,
						uint Q,
						uint np,
						cuscalar* M,
						cuscalar* invM ) ;

#endif // CUDAENERGYCOLLISION_H
