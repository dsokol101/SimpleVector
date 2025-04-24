#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream> // for std::cout

/*********************************************************

RAII
you must define special member functions when you have a pointer in the class
4/22:
1. destructor
2. copy constructor
3. operator=
4. operator[]

next time: add capacity field
put in the push_back function
see lab 2
*********************************************************/

class SimpleVector
{
private:
    int *arr;
    int size;                               // number of elements in the array
    int capacity;                           // maximum number of elements the array can hold
    static const int DEFAULT_CAPACITY = 10; // default capacity of the array

public:
    // default constructor
    SimpleVector() : arr{new int[DEFAULT_CAPACITY]}, size{0}, capacity{DEFAULT_CAPACITY}
    {
        std::cout << "in the default constructor" << std::endl;
    }
    // parameter constructor
    SimpleVector(int cap) : size{0}, capacity{cap}
    {
        arr = new int[cap];
        std::cout << "in the parameter constructor" << std::endl;
    }
    // copy constructor
    SimpleVector(const SimpleVector &other);
    // move constructor
    SimpleVector(SimpleVector &&other);
    // destructor
    ~SimpleVector() { delete[] arr; }
    SimpleVector &operator=(const SimpleVector &other);
    SimpleVector &operator=(SimpleVector &&other);
    const int &operator[](size_t index) const;
    int &operator[](size_t index);
    int getSize() const { return size; }
    void push_back(int value); // grow the array if needed
};
#endif