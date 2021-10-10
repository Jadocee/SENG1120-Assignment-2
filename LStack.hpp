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
    this->size = 0;     // Set size to 0.
}

// Destructors
template<typename T>
LStack<T>::~LStack() {
    while (this->size > 0) {    // Loop if stack has a size greater than zero.
        this->pop();            // Remove top of stack.
    }
}

// Accessors
template<typename T>
T& LStack<T>::peek() {
    /*  Precondition:   The stack isn't empty.
        Postcondition:  The data from the top of the stack is returned. */
    return this->list.getHead();    // Return the data in the head of the linked list.
}

template<typename T>
int LStack<T>::getSize() const {
    /*  Precondition:   No preconditions.
        Postcondition:  The size of the stack is returned. */
    return this->size;      // Return the size of the stack.
}

template<typename T>
bool LStack<T>::isEmpty() const {
    /*  Precondition:   None.
        Postcondition:  A boolean is returned based on whether the stack is empty or not. */
    return this->list.isEmpty();    // Return whether the linked list is empty or not.
}

// Mutators
template<typename T>
void LStack<T>::push(const T& i) {
    /*  Precondition:   None.
        Postcondition:  A new item is added to the top of the stack. */
    this->list.addToHead(i);            // Add data to the top of the stack.
    this->size = this->list.getSize();  // Update size of stack.
}

template<typename T>
T LStack<T>::pop() {
    /*  Precondition:   The stack isn't empty.
        Postcondition:  The top of the stack is removed. */
    try {
        if(this->isEmpty()) {           // Check if stack is empty.
            throw "Stack is empty.";    // If stack is empty: throw exception.
        } else {
            T data = list.getHead();                // Store data from top of stack in a temporarily.
            this->list.removeFromHead();            // Remove top of stack.
            this->size = this->list.getSize();      // Update size of stack.
            return data;                            // Return the data of what was removed.
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;  // Output the exception message to console.
        exit(1);                                    // End program with error as the cause.
    }
}

// Operator Overloads
template<typename T>
std::ostream& operator<<(std::ostream& out, LStack<T>& stack) {
    /*  Precondition:   The stack isn't empty.
        Postcondition:  The contents of the stack are returned as an ostream type. */
    if (!stack.isEmpty()) {         // Check if the stack is not empty.
        LStack<T> temp;             // Create temporary LStack.
        T tempData;                 // Create temporary data.
        while (!stack.isEmpty()) {  // Loop until the stack is empty (or check if the stack isn't empty).
            tempData = stack.pop(); // Remove top of stack and store it's data.
            temp.push(tempData);    // Add data to temporary stack.
            out << "(" << tempData.get_licence() << "," << tempData.get_type() << ")\t";    // Print the license and type from the data.
        }
        while(!temp.isEmpty()) {    // loop until the temporary stack is empty (or check if the temp stack isn't empty).
            tempData = temp.pop();  // Remove the top of the temp stack and store it's data.
            stack.push(tempData);   // Add the data back to the original stack.
        }
    } else {
        out << "List is empty.";    // Alternative if the stack is empty.
    }
    return out;                     // Return ostream.
}

template<typename T>
void LStack<T>::operator+=(LStack<T>& stack) {
    /*  Precondition:   The second stack isn't empty.
        Postcondition:  The contents of the second stack are added to the first stack. */
    try {
        if(!stack.isEmpty()) {              // Check if the second stack isn't empty.
            LStack<T> temp;                 // Create temporary LStack.
            T tempData;                     // Create temporary data.
            while(!stack.isEmpty()) {       // Loop until the second stack is empty.
                tempData = stack.pop();     // Remove from top of the second stack and store the data.
                temp.push(tempData);        // Add this data to the temporary stack.
                this->push(tempData);       // Add the same data to this (original) stack.
            }
            while(!temp.isEmpty()) {        // Loop until the temp stack is empty.
                tempData = temp.pop();      // Remove from the top of the temp stack and store its data.
                stack.push(tempData);       // Add this data back to the second stack.
            }
        } else {
            throw "Stack is empty.";        // Throw exception if the second stack is empty.
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;  // Print exception message.
        exit(1);                                    // Exit program with error indicated as the cause.
    }
}

template<typename T>
void LStack<T>::operator-=(LStack<T>& stack) {
    /*  Precondition:   Both stacks aren't empty.
        Postcondition:  The contents of the second stack are removed from the first stack.  */
    try {
        if(stack.isEmpty() && this->isEmpty()) {            // Check if both stacks are empty.
            throw "Both stacks are empty.";                 // Throw exception.
        } else if(stack.isEmpty()) {                        // Check if stack being removed is empty.
            throw "The stack to be removed is empty.";      // Throw exception.
        } else if(this->isEmpty()) {                        // Check if stack to be removed from is empty.
            throw "The stack to be removed from is empty."; // Throw exception.
        } else {
            LStack<T> temp;                     // Create temporary stack.
            LStack<T> temp2;                    // Create a second temporary stack.
            T tempData;                         // Create temporary data.
            while(!this->isEmpty()) {           // Loop while this stack isn't empty.
                while (!stack.isEmpty()) {      // Loop until second stack is empty.
                    if(this->peek() == stack.peek()) {      // Check if the top of both stacks are the same.
                        this->pop();                        // Remove the top of this stack.
                        while(!temp2.isEmpty()) {           // Loop until second temp stack is empty (or if second temp stack isn't empty).
                            tempData = temp2.pop();         // Remove from top of temp stack and store its data.
                            stack.push(tempData);           // Add the data to the second stack.
                        }
                        break;                              // Exit the loop.
                    } else {
                        tempData = stack.pop(); // Remove the top of the second stack and store its data.
                        temp2.push(tempData);   // Add this data to the second temp stack.
                    }
                }
                if(stack.isEmpty()) {           // Check if the second stack is empty.
                    while(!temp2.isEmpty()) {   // Loop until the second temp stack is empty (or if the second temp stack isn't empty).
                        tempData = temp2.pop(); // Remove from the top of the second temp stack and store its data.
                        stack.push(tempData);   // Add this data back to the second stack.
                    }
                    tempData = this->pop();     // Remove the top of this stack (i.e. the original stack) and store its data.
                    temp.push(tempData);        // Add this data to the temp stack.
                }
            }
            while(!temp.isEmpty()) {            // Loop until the temp stack is empty.
                tempData = temp.pop();          // Remove from the top of the temp stack and store its data.
                this->push(tempData);           // Add this data back to the stack.
            }
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;  // Output to console.
        exit(1);                                    // Exit program with 1.
    }
}