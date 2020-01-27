#ifndef SCALAR2DARRAY_H
#define SCALAR2DARRAY_H

#include <dataTypes.h>

/**
 * @file scalar2dArray.h
 * @author Ezequiel O. Fogliatto
 * @date 27 Ene 2020
 * @brief Allocation of two-dimensional scalar array
 */


/**
 * Allocation of two-dimensional scalar array
 * @param ptr Pointer for 2d array allocation
 * @param nrow Number of rows
 * @param ncol Number of columns
 * @param df Default value for all elements
 * @return Status. Correct if different from zero
 */


scalar scalar2dArray(scalar*** M, unsigned int nrow, unsigned int ncol, scalar df);

#endif // SCALAR2DARRAY_H
