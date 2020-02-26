#include <fuerzaPresionEOS.h>

#include <stdio.h>

void fuerzaPresionEOS(scalar* p, scalar* rho, scalar* T, basicMesh* mesh, int a, int b) {

    // Constante universal de los gases (preguntar en que unidades se debe colocar ya que este modelo es adimensional)

    scalar R = 1; 

    // Calculo de la presion
    
    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {

	p[i] = ( ( rho[i] * R * T[i] ) / ( 1 - rho[i] * b ) ) - ( a * rho[i] * rho[i] ) ;	    

	
    }
    

}
