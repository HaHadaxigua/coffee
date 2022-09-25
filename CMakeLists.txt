cmake_minimum_required(VERSION 3.23)
project(coffee C)

set(CMAKE_C_STANDARD 23)

add_executable(coffee main.c include/common.h include/common.h include/chunk.h src/chunk.c include/memory.h src/memory.c include/debug.h src/debug.c include/value.h src/value.c include/vm.h src/vm.c)
