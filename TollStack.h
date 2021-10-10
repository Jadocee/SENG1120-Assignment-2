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