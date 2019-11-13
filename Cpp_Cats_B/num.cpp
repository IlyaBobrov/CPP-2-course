#include <iostream>
#include "num.h"

Num::Num(const Num &other) {
    this->value = other.value;
    this->modulo = 0;
}

Num::Num(int value, int modulo) {
    if (modulo != 0)
        this->value = value % modulo;
    else
        this->value = value;
    this->modulo = modulo;
}
