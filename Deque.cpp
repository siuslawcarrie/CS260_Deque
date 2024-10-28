#include "Deque.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>
/*
/*Constructor (Python init) creates an array of n integer where n is the size passed in. If no
size is passed in, or if the size is <1, create an array of 20 items (default constructor). Do
not initialize the elements of the array unless you are using Python for the assignment. */


Deque::Deque(int size){
    if(size  >= 1){
        this->size = size; //putting size that's passed in into the size in the class (this);

    }
    theArray = new int[this->size];

}

Deque::~Deque(){}

/*void addTail(int value) – adds a new value to the tail of the queue, wrapping if necessary. If
        there is no room to add a new value, calls the resize( ) method.*/
void Deque::addTail(int value){}

/*
• int removeHead( ) – saves the value at the head of the queue, updates it to remove access to
that value, and returns the saved value, wrapping if necessary. If the queue is empty throws
an exception. (For C++ and C#, use the message: Array is empty in removeHead)*/

int Deque::removeHead(){}

/*
string dumpArray( ) – returns an array containing the contents of the array from index 0 to
        size-1. This is for debugging purposes and to verify that wrapping is working properly.*/

std::string Deque::dumpArray(){}

/*• resize( ) – creates a new array twice as large and copies the elements to it. This should
properly deal with situations where there has been wrapping and the tail is at an index less
than the head. Note, this is not a simple exercise where you can copy index 0 of the old
        array to index 0 of the new array and so forth. You will need to end up after copying with
        the head at index 0 and tail appropriately located. There are several ways to accomplish
this.*/

// create new array of newSize and copy to it
void Deque::resize(int newSize) {
    int *temp = new int[newSize];  // creates new array in a pointer called temp
    for (int i = 0; i < size; i++) {
        temp[i] = this->theArray[i]; //copies all data from the Array into temp
    }
    delete[] this->theArray;//delete old array
    this->theArray = temp; //copies pointers
    this->size = newSize; //changes array size
    return;
}

/*string listQueue( ) –returns a string listing the elements from head to tail. This should
properly deal with situations where there has been wrapping and the tail is at an index less
than the head.*/

std::string Deque::listQueue(){
    return "string";
}

//bool isEmpty() – returns true when the double ended queue is empty, false otherwise.
bool Deque::isEmpty(){
    return true;
};

void Deque::solveThink(int *values, int numValues){}

