//
// Created by krzysztof on 07.06.2020.
//

#include "manipulatorzzz.hpp"
#include <iostream>

istream& clearline(istream &in) {
    while(!in.eof() && in.get()!= '\n') {};
    return in;
}

ignore::ignore(int a) {
    if(a<0) {
        cerr << "Can't ignore negative number of characters" << endl;
    }
    x= a;
}

istream& operator >> (istream &in, const ignore &ign) {
    int temp= ign.x;
    while(!in.eof() && temp>0 && in.get()!= '\n') {
        temp--;
    }
    return in;
}


ostream& comma(ostream &os) {
    return os << ", ";
}

ostream& colon(ostream &os) {
    return os << ": ";
}

index::index(int a, int b) {
    if(b<0) {
        cerr << "Can't be a negative nu mber of characters" << endl;
    }
    x= a;
    w= b;
}

ostream& operator << (ostream &os, const index &id) {
    os << "[";
    os.width(id.w);
    os << id.x << "]";
    return os;

}