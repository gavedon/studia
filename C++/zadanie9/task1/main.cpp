#include <iostream>
#include "manipulatorzzz.hpp"
#include <vector>
#include <algorithm>

using namespace std;


void test(vector<string> vec, vector<string> vec_v2) {
    int temp;
    cout << "Sorted: " << endl;
    for(temp=0; temp<vec.size(); temp++) {
        int aux=0;
        while(vec[temp] != vec_v2[aux]) {
            aux++;
        }
        cout << index(aux+1, 1) << vec[temp] << comma;
    }
}


int main() {
    cout << "Testing whether colon and comma work as wanted" << endl;
    cout << comma << colon << endl;
    cout << "Checking an ignore manipulator, write a word" << colon;
    string q;
    cin >> ignore(2) >> q;
    cout << q << endl;
    cout << "Vector" << colon << endl;
    vector<string> v1, v2;
    string s;
    int x, y;
    cout << "Write down vector length" << colon;
    cin >> x;
    int counter= 1;
    for(y=0; y<x; y++) {
        cout << "Write elem nr " << counter << " out of " << x << " that will be added" << endl;
        cin >> s;
        v1.push_back(s);
        counter++;
    }
    v2= v1;
    sort(v1.begin(), v1.end());
    test(v1, v2);
    return 0;
}
