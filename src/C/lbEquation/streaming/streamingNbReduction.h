#ifndef STREAMINGNBREDUCTION_H
#define STREAMINGNBREDUCTION_H

/**
 * @file streamingNbReduction.h
 * @author Thomás Coronel
 * @date 29 Mar 2020
 * @brief Función que realiza el cálculo del valor que debe poseer field en el Streaming 
 */

/**
 *
 * Calculo del valor del streaming en todos los nodos de la grilla
 *
 * $ \mathbf{f^*}(\mathbf{x},t) $
 *
 * @param mesh Estructura basica de grilla
 * @param field Campo a realizar el streaming
 * @param sum Campo donde se guarda los valores del streaming
 * 
 */


#include <basicMesh.h>

void streamingNbReduction(scalar* sum, scalar* field, basicMesh* mesh) ;

#endif // STREAMINGNBREDUCTION_H
