#include "Deque.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>

/*
/*Constructor (Python init) creates an array of n integer where n is the size passed in. If no
size is passed in, or if the size is <1, create an array of 20 items (default constructor). Do
not initialize the elements of the array unless you are using Python for the assignment. */


Deque::Deque(int size) {
    std::string enter;
    std::cout << "mc Deque:Deque" << std::endl;
    std::cout << "mc if (size >= 1) {\n"
                 "        this->size = size;" <<std::endl;
    if (size >= 1) {
        this->size = size; //putting size that's passed in into the size in the class (this);

//        std::cin >> enter;
    }
    std::cout << "mc theArray = new int[this->size];" << std::endl;
    theArray = new int[this->size];
//    std::cin >> enter;

}

Deque::~Deque() {
    std::cout << "mc Deque::~Deque()" << std::endl;
    std::string enter;
//    std::cin >> enter;
}

/*void addTail(int value) – adds a new value to the tail of the queue, wrapping if necessary. If
        there is no room to add a new value, calls the resize( ) method.*/
void Deque::addTail(int value) {
//**go through  line by line, does count = size before resize, check in resize, if count = size also
    std::string enter;
    std::cout<<" mc addTail"<<std::endl;
    std::cout << " mc addTail function" << std::endl;
    std::cout << " mc if (tail >= size) {\n"
                 "    mc    tail = 0;\n" << std::endl;
//    std::cin >> enter;
    if (tail >= size) {
        tail = 0;
    }
    std::cout << "mc if (isEmpty()) {\n"
                 "   mc     resize(size * 2);" << std::endl;
    if (size == count) {//if size = count, resize
        resize(size * 2);

    }
count = count +1;
//    std::cin >> enter;
    std::cout << " mc theArray[tail] = value;\n"
                 "   mc  tail += 1;" << std::endl;
    theArray[tail] = value;
//    std::cin >> enter;
    std::cout << "mc tail += 1;" << std::endl;
    tail += 1;
//    std::cin >> enter;

}

/*
• int removeHead( ) – saves the value at the head of the queue, updates it to remove access to
that value, and returns the saved value, wrapping if necessary. If the queue is empty throws
an exception. (For C++ and C#, use the message: Array is empty in removeHead)*/

int Deque::removeHead() {
if (size - 1 == head){//this tests if head is at the end
    head = -1;//only resets head if at the end, this wraps head
}
    if (isEmpty()) {
        //throw exception
        throw std::out_of_range("Array is empty");
    } else {
        std::cout << " mc is Empty function" << std::endl;
        std::cout << " mc head = (head + 1) % size;" << std::endl;
        std::string enter;
        head = head + 1;//increments head - moves it to the right
//        std::cin >> enter;
        std::cout << "mc size--" << std::endl;
        count--;
        std::cout << "mc ++head" << std::endl;

//        std::cin >> enter;
    }

    return theArray[head];//returns value of head
}



/*
string dumpArray( ) – returns an array containing the contents of the array from index 0 to
        size-1. This is for debugging purposes and to verify that wrapping is working properly.*/
//list elements, purpose is to debug, gives snapshot of array, if it's wrapped properly
std::string Deque::dumpArray() {
    for (int i = 0; i < size; i++) {
        std::cout << theArray[i] << " ";
    }
    std::cout << std::endl;
}

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
//list elements
std::string Deque::listQueue() {
    return "string";
}

//bool isEmpty() – returns true when the double ended queue is empty, false otherwise.
bool Deque::isEmpty() {
    if (head + 1 == tail) {
        return true;
    }
    return false;
}

//void addHead(int value) – adds a new value at the head. Wraps if necessary. This should
//not overwrite data that was previously in the queue. If the array is full, calls resize( ) to
//double the array and copy the data as needed.
void addHead(int value) {}

//int removeTail( ) – saves the value at the tail of the queue, updating the queue to remove
//        access to the item at the tail, and returns the saved value. Wraps if necessary. If the queue
//        is empty, throws an exception. (For C++ and C#, use the message: Array is empty in
//removeTail)

int removeTail() {
    return -1;
}


//        How could you implement a stack using your double ended queue? Use this concept to list a
//        provided set of numbers in reverse order. More specifically, add a method to your Deque class
//        called thinkSolve which takes two arguments, an array of integers and the number of elements in
//the list. It instantiates a new deque, adds the integers to the new deque in their original order, then
//        removes the integers from the new deque in reverse order and adds them to the original deque
//upon which thinkSolve was called.
void Deque::solveThink(int *values, int numValues) {}

