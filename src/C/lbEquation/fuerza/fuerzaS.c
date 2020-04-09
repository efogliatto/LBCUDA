#include <fuerzaS.h>

#include <stdio.h>

#include <math.h>

void fuerzaS(scalar* S, scalar* f, scalar* fint, scalar* U, scalar psi, scalar sigma, scalar* tau, scalar delta_t) {

    S[0] = 0.0 ;	
    S[1] =  6.0 * (U[0]*f[0] + U[1]*f[1]) + 12.0 * sigma * (fint[0]*fint[0] + fint[1]*fint[1]) / (psi * psi * ((1.0/tau[1])-0.5));
    S[2] = -6.0 * (U[0]*f[0] + U[1]*f[1]) - 12.0 * sigma * (fint[0]*fint[0] + fint[1]*fint[1]) / (psi * psi * ((1.0/tau[2])-0.5));
    S[3] = f[0];
    S[4] = -f[0];
    S[5] = f[1];
    S[6] = -f[1];
    S[7] = 2 * ( U[0] * f[0] + U[1] * f[1] );
    S[8] = ( U[0] * f[1] + U[1] * f[0] );

}
