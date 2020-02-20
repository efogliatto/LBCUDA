#ifndef MOMENTODENSITY_H
#define MOMENTODENSITY_H

/**
 * @file momentoDensity.h
 * @author Ezequiel O. Fogliatto
 * @date 14 Feb 2020
 * @brief Calculo de densidad
 */


/**
 * Calculo de densidad
 * @param rho Densidad macroscópica
 * @param field Función de distribución
 * @param mesh Malla básica
 */

#include <basicMesh.h>

void momentoDensity(scalar* rho, scalar* field, basicMesh* mesh);


#endif // MOMENTODENSITY_H
