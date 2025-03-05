cmake_minimum_required (VERSION 3.9)

project(CIR2_Prog_TP)

if(NOT MSVC)
    link_libraries(m) #to link with libm on Unix 
endif()

add_executable(TD6 "TD6.cpp")