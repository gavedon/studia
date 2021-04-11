#include <iostream>
#include <cstdlib>
#include "stos.h"

using namespace std;

void interaktywne_menu() {
    cout << "-----------------------------------------------" << endl;
    cout << "Aby stworzyc stos wybierz '1'" << endl;
    cout << "Aby dodac element do stosu wybierz '2'" << endl;
    cout << "Aby sciagnac element ze stosu wybierz '3'" << endl;
    cout << "Aby wyswietlic czubek stosu wybierz '4'" << endl;
    cout << "Aby odwrocic stos wybierz '5'" << endl;
    cout << "Aby opuscic program wybierz '6'" << endl;
    cout << "-----------------------------------------------" << endl;
}

int main() {
    stos *test= nullptr;
    int choice;
    int x=0;
    while (x != 6) {
        interaktywne_menu();
        if (test != nullptr) {
            cout << "Twoj stos ma " << test->rozmiar() << " elemntow" << endl;
        }
        else {
            cout << "Aby wykonywac operacje na stosie, musisz utworzyc stos, do tego uzyj '1'" << endl;
        }
        cout << "Podaj operacje (od 1 do 6) ktora chcesz wykonac: " << endl;
        cin >> choice;
        cout << endl;
        switch(choice) {
            case 1 : {
                int a=0;
                if(test != nullptr) {
                    delete test;
                }
                cout << "Podaj rozmiar stosu jaki chcesz stworzyc :"<<endl;
                cin>>a;
                if(a<100) {
                    test = new stos(a);
                }
                else {
                     test= new stos();
                }
                break;
            }
            case 2 : {
                string s;
                cout << "Podaj wyraz ktory chcesz dodac do stosu" << endl;
                cin>>s;
                if(test!=nullptr) {
                    test->wloz(s);
                }
                else {
                    cerr << "Nie mozna dodac elementu do nieistniejacego stosu" << endl;
                }
                break;
            }
            case 3 : {
                if(test!=nullptr && test->rozmiar()!=0) {
                    cout << "Wyraz " << test->sciagnij() << " zostal sciagniety ze stosu" << endl;
                }
                else {
                    cerr << "Nie mozna sciagnac elementu z nieistniejacego  lub pustego stosu" << endl;
                }
                break;
            }
            case 4 : {
                if(test!=nullptr && test->rozmiar()!=0)
                    cout << "Czubek stosu to "<<test->sprawdz() << endl;
                else
                    cerr << "Na stosie nie ma zadnych elementow lub stos nie istnieje" << endl;
                break;
            }
            case 5 : {
                if(test != nullptr)
                {
                    stos *pom_stos= new stos(test->odwroc());
                    delete test;
                    test= pom_stos;
                }
                else
                    cerr << "Nie mozna odwrocic pustego lub nieistniejacego stosu" << endl;
                break;
            }
            case 6 : {
                cout << "Zakoncz program" << endl;
                x=6;
                break;
            }
        }
    }
    delete test;
    return 0;
}
