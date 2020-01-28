# Biblioteca de pruebas de CUDA

add_library(cudaTest SHARED
  zerothMoment.cu
  )

set_target_properties( cudaTest PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

