//
// Created by илья on 06.10.2019.
//
// For tests

#define CATCH_CONFIG_MAIN

#include <iostream>
#include "Catch.hpp"
#include "Vector.h"
#include "Matrix.h"
#include "Base.h"

using namespace std;
using namespace mat_vec;

#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)

const double lim = 0.000000000001;

// Конструирует вектор размера size со значениями value
TEST_CASE("Vector::Vector(size_t size, double value)") {
    Vector vector(10, 0.1);
    REQUIRE(vector.size() == 10);
    fori(10) {
        REQUIRE(vector[i] - 0.1 < lim);
    }
}

// Конструктор копирования
TEST_CASE("Vector::Vector(const Vector &src)") {
    Vector vector_src(10, 0.1);
    Vector vector(vector_src);
    REQUIRE(vector.size() == 10);
    fori(10) {
        REQUIRE(vector[i] - 0.1 < lim);
    }
}

// Оператор присваивания
TEST_CASE("Vector &Vector::operator=(const Vector &rhs)") {
    Vector vector_src(10, 0.1);
    Vector vector = vector_src;
    REQUIRE(vector.size() == 10);
    fori(10) {
        REQUIRE(vector[i] - 0.1 < lim);
    }
}

// Возвращает размер вектора
TEST_CASE("size_t Vector::size() const") {
    Vector vector(10);
    REQUIRE(vector.size() == 10);
}

// Доступ к n-му элементу вектора
TEST_CASE("double Vector::operator[](size_t n) const") {
    Vector vector(10, 0.1);
    REQUIRE(vector[2] - 0.1 < lim);
}

TEST_CASE("double &Vector::operator[](size_t n)") {
    Vector vector(10, 1);
    vector[2] = 0.1;
    REQUIRE(vector[2] - 0.1 < lim);
}

// L2 норма вектора
TEST_CASE("double Vector::norm() const") {
    Vector vector(4, 5);
    REQUIRE(vector.norm() - 10 < lim);
}

// Возвращает новый вектор, полученный нормализацией текущего (this)
TEST_CASE("Vector Vector::normalized() const") {
    Vector vector(4, 5);
    Vector vector_src(vector);
    vector = vector_src.normalized();
    fori(4) {
        REQUIRE(vector[i] - 0.5 < lim);
    }
}

// Нормализует текущий вектор
TEST_CASE("void Vector::normalize()") {
    Vector vector(4, 5);
    vector.normalize();
    fori(4) {
        REQUIRE(vector[i] - 0.5 < lim);
    }
}

TEST_CASE("Vector Vector::operator+(const Vector &rhs) const") {
    Vector vector1(4, 1);
    Vector vector2(4, 9);
    Vector result(vector2);
    result = vector1 + vector2;
    fori(4) {
        REQUIRE(result[i] - 10 < lim);
    }
}

TEST_CASE("Vector &Vector::operator+=(const Vector &rhs)") {
    Vector vector1(4, 1);
    Vector vector2(4, 9);
    vector2 += vector1;
    fori(4) {
        REQUIRE(vector2[i] - 10 < lim);
    }
}

TEST_CASE("Vector Vector::operator-(const Vector &rhs) const") {
    Vector vector1(4, 1);
    Vector vector2(4, 9);
    Vector result(vector2);
    result = vector2 - vector1;
    fori(4) {
        REQUIRE(result[i] - 8 < lim);
    }
}

TEST_CASE("Vector &Vector::operator-=(const Vector &rhs)") {
    Vector vector1(4, 1);
    Vector vector2(4, 9);
    vector2 -= vector1;
    fori(4) {
        REQUIRE(vector2[i] - 8 < lim);
    }
}

// Поэлементное умножение векторов
TEST_CASE("Vector Vector::operator^(const Vector &rhs) const") {
    Vector vector1(4, 5);
    Vector vector2(4, 2);
    Vector result(vector2);
    result = vector1 ^ vector2;
    fori(4) {
        REQUIRE(result[i] - 10 < lim);
    }
}

TEST_CASE("Vector &Vector::operator^=(const Vector &rhs)") {
    Vector vector1(4, 5);
    Vector vector2(4, 2);
    vector1 ^= vector2;
    fori(4) {
        REQUIRE(vector2[i] - 10 < lim);
    }
}

