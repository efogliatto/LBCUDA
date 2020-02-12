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
 * @param mesh Estructura basica de grilla
 * @param field Campo a colisionar
 * @param rho Densidad
 * @param U Velocidad
 */


#include <basicMesh.h>

void exampleCollision( basicMesh* mesh, scalar* field, scalar* rho, scalar* U);

#endif // EXAMPLECOLLISION_H
