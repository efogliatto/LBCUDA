#ifndef MOMENTOCOLLISION_H
#define MOMENTOCOLLISION_H

/**
 * @file momentoCollision.h
 * @author Thomas Coronel
 * @date 20 Feb 2020
 * @brief Ejemplo de colision MRT
 */

/**
 * Ejemplo de colision MRT
 *
 * Colisión en todos los nodos de la grilla, actualizando @p field por los valores de post-colisión
 *
 * \f$ \mathbf{f^*}(\mathbf{x},t) = \mathbf{M}^{-1} \left[ \mathbf{m} - \mathbf{\Lambda}(\mathbf{m} - \mathbf{m}^{(eq)}) + \delta_{t} \left( I - 0,5 \Lambda \right) \bar{S}  \right]_{(\mathbf{x},t)} \f$
 *
 * @param mesh Estructura basica de grilla
 * @param field Campo a colisionar
 * @param rho Densidad
 * @param U Velocidad
 * @param delta_t Paso de tiempo
 * @param S Termino de fuente
 */


#include <basicMesh.h>

#include <momentoModelCoeffs.h>

void momentoCollision( basicMesh* mesh, momentoModelCoeffs* relax, scalar* field, scalar* rho, scalar* U, scalar delta_t, scalar* S);

#endif // MOMENTOCOLLISION_H
