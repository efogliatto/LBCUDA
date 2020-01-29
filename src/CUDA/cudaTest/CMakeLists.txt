# Biblioteca de pruebas de CUDA

add_library(cudatest SHARED
  zerothMoment.cu
  )

set_target_properties( cudatest PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

