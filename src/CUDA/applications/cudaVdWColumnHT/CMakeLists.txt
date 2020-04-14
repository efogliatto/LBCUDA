#------------------ Maxwell Construction------------------#

# cudaVdWColumnHT

add_executable(cudaVdWColumnHT "cudaVdWColumnHT.cu" "writeDebug.c")

target_link_libraries(cudaVdWColumnHT ${PROJECT_LINK_LIBS} ${CUDATEST_LINK_LIBS})

set_property(TARGET cudaVdWColumnHT PROPERTY CUDA_SEPARABLE_COMPILATION ON)
