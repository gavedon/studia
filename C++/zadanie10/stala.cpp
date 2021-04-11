//
// Created by krzysztof on 14.06.2020.
//

#include "stala.hpp"

#include <utility>

map<string, double> Stala :: constsMap = {
    {"pi", 3.141},
    {"e", 2.718},
    {"fi", 1.618}
};

Stala :: Stala(string constrName, double constrValue) {
    name= move(constrName);
    value= constrValue;
}

double Stala :: getConst(string s) {
    return constsMap.at(s);
}

double Stala ::getValue() {
    return this->value;
}

Stala :: ~Stala() = default;