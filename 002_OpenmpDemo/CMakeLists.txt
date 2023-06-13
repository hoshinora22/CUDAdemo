# 指定cmake最低版本
cmake_minimum_required(VERSION 3.22)

# 项目名称
project(OpenmpDemo)

add_executable(OpenmpDemo main.cpp)

FIND_PACKAGE(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMp_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMp_CXX_FLAGS}")
endif ()

