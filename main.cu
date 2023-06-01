#include <iostream>
#include "src/MathUtils.h"

__global__ void hi_gpu()
{
    printf("Hello World from GPU!\n");
}


int main()
{
    // 用__global__定义的kernel是异步的，这意味着host不会等待kernel执行完就执行下一步
    hi_gpu<<<1, 1>>>();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}