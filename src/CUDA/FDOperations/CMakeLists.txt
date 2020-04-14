# Biblioteca de pruebas para CUDA C/CXX

add_library(cudafdoperations STATIC
  cudaScalarGradient.cu
  cudaVectorDivergence.cu
  )

set_target_properties( cudafdoperations PROPERTIES CUDA_SEPARABLE_COMPILATION ON)



# Compilacion en PTX para uso de PyCUDA

add_library(cudafdoperationsPTX OBJECT
  cudaScalarGradient.cu
  cudaVectorDivergence.cu
  )

set_property(TARGET cudafdoperationsPTX PROPERTY CUDA_PTX_COMPILATION ON)

install(TARGETS cudafdoperationsPTX
   OBJECTS DESTINATION ${CMAKE_SOURCE_DIR}/ptx 
)



