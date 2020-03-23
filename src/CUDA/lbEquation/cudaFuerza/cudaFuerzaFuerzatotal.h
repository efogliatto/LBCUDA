#ifndef CUDAFUERZAFUERZATOTAL_H
#define CUDAFUERZAFUERZATOTAL_H

/**
 * @file cudaFuerzaFuerzatotal.h
 * @author Thomás Coronel
 * @date 27 Feb 2020
 * @brief Calculo de Fuerza de Interaccion
 */


/**
 * Calculo de fuerza de interaccion
 * @param f Fuerza Total ( volumetricas + interaccion )
 * @param fint Fuerza de Interaccion
 * @param rho Densidad macroscópica
 * @param g Aceleracion macroscópica
 * @param np Numero de puntos
 */

#include <basicMesh.h>

extern "C" __global__ void cudaFuerzaFuerzatotal(cuscalar* f, cuscalar* fint, cuscalar* rho, cuscalar* g, int np)   ;


#endif // CUDAFUERZAFUERZATOTAL_H
