#include "SimpleVector.h"
// copy constructor
using namespace std;

SimpleVector::SimpleVector(const SimpleVector &other) : size{other.size}, capacity{other.capacity}
{
    cout << "in the copy constructor" << endl;
    arr = new int[capacity]; // allocate memory for the new array
    for (int i = 0; i < other.size; i++)
    {
        arr[i] = other.arr[i]; // copy the elements from the other array
    }
}
// copy assignment operator
// operator=
SimpleVector &SimpleVector::operator=(const SimpleVector &other)
{
    cout << " in the operator=" << endl;
    if (this == &other)
    {
        return *this; // check for self-assignment
    }

    delete[] arr;            // delete the current array that I (this) point to
    size = other.size;
    capacity = other.capacity;
    arr = new int[capacity]; // allocate memory for the new array
    // copy the elements from the other array
    for (int i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
    return *this; // to allow: a=b=c;
}

// this is the operator[] function
// this cannot work to set the location, only to get
// since it is labelled const
const int &SimpleVector::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("in const int& op[], index out of bounds of the array.");
    }
    return arr[index];
}
// this can work to set the location, since it is not labelled const
int &SimpleVector::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("in int &operator[], index out of bounds of the array.");
    }
    return arr[index];
}
void SimpleVector::push_back(int value)
{
    if (size == capacity)
    {
        capacity *= 2; // double the capacity
        // grow the array
        int *newArr = new int[capacity]; // create a new larger array
        // copy elt by elt from the old array to the new array
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr; // delete the old array
        arr = newArr; // point this.arr to the new array
    }
    arr[size] = value;
    size++;
}
