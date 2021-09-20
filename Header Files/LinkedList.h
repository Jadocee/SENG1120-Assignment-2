/****************************************************/
/**  Assignment 1 - Linked List Header File        **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This header file contains the functions used  **/
/**  by the LinkedListDemo cpp file.               **/
/****************************************************/

#ifndef LINKED_LIST
#define LINKED_LIST

#include "cstdlib"
#include "Node.h"
#include "string"
#include "iostream"
#include "ostream"

template<typename T>
class LinkedList {
    public:
        // Chained typedef from Node.h
        //typedef Node::value_type value_type;

        // Constructors
        LinkedList();
        LinkedList(T&);

        // Destructors
        ~LinkedList();

        // Getters (accessors)
        int getSize() const;
        Node<T>* getHead();
        Node<T>* getTail();
        Node<T>* getCurr();
        double totalIncome();
        int count(const string&);

        // Setters (mutators)
        void setCurr(Node<T>* node);
        void addToHead(T&);
        //void addToTail(value_type&);
        void addToTail(T&);
        void remove(const string&);
        void removeFromHead();
        void removeCurrent();
        void removeFromTail();
        //void order();

        // Member operators
        void operator+=(LinkedList<T>&);
        void operator-=(LinkedList<T>&);
 
    
    private:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* curr;
        int size;
        
};

// Operator Overloads
template<typename T>
std::ostream& operator<<(std::ostream& os, LinkedList<T>& list);

#include "../Source Files/LinkedList.hpp"

#endif