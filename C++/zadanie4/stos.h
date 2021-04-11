#ifndef _STOS_H
#define _STOS_H

using namespace std;

class stos {
    int pojemnosc;
    int ile;
    string *tablica;
public:
    void wloz(string);
    string sciagnij();
    string sprawdz();
    int rozmiar();
    stos odwroc();

    stos();
    stos(int);
    stos(initializer_list<string>);
    stos(stos &);
    stos(stos &&);
    ~stos();

    stos& operator=(stos const&);
    stos& operator=(stos &&);
};

#endif
