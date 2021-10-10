/****************************************************/
/**  Assignment 2 - TollStack Header File          **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This header file contains the functions used  **/
/**  by the TollStack.hpp file.                    **/
/****************************************************/

#ifndef TOLLSTACK
#define TOLLSTACK

#include "LStack.h"
#include <iostream>
#include <ostream>
#include <cstdlib>

template<typename T>
class TollStack: public LStack<T> {
    public:
    // Constructors
        TollStack();
    // Destructor
        ~TollStack();
    // Accessors
        int count(const string& type);
        double totalIncome();
    // Mutators
        void remove(const string& license);
};

#include "TollStack.hpp"
#endif