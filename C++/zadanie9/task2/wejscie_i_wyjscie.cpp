//
// Created by krzysztof on 08.06.2020.
//

#include "wejscie_i_wyjscie.hpp"
#include <iostream>

wejscie::wejscie(const string& file_name) {
    try {
        is= new ifstream(file_name.c_str(), ios::in);
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }
}

istream& wejscie::read(char* from_where, int streamsize) {
    try {
        is->read(from_where, streamsize);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

wejscie::~wejscie() {
    is->close();
    delete is;
}

wyjscie::wyjscie(const string& file_name) {
    try {
        os= new ofstream(file_name.c_str(), ios::out);
    }
    catch(const exception& e) {
        cerr << e.what() << endl;
    }
}

ostream& wyjscie::write(char* to_where, int bufsize) {
    try {
        os->write(to_where, bufsize);
        if(os->eof()){
            cerr << "End of file" << endl;
        }
        if(os->fail()) {
            cerr << "Failed to write" << endl;
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

wyjscie::~wyjscie() {
    os->close();
    delete os;
}