//
// Created by krzysztof on 14.06.2020.
//

#ifndef ONP_FUNKCJA_HPP
#define ONP_FUNKCJA_HPP

#include <iostream>
#include "symbol.hpp"
#include <map>

using namespace std;

class Funkcja : public Symbol {

    static pair<double, double> popTwo();
    static double popOne();

public:

    enum functionType {
        fAdd = 0,
        fSub = 1,
        fMul = 2,
        fDiv = 3,
        fModulo = 4,
        fMin = 5,
        fMax = 6,
        fLog = 7,
        fPow = 8,
        fAbs = 9,
        fSgn = 10,
        fFloor = 11,
        fCeil = 12,
        fFrac = 13,
        fSin = 14,
        fCos = 15,
        fAtan = 16,
        fAcot = 17,
        fLn = 18,
        fExp = 19
    };

    Funkcja :: functionType operationType;

    static Funkcja :: functionType getFunction(string);
    explicit Funkcja(functionType);
    void execute() override;
    ~Funkcja() override;


    static map<string, functionType> functionMap;

};


#endif //ONP_FUNKCJA_HPP
