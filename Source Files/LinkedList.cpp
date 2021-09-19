/****************************************************/
/**  Assignment 1 - Linked List Source File        **/
/**  Jaydon Cameron                                **/
/**  SENG1120 Data Structures                      **/
/**  C3329145                                      **/
/**  This source file contains the functions for working with the linked list and accessing the nodes.            **/
/****************************************************/

#include "LinkedList.h"
#include "cstdlib"
#include "ostream"
#include "string"

// Constructors
LinkedList::LinkedList() { // Create Linked List with no data.
    head = NULL;    // Update head.
    tail = NULL;    // Update tail.
    curr = NULL;    // Update curr.
    size = 0;       // Update size.
}

LinkedList::LinkedList(value_type& data) {  // Create linked list with data.
    this->head = new Node(data);    // Update head.
    this->tail = this->head;        // Update tail.
    this->curr = this->head;        // Update curr.
    size = 1;                       // Update size.

}

// Destructors
LinkedList::~LinkedList() {
    while (this->head != NULL) {    // Check if head points to node.
        this->removeFromHead();     // Remove head. Repeat check until empty.
    }
    this->tail = NULL;  // Update tail pointer to NULL.
}

// Mutators
void LinkedList::removeCurrent() {
    /*  Precondition:   List is not empty, and curr points to a node.
        Postcondition:  The current node is removed, and the list is 
                        updated.    */
    if (this->curr == this->head) {
        this->removeFromHead(); // Remove from head of list.
    } else if (this->curr == this->tail) {
        this->removeFromTail(); // Remove from tail of list.
    } else {
        Node* temp = this->curr;    // Create temporary node pointer, pointing to curr.
        this->curr->getPrev()->setNext(this->curr->getNext());
        this->curr->getNext()->setPrev(this->curr->getPrev()); 
        this->curr = this->head;    // Update curr to point to head.
        delete temp;    // Delete temporary node.
        this->size--;   // Update size.
    }                                    
    this->curr = this->head;    // Update curr to point to head.                                
}

void LinkedList::remove(const string& license) {
    /*  Precondition:   list is not empty.
        Postcondition:  The node (or nodes) containing the license is
                        removed.    */
    this->curr = this->head;    // Update current to point to head.
    for (int i = 0; i < this->size; i++) {  // Cycle through each node, using curr as an index.
        if (this->curr->getData().get_licence() == license) {   // Check current node contains the license.
            //Node* temp = this->curr->getNext(); // Create temporary node pointer and point it to next node.
            this->removeCurrent();  // Remove current node.
            //this->curr = temp;      // Update curr to point to the same node as temp.
            break;
        } else {
            this->curr = this->curr->getNext(); // Otherwise, update curr to point to the next node in the list.
        }
    }
}

void LinkedList::addToHead(value_type& data) {
    /*  Precondition:   No preconditions.
        Postconditon:   A new node is created and added to the beginning
                        of the list, as the new head.   */
    this->curr = new Node(data);    // Create a new node, and have curr point to it.
    if (this->size == 0) {          // Check if there is no nodes in list.
        this->tail = this->curr;    // Make curr node the tail of the list.
    } else if(this->size > 0 && this->head != NULL) {  // Check if node(s) exist.
        this->curr->setNext(this->head);               // Update currs next to point to head.
        this->head->setPrev(this->curr);               // Update heads prev to point to curr.
    }
    this->head = this->curr;    // Update head to point to curr.
    this->size++;               // Update size.
}

void LinkedList::addToTail(value_type& data) {
    /*  Precondition:   The list isnt empty.
        Postcondition:  A new node is created and added to the end of the list
                        as the new tail.    */
    this->curr = new Node(data);
    if (this->size > 0 && this->tail != NULL) {
        curr->setPrev(tail);    // Update currs prev to point to tail.
        tail->setNext(curr);    // Update tails next to point to curr.
    } else if (size == 0) {  // Check size 
        this->head = this->curr;    // Update head to point to curr.
    }
    this->tail = this->curr;    // Update tail to point to curr.
    this->size++;   // Update size.
}

void LinkedList::removeFromHead() {
    // Precondition: list isnt empty.
    // Postcondition: The head of the node is removed.
    Node* n = this->head;   // Create temporary node.
    this->head = this->head->getNext(); // Update head to point to the next node in the linked list.
    if (this->head != NULL) {
        // If head points to a node, update previous to point to NULL.
        this->head->setPrev(NULL);
    } else {
        // If list is empty, make tail point to NULL.
        this->tail = NULL;
    }
    // Remove temporary node.
    delete n;
    this->size--;   // Update size.
}

