/****************************************************/
/**  Assignment 1 - Node Header File        **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This header file contains the functions used  **/
/**  by the LinkedListDemo cpp file.               **/
/****************************************************/

#ifndef NODE
#define NODE

#include "cstdlib"
#include "string"
#include "iostream"
#include "EToll.h"

class Node  {
    public:
        // Create a typedef
        typedef EToll value_type;

        // Constructors
        Node(const value_type& data);
        Node();

        //Destructors
        ~Node();

        // Accessors
        value_type getData() const; // const at end of declaration prevents func' from changing a member variable.
        const Node* getNext() const;
        Node* getNext();
        const Node* getPrev() const;
        Node* getPrev();
        
        // Mutatators
        void setData(const value_type& data);
        void setNext(Node* next);
        void setPrev(Node* prev);

    private:
        Node* next;
        Node* prev;
        value_type data;
};

#endif