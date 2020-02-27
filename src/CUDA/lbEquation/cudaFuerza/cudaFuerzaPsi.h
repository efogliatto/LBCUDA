#ifndef CUDAFUERZAPSI_H
#define CUDAFUERZAPSI_H

/**
 * @file cudaFuerzaPsi.h
 * @author Thomas Coronel
 * @date 27 Feb 2020
 * @brief Calculo de la funcion Psi
 */


/**
 * Calculo de Psi
 * @param psi Valor de la funcion Psi
 * @param p_EOS Presion macroscópica
 * @param rho Densidad macroscópica
 * @param np Numero de puntos
 * @param G Parametro del modelo de LB
 * @param c Parametro del modelo de LB
 * @param cs_2 Parametro del modelo de LB elevado al cuadrado
 */

#include <basicMesh.h>

extern "C" __global__ void cudaFuerzaPsi(scalar* psi, scalar* p_EOS, scalar* rho, scalar c, scalar cs_2, scalar G, int np);


#endif // CUDAFUERZAPSI_H
