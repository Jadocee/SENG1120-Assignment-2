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

template <typename T>
class Node  {
    public:
        // Create a typedef
        //typedef EToll value_type;

        // Constructors
        Node(const T& data);
        Node();

        //Destructors
        ~Node();

        // Accessors
        T getData() const; // const at end of declaration prevents func' from changing a member variable.
        const Node<T>* getNext() const;
        Node<T>* getNext();
        const Node<T>* getPrev() const;
        Node<T>* getPrev();
        
        // Mutatators
        void setData(const T& data);
        void setNext(Node<T>* next);
        void setPrev(Node<T>* prev);

    private:
        Node<T>* next;
        Node<T>* prev;
        T data;
};
#include "../Source Files/Node.hpp"

#endif