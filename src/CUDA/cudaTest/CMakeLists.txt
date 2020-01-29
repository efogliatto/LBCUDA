# Biblioteca de pruebas para CUDA C/CXX

add_library(cudatest STATIC
  zerothMoment.cu
  nbReduction.cu
  )

set_target_properties( cudatest PROPERTIES CUDA_SEPARABLE_COMPILATION ON)




# Compilacion en PTX para uso de PyCUDA

add_library(cudaTestPTX OBJECT
  zerothMoment.cu
  nbReduction.cu
  )

set_property(TARGET cudaTestPTX PROPERTY CUDA_PTX_COMPILATION ON)

install(TARGETS cudaTestPTX
   OBJECTS DESTINATION ${CMAKE_SOURCE_DIR}/ptx 
)



