#ifndef FIXEDTBOUNDARYHEATING_H
#define FIXEDTBOUNDARYHEATING_H

/**
 * @file fixedTBoundaryHeating.h
 * @author Thomás Coronel
 * @date 13 May 2020
 * @brief Condición de contorno para región calefaccionada
 */

/**
 * Condición de contorno de temperatura en un ancho dado de la grilla
 * 
 * @param mesh Malla básica
 * @param field Función de distribución 
 * @param T Temperatura
 * @param U Velocidad
 * @param bdname Nombre del eje que se realiza la condición de contorno. (Y0,Y1,X0,X1)[Por ejemplo]
 * @param bdval Valor de temperatura que se aplica en ésa condición
 * @param widthbd Ancho de nodos dónde se realiza la condición
 */

#include <basicMesh.h>

void fixedTBoundaryHeating( basicMesh* mesh, scalar* field, scalar* T, scalar* U, char* bdname, scalar bdval, scalar bdheat, uint widthbd, scalar alpha_1, scalar alpha_2 ) ;

#endif // FIXEDTBOUNDARYHEATING_H
