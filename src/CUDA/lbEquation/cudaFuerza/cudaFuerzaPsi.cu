#include <cudaFuerzaPsi.h>

#include <cudaFuerzaPresionEOS.h>

#include <stdio.h>

#include <math.h>


__global__ void cudaFuerzaPsi( cuscalar psi, cuscalar p_EOS, scalar rho, scalar c, scalar cs_2, scalar G) {

    // Suma de todas las componentes
    
	psi = pow ( fabs (( 2 * ( p_EOS - rho * cs_2 ) / ( G * c * c ) ) ), 0.5 );


}
