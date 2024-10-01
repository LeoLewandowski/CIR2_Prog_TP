cmake_minimum_required (VERSION 3.9)

project(CIR2_Prog_TP)

if(NOT MSVC)
    link_libraries(m) #to link with libm on Unix 
endif()

add_executable(TD2_1 TD2_1.cpp)
add_executable(TD2_2 TD2_2.cpp)
add_executable(TD2_3 TD2_3.cpp)
add_executable(TD2_4 TD2_4.cpp "Point3D.hpp")
add_executable(TD2_5 TD2_5.cpp  "Trajectory.cpp" "Trajectory.hpp" "Point3D.hpp")