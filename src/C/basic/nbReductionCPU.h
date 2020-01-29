#ifndef NBREDUCTIONCPU_H
#define NBREDUCTIONCPU_H

/**
 * @file nbReductionCPU.h
 * @author Ezequiel O. Fogliatto
 * @date 29 Ene 2020
 * @brief Calculo de momento de orden cero en los nodos vecinos, y suma sobre cada nodo
 */


/**
 * Calculo de momento de orden cero en los nodos vecinos, y suma sobre cada nodo
 * @param sum Resultado de la suma
 * @param field Función de distribución
 * @param mesh Malla básica LB
 */

#include <basicMesh.h>

void nbReductionCPU(scalar* sum, scalar* field, basicMesh* mesh);


#endif // NBREDUCTIONCPU_H
