/****************************************************/
/**  Assignment 2 - TollStack Source File          **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This source file contains the implementation  **/
/**  of the functions in the TollStack.h file.     **/
/****************************************************/

#include "TollStack.h"

// Constructor
template<typename T>
TollStack<T>::TollStack() {}

// Destructor
template<typename T>
TollStack<T>::~TollStack() {}

// Accessors
template<typename T>
int TollStack<T>::count(const string& type) {
    /*  Precondition:   None.
        Postcondition:  The number of items in the stack that contain the desired car type is returned. */
    int n = 0;                  // Create temp counter set to 0.
    try {
        if(!this->isEmpty()) {  // Check if this stack isn't empty.
            LStack<T> temp;     // Create temporary LStack.
            T tempData;         // Create temp data.
            do {
                if(this->peek().get_type() == type) {   // Check if the type from the data in the top of the stack matches the parsed type.
                    n++;                    // Update counter.
                }
                tempData = this->pop();     // Remove from top of the stack and store the data.
                temp.push(tempData);        // Add this data to the temp stack.
            } while(!this->isEmpty());      // Loop if this stack isn't empty.
            while(!temp.isEmpty()) {        // Loop until the temp stack is empty (or if the temp stack isn't empty).
                tempData = temp.pop();      // Remove from the top of the temp stack and store its data.
                this->push(tempData);       // Add this data to this stack.
            }
        } else {
            throw "Stack is empty.";        // Throw exception.
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;  // Print exception message.
        exit(1);                                    // Exit program with error code 1.
    }
    return n;                   // Return counter.
}

template<typename T>
double TollStack<T>::totalIncome() {
    /*  Precondition:   The stack isn't empty.
        Postcondition:  The total charge is calculated from each item in the stack and then returned. */
    try {
        double total = 0;           // Create variable to store total.
        if (this->isEmpty()) {      // Check if stack is empty.
            throw "Stack is empty.";    // Throw exception.
        } else {
            LStack<T> temp;             // Create temporary stack.
            T tempData;                 // Create temporary data.
            while(!this->isEmpty()) {   // Loop until stack is empty (or loop if stack isn't empty).
                T tempData = this->pop();   // Remove from top of stack and store its data.
                temp.push(tempData);        // Add this data to the temp stack.
                total += tempData.get_charge(); // Get the charge from the data and add it to the total.
            }
            if (temp.isEmpty()) {       // Check if temp stack is empty.
                throw "Temporary stack is empty.";  // Throw exception.
            } else {
                while(!temp.isEmpty()) {    // Loop until temp stack is empty (or loop if temp stack isn't empty).
                    tempData = temp.pop();  // Remove from top of temp stack and store its data.
                    this->push(tempData);   // Add this data back to this (the original) stack.
                }
            }
            return total;   // Return the total charge.
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;  // Print exception message.
        exit(1);    // Exit program with error indicated as the cause.
    }
}

// Mutators
template<typename T>
void TollStack<T>::remove(const string& license) {
    /*  Precondition:   The stack isn't empty.
        Postcondition:  The item containing the desired license is removed from the stack. */
    try {
        LStack<T> temp;             // Create temporary LStack.
        T tempData;                 // Create temporary data.
        while (true) {              // Loop indefinitely.
            if (this->isEmpty()) {          // Check if the stack is empty.
                throw "Stack is empty.";    // Throw exception.
            } else if (this->peek().get_licence() == license){  // Check if the data from the top of the stack contains the same license as the parsed license.
                this->pop();                // Remove from the top of the stack.
                break;                      // Exit loop.
            } else if (this->peek().get_licence() != license) { // Check if the data from the top of the stack does not contain the same license as the parsed license.
                tempData = this->pop();     // Remove from the top of the stack and store its data.
                temp.push(tempData);        // Add this data to the temp stack.
            }
        }
        while (!temp.isEmpty()) {   // Loop until the temp stack is empty.
            tempData = temp.pop();  // Remove from the top of the temp stack and store its data.
            this->push(tempData);   // Add this data back to this (the original) stack.
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;  // Print exception message.
        exit(1);                                    // Exit program with error as the cause (indicated by 1).
    }
}