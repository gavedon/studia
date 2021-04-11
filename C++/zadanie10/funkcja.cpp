//
// Created by krzysztof on 14.06.2020.
//


#include "funkcja.hpp"
#include "operand.hpp"
#include "liczba.hpp"

#include <iostream>
#include <cmath>

using namespace std;

stack<Symbol*> Symbol :: Stack;

map<string, Funkcja :: functionType> Funkcja :: functionMap = {
    {"+", fAdd},
    {"-", fSub},
    {"*", fMul},
    {"/", fDiv},
    {"%", fModulo},
    {"min", fMin},
    {"max", fMax},
    {"log", fLog},
    {"pow", fPow},
    {"abs", fAbs},
    {"sgn", fSgn},
    {"floor", fFloor},
    {"ceil", fCeil},
    {"frac", fFrac},
    {"sin", fSin},
    {"cos", fCos},
    {"atan", fAtan},
    {"acot", fAcot},
    {"ln", fLn},
    {"exp", fExp}
};

Funkcja :: Funkcja(functionType constrOperationType) {
    operationType= constrOperationType;
}


Funkcja :: functionType Funkcja :: getFunction(string s) {
    return functionMap.at(s);
}

pair<double, double> Funkcja :: popTwo() {
    auto* temp = dynamic_cast<Operand*>(Symbol :: Stack.top());
    Symbol :: Stack.pop();
    auto* aux = dynamic_cast<Operand*>(Symbol :: Stack.top());
    Symbol :: Stack.pop();
    return pair<double, double >(temp->getValue(), aux->getValue());
}

double Funkcja :: popOne() {
    auto* temp = dynamic_cast<Operand*>(Symbol :: Stack.top());
    Symbol :: Stack.pop();
    return temp->getValue();
}

void Funkcja :: execute() {

    double result;
    double value;
    pair<double, double> values;
    switch(this->operationType) {
        case fAdd:
            values= popTwo();
            result= values.second + values.first;
            Symbol :: Stack.push(new Liczba(result));
            break;
        case fSub:
            values = popTwo();
            result= values.second - values.first;
            Symbol :: Stack.push(new Liczba(result));
            break;
        case fMul:
            values = popTwo();
            result= values.second * values.first;
            Symbol :: Stack.push(new Liczba(result));
            break;
        case fDiv:
            values = popTwo();
            if (values.second == 0) {
                cerr << "You'd better think twice before dividing by 0" << endl;
            }
            result= values.second / values.first;
            Symbol :: Stack.push(new Liczba(result));
            break;
        case fModulo:
            values = popTwo();
            result= fmod(values.second, values.first);
            Symbol :: Stack.push(new Liczba(result));
            break;
        case fMin:
            values = popTwo();
            result= values.first > values.second ? values.second : values.first;
            Symbol :: Stack.push(new Liczba(result));
            break;
        case fMax:
            values = popTwo();
            result= values.first < values.second ? values.second : values.first;
            Symbol :: Stack.push(new Liczba(result));
            break;
        case fLog:
            values = popTwo();
            result= log(values.second)/log(values.first);
            Symbol::Stack.push(new Liczba(result));
            break;
        case fPow:
            values = popTwo();
            result= pow(values.second, values.first);
            Symbol::Stack.push(new Liczba(result));
            break;
        case fAbs:
            value = popOne();
            result= value > 0 ? value : -value;
            Symbol::Stack.push(new Liczba(result));
            break;
        case fSgn:
            value = popOne();
            result= value > 0 ? 1 : -1;
            Symbol::Stack.push(new Liczba(result));
            break;
        case fFloor:
            value = popOne();
            result= floor(value);
            Symbol::Stack.push(new Liczba(result));
            break;
        case fCeil:
            value = popOne();
            result= ceil(value);
            Symbol::Stack.push(new Liczba(result));
            break;
        case fFrac:
            value = popOne();
            result= value - trunc(value);
            result=result >= 0 ?result : -result;
            Symbol::Stack.push(new Liczba(result));
            break;
        case fSin:
            value = popOne();
            result= sin(value);
            Symbol::Stack.push(new Liczba(result));
            break;
        case fCos:
            value = popOne();
            result= cos(value);
            Symbol::Stack.push(new Liczba(result));
            break;
        case fAtan:
            value = popOne();
            result= atan(value);
            Symbol::Stack.push(new Liczba(result));
            break;
        case fAcot:
            value = popOne();
            result= 3.141592/2 - atan(value);
            Symbol::Stack.push(new Liczba(result));
            break;
        case fLn:
            value = popOne();
            result= log(value);
            Symbol::Stack.push(new Liczba(result));
            break;
        case fExp:
            value = popOne();
            result= exp(value);
            Symbol::Stack.push(new Liczba(result));
            break;
        default:
            cerr << "En error has occurred ://" << endl;
    }
}

Funkcja :: ~Funkcja() = default;
