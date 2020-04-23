#ifndef READINITIALPARAMETERS_H
#define READINITIALPARAMETERS_H

#include <dataTypes.h>

/**
 * @file readInitialParameters.h
 * @author Thomás Coronel
 * @date 23 Abril 2020
 * @brief Lectura de parámetros iniciales 
 */


/**
 * Lectura de parámetros iniciales 
 * @param G Parametro del modelo de LB
 * @param c Parametro del modelo de LB
 * @param sigma Parametro libre para la inconsistencia termodinamica
 * @param a Constante de EOS
 * @param b Constante de EOS
 * @param g gravedad
 * @param Tr Temperatura de referencia
 * @param Tc Temperatura crítica
 * @param Rhoc Densidad crítica
 */


void readInitialParameters( scalar *G, scalar *c,scalar *sigma, scalar *a, scalar *b, scalar *g, scalar *Tr, scalar *Tc, scalar *Rhoc);

#endif // READINITIALPARAMETERS_H

// Forma que debe poseer el archivode lectura InitialParameters.txt :
/*

-1.0    
1.0     
0.125
0.5
4.0
0.0
0.0
0.0
0.9
0.037037037
0.083333333

    // Estan ordenados de la siguiente forma

    G
    c
    sigma
    a
    b
    g[0] en x
    g[1] en y
    g[2] en z
    Tr
    Tc
    Rhoc

*/
