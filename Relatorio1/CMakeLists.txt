cmake_minimum_required(VERSION 3.13)
project(Relatorio1)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include_directories(.)

add_executable(Relatorio1
        Exercicio02.cpp
        Exercicio02.h
        Exercicio01.cpp
        Exercicio01.h
        Matriz.h
        Relatorio1.cpp)
