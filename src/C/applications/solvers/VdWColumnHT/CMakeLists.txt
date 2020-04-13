#------------------ VdWColumnHT------------------#


# VdWColumnHT

add_executable(VdWColumnHT "VdWColumnHT.c" "writeDebug.c")

target_link_libraries(VdWColumnHT ${PROJECT_LINK_LIBS} ${PROJECT_LINK_LIBS})
