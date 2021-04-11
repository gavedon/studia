//
// Created by krzysztof on 14.06.2020.
//

#include "operand.hpp"

Operand :: Operand() = default;

void Operand :: execute() {
    Symbol :: Stack.push(this);
}

Operand :: ~Operand() = default;
