
#include "Vector.h"
#include "Matrix.h"
#include <cmath>



// Конструирует вектор размера size со значениями value
mat_vec::Vector::Vector(size_t size, double value) {
    data_vec = new double[size];
    size_vec = size;
    for (size_t i = 0; i < size; i++) {
        data_vec[i] = value;
    }
}

// Конструктор копирования
mat_vec::Vector::Vector(const mat_vec::Vector &src) {
    //delete[](this->data_vec);
    this->size_vec = src.size_vec;
    this->data_vec = new double[this->size_vec];
    for (size_t i = 0; i < this->size_vec; i++)
        this->data_vec[i] = src.data_vec[i];
}

// Оператор присваивания
mat_vec::Vector &mat_vec::Vector::operator=(const mat_vec::Vector &rhs) {
    this->size_vec = rhs.size_vec;
    delete[](this->data_vec);
    this->data_vec = new double[this->size_vec];
    for (size_t i = 0; i < this->size_vec; i++)
        this->data_vec[i] = rhs.data_vec[i];
    return *this;
}

// Деструктор
mat_vec::Vector::~Vector() {
    delete[](data_vec);
    data_vec = nullptr;
    size_vec = 0;
}

// Возвращает размер вектора
size_t mat_vec::Vector::size() const {
    return this->size_vec;
}

// Доступ к n-му элементу вектора
double mat_vec::Vector::operator[](size_t n) const {
    return this->data_vec[n];
}

double &mat_vec::Vector::operator[](size_t n) {
    return this->data_vec[n];
}

// L2 норма вектора
double mat_vec::Vector::norm() const {
    double sum = 0;
    for (size_t i = 0; i < this->size_vec; i++)
        sum += this->data_vec[i] * this->data_vec[i];
    return sqrt(sum);

}

// Возвращает новый вектор, полученный нормализацией текущего (this)
mat_vec::Vector mat_vec::Vector::normalized() const {
    Vector res(*this);
    double norm_vec = res.norm();
    for (size_t i = 0; i < this->size_vec; i++)
        res.data_vec[i] = this->data_vec[i] / norm_vec;
    return res;
}

// Нормализует текущий вектор
void mat_vec::Vector::normalize() {
    double norm_vec = norm();
    for (size_t i = 0; i < this->size_vec; i++)
        this->data_vec[i] /= norm_vec;
}

// Поэлементное сложение векторов
mat_vec::Vector mat_vec::Vector::operator+(const mat_vec::Vector &rhs) const {
    Vector res(this->size_vec);
    for (size_t i = 0; i < size_vec; i++)
        res.data_vec[i] = this->data_vec[i] + rhs.data_vec[i];
    return res;
}

mat_vec::Vector &mat_vec::Vector::operator+=(const mat_vec::Vector &rhs) {
    for (size_t i = 0; i < size_vec; i++)
        this->data_vec[i] = this->data_vec[i] + rhs.data_vec[i];
    return *this;
}

// Поэлементное вычитание векторов
mat_vec::Vector mat_vec::Vector::operator-(const mat_vec::Vector &rhs) const {
    Vector res(this->size_vec);
    for (size_t i = 0; i < size_vec; i++)
        res.data_vec[i] = this->data_vec[i] - rhs.data_vec[i];
    return res;
}

mat_vec::Vector &mat_vec::Vector::operator-=(const mat_vec::Vector &rhs) {
    for (size_t i = 0; i < size_vec; i++)
        this->data_vec[i] -= rhs.data_vec[i];
    return *this;
}

// Поэлементное умножение векторов
mat_vec::Vector mat_vec::Vector::operator^(const mat_vec::Vector &rhs) const {
    Vector res(this->size_vec);
    for (size_t i = 0; i < size_vec; i++)
        res.data_vec[i] = this->data_vec[i] * rhs.data_vec[i];
    return res;
}

mat_vec::Vector &mat_vec::Vector::operator^=(const mat_vec::Vector &rhs) {
    for (size_t i = 0; i < size_vec; i++)
        this->data_vec[i] *= rhs.data_vec[i];
    return *this;
}

// Скалярное произведение
double mat_vec::Vector::operator*(const mat_vec::Vector &rhs) const {
    double res = 0;
    for (size_t i = 0; i < this->size_vec; i++) {
        res += this->data_vec[i] * rhs.data_vec[i];
    }
    return res;
}

// Умножение всех элементов вектора на скаляр справа (v * k)
mat_vec::Vector mat_vec::Vector::operator*(double k) const {
    Vector res(this->size_vec);
    for (size_t i = 0; i < this->size_vec; i++)
        res.data_vec[i] = this->data_vec[i] * k;
    return res;
}

mat_vec::Vector &mat_vec::Vector::operator*=(double k) {
    for (size_t i = 0; i < this->size_vec; i++)
        this->data_vec[i] *= k;
    return *this;
}

// Деление всех элементов вектора на скаляр
mat_vec::Vector mat_vec::Vector::operator/(double k) const {

    Vector res(this->size_vec);
    for (size_t i = 0; i < this->size_vec; i++)
        res.data_vec[i] = this->data_vec[i] / k;
    return res;
}

mat_vec::Vector &mat_vec::Vector::operator/=(double k) {
    for (size_t i = 0; i < this->size_vec; i++)
        this->data_vec[i] /= k;
    return *this;
}

// Умножение вектора на матрицу
mat_vec::Vector mat_vec::Vector::operator*(const Matrix &mat) const {
    //std::pair<size_t, size_t> p = mat.shape();
    ////{rows, cols}
    //for (size_t i = 0; i < p.second/*cols*/; i++)
    //    for (size_t j = 0; j < this->size_vec/*rows*/; j++)
    //        res.data_vec[i] += mat.get(j, i) * this->data_vec[j];
    Vector res(mat.shape().second);
    for (size_t i = 0; i < res.size_vec; i++) {
        double result = 0.0;
        double value;
        for (size_t j = 0; j < this->size_vec; j++) {
            value = mat.get(j, i);
            result += this->data_vec[j] * value;
        }
        res[i] = result;
    }
    return res;
}

mat_vec::Vector &mat_vec::Vector::operator*=(const Matrix &mat) {
    //std::pair<size_t, size_t> p = mat.shape();
    //{rows, cols}
    //if (this->size_vec != p.second) exit(0);
    //for (size_t i = 0; i < p.second; i++)
    //    for (size_t j = 0; j < this->size_vec; j++)
    //        this->data_vec[i] += mat.get(j, i) * this->data_vec[j];
    //return *this;
    return *this = *this * mat;
}

// Поэлементное сравнение
bool mat_vec::Vector::operator==(const mat_vec::Vector &rhs) const {
    if (this->size_vec != rhs.size_vec) return false;
    for (size_t i = 0; i < this->size_vec; i++)
        if (this->data_vec[i] != rhs.data_vec[i]) return false;
    return true;
}

bool mat_vec::Vector::operator!=(const mat_vec::Vector &rhs) const {
    if (this->size_vec != rhs.size_vec) return true;
    for (size_t i = 0; i < this->size_vec; i++)
        if (this->data_vec[i] == rhs.data_vec[i]) return false;
    return true;
}