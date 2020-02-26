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
 * @param psi Valor de la funcion Psi
 * @param T Temperatura macroscópica
 * @param p Presion macroscópica
 * @param G Parametro del modelo de LB
 * @param a Parametro del modelo DdQq
 * @param b Parametro del modelo DdQq
 * @param c Parametro del modelo de LB
 * @param cs_2 Parametro del modelo de LB elevado al cuadrado
 */

#include <basicMesh.h>

void fuerzaFuerzatotal(scalar* f, scalar* fint, scalar* rho, scalar* g, basicMesh* mesh, scalar* psi, scalar* T, scalar* p, scalar G, int a, int b, scalar c, scalar cs_2)   ;


#endif // FUERZAFUERZATOTAL_H
