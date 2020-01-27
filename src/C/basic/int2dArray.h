#ifndef INT2DARRAY_H
#define INT2DARRAY_H

/**
 * @file int2dArray.h
 * @author Ezequiel O. Fogliatto
 * @date 27 Ene 2020
 * @brief Allocation of two-dimensional integer array
 */


/**
 * Allocation of two-dimensional integer array
 * @param ptr Pointer for 2d array allocation
 * @param nrow Number of rows
 * @param ncol Number of columns
 * @param df Default value for all elements
 * @return Status. Correct if different from zero
 */


unsigned int int2dArray(int*** M, unsigned int nrow, unsigned int ncol, int df);

#endif // INT2DARRAY_H
