#ifndef DATATYPES_H
#define DATATYPES_H


/**
 * @file dataTypes.h
 * @author Ezequiel O. Fogliatto
 * @date 27 Ene 2020
 * Basic pre-defined constants and data types
 */

/** Unsigned int short name */

typedef unsigned int uint;


/** Scalar for precision change */

#ifdef DP

typedef double scalar;

#elif SP

typedef float scalar;

#endif


#ifdef DP_CUDA

typedef double cuscalar;

#elif SP_CUDA

typedef float cuscalar;

#endif



#endif // DATATYPES_H