void LinkedList::removeFromTail() {
    /*  Precondtions:   List isnt empty. Tail points to a node.
        Postconditions: The current tail is removed and a new tail is 
                        assigned.   */
    Node* n = this->tail;   // Create temporary node. Point to tail.
    this->tail = this->tail->getPrev(); // Update tail to previous node.
    if (this->tail != NULL) {   // Check if tail points to a node.
        this->tail->setNext(NULL);  // Update tails next to NULL.
    } else {    // If tail points to NULL.
        this->head = NULL;  // Update head to be NULL.
    }
    delete n; // Delete temporary node.
    this->size--; // Update size.
}

// Accessors
int LinkedList::count(const string& vehicleType) {
    /*  Preconditions:  List isnt empty.
        Postcondtions:  The number of vehicles of the type is counted
                        and returned to the function call.  */
    this->curr = this->head;    // Update curr to point to head.
    int count = 0;              // Declare an integer "count" and assign 0.
    for (int i = 0; i < this->size; i++) {  // Loop list size times.
        if(this->curr->getData().get_type() == vehicleType) {   // Check current node contains vehicle type.
            count++;                            // Update count.
        }
        this->curr = this->curr->getNext();     // Update curr to point to the next node in the list.
    }
    return count;
}

Node* LinkedList::getTail() {
    /*  Precondition:   List isnt empty.
        Postcondition:  Tail is returned to the function caller.    */
    return this->tail;
}

Node* LinkedList::getCurr() {
    /*  Precondition:   List isnt empty.
        Postcondition:  Curr is returned to the function caller.    */
    return LinkedList::curr;
}

Node* LinkedList::getHead() {
    /*  Precondition:   List isnt empty.
        Postcondition:  head is returned to the function caller.    */
    return LinkedList::head;
}

int LinkedList::getSize() const {
    /*  Precondition:   None.
        Postcondition:  List size is returned to the function caller.    */
    return size;
}

double LinkedList::totalIncome() {
    /*  Precondition:   List isnt empty.
        Postcondition:  Total charged per vehicle is calculated and returned to
                        the function caller.    */
    this->curr = this->head;    // Update curr to point to head.
    double t = 0;               // Declare double "t" and assign 0.
    for (int i = 0; i < this->size; i++) {  // Loop list size times.
        t += curr->getData().get_charge();  // Add charge to t.
        this->curr = this->curr->getNext(); // Update curr to point to next node in list.
    }
    return t;
}

void LinkedList::setCurr(Node* node) {
    this->curr = node; // Update curr to point to desired node.
}

// Overload << operator
std::ostream& operator<<(std::ostream& out, LinkedList& list){
    /*  Precondition:   List isnt empty.
        Postcondition:  Return a concatination of strings containing the licence
                        and type of each vehicle, or whether the list is empty.*/
    if (list.getSize() > 0) {   // Check if the list contains one or more nodes.
        list.setCurr(list.getHead());   // Update curr to point to head.
        for (int i = 0; i < list.getSize(); i++) {  // Loop list size times.
            out << "(" << list.getCurr()->getData().get_licence() << "," << list.getCurr()->getData().get_type() << ")\t";  // Concatenate strings containing licence and type.
            list.setCurr(list.getCurr()->getNext()); // Update lists curr to point to the next node in the list.
        }
    } else {
        out << "List is empty.";    // If list is empty, move "list is empty" into out.
    }
    return out; 
}

// Member Operators
//  Overload += operator
void LinkedList::operator+=(LinkedList& list) {
    list.curr = list.head;    
    for (int i = 0; i < list.size; i++) {
       if (this->size == 0) {
            this->curr = new Node(list.curr->getData());
            this->head = this->curr;
            this->tail = this->curr;
        } else {
            this->curr = new Node(list.curr->getData());
            this->curr->setPrev(this->tail);
            this->tail->setNext(this->curr);
            this->tail = this->curr;
        }
        this->size++;
        list.curr = list.curr->getNext(); 
    }
}

//  Overload -= operator
void LinkedList::operator-=(LinkedList& list) {
    /*  Precondition:   List isnt empty.
        Postcondition:  The passed lists content is removed from the linked list.    */
    list.curr = list.head;  // Update list curr to point to list head.
    for(int j = 0; j < list.size; j++) {    // Loop list size times.
        this->curr = this->head; // Update curr to point to head.
        for(int i = 0; i < this->size; i++) {   // Loop this->size times.
            if(this->curr->getData() == list.curr->getData()) {
                Node* n = this->curr->getNext(); // Create temporary node pointer and point it to currs next.
                this->removeCurrent(); // Remove current node.
                this->curr = n; // Update curr to point to n.
            } else {
                this->curr = this->curr->getNext(); // Move current to next node in list.
            }
        }
        list.curr = list.curr->getNext(); // Move to next node.
    }
}