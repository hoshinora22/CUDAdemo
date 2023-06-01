#include <iostream>

__global__ void hi_gpu() {
    printf("Hello World from GPU!\n");
}

int main() {
    hi_gpu<<<1, 1>>>();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
