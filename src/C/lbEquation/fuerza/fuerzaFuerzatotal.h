#ifndef FUERZAFUERZATOTAL_H
#define FUERZAFUERZATOTAL_H

/**
 * @file fuerzaFuerzatotal.h
 * @author Thomas Coronel
 * @date 26 Feb 2020
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

void fuerzaFuerzatotal(scalar* f, scalar* fint, scalar* rho, scalar* g, basicMesh* mesh)   ;


#endif // FUERZAFUERZATOTAL_H
