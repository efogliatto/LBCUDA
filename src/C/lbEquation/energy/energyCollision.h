#ifndef ENERGYCOLLISION_H
#define ENERGYCOLLISION_H

/**
 * @file energyCollision.h
 * @author Thomás Coronel
 * @date 23 Mar 2020
 * @brief Colisión de la ecuación de energía.
 */

/**
 * Colision MRT
 *
 * Colisión en todos los nodos de la grilla, actualizando @p field por los valores de post-colisión de la ecuación de energía
 *
 * \f $ \mathbf{g^*}(\mathbf{x},t) = \mathbf{M}^{-1} \left[ \mathbf{n} - \mathbf{Q}(\mathbf{n} - \mathbf{n}^{(eq)}) + \delta_{t} \left( I - 0,5 Q \right) \hat{\Gamma}  \right]_{(\mathbf{x},t)} \f$
 *
 * @param mesh Estructura basica de grilla
 * @param field Campo a colisionar
 * @param gamma_0 Primer término de la fuente de espacios de momentos
 * @param T Temperatura macroscópica
 * @param U Velocidad
 * @param relax Coeficientes de relajación ertenecientes a la diagonal de la matriz Q
 * @param delta_t Paso de tiempo
 */


#include <basicMesh.h>

#include <energyCoeffs.h>

void energyCollision( basicMesh* mesh, scalar* field, scalar* gamma_0, scalar* T, scalar* U, energyCoeffs* relax, scalar delta_t);

#endif // ENERGYCOLLISION_H
