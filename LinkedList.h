/****************************************************/
/**  Assignment 2 - Linked List Header File        **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This header file contains the functions used  **/
/**  by the LinkedList.hpp file.                   **/
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
        T& getHead() const;
        T& getTail() const;
        T& getCurr() const;
        bool isEmpty() const;

        // Setters (mutators)
        void setCurr(Node<T>* node);
        void addToHead(const T&);
        //void addToTail(value_type&);
        void addToTail(const T&);
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

#include "LinkedList.hpp"

#endif