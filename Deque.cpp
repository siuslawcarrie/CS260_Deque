#include "Deque.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>


/*Constructor (Python init) creates an array of n integer where n is the size passed in. If no
size is passed in, or if the size is <1, create an array of 20 items (default constructor). Do
not initialize the elements of the array unless you are using Python for the assignment. */


Deque::Deque(int size) {
//    std::string enter;
//    std::cout << "mc Deque:Deque" << std::endl;
//    std::cout << "mc if (size >= 1) {\n"
//                 "        this->size = size;" <<std::endl;
    if (size >= 1) {
        this->size = size; //putting size that's passed in into the size in the class (this);

//        std::cin >> enter;
    }
//    std::cout << "mc theArray = new int[this->size];" << std::endl;
    theArray = new int[this->size];
//    std::cin >> enter;

}

Deque::~Deque() {
//    std::cout << "mc Deque::~Deque()" << std::endl;
    std::string enter;
//    std::cin >> enter;
}


/*void addHead(int value) – adds a new value at the head. Wraps if necessary. This should
//not overwrite data that was previously in the queue. If the array is full, calls resize( ) to
//double the array and copy the data as needed.*/
void Deque::addHead(int value) {//***Dr. Majchrak help & working 11.18
//    std::cout << "mc beginning of addHead, stats:" << std::endl;
//    std::cout << "Size: " << size << std::endl;
//    std::cout << "Head: " << head << std::endl;
//    std::cout << "count: " << count << "end stats" << std::endl;
//    std::cout << "dumparray: " << dumpArray() << std::endl;
//    int location;
    if (count == size) {
        resize(2 * size);
//        head = size - 1;
    }
//    if (head == (size - 1)) {
    if (head == -1) {
//        location = 7;//dr M
//location = size; //jacob
        head = size;
    } /*else {
        location = head;//if head is not at end of array
    }*///jacob change
//    theArray[location] = value;//if head is at size - 1 (end of array), does not move head, pulls next value from [0]
//    head = (head - 1 + size) % //jacob size;//jacob change

    theArray[head] = value;
    head--;//jacob, moved above theArray[head
    count++;
//    std::cout<<"mc end of addHead, stats: "<<std::endl;
//    std::cout << "Size: " << size << std::endl;
//    std::cout << "Head: " << head << std::endl;
//    std::cout << "count: " << count << " end stats" << std::endl;
}

/*
• int removeHead( ) – saves the value at the head of the queue, updates it to remove access to
that value, and ZEthe saved value, wrapping if necessary. If the queue is empty throws
an exception. (For C++ and C#, use the message: Array is empty in removeHead)*/

int Deque::removeHead() {//****WHERE TO PUT HEAD AFTER RESIze & when to wrap
//    std::cout << "mc beginning of removeHead, stats:" << std::endl;
//    std::cout << "Size: " << size << std::endl;
//    std::cout << "Head: " << head << std::endl;
//    std::cout << "count: " << count << "end stats" << std::endl;

    if (head >= size) {//this tests if head is at the end
        head = -1;//only resets head if at the end, this wraps head
//        return theArray[head];
    }
    if (isEmpty()) {
        //throw exception+

        throw std::out_of_range("Array is empty");
    }
//    head = (head + 1 + size) % size;
    int value = theArray[head+1];
//    std::cout<<"Head in value = theArray[head] "<<head<<std::endl;
//    std::cout<<"Value: "<<std::endl;
    count--;
    head++;
//    std::cout<<"Head after head++ "<<head<<std::endl;
//        std::cout << " mc is Empty function" << std::endl;
//        std::cout << " mc head = (head + 1) % size;" << std::endl;
//        std::string enter;
//        head = head + 1;//increments head - moves it to the right
//        std::cin >> enter;
//        std::cout << "mc count--" << std::endl;
//        count--;
//    std::cout << "end of removeHead, stats: " << std::endl;
//    std::cout << "Size: " << size << std::endl;
//    std::cout << "Head: " << head << std::endl;
//    std::cout << "count: " << count << "end stats" << std::endl;
    return value;//returns value of head

}

