/****************************************************/
/**  Assignment 1 - Node Source File        **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This header file contains the functions used  **/
/**  to access the nodes and its data.             **/
/****************************************************/

#include "Node.h"

// Constructors

Node::Node(const value_type& data) {
    this->data = data;
    next = NULL;
    prev = NULL;
}

Node::Node() {
    next = NULL;
    prev = NULL;
}


// Destructors

Node::~Node() {
    next = NULL;
    prev = NULL;
}

// Getters (Accessors)

Node::value_type Node::getData() const {
    return data;
}

const Node* Node::getNext() const {
    return next;
}

Node* Node::getNext() {
    return next;
}

const Node* Node::getPrev() const {
    return prev;
}

Node* Node::getPrev() {
    return prev;
}

// Setters (Mutators)

void Node::setData(const value_type& data) {
    Node::data = data;
}

void Node::setNext(Node* next) {
    Node::next = next;
}

void Node::setPrev(Node* prev) {
    Node::prev = prev;
}