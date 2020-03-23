#ifndef FUERZAPRESIONEOS_H
#define FUERZAPRESIONEOS_H

/**
 * @file fuerzaPresionEOS.h
 * @author Thomás Coronel
 * @date 26 Feb 2020
 * @brief Calculo de presion
 */


/**
 * Calculo de presion
 * @param p_EOS Presion macroscópica
 * @param rho Densidad macroscópica
 * @param T Temperatura macroscópica
 * @param a Parametro del modelo DdQq
 * @param b Parametro del modelo DdQq
 */

#include <basicMesh.h>

void fuerzaPresionEOS(scalar* p_EOS, scalar rho, scalar T, int a, int b) ;


#endif // FUERZAPRESIONEOS_H
