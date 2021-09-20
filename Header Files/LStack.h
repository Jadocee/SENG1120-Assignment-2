
#ifndef LSTACK
#define LSTACK

#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

template<typename T>
class LStack {
    public:
    // Constructors
        LStack();
    // Destructor
        ~LStack();
    // Accessors
        T& peek();
        bool isEmpty();
        int size() const;
        int count(const string& type);
        double totalIncome();
    // Mutators
        T& pop();
        void push(T& i);
        void remove(const string& license);
    // Overload Member Operators
        void operator+=(LStack<T>&);
        void operator-=(LStack<T>&);

    private:
        LinkedList<T> list;
        int used;
};

// Overload Operators
template<typename T>
std::ostream& operator<<(std::ostream& out, LStack<T>& item);



#include "../Source Files/LStack.hpp"
#endif