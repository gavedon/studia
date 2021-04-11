//
// Created by krzysztof on 14.06.2020.
//

#include "zmienna.hpp"

#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

map<string, double> Zmienna::variablesMap;

vector<string> illigalVariablesNames = {
        "print",
        "assign",
        "clear",
        "exit"
};

Zmienna :: Zmienna(string constrName) {
    name= constrName;
}

double Zmienna ::getValue() {
    return Zmienna :: variablesMap[this->name];
}

double Zmienna :: getVariable(string s) {
    return variablesMap.at(s);
}

void Zmienna :: addToMap(string s, double x)  {
    if ( s.length()>7 || find(illigalVariablesNames.begin(), illigalVariablesNames.end(), s)!=illigalVariablesNames.end()) {
        cerr << "Too long variable name or unwanted name" << endl;
    }
    Zmienna :: variablesMap[s] = x;
}

void Zmienna :: removeAll() {
    Zmienna :: variablesMap.clear();
}


Zmienna::~Zmienna() = default;