/*void addTail(int value) – adds a new value to the tail of the queue, wrapping if necessary. If
        there is no room to add a new value, calls the resize( ) method.*/
void Deque::addTail(int value) {
//**go through  line by line, does count = size before resize, check in resize, if count = size also
//    std::cout << "mc beginning of addTail" << std::endl;
//    std::cout << "Size: " << size << std::endl;
//    std::cout << "Tail: " << tail << std::endl;
//    std::cout<<"Value: "<<value<<std::endl;
//    std::cout<<"Head: "<<head<<std::endl;
//    std::cout << "count: " << count << std::endl<<std::endl;

    if (tail >= size) {
        tail = 0;
    }
//    std::cout << "mc if (isEmpty()) {\n"
//                 "   mc     resize(size * 2);" << std::endl;
    if (count == size) {//if size = count, resize
        resize(size * 2);

    }

//    std::cin >> enter;
//    std::cout << " mc theArray[tail] = value;\n"
//                 "   mc  tail += 1;" << std::endl;
    theArray[tail] = value;
//    std::cin >> enter;
//    std::cout << "mc tail += 1;" << std::endl;
    tail += 1;
    count = count + 1;
//    std::cout << "end of addTail, stats:" << std::endl;
//    std::cout << "Size: " << size << std::endl;
//    std::cout << "Tail: " << tail << std::endl;
//    std::cout<<"Value: "<<value<<std::endl;
//    std::cout << "count: " << count << "end stats " << std::endl<<std::endl;
}

//int removeTail( ) – saves the value at the tail of the queue, updating the queue to remove
//        access to the item at the tail, and returns the saved value. Wraps if necessary. If the queue
//        is empty, throws an exception. (For C++ and C#, use the message: Array is empty in
//removeTail)

int Deque::removeTail(){//***WORKING PER REMOVETAIL TEST
    //remove tail & add head both move to the left, MOVE FIRST then look.
    //remove head, add tail move to the right, LOOK FIRST, then move
    int value;

//        std::cout << "mc beginning of removeTail, stats: " << std::endl;
//        std::cout << "Size: " << size << std::endl;
//        std::cout << "Tail: " << tail << std::endl;
//        std::cout << "count: " << count << "end stats " << std::endl;
    if (isEmpty()) {
        throw std::out_of_range("Array is empty");
    }


//        tail = (tail - 1 + size) % size;
//        int value = theArray[tail];
//        count--;




    if (tail == -1) {

        tail = size - 1;
    } /*else {
        location = head;//if head is not at end of array
    }*///jacob change
//    theArray[location] = value;//if head is at size - 1 (end of array), does not move head, pulls next value from [0]
//    head = (head - 1 + size) % //jacob size;//jacob change
    tail--;
    value = theArray[tail];

    count--;
//    std::cout << "end of remove Tail, stats: " << std::endl;
//    std::cout << "Size: " << size << std::endl;
//    std::cout << "Tail: " << tail << std::endl;
//    std::cout << "count: " << count << "end stats " << std::endl;
    return value;
}
/*• resize( ) – creates a new array twice as large and copies the elements to it. This should
properly deal with situations where there has been wrapping and the tail is at an index less
than the head. Note, this is not a simple exercise where you can copy index 0 of the old
        array to index 0 of the new array and so forth. You will need to end up after copying with
        the head at index 0 and tail appropriately located. There are several ways to accomplish
this.*/

// create new array of newSize and copy to it
void Deque::resize(int newSize) {
//    std::cout << "mc beginning of resize " << "newSize: " << newSize << std::endl;
    int *temp = new int[newSize];

    // Copy elements from old array to new array, handling wrapping
    int index = head;
    for (int i = 0; i < count; i++) {
        temp[i] = theArray[index];
        index = (index + 1) % size; // Move to the next element (with wrapping)
    }

    delete[] theArray;
    theArray = temp;

    // Update head and tail for the new array
    head = -1; // Head is at the last index of the new array
    tail = count;       // Tail is at the index after the last copied element

    size = newSize;
//    std::cout << "mc end of resize" << std::endl;
}

