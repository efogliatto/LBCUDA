#ifndef MOMENTOVELOCITY_H
#define MOMENTOVELOCITY_H

/**
 * @file momentoVelocity.h
 * @author Thomás Coronel
 * @date 20 Feb 2020
 * @brief Calculo de velocidad
 */


/**
 * Calculo de velocidad
 * @param rho Densidad macroscópica
 * @param rho Velocidad macroscópica
 * @param field Función de distribución
 * @param mesh Malla básica
 * @param delta_t Paso de tiempo
 * @param F Fuerza total ( volumetrica + interaccion ) 
 */

#include <basicMesh.h>

void momentoVelocity(scalar* rho, scalar* U, scalar* field, basicMesh* mesh, scalar delta_t, scalar* F);


#endif // MOMENTOVELOCITY_H
