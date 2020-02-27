#ifndef FUERZAS_H
#define FUERZAS_H

/**
 * @file fuerzaS.h
 * @author Thomas Coronel
 * @date 26 Feb 2020
 * @brief Calculo de la fuente
 */


/**
 * Calculo del termino de fuente
 * @param S Termino de fuente
 * @param f Fuerza Total (volumetrica + Interaccion)
 * @param fint Fuerza de Interaccion
 * @param U Velocidad macroscopica
 * @param psi Valor de la funcion psi
 * @param sigma Parametro libre para la inconsistencia termodinamica.
 * @param tau_e Parametro que es uno de los valores de relajacion
 * @param tau_chi Parametro que es uno de los valores de relajacion
 * @param delta_t Paso de tiempo
 * @param mesh Malla básica
 */

#include <basicMesh.h>

void fuerzaS(scalar* S, scalar* f, scalar* fint, scalar* U, scalar* psi, scalar sigma, scalar tau_e, scalar tau_chi, basicMesh* mesh, scalar delta_t) ;


#endif // FUERZAS_H
