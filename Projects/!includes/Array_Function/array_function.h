#ifndef ARRAY_FUNCTION_H
#define ARRAY_FUNCTION_H
#include <iostream>

using namespace  std;

template <typename T>
T* allocate(int capacity);
//Precondition: takes an int variable for the capacity of the new array
//Postcondition: a dynamic array of type T is returned with capacity

template <typename T>
void initialize( T* arr, int size);
//Precondition: function takes an int variable size and type T pointer
//Postcondition: the elements of the array are initiallized

template <typename T>
void copy(T *dest, T* src, int size_to_copy);
//Precondition: takes two type T pointers and int variable for the size
//Postcondition: all elements of src are copied to dest array

template <typename T>
void print(T* arr, int size);
//Precondition: takes type T array ptr, and int var for array size
//Postcondition: prints the elements of the array to the screen

template <typename T>
T*  resize(T* arr, int old_size, int new_size);
//Precondition: takes type T array ptr and two int var for old array size
//          and new array size
//Postcondition: allocates a dynamic array of size new_size, intializes new
//          array, copies the old array and returns type T ptr to this new
//          array


template <typename T>
void delete_array(T*& arr);
//Precondition: takes a type T ptr to a dynamic array
//Postcondition: the dynamic array is deleted;
//===================Definition:========================//


template <typename T>
T* allocate(int capacity)
{
    bool debug = false;
    if(debug)
        cout<< endl << "Allocated capacity: "<< capacity << endl;

    return new T [capacity];
}


template <typename T>
void initialize( T* arr, int size)
{
    for (int i = 0; i < size; i ++)
    {
        *arr = 0.0;
        arr++;
    }
}

template <typename T>
void copy(T *dest, T* src, int size_to_copy)
{
    for (int i = 0; i < size_to_copy; i++)
    {
        *dest = *src;
        dest++;
        src++;
    }
}


template <typename T>
void print(T* arr, int size)
{
    for (int i = 0; i  < size; i++)
    {
        cout << *arr <<  "  ";
        arr++;
    }
    cout << endl << endl;
}

template <typename T>
T*  resize(T* arr, int old_size, int new_size)
{
    T* hold = arr;
    arr = allocate<T>(new_size);

    initialize(arr, new_size);

    copy(arr, hold,old_size);

    delete []hold;

    return arr;
}

template <typename T>
void delete_array(T*& arr)
{
    delete [] arr;
}

#endif // ARRAY_FUNCTION_H
