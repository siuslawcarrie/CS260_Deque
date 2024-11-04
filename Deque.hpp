//
// Created by siusl on 10/27/2024.
//


#ifndef Deque_hpp//include guard, prevents duplication of source code
#define Deque_hpp

#include <string>
#include <stdexcept>


class Deque {
private:
    const static int DEFAULT_SIZE = 20;//size
    int head = -1;
    int tail = 0;
    int *theArray = nullptr;
    int size = DEFAULT_SIZE;
    int count = 0;

public:
    // constructor and destructor
//    Deque();//default constructor but better to have a default argument
//
    Deque(int size = -1);

    ~Deque();

    // resize the array to s, if s is bigger than the current array size
    void resize(int s);

    //add new value at end
    void addTail(int value);

//    saves the value at the head of the queue, updates it to remove access to
//    that value, and returns the saved value, wrapping if necessary
    int removeHead();

//    returns an array containing the contents of the array from index 0 to size-1
    std::string dumpArray();

//return string listing elements from Head to Tail
    std::string listQueue();

    bool isEmpty();

    void addHead(int value);

    int removeTail();

    void solveThink(int *values, int numValues);

};

#endif /* Deque_hpp */

