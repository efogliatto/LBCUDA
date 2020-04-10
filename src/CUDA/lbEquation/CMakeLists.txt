# Biblioteca de pruebas para CUDA C/CXX

add_library(cudalbequation STATIC

  cudaExampleModel/cudaThreadedMatMult.cu    
  cudaExampleModel/cudaExampleCollision.cu
  cudaExampleModel/cudaExampleDensity.cu
  cudaExampleModel/cudaExampleVelocity.cu
  
  cudaMomentoFunciondist/cudaMomentoCollision.cu
  cudaMomentoFunciondist/cudaMomentoDensity.cu
  cudaMomentoFunciondist/cudaMomentoVelocity.cu
  cudaMomentoFunciondist/cudaStreaming.cu

  cudaFuerza/cudaFuerzaPresionEOS.cu
  cudaFuerza/cudaFuerzaPsi.cu
  cudaFuerza/cudaFuerzaFuerzaint.cu
  cudaFuerza/cudaFuerzaFuerzatotal.cu
  cudaFuerza/cudaFuerzaS.cu

  )

set_target_properties( cudatest PROPERTIES CUDA_SEPARABLE_COMPILATION ON)




# Compilacion en PTX para uso de PyCUDA

add_library(cudalbequationPTX OBJECT
  cudaExampleModel/cudaThreadedMatMult.cu    
  cudaExampleModel/cudaExampleCollision.cu
  cudaExampleModel/cudaExampleDensity.cu
  cudaExampleModel/cudaExampleVelocity.cu

  cudaMomentoFunciondist/cudaMomentoCollision.cu
  cudaMomentoFunciondist/cudaMomentoDensity.cu
  cudaMomentoFunciondist/cudaMomentoVelocity.cu
  cudaMomentoFunciondist/cudaStreaming.cu  

  cudaFuerza/cudaFuerzaPresionEOS.cu
  cudaFuerza/cudaFuerzaPsi.cu
  cudaFuerza/cudaFuerzaFuerzaint.cu
  cudaFuerza/cudaFuerzaFuerzatotal.cu
  cudaFuerza/cudaFuerzaS.cu

  )

set_property(TARGET cudalbequationPTX PROPERTY CUDA_PTX_COMPILATION ON)

install(TARGETS cudalbequationPTX
   OBJECTS DESTINATION ${CMAKE_SOURCE_DIR}/ptx 
)



