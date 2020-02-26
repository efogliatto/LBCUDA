#ifndef FUERZAPRESIONEOS_H
#define FUERZAPRESIONEOS_H

/**
 * @file fuerzaPresionEOS.h
 * @author Thomas Coronel
 * @date 26 Feb 2020
 * @brief Calculo de presion
 */


/**
 * Calculo de presion
 * @param p Presion macroscópica
 * @param rho Densidad macroscópica
 * @param T Temperatura macroscópica
 * @param mesh Malla básica
 * @param a Parametro del modelo DdQq
 * @param b Parametro del modelo DdQq
 */

#include <basicMesh.h>

void fuerzaPresionEOS(scalar* p, scalar* rho, scalar* T, basicMesh* mesh, int a, int b) ;


#endif // FUERZAPRESIONEOS_H
