//
// Created by krzysztof on 09.05.2020.
//

#ifndef WYMIERNE_WYMIERNE_HPP
#define WYMIERNE_WYMIERNE_HPP


#include <iostream>
#include <climits>

using namespace std;

namespace obliczenia {

    class Wymierna {

        int licznik;
        int mianownik;
        void Skroc();

    public:
        int getLicznik() const {
            return licznik;
        };
        int getMianownik() const {
            return mianownik;
        };
        Wymierna(int licz, int mian);
        Wymierna(int licz);
        Wymierna(const Wymierna&)= default;
        Wymierna & operator= (const Wymierna&)= default;
        friend ostream& operator<< (ostream &wyj, const Wymierna &w) {
            double x= (double)w.getLicznik()/(double)w.getMianownik();
            wyj << x << endl;
            return wyj;

        };

        Wymierna operator + (const Wymierna &);
        Wymierna operator - (const Wymierna &);
        Wymierna operator * (const Wymierna &);
        Wymierna operator / (const Wymierna &);

        Wymierna operator ! ();
        Wymierna operator - ();

        explicit operator int();
        operator double();

    };

}
class WyjatekWym : public exception {
public:
    string error();
};

class DzieleniePrzezZero : public WyjatekWym {
public:
    string error();
};

class PozaZakresem : public WyjatekWym {
public:
    string error();
};

#endif //WYMIERNE_WYMIERNE_HPP