#pragma once
//
// Created by илья on 13.10.2019.
//

#ifndef HW_CPP_1_MATRIX_H
#define HW_CPP_1_MATRIX_H

#include "Base.h"
//#include "Vector.h"
#include <tuple>

namespace mat_vec {

    //class Vector;

    class Matrix {
    public:

        double &get(size_t, size_t);

        // Конструирует матрицу с размерами size x size, заполненную value
        explicit Matrix(size_t size, double value = 0);

        // Возвращает единичную матрицу
        static Matrix eye(size_t size);

        // Возвращает матрицу с размерами rows x cols, заполненную value
        Matrix(size_t rows, size_t cols, double value );

        // Конструктор копирования
        Matrix(const Matrix &src);

        // Оператор присваивания
        Matrix &operator=(const Matrix &rhs);

        // Деструктор
        ~Matrix();

        // Изменяет ширину и высоту матрицы, не изменяя при этом
        // порядок следования элементов от левого верхнего к правому нижнему:
        //
        // [1 2 3] -> [1 2]
        // [4 5 6] -> [3 4]
        //            [5 6]
        void reshape(size_t rows, size_t cols);

        // Возвращает пару {rows, cols} -- количество строк и столбцов матрицы
        std::pair<size_t, size_t> shape() const;

        // Возвращает элемент на позиции [row, col]
        double get(size_t row, size_t col) const;

        // Поэлементное сложение
        Matrix operator+(const Matrix &rhs) const;
        Matrix &operator+=(const Matrix &rhs);

        // Поэлементное вычитание
        Matrix operator-(const Matrix &rhs) const;
        Matrix &operator-=(const Matrix &rhs);

        // Матричное умножение
        Matrix operator*(const Matrix &rhs) const;
        Matrix &operator*=(const Matrix &rhs);

        // Умножение всех элементов матрицы на константу
        Matrix operator*(double k) const;
        Matrix &operator*=(double k);

        // Деление всех элементов матрицы на константу
        Matrix operator/(double k) const;
        Matrix &operator/=(double k);

        // Возвращает новую матрицу, полученную транспонированием текущей (this)
        Matrix transposed() const;

        // Транспонирует текущую матрицу
        void transpose();


        // Определитель
        double det() const;

        // Обратная матрица
        Matrix inv() const;
        Matrix preInv() const;

            // УМножение матрицы на вектор
        Vector operator*(const Vector &vec) const;

        // Поэлементное сравнение
        bool operator==(const Matrix &rhs) const;
        bool operator!=(const Matrix &rhs) const;


        double minor(int k, int d) const;


    private:
        double** data_mat;
        size_t rows_mat;
        size_t cols_mat;
    };

} // namespace mat_vec

//double Minor(double **, size_t);


#endif //HW_CPP_1_MATRIX_H
