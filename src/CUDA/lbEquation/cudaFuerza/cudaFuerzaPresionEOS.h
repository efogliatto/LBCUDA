#ifndef CUDAFUERZAPRESIONEOS_H
#define CUDAFUERZAPRESIONEOS_H

/**
 * @file cudaFuerzaPresionEOS.h
 * @author Thomas Coronel
 * @date 27 Feb 2020
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

__device__ void cudaFuerzaPresionEOS( cuscalar* p_EOS, cuscalar rho, cuscalar T, int a, int b) ;


#endif // CUDAFUERZAPRESIONEOS_H
