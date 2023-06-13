//
// Created by nora1 on 2023/6/14.
//

#include <iostream>
#include <omp.h>

int main(int argc, char **argv)
{
    //
    omp_set_num_threads(4);
#pragma omp parallel
    {
        std::cout << "hello" << ", I am Thread " << omp_get_thread_num() << std::endl;
        if (omp_get_thread_num() == 3)
        {
            std::cout << "I am 3" << std::endl;
        }
    }
}