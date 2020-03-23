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
 * @param rho Densidad
 * @param U Velocidad
 * @param delta_t Paso de tiempo
 * @param f Fuerza total ( volumetrica + Interaccion)
 * @param fint Fuerza de interaccion
 * @param T Temperatura macroscópica
 * @param a Parametro del modelo DdQq
 * @param b Parametro del modelo DdQq
 * @param G Parametro del modelo de LB
 * @param c Parametro del modelo de LB
 * @param cs_2 Parametro del modelo de LB elevado al cuadrado
 * @param sigma Parametro libre para la inconsistencia termodinamica.
 */


#include <basicMesh.h>

#include <momentoModelCoeffs.h>

void momentoCollision( basicMesh* mesh, momentoModelCoeffs* relax, scalar* field, scalar* rho, scalar* U, scalar* f, scalar* fint, scalar* T, scalar delta_t, int a, int b, scalar c, scalar cs_2, scalar G, scalar sigma);

#endif // ENERGYCOLLISION_H
