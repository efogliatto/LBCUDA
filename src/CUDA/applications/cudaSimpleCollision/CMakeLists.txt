#------------------ simpleCollision------------------#

# cudaSimpleCollision

add_executable(cudaSimpleCollision "cudaSimpleCollision.cu")

target_link_libraries(cudaSimpleCollision ${PROJECT_LINK_LIBS} ${CUDATEST_LINK_LIBS})

set_property(TARGET cudaSimpleCollision PROPERTY CUDA_SEPARABLE_COMPILATION ON)
