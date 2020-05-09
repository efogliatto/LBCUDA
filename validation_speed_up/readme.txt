En la presente carpeta se encuentran los detinos de los datos de validación y de speed up 
del problema Construcción de Maxwell (MxC) y de la Estratificación de un fluido de Van Der Waals en una Columna (VdW)
los detinos son las carpetas:
    * valMxC
    * valVdW

En los ejecutables se encuentran los de validación y de speed up.
    
    Los ejecutables del proyecto generan archivos que son copiados 
    en una carpeta externa a LBCUDA_Test (en el mismo fichero/PATH que ésta se encuentra)

    La limpieza de los archivos generados se hacen con los ejecutables de nombre Clean

    Por defectos las grillas de validación son 
        MxC  100 100
        VdW  3   300
        
        pueden cambiarse modificando el ejecutable correspondiente

    Por defecto las Tr varian de a 0.025 con Tr = [ 0.6 ; 0.975 ]
    
    
