/****************************************************/
/**  Assignment 1 - Node Source File        **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This header file contains the functions used  **/
/**  to access the nodes and its data.             **/
/****************************************************/

#include "../Header Files/Node.h"
// Constructors
template<typename T>
Node<T>::Node(const T& data) {
    this->data = data;
    next = NULL;
    prev = NULL;
}

template<typename T>
Node<T>::Node() {
    next = NULL;
    prev = NULL;
}


// Destructors
template<typename T>
Node<T>::~Node() {
    next = NULL;
    prev = NULL;
}

// Getters (Accessors)
template<typename T>
T Node<T>::getData() const {
    return data;
}

template<typename T>
const Node<T>* Node<T>::getNext() const {
    return this->next;
}

template<typename T>
Node<T>* Node<T>::getNext() {
    return this->next;
}

template<typename T>
const Node<T>* Node<T>::getPrev() const {
    return prev;
}

template<typename T>
Node<T>* Node<T>::getPrev() {
    return prev;
}

// Setters (Mutators)
template<typename T>
void Node<T>::setData(const T& data) {
    Node<T>::data = data;
}

template<typename T>
void Node<T>::setNext(Node<T>* next) {
    Node<T>::next = next;
}

template<typename T>
void Node<T>::setPrev(Node<T>* prev) {
    Node<T>::prev = prev;
}