
#include "LStack.h"

// Constructors
template<typename T>
LStack<T>::LStack() {}

// Destructors
template<typename T>
LStack<T>::~LStack() {}

// Accessors
template<typename T>
T& LStack<T>::peek() {
    return this->list.getHead()->getData();
}

template<typename T>
int LStack<T>::size() const {
    return this->list.getSize();
}

template<typename T>
bool LStack<T>::isEmpty() {
    if (this->list.getHead() == NULL) {
        return true;
    } else {
        return false;
    }
}

template<typename T>
int LStack<T>::count(const string& type) {
    return this->list.count(type);
}

template<typename T>
double LStack<T>::totalIncome() {
    return this->list.totalIncome();
}

template<typename T>
LinkedList<T>& LStack<T>::getList() {
    return this->list;
}

// Mutators
template<typename T>
void LStack<T>::push(T& i) {
    //TODO stack overflow
    list.addToHead(i);
}

template<typename T>
T LStack<T>::pop() {
    T data = list.getHead()->getData();
    list.removeFromHead();
    return data;
}

template<typename T>
void LStack<T>::remove(const string& license) {
    this->list.remove(license);
}

// Operator Overloads
template<typename T>
std::ostream& operator<<(std::ostream& out, LStack<T>& stack) {
    out << stack.getList();
    return out;
}

template<typename T>
void LStack<T>::operator+=(LStack<T>& stack) {
    this->list += stack.list;
}

template<typename T>
void LStack<T>::operator-=(LStack<T>& stack) {
    this->list -= stack.list;
}