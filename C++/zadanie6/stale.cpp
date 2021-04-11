#include "wyrazenie.hpp"

Pi::Pi() {
    wartosc= 3.14;
    nazwa= "pi";
}

double Pi::oblicz() {
    return wartosc;
}

string Pi::opis() {
    return nazwa;
}

E::E() {
    wartosc= 2.71;
    nazwa= "e";
}

double E::oblicz() {
    return wartosc;
}

string E::opis() {
    return nazwa;
}

Fi::Fi() {
    wartosc= 1.61;
    nazwa= "fi";
}

double Fi::oblicz() {
    return wartosc;
}

string Fi::opis() {
    return nazwa;
}