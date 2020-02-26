#ifndef FUERZAFUERZAINT_H
#define FUERZAFUERZAINT_H

/**
 * @file fuerzaFuerzaint.h
 * @author Thomas Coronel
 * @date 26 Feb 2020
 * @brief Calculo de Fuerza de Interaccion
 */


/**
 * Calculo de fuerza de interaccion
 * @param fint Fuerza de Interaccion
 * @param psi Valor de la funcion
 * @param mesh Malla básica
 * @param G Parametro del modelo de LB

 */

#include <basicMesh.h>

void fuerzaFuerzaint(scalar* fint, scalar* psi, basicMesh* mesh, scalar G)  ;


#endif // FUERZAFUERZAINT_H
