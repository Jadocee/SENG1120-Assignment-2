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

class LinkedList {
    public:
        // Chained typedef from Node.h
        typedef Node::value_type value_type;

        // Constructors
        LinkedList();
        LinkedList(value_type&);

        // Destructors
        ~LinkedList();

        // Getters (accessors)
        int getSize() const;
        Node* getHead();
        Node* getTail();
        Node* getCurr();
        double totalIncome();
        int count(const string&);

        // Setters (mutators)
        void setCurr(Node* node);
        void addToHead(value_type&);
        //void addToTail(value_type&);
        void addToTail(value_type&);
        void remove(const string&);
        void removeFromHead();
        void removeCurrent();
        void removeFromTail();
        //void order();

        // Member operators
        void operator+=(LinkedList&);
        void operator-=(LinkedList&);
 
    
    private:
        Node* head;
        Node* tail;
        Node* curr;
        int size;
        
};

// overloads
std::ostream& operator<<(std::ostream& os, LinkedList& list);



#endif