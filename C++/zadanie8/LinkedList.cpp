//
// Created by krzysztof on 31.05.2020.
//

#include "LinkedList.hpp"
template <typename T>
LinkedList<T>::LinkedList() : numberOfElements(0), start(nullptr) {
}

template <typename T>
int LinkedList<T>::getNumberOfElements() {
    return numberOfElements;
}

template <typename T>
int LinkedList<T>::search(T data) {
    int result = -1;
    Node* node = start;
    if (start != nullptr) {
        while (node->nextNode != nullptr) {
            if (node->getData() == data) {
                return node->getPosition();
            }
            node = node->nextNode;
        }
    }
    return result;
}


template <typename T>
void LinkedList<T>::deleteNode(T data) {
    Node* x= start;
    if(x->getData() == data) {
        start= x->nextNode;
        delete x;
        numberOfElements--;
        return;
    }
    Node* p=nullptr;
    while(x->getData()!=data && x!=nullptr) {
        p=x;
        x=x->nextNode;
    }
    if(x!=nullptr) {
        Node* temp= x->nextNode;
        //p->temp; ?????? tutaj nie wiem o co chodzilo
        delete x;
        delete temp;
        numberOfElements--;
    }
}

template <typename T>
void LinkedList<T>::insertNewNode(T data, int position) {
    Node* node = new Node(data, position);
    if (numberOfElements > position){
        changeNode(node, position);
    }
    else{
        addToEnd(node);
    }
}

template <typename T>
T LinkedList<T>::getValue(int pos) {
    Node* x=start;
    int i=0;
    while(i != pos) {
        x= x->nextNode;
        i++;
    }
    return x->getData();
}


template <typename T>
LinkedList<T>::Node::Node(T data, int position) :position(position), data(data),
                                                 nextNode(nullptr){

}

template <typename T>
T LinkedList<T>::Node::getData() {
    return data;
}

template <typename  T>
int LinkedList<T>::Node::getPosition() {
    return position;
}

template <typename T>
void LinkedList<T>:: changeNode(Node* newNode, int position){

    Node* node = start;
    while ( node -> position != position - 1){
        node = node -> nextNode;
    }
    newNode -> nextNode = node -> nextNode -> nextNode;
    node -> nextNode = newNode;
}

template <typename T>
void LinkedList<T>::addToEnd(Node* newNode){
    Node* node = start;
    if (node != nullptr) {
        while (node->nextNode != nullptr) {
            node = node->nextNode;
        }
        node->nextNode = newNode;
    }
    else start = newNode;
    numberOfElements ++;
}

template <typename T>
LinkedList<T> :: LinkedList(initializer_list<T> init) {
    for(T k:init)
        this->addToEnd(k);
    cout << "Initialized list length is:" << this->getNumberOfElements();
}

template <typename T>
LinkedList<T>::~LinkedList<T>() {
    Node* node = start;
    if (node != nullptr) {
        while (node->nextNode != nullptr) {
            Node *temp = node->nextNode;
            node->nextNode = temp->nextNode;
            delete temp;
        }
    }
}