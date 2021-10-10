/****************************************************/
/**  Assignment 2 - TollStack Source File          **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This source file contains the implementation  **/
/**  of the functions in the TollStack.h file.     **/
/****************************************************/

#include "TollStack.h"

template<typename T>
TollStack<T>::TollStack() {}

template<typename T>
TollStack<T>::~TollStack() {}

template<typename T>
int TollStack<T>::count(const string& type) {
    int n = 0;
    try {
        if(!this->isEmpty()) {
            LStack<T> temp;
            T tempData;
            do {
                if(this->peek().get_type() == type) {
                    n++;
                }
                tempData = this->pop();
                temp.push(tempData);
            } while(!this->isEmpty());
            while(!temp.isEmpty()) {
                tempData = temp.pop();
                this->push(tempData);
            }
        } else {
            throw "Stack is empty.";
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return n;
}

template<typename T>
double TollStack<T>::totalIncome() {
    try {
        double total = 0;
        if (this->isEmpty()) {
            throw "Stack is empty.";
        } else {
            LStack<T> temp;
            T tempData;
            while(!this->isEmpty()) {
                T tempData = this->pop();
                temp.push(tempData);
                total += tempData.get_charge();
            }
            if (temp.isEmpty()) {
                throw "Temporary stack is empty.";
            } else {
                while(!temp.isEmpty()) {
                    tempData = temp.pop();
                    this->push(tempData);
                }
            }
            return total;
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;
        return 0;
    }
}

template<typename T>
void TollStack<T>::remove(const string& license) {
    try {
        LStack<T> temp;
        T tempData;
        while (true) {
            if (this->isEmpty()) {
                throw "Stack is empty.";
            } else if (this->peek().get_licence() == license){
                this->pop();
                break;
            } else if (this->peek().get_licence() != license) {
                tempData = this->pop();
                temp.push(tempData);
            }
        }
        while (!temp.isEmpty()) {
            tempData = temp.pop();
            this->push(tempData);
        }
    } catch(exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}