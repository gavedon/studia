//
// Created by krzysztof on 14.06.2020.
//

#include "symbol.hpp"
#include "liczba.hpp"

using namespace std;

Symbol :: Symbol() = default;

double Symbol :: result() {
    double result = dynamic_cast<Liczba*>(Symbol::Stack.top())->getValue();
    Stack.pop();
    return result;
}

Symbol :: ~Symbol() = default;
