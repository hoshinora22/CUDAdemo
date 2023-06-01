cmake_minimum_required(VERSION 3.22)
project(CUDAdemo CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(CUDAdemo main.cu)

set_target_properties(CUDAdemo PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
