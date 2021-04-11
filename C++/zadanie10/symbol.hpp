//
// Created by krzysztof on 14.06.2020.
//

#ifndef ONP_SYMBOL_HPP
#define ONP_SYMBOL_HPP


#include <iostream>
#include <stack>

using namespace std;


class Symbol {

public:
    static stack<Symbol*> Stack;
    static double result();

    Symbol();
    virtual void execute()= 0;
    virtual ~Symbol();
};

#endif //ONP_SYMBOL_HPP
