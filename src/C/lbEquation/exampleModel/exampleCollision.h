#ifndef EXAMPLECOLLISION_H
#define EXAMPLECOLLISION_H

/**
 * @file exampleCollision.h
 * @author Ezequiel O. Fogliatto
 * @date 11 Feb 2020
 * @brief Ejemplo de colision MRT
 */

/**
 * Ejemplo de colision MRT
 *
 * Colisión en todos los nodos de la grilla, actualizando @p field por los valores de post-colisión
 *
 * \f$ \mathbf{f^*}(\mathbf{x},t) = \mathbf{M}^{-1} \left[ \mathbf{m}(\mathbf{x},t) - \mathbf{\Lambda}(\mathbf{m} - \mathbf{m}^{(eq)})_{(\mathbf{x},t)}  \right] \f$
 *
 * @param mesh Estructura basica de grilla
 * @param field Campo a colisionar
 * @param rho Densidad
 * @param U Velocidad
 */


#include <basicMesh.h>

#include <exampleModelCoeffs.h>

void exampleCollision( basicMesh* mesh, exampleModelCoeffs* relax, scalar* field, scalar* rho, scalar* U);

#endif // EXAMPLECOLLISION_H
