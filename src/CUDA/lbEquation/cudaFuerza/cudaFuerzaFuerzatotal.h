#ifndef CUDAFUERZAFUERZATOTAL_H
#define CUDAFUERZAFUERZATOTAL_H

/**
 * @file cudaFuerzaFuerzatotal.h
 * @author Thomas Coronel
 * @date 27 Feb 2020
 * @brief Calculo de Fuerza de Interaccion
 */


/**
 * Calculo de fuerza de interaccion
 * @param f Fuerza Total ( volumetricas + interaccion )
 * @param fint Fuerza de Interaccion
 * @param rho Densidad macroscópica
 * @param g Aceleracion macroscópica
 * @param mesh Malla básica
 */

#include <basicMesh.h>

extern "C" __global__ void cudaFuerzaFuerzatotal(scalar* f, scalar* fint, scalar* rho, scalar* g, basicMesh* mesh)   ;


#endif // CUDAFUERZAFUERZATOTAL_H
