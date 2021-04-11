//
// Created by krzysztof on 07.06.2020.
//

#ifndef MANIPULATORS_MANIPULATORZZZ_HPP
#define MANIPULATORS_MANIPULATORZZZ_HPP

#include <iostream>
using namespace std;

istream& clearline(istream &in);

class ignore {
    int x;
public:
    friend istream& operator >> (istream &in, const ignore &ign );
    ignore(int);

};

ostream& comma(ostream &os);
ostream& colon(ostream &os);

class index {
    int x;
    int w;
public:
    friend ostream& operator << (ostream &os, const index &id);
    index(int, int);
};

#endif //MANIPULATORS_MANIPULATORZZZ_HPP
