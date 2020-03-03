#ifndef CUDAFUERZAS_H
#define CUDAFUERZAS_H

/**
 * @file cudaFuerzaS.h
 * @author Thomas Coronel
 * @date 27 Feb 2020
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
 * @param tau Vector de los parametros de relajacion
 * @param delta_t Paso de tiempo

 */

#include <basicMesh.h>

__global__ void cudaFuerzaS(cuscalar* S, cuscalar* f, cuscalar* fint, cuscalar* U, cuscalar psi, cuscalar sigma, cuscalar* tau, scalar delta_t) ;


#endif // CUDAFUERZAS_H
