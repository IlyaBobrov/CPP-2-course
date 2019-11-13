//
// Created by илья on 10.10.2019.
//

#ifndef CPP_CATS_A_PRIME_GEN_H
#define CPP_CATS_A_PRIME_GEN_H

class PrimeNumberGenerator {
public:
    explicit PrimeNumberGenerator(int start);
    int GetNextPrime();
private:
    int start;
};


#endif //CPP_CATS_A_PRIME_GEN_H
