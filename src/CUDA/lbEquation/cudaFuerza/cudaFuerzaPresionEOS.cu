#include <cudaFuerzaPresionEOS.h>

#include <stdio.h>


extern "C" __global__ void cudaFuerzaPresionEOS(scalar* p, scalar* rho, scalar* T, basicMesh* mesh, int a, int b) {

    int idx = threadIdx.x + blockIdx.x*blockDim.x;

    // Constante universal de los gases (preguntar en que unidades se debe colocar ya que este modelo es adimensional)

    scalar R = 1; 

    // Calculo de la presion
    
    if( idx < mesh->nPoints ) {

	p[idx] = ( ( rho[idx] * R * T[idx] ) / ( 1 - rho[idx] * b ) ) - ( a * rho[idx] * rho[idx] ) ;	    

	
    }
    

}
