# Biblioteca de pruebas para CUDA C/CXX

add_library(cudalbequation STATIC
  cudaExampleModel/cudaThreadedMatMult.cu    
  cudaExampleModel/cudaExampleCollision.cu
  )

set_target_properties( cudatest PROPERTIES CUDA_SEPARABLE_COMPILATION ON)




# Compilacion en PTX para uso de PyCUDA

add_library(cudalbequationPTX OBJECT
  cudaExampleModel/cudaThreadedMatMult.cu    
  cudaExampleModel/cudaExampleCollision.cu
  )

set_property(TARGET cudalbequationPTX PROPERTY CUDA_PTX_COMPILATION ON)

install(TARGETS cudalbequationPTX
   OBJECTS DESTINATION ${CMAKE_SOURCE_DIR}/ptx 
)



