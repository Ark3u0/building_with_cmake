# first we add the executable that generates the table
add_executable(MakeTable MakeTable.cpp)

# add the command to generate the source code
add_custom_command (
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
)

# add the binary tree directory to the search path for include files
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

# add the main library
add_library(MathFunctions mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

######################
# WHAT IS HAPPENING? #
######################

# - When this project is built it will first build the MakeTable executable. 
# - It will then run MakeTable to produce Table.h. 
# - Finally, it will compile mysqrt.cxx which includes Table.h to produce the MathFunctions library. 

