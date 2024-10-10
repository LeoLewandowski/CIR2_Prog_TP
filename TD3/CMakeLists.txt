cmake_minimum_required (VERSION 3.9)

project(CIR2_Prog_TP)

if(NOT MSVC)
    link_libraries(m) #to link with libm on Unix 
endif()

add_executable(TD3_1 TD3_1.cpp)
add_executable(TD3_2 TD3_2.cpp "Point.cpp" "Shapes.cpp")
add_executable(TD3_3 TD3_3.cpp "Point.cpp")
add_executable(TD3_4 TD3_4.cpp "Point.cpp")