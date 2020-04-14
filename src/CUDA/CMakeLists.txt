# Estructura de malla para device
add_subdirectory (latticeMesh)

# Bibliotecas de pruebas
add_subdirectory (cudaTest)

# Bibliotecas de modelos LB
add_subdirectory (lbEquation)

# Operadores diferenciales con diferencias finitas
add_subdirectory (FDOperations)

# Aplicaciones
add_subdirectory (applications)
