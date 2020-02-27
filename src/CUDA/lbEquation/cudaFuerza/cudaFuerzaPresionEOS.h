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
 * @param p Presion macroscópica
 * @param rho Densidad macroscópica
 * @param T Temperatura macroscópica
 * @param np Numero de puntos
 * @param a Parametro del modelo DdQq
 * @param b Parametro del modelo DdQq
 */

#include <basicMesh.h>

extern "C" __global__ void cudaFuerzaPresionEOS(scalar* p, scalar* rho, scalar* T, int np, int a, int b) ;


#endif // CUDAFUERZAPRESIONEOS_H
