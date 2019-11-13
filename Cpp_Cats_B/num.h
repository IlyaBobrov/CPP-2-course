//
// Created by илья on 10.10.2019.
//
#pragma once

#ifndef CPP_CATS_B_NUM_H
#define CPP_CATS_B_NUM_H



#include <iostream>

class Num {
public:

    //конструктор
    Num(int value = 0, int modulo = 0);

    //конструктор копирования
    Num(const Num& other);

    int value;
    int modulo;
};

#endif //CPP_CATS_B_NUM_H
