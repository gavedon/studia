//
// Created by krzysztof on 14.06.2020.
//

#ifndef ONP_ZMIENNA_HPP
#define ONP_ZMIENNA_HPP

#include <map>
#include <iostream>
#include "operand.hpp"

using namespace std;


class Zmienna : public Operand {

    static map< string, double> variablesMap;
public:

    string name;

    Zmienna(string);
    double getValue() override;
    static double getVariable(string);
    static void addToMap(string, double);
    static void removeAll();
    ~Zmienna() override;
};

#endif //ONP_ZMIENNA_HPP
