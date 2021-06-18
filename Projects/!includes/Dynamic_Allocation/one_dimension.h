#ifndef ONE_DIMENSION_H
#define ONE_DIMENSION_H

#include <iostream>

using namespace  std;

//==============================================================
//   one dimension function declaration
//==============================================================
template <typename T>
T* allocate(int capacity);
//Precondition:takes an int var for the capacity of the new array
//Postcondition: a dynamic array of size array[capacity]

template <typename T>
void deallocate(T* arr);
// Precondition: arr holds the address of the the dynamic array
// Postcondition: the dynamic array is destroyed

template <typename T>
T* Find(T* list, const T& find_me, int size);
//Precondition: takes type T ptr, and const var to search in the list
//Postcondition:returns a type T ptr that holds location of find_me
//              in the list array or a nullptr if find_me isn't  found

template <typename T>
void initialize( T* arr, int size);
//Precondition: takes a pointer to an array and int variable for size
//Postcondition: all the array elements are initiallized

template <typename T>
void print(T* dest, int size);
//Precondition: takes type T ptr to an array and int var for array size
//Postcondition: prints the elements of the array to the screen


//==============================================================
//   one dimension function declaration
//==============================================================

template <typename T>
T* allocate(int capacity)
{
    return new T [capacity];
}

template <typename T>
void deallocate(T* arr)
{
    delete[] arr;
}

template <typename T>
T* Find(T* list, const T& find_me, int size)
{
    T* ptr = nullptr;
    for (int i = 0; i < size; i++)
    {
        if ( find_me == *list) // when find_me is found in list
        {
            ptr = list; // ptr points to address of find_me in the list
            break;
        }
        else
            list++;
    }
    return ptr;
}

template <typename T>
void initialize( T* arr, int size)
{
    for (int i = 0; i < size; i ++)
    {
        *arr = i;
        arr++;
    }
}

template <typename T>
void print(T* dest, int size)
{
    for (int i = 0; i  < size; i++)
    {
        cout << *dest <<  "  ";
        dest++;
    }
    cout << endl << endl;
}


#endif // ONE_DIMENSION_H
