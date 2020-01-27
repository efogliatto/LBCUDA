#ifndef LATTICEINFO_H
#define LATTICEINFO_H


/**
 * @file latticeInfo.h
 * @author Ezequiel O. Fogliatto
 * @date 27 Ene 2020
 * @brief Lattice model parameters
 */


/**
 * @brief Available lattice models
 *
 * Available lattice models. DdQq type.
 */

#include "dataTypes.h"

typedef enum {
    D2Q9,
    D3Q15
} DdQq;


/**
 * @brief Lattice model parameters
 *
 * Lattice model parameters. DdQq related constants (d, Q, weights, etc.).
 */

typedef struct {

    /** General lattice model */
    DdQq model;
    
    /* /\** Sound speed *\/ */
    /* scalar cs2; */

    /* /\** Dimension *\/ */
    /* int d; */

    /* /\** Number of discrete velocities *\/ */
    /* int Q; */

    /* /\** DdQq model velocities *\/ */
    /* int** vel; */

    /* /\** DdQq model reverse indices *\/ */
    /* int* reverse; */

    /* /\** DdQq model weights *\/ */
    /* scalar* omega; */

    /* /\** Interaction force weights *\/ */
    /* scalar* weights; */

    /* /\** MRT transformation matrix *\/ */
    /* scalar** M; */

    /* /\** MRT inverse of transformation matrix *\/ */
    /* scalar** invM; */
    
}latticeInfo;

#endif // LATTICEINFO_H
