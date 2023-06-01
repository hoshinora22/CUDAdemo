//
// Created by Nora on 2023-6-1.
//

#pragma once

#include <vector>

namespace Utils
{

const static double eps = 1e-5;

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

