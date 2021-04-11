#include "wyrazenie.hpp"

double Liczba :: oblicz() {
    return wartosc;
}

string Liczba :: opis() {
    return to_string(wartosc);
}

Liczba :: Liczba(double x) {
    wartosc= x;
}

Sin :: Sin(Wyrazenie *wyr) {
     jeden= wyr;
}

double Sin :: oblicz() {
    return sin(jeden->oblicz());
}

string Sin :: opis() {
    return "sin(" + jeden->opis() + ")";
}

Bezwzgl :: Bezwzgl(Wyrazenie *wyr) {
     jeden= wyr;
}

double Bezwzgl :: oblicz() {
    return abs(jeden->oblicz());
}

string Bezwzgl :: opis() {
    return "|" + jeden->opis() + "|";
}

Cos :: Cos(Wyrazenie *wyr) {
    jeden= wyr;
}

double Cos :: oblicz() {
    return cos(jeden->oblicz());
}

string Cos :: opis() {
    return "cos(" + jeden->opis() + ")";
}

Przeciw :: Przeciw(Wyrazenie *wyr) {
    jeden= wyr;
}

double Przeciw :: oblicz() {
    return -1 * (jeden->oblicz());
}

string Przeciw :: opis() {
    return "Przeciwna(" + jeden->opis() + ")";
}

Exp :: Exp(Wyrazenie *wyr) {
    jeden= wyr;
}

double Exp :: oblicz() {
    return exp(jeden->oblicz());
}

string Exp :: opis() {
    return "exp(" + jeden->opis() + ")";
}

Odwrot :: Odwrot(Wyrazenie *wyr) {
    jeden= wyr;
}

double Odwrot :: oblicz() {
    if(jeden->oblicz() != 0) {
        return 1 / (jeden->oblicz());
    }
    else {
        cerr << "Nie wolno dzielic przez 0" << endl;
    }
}

string Odwrot :: opis() {
    return "Odwrotna("+ jeden->opis() + ")";
}

Ln :: Ln(Wyrazenie *wyr) {
    jeden= wyr;
}

double Ln :: oblicz() {
    return log(jeden->oblicz());
}

string Ln :: opis() {
    return "ln(" + jeden->opis() + ")";
}

Dodaj :: Dodaj(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona) {
    jeden= lewa_strona;
    dwa= prawa_strona;
}

double Dodaj :: oblicz() {
    return jeden->oblicz() + dwa->oblicz();
}

string Dodaj :: opis() {
    string lewa_strona= jeden->opis();
    string prawa_strona= dwa->opis();
    return lewa_strona + "+" + prawa_strona;
}

Logarytm :: Logarytm(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona) {
    jeden= lewa_strona;
    dwa= prawa_strona;
}

double Logarytm :: oblicz() {
    return log(jeden->oblicz()) / log(dwa->oblicz());
}

string Logarytm :: opis() {
    string lewa_strona = jeden->opis();
    if (jeden->priority() <= prior)
        lewa_strona = "(" + lewa_strona + ")";
    string prawa_strona = dwa->opis();
    if (dwa->priority() <= prior)
        prawa_strona = "(" + prawa_strona + ")";
    return "log" + lewa_strona + "z" + prawa_strona;
}

Odejmij :: Odejmij(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona) {
    jeden= lewa_strona;
    dwa= prawa_strona;
}

double Odejmij :: oblicz() {
    return jeden->oblicz() - dwa->oblicz();
}

string Odejmij :: opis() {
    string lewa_strona= jeden->opis();
    string prawa_strona= dwa->opis();
    if(dwa->priority() == prior) {
        prawa_strona= "(" + prawa_strona + ")";
    }
    return lewa_strona + "-" + prawa_strona;
}

Modulo :: Modulo(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona) {
    jeden= lewa_strona;
    dwa= prawa_strona;
}

double Modulo :: oblicz() {
    return fmod(jeden->oblicz(), dwa->oblicz());
}

string Modulo :: opis() {
    string lewa_strona = jeden->opis();
    if (jeden->priority() <= prior)
        lewa_strona = "(" + lewa_strona + ")";
    string prawa_strona = dwa->opis();
    if (dwa->priority() <= prior)
        prawa_strona = "(" + prawa_strona + ")";
    return lewa_strona + "%" + prawa_strona;
}

Mnoz :: Mnoz(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona) {
    jeden= lewa_strona;
    dwa= prawa_strona;
}

double Mnoz :: oblicz() {
    return jeden->oblicz() * dwa->oblicz();
}

string Mnoz :: opis() {
    string lewa_strona = jeden->opis();
    if(jeden->priority() < prior)
        lewa_strona = "(" + lewa_strona + ")";
    string prawa_strona = dwa->opis();
    if(dwa->priority() < prior)
        prawa_strona = "(" + prawa_strona + ")";
    return lewa_strona + "*" + prawa_strona;
}

Potega :: Potega(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona) {
    jeden= lewa_strona;
    dwa= prawa_strona;
}

double Potega :: oblicz() {
    return pow(jeden->oblicz(), dwa->oblicz());
}

string Potega :: opis() {
    string lewa_strona = jeden->opis();
    if (jeden->priority() < prior)
        lewa_strona = "(" + lewa_strona + ")";
    string prawa_strona = dwa->opis();
    if (dwa->priority() < prior)
        prawa_strona = "(" + prawa_strona + ")";
    return lewa_strona + "^" + prawa_strona;
}

Dziel :: Dziel(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona) {
    jeden= lewa_strona;
    dwa= prawa_strona;
}

double Dziel :: oblicz() {
    return jeden->oblicz() / dwa->oblicz();
}

string Dziel :: opis() {
    string lewa_strona = jeden->opis();
    if (jeden->priority() < prior)
        lewa_strona = "(" + lewa_strona + ")";
    string prawa_strona = dwa->opis();
    if (dwa->priority() <= prior)
        prawa_strona = "(" + prawa_strona + ")";
    return lewa_strona + "/" + prawa_strona;
}