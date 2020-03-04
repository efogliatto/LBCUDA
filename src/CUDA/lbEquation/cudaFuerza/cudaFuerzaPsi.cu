#include <cudaFuerzaPsi.h>

#include <cudaFuerzaPresionEOS.h>

#include <stdio.h>

#include <math.h>


__device__ void cudaFuerzaPsi( cuscalar* psi, cuscalar p_EOS, cuscalar rho, cuscalar c, cuscalar cs_2, cuscalar G) {

    // Suma de todas las componentes
    
	*psi = pow ( fabs (( 2 * ( p_EOS - rho * cs_2 ) / ( G * c * c ) ) ), 0.5 );


}
