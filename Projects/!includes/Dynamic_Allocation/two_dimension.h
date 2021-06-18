#ifndef TWO_DIMENSION_H
#define TWO_DIMENSION_H

#include <iostream>
#include "../../!includes/Dynamic_Allocation/one_dimension.h"


//==============================================================
//   two dimension function declaration
//==============================================================

template <typename T>
T** allocate(int* capacity);
//Precondition: takes int ptr for the the size of each array to be created
//Postcondition: returns a a pointer pointer with the address of the new
//               dynamic array

template <typename T>
void deallocate( T** twoD);
//Precondition: takes a pointer pointer to a dynamic array
//Postcondition: the dynamic pointer array is destroyed

template <typename T>
bool Find(T** twoD, int* sizes, const T& key, int& row, int& col);
//Precondition: takes a pointer pointer to a dynamic array and int ptr
//               int ptr for the size of each dynamic array and type T
//                const var for the item to be searched
//Postcondition: value of Key is searched in the entire 2d array
//               and  if found row and col carry the address of the
//               key and function returns true else func returns false

template <typename T>
T& get(T** twod, int row, int col);
//Precondition: takes a pointer pointer to a dynamic array and two int
//              vars that hold row and col of an item inside twoD
//Postcondition: returns the address of item with row and col number
//               as a ref

template <typename T>
void initialize(T** twoD, int* size);
//Precondition: takes a pointer pointer to a dynamic array and int ptr
//             var for the size of each dynamic  array
//Postcondition: all elements of array are intialized to type T values

template <typename T>
void print(T** twoD, int* size);
//Precondition:takes a pointer pointer to a dynamic array, with an int
//             ptr for each array size
//Postcondition:all elements in the array are are printed on the screen

template <typename T>
T read(T** twod, int row, int col);
//Precondition: takes a pointer pointer to a dynamic array and two int
//              vars that hold row and col number of an item inside twoD
//Postcondition: returns a copy of the address of item with row and col
//                number the element

template <typename T>
void write(T** twod, int row, int col, const T& item);
//Precondition: takes a pointer pointer to a dynamic array, two int
//              vars that hold row and col number of an item inside twoD
//              and a type T var that hold a value to replace element
//              at the give address
//Postcondition: element at the address is changed to the value of item

//==============================================================
//   two dimension function definition
//==============================================================

template <typename T>
T** allocate(int* capacity)
{
    const int SIZE = 10;
    T** twoD = new T* [SIZE];
    T** walker = twoD;
    for (   ; *capacity != -1; capacity++)
    {
        *walker = allocate<T>(*capacity);
        walker++;
    }
    *walker = nullptr;  //last ptr set to nullptr for checking end of ptr
    return twoD;
}

template <typename T>
void deallocate( T** twoD)
{
    T** walker = twoD ;
    for (  ; *walker != nullptr; walker++)
    {
        deallocate<T>(*walker);
    }
    delete []twoD;
}

template <typename T>
bool Find(T** twoD, int* size, const T& key, int& row, int& col)
{
    for (T** walker = twoD; *walker != nullptr; walker++)
    {
        T* ptr = Find(*walker, key, *size);
        if ( ptr != nullptr) // find_me is found in list array
        {
            row = walker - twoD;
            col = ptr - *walker;
            return true;
        }
        else
        size++;
    }
    return false;
}

template <typename T>
T& get(T** twod, int row, int col)
{
    T** row_Walker = twod + row - 1;
    T* col_Walker = *row_Walker + col - 1;
    return *col_Walker;
}

template <typename T>
void initialize(T** twoD, int* size)
{
    for (T** walker = twoD; *walker != nullptr; walker++)
    {
        initialize<T>(*walker, *size);
        size++;
    }
}

template <typename T>
void print(T** twoD, int* size)
{
    for (T** walker = twoD; *walker != nullptr; walker++)
    {
        print( *walker, *size);
        size++;
    }
}

template <typename T>
T read( T** twod, int row, int col)
{
    T** row_Walker = twod + row - 1;
    T* col_Walker = *row_Walker + col - 1;
    return *col_Walker;
}

template <typename  T>
void write(T** twod, int row, int col, const T& item)
{
    get(twod, row, col) = item;
}

#endif // TWO_DIMENSION_H
