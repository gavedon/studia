//
// Created by krzysztof on 08.06.2020.
//

#ifndef MANIPULATORS_WEJSCIE_I_WYJSCIE_HPP
#define MANIPULATORS_WEJSCIE_I_WYJSCIE_HPP

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


class wejscie {

private:
    ifstream *is;
public:
    wejscie(const string& file_name);
    istream& read(char*, int);
    ~wejscie();
};


class wyjscie {

private:
    ofstream *os;
public:
    wyjscie(const string& file_name);
    ostream& write(char*, int);
    ~wyjscie();
};

#endif //MANIPULATORS_WEJSCIE_I_WYJSCIE_HPP