#include <iostream>
#include <cstdlib>
#include "wejscie_i_wyjscie.hpp"

using namespace std;

//#define range_of_ints 100
#define type int

string file= "test.txt";

void test (int number_of_ints) {
    auto* out= new wyjscie(file);
    int k=0;
    while(k < number_of_ints) {
        auto* random_number= new size_t(rand()%71);
        out->write((char*)random_number, sizeof(type));
        k++;
    }
    delete out;
    auto* temp= new wejscie(file);
    int i=0;
    while(i < number_of_ints) {
        type x;
        temp->read((char*)&x, sizeof(type));
        cout << x << endl;
        i++;
    }
    delete temp;
}

void test_v2(int number_of_ints) {
    auto* temp= new wejscie(file);
    for(int i=0; i<number_of_ints * sizeof(type); i++) {
        char x;
        temp->read((char*)&x, sizeof x);
        if(x >= 30 ) {
            cout << "In decimal: " << dec << (int)x << endl;
            cout << "In hexagonal: " << hex << (int)x << endl;
        }
    }
    delete temp;
}

int main() {
    test(20);
    test_v2(20);
    return 0;
}