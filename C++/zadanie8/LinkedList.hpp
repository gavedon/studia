//
// Created by krzysztof on 31.05.2020.
//

#ifndef LINKEDLIST_LINKEDLIST_HPP
#define LINKEDLIST_LINKEDLIST_HPP

#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(initializer_list<T>);
    ~LinkedList();
    void insertNewNode(T, int);
    void deleteNode(T);
    int search(T);
    int getNumberOfElements();
    T getValue(int);

    int numberOfElements{};

    class Node {
    public:
        Node(T, int);
        T getData();
        int getPosition();
        Node* nextNode;
        friend class LinkedList;
    private:
        int position;
        T data;

    };
    Node* start;
    void changeNode(Node*, int);
    void addToEnd(Node*);

    friend ostream& operator<<(ostream& os,const LinkedList& lst) {
        Node* x= lst.start;
        while(x != nullptr) {
            os << x-> getData() << endl;
            x= x->nextNode;
        }
        return os;
    }

};

template<typename T>
class traitlike {
public:
    static bool trait(T x, T y) {
        return x<= y;
    }
};

template<typename T>
class traitlike_v2 {
public:
    static bool trait_v2(T x, T y) {
        return x> y;
    }
};

template <typename T>
bool check(LinkedList<T>* lst) {
    int length= lst->getNumberOfElements();
    for( int k=0; k<=length; k++) {
        if(lst->getValue(k) > lst->getValue(k+1)) {
            return false;
        }
    }
    return true;
}


template <typename T>
void sort(LinkedList<T>* lst) {
    int length =lst->getNumberOfElements();
    for(int i=0;i<length;i++) {
        for(int j=0;j<length-i-1;j++) {
            if(lst->getValue(j) > lst->getValue(j+1)) {
                T temp= lst->getValue(j);
                lst->deleteNode(temp);
                lst->insertNewNode(temp, j+1);
            }
        }
    }
}


#endif //LINKEDLIST_LINKEDLIST_HPP
