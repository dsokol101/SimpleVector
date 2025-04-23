#include "SimpleVector.h"
#include <iostream>
using namespace std;

// When I pass an object by value, and make changes in the function, do they stick?
// NO. A full copy is made by calling the copy constructor.
void printSize(SimpleVector v);
int main()
{
    SimpleVector v1; // default constructor
    SimpleVector v2(20); // constructor with capacity
    SimpleVector v3(v2); // copy constructor
    v1=v2; // operator=
    v1[0] = 10;
    v1[1] = 20;
    printSize(v1);
    cout << "back in main: " << v1[0] << endl;
    return 0;
}
// pass by value
void printSize(SimpleVector v)
{
    v[0]=100;
    cout << "Size of vector: " << v.getSize() << endl;
}
// pass by const reference
// pass by pointer

// pass by reference
// return an object by value
// return an object by reference
