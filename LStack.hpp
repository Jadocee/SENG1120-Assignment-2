/*********************************************************/
/**     Assignment 2 - LStack Source File               **/
/**     Jaydon Cameron                                  **/
/**     SENG1120 Data Structures                        **/
/**     C3329145                                        **/
/**     This source file contains the implementation of **/
/**     the functions in the LStack.h file.             **/
/*********************************************************/

#include "LStack.h"
#include <string>
#include <iostream>
#include <exception>

// Constructors
template<typename T>
LStack<T>::LStack() {
    this->size = 0;
}

// Destructors
template<typename T>
LStack<T>::~LStack() {
    while (this->size > 0) {
        this->pop();
    }
}

// Accessors
template<typename T>
T& LStack<T>::peek() {
    return this->list.getHead();
}

template<typename T>
int LStack<T>::getSize() const {
    return this->size;
}

template<typename T>
bool LStack<T>::isEmpty() const {
    return this->list.isEmpty();
}

// Mutators
template<typename T>
void LStack<T>::push(const T& i) {
    //TODO stack overflow
    this->list.addToHead(i);
    this->size++;
}

template<typename T>
T LStack<T>::pop() {
    T data = list.getHead();
    this->list.removeFromHead();
    this->size--;
    return data;
}

// Operator Overloads
template<typename T>
std::ostream& operator<<(std::ostream& out, LStack<T>& stack) {
    if (!stack.isEmpty()) {
        LStack<T> temp;
        T tempData;
        while (!stack.isEmpty()) {
            tempData = stack.pop();
            temp.push(tempData);
            out << "(" << tempData.get_licence() << "," << tempData.get_type() << ")\t";
        }
        while(!temp.isEmpty()) {
            tempData = temp.pop();
            stack.push(tempData);
        }
    } else {
        out << "List is empty.";
    }
    return out;
}

template<typename T>
void LStack<T>::operator+=(LStack<T>& stack) {
    try {
        if(!stack.isEmpty()) {
            LStack<T> temp;
            T tempData;
            while(!stack.isEmpty()) {
                tempData = stack.pop();
                temp.push(tempData);
                this->push(tempData);
            }
            while(!temp.isEmpty()) {
                tempData = temp.pop();
                stack.push(tempData);
            }
        } else {
            throw "Stack is empty.";
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

template<typename T>
void LStack<T>::operator-=(LStack<T>& stack) {
    try {
        if(stack.isEmpty() && this->isEmpty()) {            // Check if both stacks are empty.
            throw "Both stacks are empty.";                 // Throw exception.
        } else if(stack.isEmpty()) {                        // Check if stack being removed is empty.
            throw "The stack to be removed is empty.";      // Throw exception.
        } else if(this->isEmpty()) {                        // Check if stack to be removed from is empty.
            throw "The stack to be removed from is empty."; // Throw exception.
        } else {
            LStack<T> temp;
            LStack<T> temp2;                 // Temporary stack.
            T tempData;                     // Temporary data.
            while(!this->isEmpty()) {       // Loop while this stack isn't empty.
                while (!stack.isEmpty()) {
                    if(this->peek() == stack.peek()) {
                        this->pop();
                        while(!temp2.isEmpty()) {
                            tempData = temp2.pop();
                            stack.push(tempData);
                        }
                        break;
                    } else {
                        tempData = stack.pop();
                        temp2.push(tempData);
                    }
                }
                if(stack.isEmpty()) {
                    while(!temp2.isEmpty()) {
                        tempData = temp2.pop();
                        stack.push(tempData);
                    }
                    tempData = this->pop();
                    temp.push(tempData);
                }
            }
            while(!temp.isEmpty()) {
                tempData = temp.pop();
                this->push(tempData);
            }
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;  // Output to console.
    }
}