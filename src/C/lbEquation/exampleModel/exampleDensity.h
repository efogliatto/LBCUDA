#ifndef EXAMPLEDENSITY_H
#define EXAMPLEDENSITY_H

/**
 * @file exampleDensity.h
 * @author Ezequiel O. Fogliatto
 * @date 19 Feb 2020
 * @brief Calculo de densidad
 */


/**
 * Calculo de densidad
 * @param rho Densidad macroscópica
 * @param field Función de distribución
 * @param mesh Malla básica
 */

#include <basicMesh.h>

void exampleDensity(scalar* rho, scalar* field, basicMesh* mesh);


#endif // EXAMPLEDENSITY_H
