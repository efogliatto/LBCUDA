#ifndef ZEROTHMOMENTCPU_H
#define ZEROTHMOMENTCPU_H

/**
 * @file zerothMomentCPU.h
 * @author Ezequiel O. Fogliatto
 * @date 28 Ene 2020
 * @brief Calculo de momento de orden cero
 */


/**
 * Calculo de momento de orden cero
 * @param ptr Pointer for 2d array allocation
 * @param nrow Number of rows
 * @param ncol Number of columns
 * @param df Default value for all elements
 * @return Status. Correct if different from zero
 */

#include <basicMesh.h>

void zerothMomentCPU(scalar* sum, scalar* field, basicMesh* mesh);


#endif // ZEROTHMOMENTCPU_H
