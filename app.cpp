#include "SimpleVector.h"
#include <iostream>
using namespace std;

// When I pass an object by value, and make changes in the function, do they stick?
// NO. A full copy is made by calling the copy constructor.
// When you return an object by value, the approporate operator= is called.
void printSize(SimpleVector v);
SimpleVector getVector();
void modifyVector(SimpleVector &v);
void constRef(const SimpleVector &v);
int main()
{
    SimpleVector v1; // default constructor
    SimpleVector v2(20); // constructor with capacity
    SimpleVector v3(v2); // copy constructor
    v1=v2; // operator=
   // v1[0] = 10;
   // v1[1] = 20;
    printSize(v1);
    //cout << "back in main: " << v1[0] << endl;
    v3 = getVector(); // return by value
    modifyVector(v3); // pass by reference
    return 0;
}
// pass by value (copy constructor gets called)
// changes to v do not stick!
void printSize(SimpleVector v)
{
   // v[0]=100;
    cout << "Size of vector: " << v.getSize() << endl;
}
// return an object by value (operator= gets called)
SimpleVector getVector()
{
    SimpleVector v;
    return v; // return by value
}
// pass by reference -- all changes stick
void modifyVector(SimpleVector &v)
{
    //v[0] = 100;
}
// pass by const reference -- no changes can be made
void constRef(const SimpleVector &v)
{
    // v[0] = 100; // compiler error: cannot modify a const object
}   




