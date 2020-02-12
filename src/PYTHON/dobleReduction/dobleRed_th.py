from time import time
import numpy as np
import pycuda
from pycuda import gpuarray
import pycuda.autoinit
import argparse


zm_mod = pycuda.driver.module_from_file('/users/coronelth/Seguir_Proyecto/LBCUDA_Test/ptx/objects-Release/cudaTestPTX/thomasReduction.ptx')

zm_ker = zm_mod.get_function('thomasReduction')


if __name__ == '__main__':



    # Argumentos de consola
    
    parser = argparse.ArgumentParser(description='Suma de componentes de funciones de distribucion')

    parser.add_argument('--nit', help='Numero de iteraciones', type = int, default = 1)

    parser.add_argument('--gsize', help='Tamano de grilla', type = int, default = 1)    

    args = parser.parse_args()


    
    # Lectura de vecinos

    with open( 'lattice/neighbours' ) as nbfile:

        nPoints, meshQ = nbfile.readline().split()
        
        neighbours = nbfile.read().split()
        
        neighbours = np.int32(np.ravel(neighbours)).reshape((np.int32(nPoints), np.int32(meshQ)))
        
#        neighbours = neighbours.reshape((np.int32(nPoints), np.int32(meshQ)))
        
    nPoints = np.int32( nPoints )

    meshQ = np.int32( meshQ )    
            
    print( '\n Lectura de {} vecinos con {} componentes\n'.format(nPoints, meshQ) )

    


    # Inicializacion
    
    neighbours = np.zeros( (nPoints,meshQ), dtype=np.int32 )
    
    print(neighbours)

    hostField = np.zeros( nPoints*meshQ, dtype=np.float32 )

    hostSum = np.zeros( nPoints, dtype=np.float32 )    

    for i in range(len(hostField)):
        hostField[i] = i;



    # Arreglos de device

    deviceField = gpuarray.to_gpu( hostField )

    deviceSum = gpuarray.to_gpu( hostSum )    

        
    
    # Reduccion

    t1 = time()

    gs = int( nPoints*meshQ/args.gsize ) + 1
#%%
    for k in range(args.nit):
        
        zm_ker( deviceField,
                deviceSum,
                neighbours,
                np.int32( nPoints ),
                np.int32( meshQ ),
                block=( args.gsize, 1, 1 ),
                grid=( gs, 1, 1) )


        pycuda.driver.Context.synchronize()
        
    
    t2 = time()

    print('\n Reduccion finalizada en {:g} segundos\n'.format( t2 - t1 ))
    print('\n Tiempo promedio por iteracion: {:g} segundos\n'.format( (t2 - t1)/args.nit ))      
    print(' --------------------------------------------')

    
    # # De vuelta al host

    # hostSum = deviceSum.get()  
