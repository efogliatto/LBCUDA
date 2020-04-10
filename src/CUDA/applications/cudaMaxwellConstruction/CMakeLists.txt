#------------------ Maxwell Construction------------------#

# cudaMaxwellConstruction

add_executable(cudaMaxwellConstruction "cudaMaxwellConstruction.cu")

target_link_libraries(cudaMaxwellConstruction ${PROJECT_LINK_LIBS} ${CUDATEST_LINK_LIBS})

set_property(TARGET cudaMaxwellConstruction PROPERTY CUDA_SEPARABLE_COMPILATION ON)
