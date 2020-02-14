#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <D2Q9_VelArray.h>


int* D2Q9_VelArray() {

    int* vel;
    
    vel = (int*)malloc( 27 * sizeof(int));


    vel[0] = 0;
    vel[1] = 0;
    vel[2] = 0;
    
    vel[3] = 1;
    vel[4] = 0;
    vel[5] = 0;

    vel[6] = 0;
    vel[7] = 1;
    vel[8] = 0;

    vel[9] = -1;
    vel[10] = 0;
    vel[11] = 0;

    vel[12] = 0;
    vel[13] = -1;
    vel[14] = 0;

    vel[15] = 1;
    vel[16] = 1;
    vel[17] = 0;

    vel[18] = -1;
    vel[19] = 1;
    vel[20] = 0;

    vel[21] = -1;
    vel[22] = -1;
    vel[23] = 0;

    vel[24] = 1;
    vel[25] = -1;
    vel[26] = 0;
    


    return vel;

}
