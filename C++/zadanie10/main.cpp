#include "funkcja.hpp"
#include "liczba.hpp"
#include "zmienna.hpp"
#include "stala.hpp"

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

double print(const string& expr) {

    vector<shared_ptr<Symbol>> vec;

    int index = 0;
    int theEnd;
    do {
        theEnd = expr.find(' ', index);
        string s= expr.substr(index, theEnd-index);
        index= index + s.length()+1;

        if (isdigit(s.at(0)) || s.at(0) == '-') {
            int value= stoi(s);
            shared_ptr<Symbol> s;
            s.reset(new Liczba(value));
            vec.push_back(s);
        }
        else {
            bool found= false;
            try {
                double value = Zmienna :: getVariable(s);
                shared_ptr<Symbol> sym;
                sym.reset(new Zmienna(s));
                vec.push_back(sym);
                found= true;
            }
            catch (...) {}

            if (!found)
                try {
                    double value = Stala :: getConst(s);
                    shared_ptr<Symbol> sym;
                    sym.reset(new Stala(s, value));
                    vec.push_back(sym);
                    found = true;
                }
            catch (...) {}

            if (!found)
                try {
                    Funkcja :: functionType funType = Funkcja :: getFunction(s);
                    shared_ptr<Symbol> sym;
                    sym.reset(new Funkcja(funType));
                    vec.push_back(sym);
                } catch (...) {}

        }
    }
    while (theEnd != -1);


    for (auto & k : vec) {
        k->execute();
    }

    double finalResult = Symbol :: result();
    return finalResult;
}

void assign(const string& expr, const string& var) {
    try {
        double result = print(expr);
        Zmienna :: addToMap(var, result);
    } catch (...) {
        clog << "Its either unwanted name used or the name length exceeds 7 letters limit" << endl;
    }
}

void clear() {
    Zmienna :: removeAll();
}


int main() {
    cout << "Welcome to RPN calculator" << endl;
    while (true) {
        cout << "Enter your command" << endl;
        string command;
        getline(cin, command);
        try {
            int spacePoint= command.find(' ');
            string firstElem= command.substr(0, spacePoint);
            if (firstElem == "print") {
                if (spacePoint == -1) {
                    clog << "Print command missing expression" << endl;
                    continue;
                }
                double result= print(command.substr(6, command.length()));
                cout << result << endl;
            }
            else if (firstElem == "assign") {
                if (spacePoint == -1) {
                    clog << "Incorrect expression" << endl;
                    continue;
                }
                string temp= command.substr(7, command.length());
                spacePoint= temp.find(" to ");
                if (spacePoint == -1) {
                    clog << "Wrong expression" << endl;
                    continue;
                }
                string expression = temp.substr(0, spacePoint);
                string variable = temp.substr(spacePoint + 4, temp.length());
                assign(expression, variable);
                cout << "Assigned" << endl;
            }
            else if (firstElem == "clear") {
                clear();
                cout << "Variables assignments removed" << endl;
            }
            else if (firstElem == "exit") {
                cout << "Program to be closed" << endl;
                break;
            }
            else {
                clog << "Wrong command" << endl;
            }
        }
        catch(...) {
            clog << "Something wrong has occurred :((" << endl;
        }
    }
}