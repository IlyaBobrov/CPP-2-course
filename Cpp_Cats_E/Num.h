//
// Created by илья on 28.10.2019.
//

#pragma once


#ifndef CPP_CATS_E_V14_NUM_H
#define CPP_CATS_E_V14_NUM_H

class Num {
public:
    Num(int value, int modulo);

    Num& operator=(const Num& other);

    Num operator+(const Num& other);
    Num operator-(const Num& other);
    Num operator*(const Num& other);
    Num operator+(int num);
    Num operator-(int num);
    Num operator*(int num);

    Num& operator+=(const Num& other);
    Num& operator-=(const Num& other);
    Num& operator*=(const Num& other);
    Num& operator+=(int num);
    Num& operator-=(int num);
    Num& operator*=(int num);


    int value;
    int modulo;
};



#endif //CPP_CATS_E_V14_NUM_H
