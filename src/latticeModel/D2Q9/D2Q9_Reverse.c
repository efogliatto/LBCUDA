#include <stdio.h>
#include <stdlib.h>
#include <D2Q9_Reverse.h>

int* D2Q9_Reverse() {

    int* vel;
    
    vel = (int*)malloc( 9 * sizeof(int));

    vel[0] = 0;
    vel[1] = 3;
    vel[2] = 4;
    vel[3] = 1;
    vel[4] = 2;
    vel[5] = 7;
    vel[6] = 8;
    vel[7] = 5;
    vel[8] = 6;

    return vel;

}
