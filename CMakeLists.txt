cmake_minimum_required(VERSION 3.23)
project(coffee C)

set(CMAKE_C_STANDARD 23)

add_executable(coffee main.c common.h common.h chunk.h chunk.c memory.h memory.c debug.h debug.c)
