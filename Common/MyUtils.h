//
// Created by Nora on 2023-6-1.
//

#pragma once

#include <vector>



namespace Utils
{

#define CHECK(call)\
{\
  const cudaError_t error=call;\
  if(error!=cudaSuccess)\
  {\
      printf("ERROR: %s:%d,",__FILE__,__LINE__);\
      printf("code:%d,reason:%s\n",error,cudaGetErrorString(error));\
      exit(1);\
  }\
}

const static double eps = 1e-5;

/// 数据初始化
void initialData(double *vec, int size)
{
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < size; ++i)
    {
        vec[i] = (double)(rand()&0xffff)/1000.0f;
    }
}

/// 检查两个长度为n的向量是否相等
void checkResult(double *hostRef, double *gpuRef, const int N)
{
    double epsilon = 1.0E-8;
    for (int i = 0; i < N; i++)
    {
        if (abs(hostRef[i] - gpuRef[i]) > epsilon)
        {
            printf("Results don\'t match!\n");
            printf("%f(hostRef[%d])!= %f(gpuRef[%d])\n", hostRef[i], i, gpuRef[i], i);
            return;
        } else
        {
            printf("%f(hostRef[%d]) = %f(gpuRef[%d])\n", hostRef[i], i, gpuRef[i], i);
        }
    }
    printf("Check result success!\n");
}

/// 矩阵
template <typename T>
struct Matrix
{
    int _row = 0;   // 矩阵行数
    int _col = 0;   // 矩阵列数
    std::vector<std::vector<T>> _data{};    // 矩阵数据

    explicit Matrix(int row, int col, const T &init) :
    _row(row), _col(col)
    {
        _data.resize(_row, std::vector<T>(_col, init));
    }

    // 获取矩阵的行数
    int getRow() const
    {
        return _row;
    }

    // 获取矩阵的列数
    int getCol() const
    {
        return _col;
    }

    // 访问矩阵中的元素
    T& operator()(int i, int j)
    {
        return _data[i][j];
    }

    // 访问矩阵中的元素（const版本）
    const T& operator()(int i, int j) const
    {
        return _data[i][j];
    }
};



}

