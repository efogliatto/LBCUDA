#ifndef FUERZAFUERZAINT_H
#define FUERZAFUERZAINT_H

/**
 * @file fuerzaFuerzaint.h
 * @author Thomás Coronel
 * @date 26 Feb 2020
 * @brief Calculo de Fuerza de Interaccion
 */


/**
 * Calculo de fuerza de interaccion
 * @param fint Fuerza de Interaccion
 * @param rho Densidad macroscópica
 * @param T Temperatura macroscópica
 * @param mesh Malla básica
 * @param G Parametro del modelo de LB
 * @param c Parametro del modelo de LB
 * @param cs_2 Parametro del modelo de LB elevado al cuadrado
 * @param a Parametro del modelo DdQq
 * @param b Parametro del modelo DdQq
 */

#include <basicMesh.h>

void fuerzaFuerzaint(scalar* fint, scalar* rho, scalar* T , basicMesh* mesh, scalar G, scalar c, scalar cs_2, scalar a, scalar b)   ;


#endif // FUERZAFUERZAINT_H
