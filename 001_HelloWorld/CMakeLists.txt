# 指定cmake最低版本
cmake_minimum_required(VERSION 3.22)

# 项目名称
project(CUDAdemo CUDA)

# cuda版本
set(CMAKE_CUDA_STANDARD 14)

# 添加编译选项，指定文件编码为UTF-8，add_compile_options需要在add_executable之前
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# 导入指定目录下的所有源码
aux_source_directory(../000_Common DIR_SRCS)

# 打印hello world
add_executable(CUDAdemo main.cu)

set_target_properties(CUDAdemo PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
