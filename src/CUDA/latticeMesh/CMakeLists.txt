# Biblioteca de pruebas de CUDA

add_library(cudalatticemesh SHARED
  hostToDeviceMesh.cu
  )

set_target_properties( cudalatticemesh PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

