//
// Created by krzysztof on 09.05.2020.
//

#include "wymierne.hpp"

using namespace obliczenia;

Wymierna::Wymierna(int licz, int mian) {
    if(mian==0)
        throw DzieleniePrzezZero();
    if(mian<0) {
        licznik= -licz;
        mianownik= -mian;
    }
    else {
        licznik= licz;
        mianownik= mian;
    }
    Skroc();
}

Wymierna::Wymierna(int wym) : licznik(wym), mianownik(1) {
    Skroc();
}

int NWD(int x, int y) {
    while(x!=y) {
        if(x>y)
            x= x-y;
        else
            y= y-x;
    }
    return x;
}


void Wymierna::Skroc() {
    int x;
    if(this->licznik<0) {
        x= -this->licznik;
    }
    else {
        x= this->licznik;
    }
    x= NWD(x, this->mianownik);
    this->licznik= this->licznik/x;
    this->mianownik= this->mianownik/x;
}


Wymierna Wymierna:: operator + (const Wymierna &w2) {
    int lcm = this->mianownik * w2.mianownik / NWD(this->mianownik , w2.mianownik);
    int licz = this->licznik * lcm / this->mianownik;
    int licz_2 = w2.licznik * lcm / w2.mianownik;
    if( 1LL * licz * 1LL * licz_2 > INT_MAX ) {
        throw PozaZakresem();
    }
    return Wymierna(licz + licz_2, lcm);
}


Wymierna Wymierna:: operator - (const Wymierna &w2) {
    int lcm = this->mianownik * w2.mianownik / NWD(this->mianownik , w2.mianownik);
    int licz = this->licznik * lcm / this->mianownik;
    int licz_2 = w2.licznik * lcm / w2.mianownik;
    return Wymierna(licz - licz_2, lcm);
}

Wymierna Wymierna:: operator * ( const Wymierna &w2) {
    if( 1LL * this->licznik * 1LL * w2.licznik> INT_MAX ) {
        throw PozaZakresem();
    }
    int licz = this->licznik * this->licznik;
    int mian = this->mianownik * w2.mianownik;
    if( mian < 0 ) {
        mian*= -1;
        licz *= -1;
    }
    return Wymierna(licz, mian);
}

Wymierna Wymierna:: operator / (const Wymierna &w2) {
    int licz = this->licznik * w2.mianownik;
    int mian = this->mianownik * w2.licznik;
    if( mian == 0 ) {
        throw DzieleniePrzezZero();
    }
    if( mian < 0 ) {
        mian *= -1;
        licz *= -1;
    }
    return Wymierna(licz, mian);
}

Wymierna Wymierna::operator ! () {
    if(this->licznik==0)
        throw DzieleniePrzezZero();
    if(this->licznik<0) {
        int aux = -this->licznik;
        this->licznik = -this->mianownik;
        this->mianownik = aux;
    }
    else {
        int aux = this->licznik;
        this->licznik = this->mianownik;
        this->mianownik = aux;
    }
    return *this;
}

Wymierna Wymierna::operator - () {
    this->licznik = -1 * this->licznik;
    return *this;
}
Wymierna::operator int() {
    return this->licznik/this->mianownik;
}

Wymierna::operator double() {
    return (double)this->licznik/(double)this->mianownik;
}


string DzieleniePrzezZero::error() {
    return "Nie mozna dzielic przez 0!\n";
}

string PozaZakresem::error() {
    return "Przekroczony zakres\n";
}

