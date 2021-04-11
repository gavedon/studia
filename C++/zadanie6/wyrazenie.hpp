#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

#ifndef WYRAZENIE_HPP
#define WYRAZENIE_HPP

class Wyrazenie {
public:
    virtual double oblicz()= 0;
    virtual string opis()= 0;
    virtual int priority()= 0;
    ~Wyrazenie()= default;

};

class Liczba : public Wyrazenie {
    double wartosc;
    int prior= 5;
public:
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    };
    Liczba(double x);
};

class Stala : public Wyrazenie {
public:
    double wartosc;
    string nazwa;
    int prior= 5;
    virtual int priority() {
        return prior;
    };
};

class Pi : public Stala {
public:
    Pi();
    virtual double oblicz();
    virtual string opis();
};

class E : public Stala {
public:
    E();
    virtual double oblicz();
    virtual string opis();
};

class Fi : public Stala {
public:
    Fi();
    virtual double oblicz();
    virtual string opis();
};

class Zmienna : public Wyrazenie {
    string nazwa;
    int prior= 5;
    static vector<pair<string,double>> vec;
public:
    virtual double oblicz();
    virtual string opis();
    void static dodaj_elem_do_vectora(string s, double x);
    bool static czy_jest_w_vectorze(string w);
    double static wypisz_elem_z_vectora(string w);
    virtual int priority() {
        return prior;
    };
    Zmienna(string s);
    Zmienna(vector<pair<string,double>> v);
};

class Operator1arg : public Wyrazenie {
public:
    Wyrazenie *jeden;
    ~Operator1arg()= default;
};

class Sin : public Operator1arg {
    int prior= 4;
public:
    Sin(Wyrazenie *wyr);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Bezwzgl : public Operator1arg {
    int prior= 4;
public:
    Bezwzgl(Wyrazenie *wyr);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Cos : public Operator1arg {
    int prior= 4;
public:
    Cos(Wyrazenie *wyr);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Przeciw : public Operator1arg {
    int prior= 4;
public:
    Przeciw(Wyrazenie *wyr);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Exp : public Operator1arg {
    int prior= 4;
public:
    Exp(Wyrazenie *wyr);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Odwrot : public Operator1arg {
    int prior= 4;
public:
    Odwrot(Wyrazenie *wyr);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Ln : public Operator1arg {
    int prior= 4;
public:
    Ln(Wyrazenie *wyr);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Operator2arg : public Operator1arg {
public:
    Wyrazenie *dwa;
    ~Operator2arg()= default;

};

class Dodaj : public Operator2arg {
    int prior= 1;
public:
    Dodaj(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Logarytm : public Operator2arg {
    int prior= 3;
public:
    Logarytm(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Odejmij : public Operator2arg {
    int prior= 1;
public:
    Odejmij(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Modulo : public Operator2arg {
    int prior= 2;
public:
    Modulo(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Mnoz : public Operator2arg {
    int prior= 2;
public:
    Mnoz(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Potega : public Operator2arg {
    int prior= 3;
public:
    Potega(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};

class Dziel : public Operator2arg {
    int prior= 2;
public:
    Dziel(Wyrazenie *lewa_strona, Wyrazenie *prawa_strona);
    virtual double oblicz();
    virtual string opis();
    virtual int priority() {
        return prior;
    }
};
#endif