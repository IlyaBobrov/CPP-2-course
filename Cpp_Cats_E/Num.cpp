#include <iostream>

#include "Num.h"

Num::Num(int value, int modulo) {
    if (modulo == 0)
        this->value = value;
    else
        this->value = value % modulo;
    this->modulo = modulo;
}

Num &Num::operator=(const Num &other) {
    this->value = other.value;
    this->modulo = other.modulo;
    return *this;
}

Num Num::operator+(const Num &other) {
    int64_t cur_value_mod = (this->value + other.value);
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    Num res(res_cur, modulo);
    return res;
}

Num Num::operator-(const Num &other) {
    int64_t cur_value_mod = (this->value - other.value);
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    Num res(res_cur, modulo);
    return res;
}

Num Num::operator*(const Num &other) {
    int64_t cur_value_mod = this->value * other.value;
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    Num res(res_cur, modulo);
    return res;
}

Num Num::operator+(int num) {
    int64_t cur_value_mod = this->value + num;
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    Num res(res_cur, modulo);
    return res;
}

Num Num::operator-(int num) {
    int64_t cur_value_mod = (this->value - num);
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    Num res(res_cur, modulo);
    return res;
}

Num Num::operator*(int num) {
    int64_t cur_value_mod = this->value * num;
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    Num res(res_cur, modulo);
    return res;
}

Num &Num::operator+=(const Num &other) {
    int64_t cur_value_mod = this->value + other.value;
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    this->value = res_cur;
    return *this;
}

Num &Num::operator-=(const Num &other) {
    int64_t cur_value_mod = (this->value - other.value);
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    this->value = res_cur;
    return *this;
}

Num &Num::operator*=(const Num &other) {
    int64_t cur_value_mod = (this->value * other.value);
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    this->value = res_cur;
    return *this;
}

Num &Num::operator+=(int num) {
    if (this->modulo != 0) {
        num %= this->modulo;
        this->value %= this->modulo;
    }
    int64_t cur_value_mod = (int64_t)this->value + (int64_t)num;
    if (this->modulo != 0) cur_value_mod %= (int64_t)this->modulo;
    if (cur_value_mod < 0) cur_value_mod += (int64_t)this->modulo;
    int res_cur = cur_value_mod;
    this->value = res_cur;
    return *this;
}

Num &Num::operator-=(int num) {
    int64_t cur_value_mod = (this->value - num);
    if (this->modulo != 0) cur_value_mod %= this->modulo;
    if (cur_value_mod < 0) cur_value_mod += this->modulo;
    int res_cur = cur_value_mod;
    this->value = res_cur;
    return *this;
}

Num &Num::operator*=(int num) {
    int64_t cur_value_mod = (int64_t)this->value * (int64_t)num;
    if (this->modulo != 0) cur_value_mod %= (int64_t)this->modulo;
    if (cur_value_mod < 0) cur_value_mod += (int64_t)this->modulo;
    int res_cur = cur_value_mod;
    this->value = res_cur;
    return *this;
}
