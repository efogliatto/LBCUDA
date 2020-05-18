En la presente carpeta se encuentran los ejecutables para realizar los datos de validación y de speed up 
del problema Construcción de Maxwell (MxC) y de la Estratificación de un fluido de Van Der Waals en una Columna (VdW).

Los ejecutables del proyecto generan archivos que son depositados en una carpeta externa
a LBCUDA_Test (en el mismo fichero/PATH que ésta se encuentra), siendo los mismos.

    Para el caso de validación:

    * validacion_MxC
    * validacion_cudaMxC
    * validacion_VdW
    * validacion_cudaVdW

    Para el caso de speed up:

    * speedUp_MxC
    * speedUp_cudaMxC
    * speedUp_VdW
    * speedUp_cudaVdW

    
En ésta carpeta se encuentran los valores iniciales, donde serán copiados por el ejecutable y generar los datos.

    * sUpMxC
    * sUpVdW

En los ejecutables se encuentran los de validación y de speed up.

    RunMxCVal       *Validacion de Construcción de Maxwell en C
    RunVdWVal       *Validacion de VdWColumn en C
    cudaRunMxCVal   *Validacion de Construcción de Maxwell en CUDA
    cudaRunVdWVal   *Validacion de VdWColumn en CUDA


    RunMxCsUp       *SpeedUp de Construcciónde Maxwell en C
    RunVdWsUp       *SpeedUp de VdWColumn en C
    cudaRunMxCsUp   *SpeedUp de Construcciónde Maxwell en CUDA
    cudaRunVdWsUp   *SpeedUp de VdWColumn en CUDA

        
    VALIDACION :

        Por defectos las grillas de validación son 
        
            MxC  201 201
            VdW  3   300
            
            pueden cambiarse modificando el ejecutable correspondiente

        Por defecto las Tr varian de a 0.025 con Tr = [ 0.6 ; 0.975 ]
        
    SPEED UP

        Por defecto la configuración para la toma de tiempo es un total de 20000 pasos para VdW 
        y de 100000 en MxC (hasta 64 de tamaño de la grilla), luego de 50000 hasta 5122, para arriba de 512 de grilla la toma de tiempo es de 2500
        
        Para MxC las grillas son cuadraras siendo su tamaño de:
            16x 16 32x32 64x64 128x128 256x256 512x512 1024x1024 2048x2048 4096x4096

        Para VdW las grillas son rectangulares siendo su tamaño de Y fijo en 300, variando en X:
            3x300 4x300 8x300 16x300 32x300 64x300 128x300 256x300 512x300 1024x300

        Para los casos de CUDA se correrán en la siguiente cantidad de bloques:
            1 2 4 8 16 32 64 128 256 512

        Por como están configurado los ejecutables del speedUp lo único que tendrá como salida 
        es un archivo llamado time_exc con el tiempo de ejecución.

