//
// Created by krzysztof on 14.06.2020.
//

#ifndef ONP_STALA_HPP
#define ONP_STALA_HPP

#include <iostream>
#include <map>
#include "operand.hpp"

using namespace std;

class Stala : public Operand {

    static map<string, double> constsMap;
public:

    string name;
    double value;

    double getValue() override;
    static double getConst(string);
    Stala(string, double);
    ~Stala() override;
};

#endif //ONP_STALA_HPP
