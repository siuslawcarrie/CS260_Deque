//
// Created by siusl on 10/27/2024.
//

#ifndef CS260_DEQUE_DEQUE_HPP
#define CS260_DEQUE_DEQUE_HPP
#ifndef Deque_hpp
#define Deque_hpp

#include <string>
#include <stdexcept>

class Deque {
private:
    const static int SIZE = 10;
    int size;

public:
    // constructor and destructor
    Deque(int size = SIZE);

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


    void solveThink(int *values, int numValues);

};

#endif /* Deque_hpp */
#endif //CS260_DEQUE_DEQUE_HPP
