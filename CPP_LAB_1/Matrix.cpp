//
// Created by илья on 13.10.2019.
//

#include <cmath>
#include "Matrix.h"
#include "Vector.h"

double & mat_vec::Matrix::get(size_t rows, size_t cols) {
    return data_mat[rows][cols];
}

// Конструирует матрицу с размерами size x size, заполненную value
mat_vec::Matrix::Matrix(size_t size, double value)/*:Matrix(size, size, value)*/{
    cols_mat = size;
    rows_mat = size;
    data_mat = new double* [rows_mat];
    for (size_t i = 0; i < rows_mat; i++){
        data_mat[i] = new double [cols_mat];
        for (size_t j = 0; j < cols_mat; j++)
            data_mat[i][j] = value;
    }

}

// Возвращает единичную матрицу
mat_vec::Matrix mat_vec::Matrix::eye(size_t size) {
    Matrix res(size, 0.0);
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            if (i == j)
                res.data_mat[i][j] = 1.0;
    return res;
}

// Возвращает матрицу с размерами rows x cols, заполненную value
mat_vec::Matrix::Matrix(size_t rows, size_t cols, double value) {
    cols_mat = cols;
    rows_mat = rows;
    data_mat = new double* [rows_mat];
    for (size_t i = 0; i < rows_mat; i++){
        data_mat[i] = new double [cols_mat];
        for (size_t j = 0; j < cols_mat; j++)
            data_mat[i][j] = value;
    }

}

// Конструктор копирования
mat_vec::Matrix::Matrix(const mat_vec::Matrix &src) {

    this->cols_mat = src.cols_mat;
    this->rows_mat = src.rows_mat;

    this->data_mat = new double* [this->rows_mat];
    for (size_t i = 0; i < this->rows_mat; i++){
        this->data_mat[i] = new double [this->cols_mat];
        for (size_t j = 0; j < this->cols_mat; j++)
            this->data_mat[i][j] = src.data_mat[i][j];
    }
}

// Оператор присваивания
mat_vec::Matrix& mat_vec::Matrix::operator=(const mat_vec::Matrix &rhs) {
    this->cols_mat = rhs.cols_mat;
    this->rows_mat = rhs.rows_mat;

    for (size_t i = 0; i < this->rows_mat; i++)
        delete[](this->data_mat[i]);
    delete[](this->data_mat);

    this->data_mat = new double* [this->rows_mat];
    for (size_t i = 0; i < this->rows_mat; i++){
        this->data_mat[i] = new double [this->cols_mat];
        for (size_t j = 0; j < this->cols_mat; j++)
            this->data_mat[i][j] = rhs.data_mat[i][j];
    }
    return *this;
}

mat_vec::Matrix::~Matrix() {
    for (size_t i = 0; i < this->rows_mat; i++)
        delete[](this->data_mat[i]);
    delete[](this->data_mat);
    this->rows_mat = 0;
    this->cols_mat = 0;
}

