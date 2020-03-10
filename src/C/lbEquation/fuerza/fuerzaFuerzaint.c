#include <fuerzaFuerzaint.h>

#include <fuerza.h>

#include <stdio.h>

void fuerzaFuerzaint(scalar* fint, scalar* rho, scalar* T , basicMesh* mesh, scalar G, scalar c, scalar cs_2, int a, int b) {

	 printf("\n Fint calculada con C \n\n");

	// Valores de los pesos del modelo D2Q9

	scalar weight[(const int) mesh->Q];

	weight[0] = 0.0 ;	
	weight[1] = (1.0/3.0);    
	weight[2] = (1.0/3.0);
	weight[3] = (1.0/3.0);
	weight[4] = (1.0/3.0);
	weight[5] = (1.0/12.0);
	weight[6] = (1.0/12.0);
	weight[7] = (1.0/12.0);
	weight[8] = (1.0/12.0);

	
    // Suma de todas las componentes
    
    for( uint i = 0 ; i < mesh->nPoints ; i++ ) {
		if ( i == 0 ) 			
			printf(" i: %d\n",i);

		// Local force
		
		scalar lf[3] = {0,0,0};

		// Move over velocity components
		
		for( uint j = 0 ; j < 3 ; j++ ) {
			if ( i == 0 ) 			
				printf("\t j: %d\n",j);

			scalar p_EOS = 0.0;
			
			scalar psi = 0.0;

			// Move over model velocities

			for(uint k = 0 ; k < mesh->Q ; k++) {

				int idx_nb = mesh->nb[i][k];	// index of neighbour to analize

				if ( idx_nb >= 0){
					
					fuerzaPresionEOS( &p_EOS, rho[idx_nb] , T[idx_nb], a, b); 

					fuerzaPsi( &psi, p_EOS, rho[idx_nb], c, cs_2, G);
					
					lf[j] += (scalar)mesh->lattice.vel[k*3+j] * weight[k] * psi ;	
				}

				else {
					lf[j] += 0.0;
				}
				if ( i == 0 ) 				
					printf("\t\t K:%d \t idx_nb:%d \t rho:%f \t p_EOS:%f \t psi:%f \t lvel:%f \t weight:%f \t lf:%f   \n",k,idx_nb,rho[i],p_EOS,psi,(scalar)mesh->lattice.vel[k*3+j],weight[k],lf[j]);

				
				
			}

			// Se necesita utilizar el psi del nodo --> i que es en el que me encuentro 

			fuerzaPresionEOS( &p_EOS, rho[i] , T[i], a, b); 

			fuerzaPsi( &psi, p_EOS, rho[i], c, cs_2, G);
		
			lf[j] = ( - G ) * lf[j]  * psi;     
	
		}


		// Copy to global array
		for(uint j = 0 ; j < 3 ; j++) {
			fint[i*3+j] = lf[j];

		//	printf("%lf \t",fint[i*3+j]);
		}

		//printf("\n");

    }
	//printf("\nESTOY AFUERA DE FINT ------------\n\n");

}
