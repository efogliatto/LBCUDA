#include <cudaFuerzaFuerzatotal.h>

#include <stdio.h>

extern "C" __global__ void cudaFuerzaFuerzatotal(cuscalar* f, cuscalar* fint, cuscalar* rho, cuscalar* g, int np) {

	printf("ENTRE A LA FUNCION FUERZA TOTAL \n \n");


    int idx = threadIdx.x + blockIdx.x*blockDim.x;
	
    // Suma de todas las componentes

    if( idx < np ) {

	// Volumetric force add Interaction force

		uint j = 0 ;

		while( j < 3 ) {
	
	    	f[idx*3+j] = rho[idx] * g[j] + fint[idx*3+j];

	    	j++;
			
			printf("%lf \t",f[idx*3+j]);
		}
		printf("\n");
    }

}
