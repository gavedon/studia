#include "wyrazenie.hpp"

vector<pair<string,double>> Zmienna :: vec;

int main() {
    //1. Przyklad pierwszy z tresci zadania
    Wyrazenie *w = new Dziel(new Mnoz(new Odejmij(new Zmienna("x"), new Liczba(1)), new Zmienna("x")), new Liczba(2));
    Zmienna :: dodaj_elem_do_vectora("x",3);
    cout << w->opis() << " = " << w->oblicz() << endl;

    //2. Przyklad drugi z tresci zadania
    w= new  Dziel(new Dodaj(new Liczba(3), new Liczba(5)), new Dodaj(new Liczba(2), new Mnoz(new Zmienna("x"), new Liczba(7))));
    cout << w->opis() << " = " << w->oblicz() << endl;

    //3. Przyklad trzeci z tresci zadania
    w = new Odejmij(new Dodaj(new Liczba(2), new Mnoz( new Zmienna("x"), new Liczba(7))), new Dodaj
            (new Liczba(5), new Mnoz(new Liczba(3), new Zmienna("y"))));
    Zmienna :: dodaj_elem_do_vectora("y",2);
    cout << w->opis() << " = " << w->oblicz() << endl;

    //4. Przyklad czwarty z tresci zadania
    w = new Dziel(new Cos(new Mnoz(new Zmienna("x"), new Dodaj(new Zmienna("x"), new Liczba(1)))), new Potega(new E(), new Potega(new Zmienna("x"), new Liczba(2))));
    cout << w->opis() << " = " << w->oblicz() << endl;


    // Wykorzystanie innych klas
    w = new Przeciw(new Bezwzgl(new Odwrot(new Liczba(-2))));
    cout << w->opis() << " = " << w->oblicz() << endl;

    //Obliczmy wartosc pierwszego wyrazenia w zaleznosci od iterujacego iksa
    for(double k=0.0; k<1.00; k=k+0.01) {
        w = new Dziel(new Mnoz(new Odejmij(new Zmienna("x"), new Liczba(1)), new Zmienna("x")), new Liczba(2));
        Zmienna :: dodaj_elem_do_vectora("x",k);
        cout << w->opis() << " = " << w->oblicz() << endl;
    }
}
