#include <iostream>
#include "wymierne.hpp"

using namespace obliczenia;
using namespace std;

int main()
{
    try
    {
        Wymierna w1(2,3);
        Wymierna w8(-3,7);
        cout << w8.getLicznik() << " - licznik liczby -3/7\n" << w8.getMianownik() << " -mianownik liczby -3/7" << endl;
        Wymierna w2(5,7);
        cout << "2/3 + 5/7 = ";
        Wymierna w3 = w1 + w2;
        cout << w3 << endl;
        Wymierna w7= -w3;
        cout << w7 << endl;
        Wymierna w6= !w7;
        cout << w6 << endl;
        Wymierna w4(3,4);
        cout << "3/4 = " << w4 << endl;
        w3 = w1 - w2;
        cout << "2/3 - 5/7 = " << w3 << endl;
        w3 = w1 * w2;
        cout << "2/3 * 5/7 = " << w3 << endl;
        w3 = w1 / w2;
        cout << "2/3 / 5/7 = " << w3 << endl;
        Wymierna w5(4,0);
    }

    catch(DzieleniePrzezZero &err) {
        cerr << err.error()<<endl;
    }

    catch(PozaZakresem &err) {
        cerr << err.error()<<endl;
    }
}