// Изменяет ширину и высоту матрицы, не изменяя при этом
// порядок следования элементов от левого верхнего к правому нижнему:
//
// [1 2 3] -> [1 2]
// [4 5 6] -> [3 4]
//            [5 6]
void mat_vec::Matrix::reshape(size_t rows, size_t cols) {
    /*

    double tmp[rows * cols];
    int k = 0;

    for (size_t i = 0; i < this->m_rows; ++i) {
        for (size_t j = 0; j < this->m_cols; ++j) {
            tmp[k] = this->matrix[i][j];
            k++;
        }
    }

    k = 0;
    for (size_t i = 0; i < this->m_rows; ++i) delete [] this->matrix[i];
    delete [] this->matrix;
    this->m_rows = rows;
    this->m_cols = cols;
    this->matrix = new double*[this->m_cols];
    for (size_t i = 0; i < this->m_rows; ++i)
        matrix[i] = new double[this->m_rows];

    for (size_t i = 0; i < this->m_rows; ++i) {
        for (size_t j = 0; j < this->m_cols; ++j) {
            this->matrix[i][j] = tmp[k];
            k++;
        }
    }

     * */

    size_t old_rows = this->rows_mat;
    size_t old_cols = this->cols_mat;
    size_t new_rows = rows;
    size_t new_cols = cols;

    //check exit
    if ((old_cols == new_cols) || (old_rows == new_rows)) return;
    if (old_cols * old_rows != new_cols * new_rows) return;/// exit('matrix dimension error');

    size_t _i = 0, _j = 0;
    double **buf = new double* [new_rows];

    for (size_t i = 0; i < new_rows; i++) {
        buf[i] = new double[new_cols];

        for (size_t j = 0; j < new_cols; j++) {
            buf[i][j] = this->data_mat[_i][_j];
            _j++;
            if (_j == old_cols){
                _i++;
                _j = 0;
            }
        }
    }

    ///==
    for (size_t i = 0; i < old_rows; i++)
        delete[](this->data_mat[i]);
    delete[](this->data_mat);

    this->cols_mat = new_cols;
    this->rows_mat = new_rows;
    this->data_mat = buf;


    for (size_t i = 0; i < new_rows; i++)
        delete[](buf[i]);
    delete[](buf);
}

// Возвращает пару {rows, cols} -- количество строк и столбцов матрицы
std::pair<size_t, size_t> mat_vec::Matrix::shape() const {
    return {this->rows_mat, this->cols_mat};
}

// Возвращает элемент на позиции [row, col]
double mat_vec::Matrix::get(size_t row, size_t col) const {
    return this->data_mat[row][col];
}

// Поэлементное сложение
mat_vec::Matrix mat_vec::Matrix::operator+(const mat_vec::Matrix &rhs) const {
    Matrix res(*this);
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            res.data_mat[i][j] = this->data_mat[i][j] + rhs.data_mat[i][j];

    return res;
}
mat_vec::Matrix& mat_vec::Matrix::operator+=(const mat_vec::Matrix &rhs) {
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            this->data_mat[i][j] += rhs.data_mat[i][j];

    return *this;
}

mat_vec::Matrix mat_vec::Matrix::operator-(const mat_vec::Matrix &rhs) const {
    Matrix res(*this);
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            res.data_mat[i][j] = this->data_mat[i][j] - rhs.data_mat[i][j];

    return res;
}

mat_vec::Matrix& mat_vec::Matrix::operator-=(const mat_vec::Matrix &rhs) {
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            this->data_mat[i][j] -= rhs.data_mat[i][j];

    return *this;
}

mat_vec::Matrix mat_vec::Matrix::operator*(const mat_vec::Matrix &rhs) const {
    Matrix res(this->rows_mat, rhs.cols_mat,0.0);
    for (int i = 0; i < this->rows_mat; i++)
        for (int j = 0; j < rhs.cols_mat; j++) {
            double buf = 0.0;
            for (int k = 0; k < this->cols_mat; k++)
                buf = this->data_mat[i][k] * rhs.data_mat[k][j];
            res.data_mat[i][j] = buf;
        }
    return res;

}

mat_vec::Matrix& mat_vec::Matrix::operator*=(const mat_vec::Matrix &rhs) {
    return *this = *this * rhs;
}

mat_vec::Matrix mat_vec::Matrix::operator*(double k) const {
    Matrix res(*this);
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            res.data_mat[i][j] = this->data_mat[i][j] * k;

    return res;
}

mat_vec::Matrix& mat_vec::Matrix::operator*=(double k) {
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            this->data_mat[i][j] *= k;

    return *this;
}

mat_vec::Matrix mat_vec::Matrix::operator/(double k) const {
    Matrix res(*this);
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            res.data_mat[i][j] = this->data_mat[i][j] / k;

    return res;
}

mat_vec::Matrix& mat_vec::Matrix::operator/=(double k) {
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            this->data_mat[i][j] /= k;

    return *this;
}

