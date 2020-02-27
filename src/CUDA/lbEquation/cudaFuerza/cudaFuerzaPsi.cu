#include <cudaFuerzaPsi.h>

#include <cudaFuerzaPresionEOS.h>

#include <stdio.h>

#include <math.h>


extern "C" __global__ void cudaFuerzaPsi(scalar* psi, scalar* p_EOS, scalar* rho, scalar c, scalar cs_2, scalar G, basicMesh* mesh) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;

    // Suma de todas las componentes
    
    if( idx <  mesh->nPoints ) {

	psi[idx] = pow ( ( 2 * ( p_EOS[idx] - rho[idx] * cs_2 ) / ( G * c * c ) ), 0.5 );

   }
    

}
