//
// Created by krzysztof on 14.06.2020.
//

#ifndef ONP_LICZBA_HPP
#define ONP_LICZBA_HPP

#include "operand.hpp"
#include <iostream>


class Liczba : public Operand {

public:
    double value;
    explicit Liczba(double);
    double getValue() override;
    ~Liczba() override;
};

#endif //ONP_LICZBA_HPP
