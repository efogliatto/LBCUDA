#include <cudaFuerzaPresionEOS.h>

#include <stdio.h>


__device__ void cudaFuerzaPresionEOS( cuscalar* p_EOS, cuscalar rho, cuscalar T, int a, int b) {


    // Constante universal de los gases (preguntar en que unidades se debe colocar ya que este modelo es adimensional)

    scalar R = 1; 

    // Calculo de la presion
    
 

	*p_EOS = ( ( rho * R * T ) / ( 1 - rho * b ) ) - ( a * rho * rho ) ;	    

  	printf("p_EOS despues :%f \n ", *p_EOS);

}
