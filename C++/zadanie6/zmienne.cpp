#include "wyrazenie.hpp"

Zmienna :: Zmienna(string s) {
    nazwa= s;
}

Zmienna :: Zmienna(vector<pair<string, double>> v) {
    vec= v;
}

string Zmienna :: opis() {
    return nazwa;
}

void Zmienna :: dodaj_elem_do_vectora(string s, double x) {
    if(czy_jest_w_vectorze(s) == false) {
        vec.push_back(make_pair(s, x));
    }
    else {
        for(auto k= vec.begin(); k!= vec.end(); k++) {
            if(k->first == s) {
                k->second= x;
            }
        }
    }
}
double Zmienna :: wypisz_elem_z_vectora(string w) {
    for(auto k= vec.begin(); k!= vec.end(); k++) {
        if(k->first == w) {
            return k->second;
        }
    }
}
bool Zmienna :: czy_jest_w_vectorze(string w) {
    for(auto k= vec.begin(); k!= vec.end(); k++) {
        if(k->first == w) {
            return true;
        }
    }
    return false;
}

double Zmienna :: oblicz() {
    if(czy_jest_w_vectorze(nazwa)) {
        return wypisz_elem_z_vectora(nazwa);
    }
    else {
        cerr << "Brak zmiennej w wektorze" << endl;
    }
}