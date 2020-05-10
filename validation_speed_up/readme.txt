En la presente carpeta se encuentran los destinos de los datos de validación y de speed up 
del problema Construcción de Maxwell (MxC) y de la Estratificación de un fluido de Van Der Waals en una Columna (VdW)
los detinos son las carpetas:
    * valMxC
    * valVdW
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

    
    Los ejecutables del proyecto generan archivos que son copiados 
    en una carpeta externa a LBCUDA_Test (en el mismo fichero/PATH que ésta se encuentra)

    Para el caso de validación:

        validacion_MxC
        validacion_VdW
        validacion_cudaMxC
        validacion_cudaVdW

    Para el caso de speedUp

        speedUp_MxC
        speedUp_VdW
        speedUp_cudaMxC
        speedUp_cudaVdW

    La limpieza de los archivos generados se hacen con los ejecutables de nombre Clean

    VALIDACION :

        Por defectos las grillas de validación son 
        
            MxC  100 100
            VdW  3   300
            
            pueden cambiarse modificando el ejecutable correspondiente

        Por defecto las Tr varian de a 0.025 con Tr = [ 0.6 ; 0.975 ]
        
    SPEED UP

        Por defecto la configuración para la toma de tiempo es un total de 50000 pasos para VdW y MxC
        
        Para MxC las grillas son cuadraras siendo su tamaño de:
            16x 16 32x32 64x64 128x128 256x256 512x512 1024x1024 2048x2048 4096x4096

        Para VdW las grillas son rectangulares siendo su tamaño de:
            3x 3 32x32 3x64 3x128 3x256 3x512 3x1024 3x2048 3x4096

        Para los casos de CUDA se correrán en la siguiente cantidad de bloques:
            1 2 4 8 16 32 64 128 256 512

        Por como están configurado los ejecutables del speedUp lo único que tendrá como salida 
        es un archivo llamado time_exc con el tiempo de ejecución.

