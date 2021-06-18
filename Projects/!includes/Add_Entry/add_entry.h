#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H
#include <iostream>
#include <iomanip>

using namespace  std;

template <typename T>
T* add_entry(T* list, const T& new_entry,int& size, int& capacity);
///@pre: takes type T array pointer and var, array size & capacity
///@post: \if  capacity of array = size of array allocate 2*capacity
///            add new_entry at the end of array, increase size by 1
///            \return a pointer to edited array

template <typename T>
T* allocate( int capacity );
//@pre: takes an int variable for the capacity of the array
//@post: allocate a new array of with max capacity = capacity
///         \returns  pointer to this array

template <typename T>
void append (T value, T* dest, int& size);
///@pre: takes type T variable, array ptr, and array size
///@post : appended value at the end of array, increase size by 1

template <typename T>
void copy(T *dest, T* src, int how_many);
///@pre : takes two type T array pointers and int for the size
///@post: how_many elements of src are copied to dest array

template <typename T>
void deallocate( T* arr );
/// @pre: takes a type T array pointer
/// @post: array is deleted

template <typename T>
T* Find(T* list, const T& find_me, int size);
/// @pre  : takes type T ptr, item to find and array size
/// @post : search find_me inside list
///         \if found          \return a pointer to this value
///         \else not found    \return nullpointer address

template <typename T>
void initialize( T* arr, int size);
/// @pre : takes type T pointer/array and an int variable size
/// @post: array is initiallized to default type of T

template <typename T>
void print( T* dest, int size );
/// @pre: takes type T array ptr, and size of array
/// @post: prints the elements of the array to the screen

template <typename T>
T* remove_entry(T* list, const T& delete_me,int& size, int& capacity);
///@pre: takes type T array pointer and var, array size & capacity
///@post : delete_me is replaced with the last element of array
///             reduce size by 1. if size less than half capacity,
///             allocate new array with half capacity, and copy old array
///             \return a pointer to edited array

template <typename T>
T* shift(T* list, T* location, int& size);
///@pre: takes a pointer to an array & pointer to a single
///             item in the array and size of array
///@post: value at location is replaced with the last element
///             of array, reduced size by 1 and \return a ptr to array

template  <typename T>
T* shift_Left(T* list, int erase_index, int& size);
/// @pre : takes type T array ptr and its size as int and
///         the index of an element to be erased
/// @post: all the elements on the right to erase_index are
///          shifted one size to their left and size is decreased
///          by one. \return pointer to this edited array

template <typename T>
T* shift_Right(T* list, int insert_here, int& size);
/// @pre : takes type T array ptr and its size as int and an int
///          var for the index of an element to be erased
/// @post: all elements to the right of the index insert_here are
///         shifted one size to their right. increase size by 1
///         \return a pointer to the edited array
/// \note will be used when trying to insert someting at insert_here index

//=========================================================
//              Definition
//=========================================================

template <typename T>
T* add_entry(T* list, const T& new_entry,int& size, int& capacity)
{
    if( size >= capacity)
    {   capacity = size * 2;
        T* newList = allocate <T> (capacity);
        copy( newList, list, size);
        delete [] list;
        T* walker = newList + size;
        append  ( new_entry, walker, size);
        return newList;
    }
    else
    {
        T* walker = list + size;
        append(new_entry, walker, size);
    }
    return list;
}

template <typename T>
T* allocate( int capacity )
{
    const bool DEBUG = false;
    if(DEBUG)
    {
        cout << "New capacity: "<< capacity << endl;
    }
    return new T [capacity];
}

template <typename T>
void append (T value, T* dest, int& size)
{
    *dest = value;
    size++;
}

template <typename T>
void copy(T *dest, T* src, int copy_size)
{
    for (int i = 0; i < copy_size; i++)
    {
        *dest = *src;
        dest++;
        src++;
    }
}

template <typename T>
void deallocate(T* arr)
{
    delete [] arr;
    arr = nullptr;
}

template <typename T>
T* Find(T* list, const T& find_me, int size)
{
    T* ptr = nullptr;
    for (int i = 0; i < size; i++)
    {
        if ( find_me == *list) // when find_me is located in list
        {
            ptr = list; // ptr holds address of find_me from list arr
            break;
        }
        else
            list++;
    }
    return ptr; // find_me is not found in list
}

template <typename T>
void initialize( T* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = T();
    }
}

template <typename T>
void print(T* dest, int size)
{
    for (int i = 0; i  < size; i++)
    {
        cout << dest[i] << "   ";
    }
    cout << endl << endl;
}


template <typename T>
T* remove_entry(T* list, const T& delete_me,int& size, int& capacity)
{
    T* location = Find( list, delete_me, size);
    //search delete_me in list

    if(location != nullptr)
        //if delete_me is found in list
    {
        int temp = location - list + 1;// holds index of value
        list = shift_Left(list, temp, size);
        if( size == capacity / 4)
        {
            // if only 1/4 capacity is being used
            //reallocate new dynamic array with 1/2 capacity of old
            capacity = capacity / 2;
            T* newList = allocate <T> (capacity);
            copy( newList, list, size);
            delete [] list;           //delete the old array
            return newList;
        }
    }
    return list;
}

template <typename T>
T* shift(T* list,T* location, int& size)
{
    T* walker = list + size -1; // points to the last element
    *location = *walker;        // item at location = item at walker
    size--;
    return list;
}

template <typename T>
T* shift_Right(T* arr, int insert_here, int& size)
{
    T* temp = new T [size];
    T* arr_walker = arr + insert_here + 1;

    copy(temp, arr, size);
    copy(arr_walker , temp + insert_here, size - insert_here);
    size++;
    delete [] temp;
    return arr;
}


template <typename T>
T* shift_Left(T* arr, int erase_index, int& size)
{
    T* walker = arr + erase_index -1;
    T* temp = arr + erase_index;
    for( ; walker < arr + size  ; walker++)
    {
        *walker = *temp;
        temp++;
    }
    size--;
    return arr;
}

#endif // ADD_ENTRY_H
