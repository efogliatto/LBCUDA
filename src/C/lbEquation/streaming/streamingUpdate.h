#ifndef STREAMINGUPDATE_H
#define STREAMINGUPDATE_H

/**
 * @file streamingUpdate.h
 * @author Thomás Coronel
 * @date 29 Mar 2020
 * @brief Función que actualiza los valores de Streaming calculados para el campo field
 */

/**
 *
 * Actualización de los valores de field, a traves de los valores calculados para hacer el streaming
 *
 * @param mesh Estructura basica de grilla
 * @param field Campo a copiar los argumentos y realizar el streaming
 * @param strupdate Campo que posee los valores actualizados y deben pasarse
 * 
 */


#include <basicMesh.h>

void streamingUpdate( scalar* field, scalar* strupdate, basicMesh* mesh);

#endif // STREAMINGUPDATE_H
