#ifndef EXAMPLEVELOCITY_H
#define EXAMPLEVELOCITY_H

/**
 * @file exampleVelocity.h
 * @author Ezequiel O. Fogliatto
 * @date 19 Feb 2020
 * @brief Calculo de velocidad
 */


/**
 * Calculo de velocidad
 * @param rho Densidad macroscópica
 * @param rho Velocidad macroscópica
 * @param field Función de distribución
 * @param mesh Malla básica
 */

#include <basicMesh.h>

void exampleVelocity(scalar* rho, scalar* U, scalar* field, basicMesh* mesh);


#endif // EXAMPLEVELOCITY_H