/*    int *temp = new int[newSize];
    int i = 0;
    int count = this->count; //value of current instance's count
    bool running = true;
    while (running) {
        try {
            temp[i] = removeHead();
            i++;
        }
        catch (const std::out_of_range &error) {
            running = false;
        }
    }
    delete[] theArray; //delete with brackets deletes entire array; without brackets only deletes first element
    theArray = temp;
    this->count = count;*/


//    }
/* int *temp = new int[newSize];  // creates new array in a pointer called temp
 for (int i = 0; i < size; i++) {
     temp[i] = this->theArray[i]; //copies all data from the Array into temp
 }
 delete[] this->theArray;//delete old array
 this->theArray = temp; //copies pointers
 this->size = newSize; //changes array size
 return;*/

/*string listQueue( ) –returns a string listing the elements from head to tail. This should
properly deal with situations where there has been wrapping and the tail is at an index less
than the head.*/
//list elements
std::string Deque::listQueue() {
    std::stringstream ss;
    int temp = head + 1;
    for (int i = 0; i < count; i++) {
        ss << theArray[temp] << " ";
        temp = (temp + 1) % size;
    }
    return ss.str();
}

/*
string dumpArray( ) – returns an array containing the contents of the array from index 0 to
        size-1. This is for debugging purposes and to verify that wrapping is working properly.*/
//list elements, purpose is to debug, gives snapshot of array, if it's wrapped properly
std::string Deque::dumpArray() {
//    std::cout << "mc mc beginning of dumpArray, stats:" << std::endl;
//    std::cout << "size: " << size << std::endl;
//    std::cout << "count: " << count << std::endl;
//    std::cout << "head: " << head << std::endl;
//    std::cout << "tail: " << tail << std::endl<<std::endl;
    head +=1;

    std::stringstream ss;
    for (int i = 0; i <= size -1; i++) {
        ss << theArray[i] << " ";
//        std::cout<<"inside for loop for theArray"<<std::endl;
//        std::cout<<"index: "<<i<<std::endl;
//        std::cout<<"ss: "<<ss.str()<<std::endl;
//        std::cout<<"Head in dumparray"<<head<<std::endl;
//        std::cout<<"tail in dumparray: "<<tail<<std::endl;
//        std::cout<<"end of for loop for theArray"<<std::endl<<std::endl;
    }

    ss << std::endl;
//    std::cout << "end of dumparray, stats:" << std::endl;
//    std::cout << "size: " << size << std::endl;
//    std::cout << "count: " << count << std::endl;
//    std::cout << "head: " << head << std::endl;
//    std::cout << "tail: " << tail << std::endl;
    return ss.str();
}

//bool isEmpty() – returns true when the double ended queue is empty, false otherwise.
bool Deque::isEmpty() {
    if (count == 0) {
        return true;
    }
    return false;
}

//        How could you implement a stack using your double ended queue? Use this concept to list a
//        provided set of numbers in reverse order. More specifically, add a method to your Deque class
//        called thinkSolve which takes two arguments, an array of integers and the number of elements in
//the list. It instantiates a new deque, adds the integers to the new deque in their original order, then
//        removes the integers from the new deque in reverse order and adds them to the original deque
//upon which thinkSolve was called.
void Deque::solveThink(int *values, int numValues) {
    Deque stackDeque(numValues);  // Create a new deque to act as a stack

    // Add elements to the stackDeque in their original order (using addTail to simulate push)
    for (int i = 0; i < numValues; ++i) {
        stackDeque.addHead(values[i]);
    }

    // Remove elements from the stackDeque in reverse order (using removeHead to simulate pop)
    // and add them to the current deque (using addTail)
    for (int i = 0; i < numValues; i++) {
        this->addTail(stackDeque.removeHead());
    }
}//
// Created by siusl on 11/29/2024.
//