TEST_CASE("double Vector::operator*(const Vector &rhs) const") {
    Vector vector1(4, 5);
    Vector vector2(4, 2);
    double result = vector1 * vector2;
    REQUIRE(result - 40 < lim);
}

TEST_CASE("Vector Vector::operator*(double k) const") {
    Vector vector1(4, 5);
    Vector vector2(4, 2);
    vector1 = vector2 * 5;
    fori(4) {
        REQUIRE(vector1[i] - 10 < lim);
    }
}



// Умножение всех элементов вектора на скаляр справа (v * k)
TEST_CASE("Vector mat_vec::operator*(double k, const Vector &v)") {
    Vector vector1(4, 5);
    Vector vector2(4, 2);
    vector1 = vector2 * 5;
    fori(4) {
        REQUIRE((vector1[i] - 10) < lim);
    }
}

TEST_CASE("Vector &Vector::operator*=(double k)") {
    Vector vector(4, 2);
    vector *= 5;
    fori(4) {
        REQUIRE(vector[i] - 10 < lim);
    }
}

TEST_CASE("Vector Vector::operator/(double k) const") {
    Vector vector1(4, 6);
    Vector vector2(4, 4);
    vector2 = vector1 / 2;
    fori(4) {
        REQUIRE(vector2[i] - 3 < lim);
    }
}

TEST_CASE("Vector &Vector::operator/=(double k)") {
    Vector vector(4, 6);
    vector /= 2;
    fori(4) {
        REQUIRE(vector[i] - 3 < lim);
    }
}

TEST_CASE("Vector Vector::operator*(const Matrix &mat) const") {
    Matrix mat(2, 3, 0);
    Vector vector1(2);
    fori(2) {
        forj(3) {
            mat.get(i, j) = i * 3 + j + 1;
        }
    }
    fori(2) {
        vector1[i] = i + 1;
    }
    Vector vector2 = vector1 * mat;
    REQUIRE(vector2.size() == 3);
    REQUIRE(vector2[0] - 9 < lim);
    REQUIRE(vector2[1] - 12 < lim);
    REQUIRE(vector2[2] - 15 < lim);
}

TEST_CASE("Vector &Vector::operator*=(const Matrix &mat)") {
    Matrix matrix(2, 3, 0);
    Vector vector(2);
    fori(2) {
        forj(3) {
            matrix.get(i, j) = i * 3 + j + 1;
        }
    }
    fori(2) {
        vector[i] = i + 1;
    }
    vector *= matrix;
    REQUIRE(vector.size() == 3);
    REQUIRE(vector[0] - 9 < lim);
    REQUIRE(vector[1] - 12 < lim);
    REQUIRE(vector[2] - 15 < lim);
}

TEST_CASE("bool Vector::operator==(const Vector &rhs) const") {
    Vector vector1(4, 5);
    Vector vector2(4, 3);
    Vector rhs(4, 5);
    REQUIRE(rhs == vector1);
    REQUIRE(!(vector2 == vector1));
}

TEST_CASE("bool Vector::operator!=(const Vector &rhs) const") {
    Vector vector1(4, 5);
    Vector vector2(4, 5);
    Vector rhs(4, 4);
    REQUIRE(rhs != vector1);
    REQUIRE(!(vector2 != vector1));
}

//
TEST_CASE("Matrix::Matrix(size_t size, double value)") {
    Matrix matrix(3, 5);
    REQUIRE(matrix.shape().first == 3);
    REQUIRE(matrix.shape().second == 3);
    fori(3) {
        forj(3) {
            REQUIRE(matrix.get(i, j) - 5 < lim);
        }
    }
}

TEST_CASE("Matrix Matrix::eye(size_t size)") {
    Matrix matrix(3);
    matrix = matrix.eye(3);
    fori(3) {
        forj(3) {
            if (i == j) {
                REQUIRE(matrix.get(i, j) - 1 < lim);
            } else {
                REQUIRE(matrix.get(i, j) - 0 < lim);
            }
        }
    }
}

TEST_CASE("Matrix::Matrix(size_t rows, size_t cols, double value)") {
    Matrix matrix(2, 4, 3);
    fori(2) {
        forj(4) {
            REQUIRE(matrix.get(i, j) - 3 < lim);
        }
    }
}

