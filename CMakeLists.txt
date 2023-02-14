cmake_minimum_required(VERSION 3.13)
project(proj C)

set(CMAKE_C_STANDARD 99)

add_executable(proj cmake-build-debug/interpretador.c cmake-build-debug/interpretador.h cmake-build-debug/estado.h cmake-build-debug/main.c cmake-build-debug/estado.c cmake-build-debug/stack.c)