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

/*void addTail(int value) – adds a new value to the tail of the queue, wrapping if necessary. If
        there is no room to add a new value, calls the resize( ) method.*/
void Deque::addTail(int value) {
//**go through  line by line, does count = size before resize, check in resize, if count = size also
//    std::string enter;
//    std::cout<<" mc addTail"<<std::endl;
//    std::cout << " mc addTail function" << std::endl;
//    std::cout << " mc if (tail >= size) {\n"
//                 "    mc    tail = 0;\n" << std::endl;
//    std::cin >> enter;
    std::cout << "mc beginning of addTail" << std::endl;
    if (tail >= size) {
        tail = 0;
    }
//    std::cout << "mc if (isEmpty()) {\n"
//                 "   mc     resize(size * 2);" << std::endl;
    if (size == count) {//if size = count, resize
        resize(size * 2);

    }
    count = count + 1;
//    std::cin >> enter;
//    std::cout << " mc theArray[tail] = value;\n"
//                 "   mc  tail += 1;" << std::endl;
    theArray[tail] = value;
//    std::cin >> enter;
//    std::cout << "mc tail += 1;" << std::endl;
    tail += 1;
    std::cout << "end of addTail" << std::endl;
//    std::cin >> enter;

}

/*
• int removeHead( ) – saves the value at the head of the queue, updates it to remove access to
that value, and returns the saved value, wrapping if necessary. If the queue is empty throws
an exception. (For C++ and C#, use the message: Array is empty in removeHead)*/

int Deque::removeHead() {
    std::cout << "mc beginning of removeHead" << std::endl;
    if (size - 1 == head) {//this tests if head is at the end
        head = -1;//only resets head if at the end, this wraps head
    }
    if (isEmpty()) {
        //throw exception
        throw std::out_of_range("Array is empty");
    } else {
//        std::cout << " mc is Empty function" << std::endl;
//        std::cout << " mc head = (head + 1) % size;" << std::endl;
//        std::string enter;
        head = head + 1;//increments head - moves it to the right
//        std::cin >> enter;
//        std::cout << "mc count--" << std::endl;
        count--;
//

//        std::cin >> enter;
    }

    return theArray[head];//returns value of head
    std::cout << "end of removeHead" << std::endl;
}



/*
string dumpArray( ) – returns an array containing the contents of the array from index 0 to
        size-1. This is for debugging purposes and to verify that wrapping is working properly.*/
//list elements, purpose is to debug, gives snapshot of array, if it's wrapped properly
std::string Deque::dumpArray() {
    std::cout << "mc mc beginning of dumpArray" << std::endl;
    std::stringstream ss;
    for (int i = 0; i < size; i++) {
        ss << theArray[i] << " ";
    }
    ss << std::endl;
    std::cout << "end of dumparray" << std::endl;
    return ss.str();
    std::cout << "mc end  of dumpArray" << std::endl;

}

/*• resize( ) – creates a new array twice as large and copies the elements to it. This should
properly deal with situations where there has been wrapping and the tail is at an index less
than the head. Note, this is not a simple exercise where you can copy index 0 of the old
        array to index 0 of the new array and so forth. You will need to end up after copying with
        the head at index 0 and tail appropriately located. There are several ways to accomplish
this.*/

// create new array of newSize and copy to it
void Deque::resize(int newSize) {
    std::cout << "mc beginning of resize " << "newSize: " << newSize << std::endl;
    int *temp = new int[newSize];
    for (int i = 0; i < size; i++) {
        if (head > size) {
            head = -1;
        }
        temp[i] = theArray[head + i + 1];
    }
    delete[] theArray; //deallocates the memory that the array pointer is pointing to
    theArray = temp; //reassigns the pointer to what temp is pointing to
    delete[] temp; //delete with brackets deletes entire array; without brackets only deletes first element
    std::cout<<"mc end of resize"<<std::endl;
}
//    temp[i] = removeHead();
//    i++;
//    std::cout << "mc end  of resize" << std::endl;

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


//bool isEmpty() – returns true when the double ended queue is empty, false otherwise.
bool Deque::isEmpty() {
    if (count == 0) {
        return true;
    }
    return false;
}

//void addHead(int value) – adds a new value at the head. Wraps if necessary. This should
//not overwrite data that was previously in the queue. If the array is full, calls resize( ) to
//double the array and copy the data as needed.
void Deque::addHead(int value) {//***Dr. Majchrak help & working 11.13
//    std::cout << "mc beginning of addHead" << std::endl;
//    std::cout << "dumparray: " << dumpArray() << std::endl;
int location;
    if (count == size) {
        resize(2 * size);
        head = size - 1;//review this, why -1?
    }
    if (head == (size - 1)){
      location = -1;
    }
    else{
        location = head;//if head is not at end of array
    }
    theArray[location + 1] = value;//if head is at size - 1 (end of array), does not move head, pulls next value from [0]
    head = (head - 1 + size) % size;

    count++;

//    std::cout<<"mc end of addHead"<<std::endl;
    }



//int removeTail( ) – saves the value at the tail of the queue, updating the queue to remove
//        access to the item at the tail, and returns the saved value. Wraps if necessary. If the queue
//        is empty, throws an exception. (For C++ and C#, use the message: Array is empty in
//removeTail)

int Deque::removeTail() {//***WORKING PER REMOVETAIL TEST
    //remove tail & add head both move to the left, MOVE FIRST then look.
    //remove head, add tail move to the right, LOOK FIRST, then move
//    std::cout << "mc beginning of removeTail" << std::endl;
    int value;
    if (isEmpty()) {
        throw std::runtime_error("Array is empty");
    }
    if (tail < 0) {// Wrap around if necessary
        tail = size;
    }
    tail -= 1;
    value = theArray[tail];
    count--;
//    std::cout << "end of remove Tail" << std::endl;
    return value;
std::cout<<"dump array in removeTail = "<<dumpArray()<<std::endl;
std::cout<<"tail=" <<tail<<std::endl;
    if (isEmpty()) {
        throw std::runtime_error("Array is empty");
    }

    // Circular array wrap around:
//    int value = theArray[tail];
//    tail = (tail - 1 + size) % size;

    count--;
    return value;

    std::cout << "mc end  of removeTail" << std::endl;
}


//        How could you implement a stack using your double ended queue? Use this concept to list a
//        provided set of numbers in reverse order. More specifically, add a method to your Deque class
//        called thinkSolve which takes two arguments, an array of integers and the number of elements in
//the list. It instantiates a new deque, adds the integers to the new deque in their original order, then
//        removes the integers from the new deque in reverse order and adds them to the original deque
//upon which thinkSolve was called.
void Deque::solveThink(int *values, int numValues) {
//    int stackDeque(numValues);  // Create a new deque to act as a stack
//
//    // Add elements to the stackDeque in their original order (using addTail to simulate push)
//    for (int i = 0; i < numValues; ++i) {
//        stackDeque.addTail(values[i]);
//    }
//
//    // Remove elements from the stackDeque in reverse order (using removeHead to simulate pop)
//    // and add them to the current deque (using addTail)
//    for (int i = 0; i < numValues; ++i) {
//        this->addTail(stackDeque.removeHead());
//    }
//}
};


