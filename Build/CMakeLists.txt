cmake_minimum_required(VERSION 3.17)

project(main)
set(CMAKE_CPP_COMPILER clang++)
SET(GCCCompilerFlags "-std=c++23")
FILE(GLOB SRC
        "*.cc"
        "../*.h"
        "../*.cc"
    )
add_executable(${PROJECT_NAME} ${SRC})
set (CMAKE_BUILD_TYPE Debug)