mat_vec::Matrix mat_vec::Matrix::transposed() const {
    Matrix res(*this);
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            res.data_mat[i][j] = this->data_mat[j][i];
    return res;
}


void mat_vec::Matrix::transpose() {
    *this = this->transposed();
}

// Определитель
double mat_vec::Matrix::det() const {
    Matrix det_res(*this);
    int k;
    double det = 1.0;
    int n = det_res.cols_mat;
    for (int i = 0; i < n; i++) {
        k = i;
        for (int j = i + 1; j < n; j++)
            if (std::abs(det_res.data_mat[j][i]) > std::abs(det_res.data_mat[k][i]))
                k = j;


        for (int t = 0; t < n; t++) {
            double tmp = det_res.data_mat[i][t];
            det_res.data_mat[i][t] = det_res.data_mat[k][t];
            det_res.data_mat[k][t] = tmp;
        }

        if (i != k)
            det = -det;

        det *= det_res.data_mat[i][i];
        for (int j = i + 1; j < n; j++)
            det_res.data_mat[i][j] /= det_res.data_mat[i][i];

        for (int j = 0; j < n; j++)
            if (j != i && std::abs(det_res.data_mat[j][i]) > 0.000000000001)
                for (int d = i + 1; d < n; d++)
                    det_res.data_mat[j][d] -= det_res.data_mat[i][d] * det_res.data_mat[j][i];


    }
    return det;
}

double mat_vec::Matrix::minor(int k, int d) const {
    Matrix Minor_res(this->cols_mat - 1);
    int ind1 = 0, ind2 = 0;
    for (int i = 0; i < this->rows_mat; i++)
        for (int j = 0; j < this->cols_mat; j++)
            if (k != i && d != j) {
                Minor_res.data_mat[ind1][ind2] = this->data_mat[i][j];
                ind2++;
                if (ind2 == this->cols_mat - 1) {
                    ind2 = 0;
                    ind1++;
                }
            }

    double MinorKof = (k + d) % 2 == 0 ? 1.0 : -1.0;
    double MinorDet = Minor_res.det();
    return MinorKof * MinorDet;
}

mat_vec::Matrix mat_vec::Matrix::preInv() const {
    Matrix mat_pre_inv(*this);
    for (size_t i = 0; i < mat_pre_inv.rows_mat; i++)
        for (size_t j = 0; j < mat_pre_inv.cols_mat; j++)
            mat_pre_inv.data_mat[i][j] = this->minor(i, j);

    return mat_pre_inv;
}

// Обратная матрица
mat_vec::Matrix mat_vec::Matrix::inv() const {
    Matrix mat_trans(*this);
    double detA = mat_trans.det();
    mat_trans = mat_trans.preInv();
    mat_trans = mat_trans.transposed();
    mat_trans /= detA;
    return mat_trans;
}



// УМножение матрицы на вектор
mat_vec::Vector mat_vec::Matrix::operator*(const mat_vec::Vector &vec) const {
    Vector res(this->rows_mat, 0.0);
    for (int i = 0; i < this->rows_mat; i++) {
        double result = 0.0;
        for (int j = 0; j < this-> cols_mat; j++)
            result += vec[j] * this->data_mat[i][j];
        res[i] = result;
    }
    return res;
}

bool mat_vec::Matrix::operator==(const mat_vec::Matrix &rhs) const {
    if ((this->cols_mat != rhs.cols_mat) || (this->rows_mat != rhs.rows_mat)) return false;
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            if (this->data_mat[i][j] != rhs.data_mat[i][j]) return false;

    return true;
}

bool mat_vec::Matrix::operator!=(const mat_vec::Matrix &rhs) const {
    if ((this->cols_mat != rhs.cols_mat) || (this->rows_mat != rhs.rows_mat)) return true;
    for (size_t i = 0; i < rows_mat; i++)
        for (size_t j = 0; j < cols_mat; j++)
            if (this->data_mat[i][j] == rhs.data_mat[i][j]) return false;

    return true;
}

