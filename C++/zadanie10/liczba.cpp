//
// Created by krzysztof on 14.06.2020.
//

#include "liczba.hpp"

using namespace std;

Liczba :: Liczba(double constrValue) {
    value= constrValue;
}

double Liczba :: getValue() {
    return this->value;
}

Liczba :: ~Liczba() = default;
