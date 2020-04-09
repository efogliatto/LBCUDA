#ifndef MOMOENTOFEQ_H
#define MOMOENTOFEQ_H

/**
 * @file momentoFeq.h
 * @author Thomás Coronel
 * @date 8 Abril 2020
 * @brief Cálculo de field de equilibrio
 */

/**
 * Cálculo de field de equilibrio
 *
 * Campo ed field de equilibrio en todos los nodos de la grilla
 *
 * \f$ \mathbf{f^{eq}} = \mathbf{M}^{-1} \mathbf{m}^{eq}\f$
 *
 * @param mesh Estructura basica de grilla
 * @param field Campo a calcular el equilibrio
 * @param rho Densidad macroscópica
 * @param U Velocidad
 */


#include <basicMesh.h>

void momentoFeq( basicMesh* mesh, scalar* field, scalar* rho, scalar* U) ;

#endif // MOMOENTOFEQ_H
