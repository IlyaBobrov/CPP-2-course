//
// Created by илья on 10.10.2019.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <functional>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>

class PrimeNumberGenerator {

public:
    explicit PrimeNumberGenerator(int start) {
        this->start = start;
    }
    int GetNextPrime() {
        int i = 2;
        if (this->start == 1) this->start++;
        while (i < this->start) {
            if ((this->start % i) == 0 || this->start == 1) {
                this->start++;
                i = 2;
            } else {
                i++;
            }
        }
        this->start++;
        return this->start - 1;
    }

private:
    int start;
};





