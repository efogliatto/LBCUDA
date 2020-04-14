#include <cudaFuerzaPresionEOS.h>

#include <stdio.h>


extern "C" __device__ void cudaFuerzaPresionEOS(cuscalar* p_EOS, cuscalar rho, cuscalar T, cuscalar a, cuscalar b) {

    // Constante universal de los gases (preguntar en que unidades se debe colocar ya que este modelo es adimensional)

    scalar R = 1; 

    *p_EOS = ( ( rho * R * T ) / ( 1 - rho * b ) ) - ( a * rho * rho ) ;	    

}
