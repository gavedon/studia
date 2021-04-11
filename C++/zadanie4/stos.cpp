#include <iostream>
#include <cstdlib>
#include "stos.h"

using namespace std;

//Funkcje

void stos::wloz(string value) {
    if(ile < pojemnosc) {
        tablica[ile]=value;
        ile++;
    }
    else {cerr << "Nie ma wiecej miejsca na stosie" << endl;}
}
string stos::sciagnij() {
    if(ile == 0) {
        cerr << "Stos jest pusty, nie mozna niczego zdjac" << endl;
    }
    else {
        ile -= 1;
        string pom = tablica[ile];
        tablica[ile] = "";
        return pom;
    }
}
string stos::sprawdz() {
    if(ile == 0) {
        cerr << "Stos jest pusty" << endl;
    }
    string pom= tablica[ile-1];
    return pom;
}
int stos::rozmiar() {
    return ile;
}
stos stos::odwroc() {
    stos pom_stos(pojemnosc);
    for(int k=ile; k>0; k--) {
        pom_stos.wloz(tablica[k-1]);
    }
    return pom_stos;
}

//Konstruktory

stos::stos(int pojemnosc) {
    if (pojemnosc > 0 && pojemnosc< 100) {
        ile= 0;
        this->pojemnosc=pojemnosc;
        tablica = new string[pojemnosc];
    }
    else {
        throw invalid_argument("Za mala lub za duza pojemnosc");
    }
}
stos::stos() {
    pojemnosc=1;
    ile=0;
    tablica = new string[1];
}

stos::stos(const initializer_list<string> init): pojemnosc(init.size()), tablica(new string[init.size()]), ile(init.size()) {
    int i=0;
    for(string k : init) {
        tablica[i] = k;
        i++;
    }
}
stos& stos::operator=(stos const& to_be_copied) {
    if (&to_be_copied == this) {
        return *this;
    }
    delete[] tablica;

    pojemnosc = to_be_copied.pojemnosc;
    tablica = new string[pojemnosc];
    ile = to_be_copied.ile;
    for (int k=0; k<ile; k++) {
        tablica[k] = to_be_copied.tablica[k];
    }
    return *this;
}
stos::stos(stos &to_be_copied): pojemnosc(to_be_copied.pojemnosc), ile(to_be_copied.ile), tablica(new string[to_be_copied.pojemnosc]) {
    for (int k = 0; k < ile; k++) {
        tablica[k] = to_be_copied.tablica[k];
    }
}
stos& stos::operator=(stos&& to_be_moved) {
    if (&to_be_moved == this) {
        return *this;
    }
    delete[] tablica;

    pojemnosc= to_be_moved.pojemnosc;
    tablica= to_be_moved.tablica;
    ile= to_be_moved.ile;

    to_be_moved.tablica= nullptr;
    return *this;
}
stos::stos(stos &&to_be_moved):pojemnosc(to_be_moved.pojemnosc), tablica(to_be_moved.tablica), ile(to_be_moved.ile) {
    to_be_moved.tablica= nullptr;
}
stos::~stos() {
    delete[] tablica;
}