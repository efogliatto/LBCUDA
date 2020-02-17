#include <cudaThreadedMatMult.h>

#include <stdio.h>


extern "C" __global__ void cudaThreadedMatMult(cuscalar* mat, cuscalar* vec, uint id, uint Q) {

    int thid = threadIdx.x;

    printf("%d\n", thid);

}
