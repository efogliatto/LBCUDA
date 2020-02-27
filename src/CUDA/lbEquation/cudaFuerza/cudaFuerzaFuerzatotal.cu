#include <cudaFuerzaFuerzatotal.h>

#include <stdio.h>









extern "C" __global__ void cudaFuerzaFuerzatotal(scalar* f, scalar* fint, scalar* rho, scalar* g, basicMesh* mesh) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;
	
    // Suma de todas las componentes

    if( idx < mesh->nPoints ) {


	// Volumetric force add Interaccion force

	uint j = 0 ;

	while( j < 3 ) {
	
	    f[idx*3+j] = rho[idx] * g[j] + fint[idx*3+j];

	    j++;
	
	}

    }

}
