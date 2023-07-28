cmake_minimum_required(VERSION 3.22)
project(clox)

set(CMAKE_CXX_STANDARD 17)

add_executable(clox main.c
        common.h
        chunk.h
        chunk.c
        memory.h
        memory.c
        debug.c
        debug.h chunk.c chunk.h common.h debug.c debug.h memory.c memory.h value.h value.c vm.c vm.h compiler.c compiler.h scanner.c scanner.h object.h object.c)
