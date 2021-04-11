//
// Created by krzysztof on 14.06.2020.
//

#ifndef ONP_OPERAND_HPP
#define ONP_OPERAND_HPP

#include "symbol.hpp"
#include <iostream>

using namespace std;

class Operand : public Symbol {

public:
    Operand();
    virtual double getValue()= 0;
    void execute() override;
    ~Operand() override;
};

#endif //ONP_OPERAND_HPP
