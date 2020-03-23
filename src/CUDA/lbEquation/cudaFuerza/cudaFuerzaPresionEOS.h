#ifndef CUDAFUERZAPRESIONEOS_H
#define CUDAFUERZAPRESIONEOS_H

/**
 * @file cudaFuerzaPresionEOS.h
 * @author Thomás Coronel
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

extern "C" __device__ void cudaFuerzaPresionEOS(scalar* p_EOS, scalar rho, scalar T, int a, int b) ;


#endif // CUDAFUERZAPRESIONEOS_H