TEST_CASE("Matrix::Matrix(const Matrix &src)") {
    Matrix matrix(5, 3);
    Matrix matrix2(matrix);
    fori(5) {
        forj(5) {
            REQUIRE(matrix2.get(i, j) - 3 < lim);
        }
    }
}

TEST_CASE("Matrix &Matrix::operator=(const Matrix &rhs)") {
    Matrix matrix1(5, 3);
    Matrix matrix2 = matrix1;
    fori(5) {
        forj(5) {
            REQUIRE(matrix2.get(i, j) - 3 < lim);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("void Matrix::reshape(size_t rows, size_t cols)\nstd::pair<size_t, size_t> Matrix::shape() const") {
    Matrix matrix1(2, 4, 3);
    REQUIRE(matrix1.shape().first == 2);
    REQUIRE(matrix1.shape().second == 4);
    fori(matrix1.shape().first) {
        forj(matrix1.shape().second) {
            matrix1.get(i, j) = i * matrix1.shape().second + j + 1;
        }
    }
    matrix1.reshape(4, 2);
    REQUIRE(matrix1.shape().first == 4);
    REQUIRE(matrix1.shape().second == 2);
    fori(matrix1.shape().first/*4*/) {
        forj(matrix1.shape().second/*2*/) {
            REQUIRE(abs(matrix1.get(i, j) - (i * matrix1.shape().second + j + 1)) < lim);
        }
    }
}
//TEST_CASE("void Matrix::reshape(size_t rows, size_t cols)\nstd::pair<size_t, size_t> Matrix::shape() const") {
//
//    mat_test2.reshape(3,3);
//    REQUIRE(mat_test2.shape().first == 3);
//    REQUIRE(mat_test2.shape().second == 3);
//    count = 0;
//    for (size_t i = 0; i < mat_test2.shape().first; ++i) {
//        for (size_t j = 0; j < mat_test2.shape().second; ++j) {
//            REQUIRE(mat_test2.get(i, j) == count++);
//        }
//    }
//}


TEST_CASE("Matrix Matrix::operator+(const Matrix &rhs) const") {
    Matrix matrix(4, 5);
    Matrix matrix2(4, 7);
    Matrix matrix3(matrix2);
    matrix3 = matrix2 + matrix;
    fori(4) {
        forj(4) {
            REQUIRE(matrix3.get(i, j) - 12 < lim);
        }
    }
}

TEST_CASE("Matrix &Matrix::operator+=(const Matrix &rhs)") {
    Matrix matrix(4, 5);
    Matrix matrix2(4, 7);
    matrix2 += matrix;
    fori(4) {
        forj(4) {
            REQUIRE(matrix2.get(i, j) - 12 < lim);
        }
    }
}

TEST_CASE("Matrix Matrix::operator-(const Matrix &rhs) const") {
    Matrix matrix(4, 5);
    Matrix matrix2(4, 7);
    Matrix matrix3(matrix2);
    matrix3 = matrix2 - matrix;
    fori(4) {
        forj(4) {
            REQUIRE(matrix3.get(i, j) - 2 < lim);
        }
    }
}

TEST_CASE("Matrix &Matrix::operator-=(const Matrix &rhs)") {
    Matrix matrix(4, 5);
    Matrix matrix2(4, 7);
    matrix2 -= matrix;
    fori(4) {
        forj(4) {
            REQUIRE(matrix2.get(i, j) - 2 < lim);
        }
    }
}

TEST_CASE("Matrix Matrix::operator*(const Matrix &rhs) const") {
    Matrix matrix(2, 4, 0);
    matrix.get(0, 0) = 1;
    matrix.get(0, 1) = 2;
    matrix.get(0, 2) = 3;
    matrix.get(0, 3) = 4;
    matrix.get(1, 0) = 5;
    matrix.get(1, 1) = 6;
    matrix.get(1, 2) = 7;
    matrix.get(1, 3) = 8;
    Matrix matrix2(4, 3, 0);
    matrix2.get(0, 0) = 1;
    matrix2.get(0, 1) = 2;
    matrix2.get(0, 2) = 3;
    matrix2.get(1, 0) = 4;
    matrix2.get(1, 1) = 5;
    matrix2.get(1, 2) = 6;
    matrix2.get(2, 0) = 7;
    matrix2.get(2, 1) = 8;
    matrix2.get(2, 2) = 9;
    matrix2.get(3, 0) = 10;
    matrix2.get(3, 1) = 11;
    matrix2.get(3, 2) = 12;
    Matrix matrix3 = matrix * matrix2;
    REQUIRE(matrix3.get(0, 0) - 70 < lim);
    REQUIRE(matrix3.get(0, 1) - 80 < lim);
    REQUIRE(matrix3.get(0, 2) - 90 < lim);
    REQUIRE(matrix3.get(1, 0) - 158 < lim);
    REQUIRE(matrix3.get(1, 1) - 184 < lim);
    REQUIRE(matrix3.get(1, 2) - 210 < lim);
}

TEST_CASE("Matrix &Matrix::operator*=(const Matrix &rhs)") {
    Matrix matrix(2, 4, 0);
    matrix.get(0, 0) = 1;
    matrix.get(0, 1) = 2;
    matrix.get(0, 2) = 3;
    matrix.get(0, 3) = 4;
    matrix.get(1, 0) = 5;
    matrix.get(1, 1) = 6;
    matrix.get(1, 2) = 7;
    matrix.get(1, 3) = 8;
    Matrix matrix2(4, 3, 0);
    matrix2.get(0, 0) = 1;
    matrix2.get(0, 1) = 2;
    matrix2.get(0, 2) = 3;
    matrix2.get(1, 0) = 4;
    matrix2.get(1, 1) = 5;
    matrix2.get(1, 2) = 6;
    matrix2.get(2, 0) = 7;
    matrix2.get(2, 1) = 8;
    matrix2.get(2, 2) = 9;
    matrix2.get(3, 0) = 10;
    matrix2.get(3, 1) = 11;
    matrix2.get(3, 2) = 12;
    matrix *= matrix2;
    REQUIRE(matrix2.get(0, 0) - 70 < lim);
    REQUIRE(matrix2.get(0, 1) - 80 < lim);
    REQUIRE(matrix2.get(0, 2) - 90 < lim);
    REQUIRE(matrix2.get(1, 0) - 158 < lim);
    REQUIRE(matrix2.get(1, 1) - 184 < lim);
    REQUIRE(matrix2.get(1, 2) - 210 < lim);
}

TEST_CASE("Matrix Matrix::operator*(double k) const") {
    Matrix matrix(4, 6);
    Matrix matrix2(4);
    matrix2 = matrix * 2;
    fori(4) {
        forj(4) {
            REQUIRE(matrix2.get(i, j) - 12 < lim);
        }
    }
}

TEST_CASE("Matrix &Matrix::operator*=(double k)") {
    Matrix matrix(4, 6);
    matrix *= 2;
    fori(4) {
        forj(4) {
            REQUIRE(matrix.get(i, j) - 12 < lim);
        }
    }
}

TEST_CASE("Matrix Matrix::operator/(double k) const") {
    Matrix matrix(4, 6);
    Matrix matrix2(4);
    matrix2 = matrix / 2;
    fori(4) {
        forj(4) {
            REQUIRE(matrix2.get(i, j) - 3 < lim);
        }
    }
}

TEST_CASE("Matrix &Matrix::operator/=(double k)") {
    Matrix matrix(4, 6);
    matrix /= 2;
    fori(4) {
        forj(4) {
            REQUIRE(matrix.get(i, j) - 3 < lim);
        }
    }
}

TEST_CASE("Matrix Matrix::transposed() const") {
    Matrix matrix(3);
    matrix.get(0, 0) = 1;
    matrix.get(0, 1) = 2;
    matrix.get(0, 2) = 4;
    matrix.get(1, 0) = 5;
    matrix.get(1, 1) = 7;
    matrix.get(1, 2) = 8;
    matrix.get(2, 0) = 10;
    matrix.get(2, 1) = 11;
    matrix.get(2, 2) = 13;
    Matrix matrix2 = matrix.transposed();
    REQUIRE(matrix2.get(0, 0) - 1 < lim);
    REQUIRE(matrix2.get(0, 1) - 5 < lim);
    REQUIRE(matrix2.get(0, 2) - 10 < lim);
    REQUIRE(matrix2.get(1, 0) - 2 < lim);
    REQUIRE(matrix2.get(1, 1) - 7 < lim);
    REQUIRE(matrix2.get(1, 2) - 11 < lim);
    REQUIRE(matrix2.get(2, 0) - 4 < lim);
    REQUIRE(matrix2.get(2, 1) - 8 < lim);
    REQUIRE(matrix2.get(2, 2) - 13 < lim);
}

TEST_CASE("void Matrix::transpose()") {
    Matrix matrix(3);
    matrix.get(0, 0) = 1;
    matrix.get(0, 1) = 2;
    matrix.get(0, 2) = 4;
    matrix.get(1, 0) = 5;
    matrix.get(1, 1) = 7;
    matrix.get(1, 2) = 8;
    matrix.get(2, 0) = 10;
    matrix.get(2, 1) = 11;
    matrix.get(2, 2) = 13;
    matrix.transpose();
    REQUIRE(matrix.get(0, 0) - 1 < lim);
    REQUIRE(matrix.get(0, 1) - 5 < lim);
    REQUIRE(matrix.get(0, 2) - 10 < lim);
    REQUIRE(matrix.get(1, 0) - 2 < lim);
    REQUIRE(matrix.get(1, 1) - 7 < lim);
    REQUIRE(matrix.get(1, 2) - 11 < lim);
    REQUIRE(matrix.get(2, 0) - 4 < lim);
    REQUIRE(matrix.get(2, 1) - 8 < lim);
    REQUIRE(matrix.get(2, 2) - 13 < lim);
}

TEST_CASE("double Matrix::det() const") {
    Matrix matrix(3);
    matrix.get(0, 0) = 1;
    matrix.get(0, 1) = 2;
    matrix.get(0, 2) = 4;
    matrix.get(1, 0) = 5;
    matrix.get(1, 1) = 7;
    matrix.get(1, 2) = 8;
    matrix.get(2, 0) = 10;
    matrix.get(2, 1) = 11;
    matrix.get(2, 2) = 13;
    double det = matrix.det();
    REQUIRE(det - (-27) < lim);
}

TEST_CASE("Matrix Matrix::inv() const") {
    double eps = 0.000001;
    Matrix matrix(3);
    matrix.get(0, 0) = 1;
    matrix.get(0, 1) = 2;
    matrix.get(0, 2) = 4;
    matrix.get(1, 0) = 5;
    matrix.get(1, 1) = 7;
    matrix.get(1, 2) = 8;
    matrix.get(2, 0) = 10;
    matrix.get(2, 1) = 11;
    matrix.get(2, 2) = 13;
    matrix = matrix.inv();
    REQUIRE(matrix.get(0, 0) - (-0.111111) < eps);
    REQUIRE(matrix.get(0, 1) - (-0.666667) < eps);
    REQUIRE(matrix.get(0, 2) - (0.444444) < eps);
    REQUIRE(matrix.get(1, 0) - (-0.555556) < eps);
    REQUIRE(matrix.get(1, 1) - (1) < eps);
    REQUIRE(matrix.get(1, 2) - (-0.444444) < eps);
    REQUIRE(matrix.get(2, 0) - (0.555556) < eps);
    REQUIRE(matrix.get(2, 1) - (-0.333333) < eps);
    REQUIRE(matrix.get(2, 2) - (0.111111) < eps);
}

TEST_CASE("Vector Matrix::operator*(const Vector &vec) const") {
    Matrix matrix(3, 2, 0);
    Vector vector(2);
    fori(3) {
        forj(2) {
            matrix.get(i, j) = i * 2 + j + 1;
        }
    }
    fori(2) {
        vector[i] = i + 1;
    }
    Vector vector2 = matrix * vector;
    REQUIRE(vector2.size() == 3);
    REQUIRE(vector2[0] - 5 < lim);
    REQUIRE(vector2[1] - 11 < lim);
    REQUIRE(vector2[2] - 17 < lim);
}

TEST_CASE("bool Matrix::operator==(const Matrix &rhs) const") {
    Matrix matrix(5, 5);
    Matrix matrix2(5, 5);
    Matrix matrix3(5, 3);
    REQUIRE(matrix == matrix2);
    REQUIRE(!(matrix == matrix3));
}

TEST_CASE("bool Matrix::operator!=(const Matrix &rhs) const") {
    Matrix matrix(5, 5);
    Matrix matrix2(5, 3);
    Matrix matrix3(5, 3);
    REQUIRE(matrix != matrix2);
    REQUIRE(!(matrix3 != matrix2));
}
