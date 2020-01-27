#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "D2Q9_Vel.h"


int** D2Q9_Vel() {

    int** vel;
    
    vel = (int**)malloc( 9 * sizeof(int*));

    uint i;
    for( i = 0 ; i < 9 ; i++) {

    	vel[i] = (int*)malloc( 3 * sizeof(int));
	
    }

    vel[0][0] = 0;
    vel[0][1] = 0;
    vel[0][2] = 0;
    
    vel[1][0] = 1;
    vel[1][1] = 0;
    vel[1][2] = 0;

    vel[2][0] = 0;
    vel[2][1] = 1;
    vel[2][2] = 0;

    vel[3][0] = -1;
    vel[3][1] = 0;
    vel[3][2] = 0;

    vel[4][0] = 0;
    vel[4][1] = -1;
    vel[4][2] = 0;

    vel[5][0] = 1;
    vel[5][1] = 1;
    vel[5][2] = 0;

    vel[6][0] = -1;
    vel[6][1] = 1;
    vel[6][2] = 0;

    vel[7][0] = -1;
    vel[7][1] = -1;
    vel[7][2] = 0;

    vel[8][0] = 1;
    vel[8][1] = -1;
    vel[8][2] = 0;
    


    return vel;

}
