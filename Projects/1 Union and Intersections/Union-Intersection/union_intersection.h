#ifndef UNION_N_INTERSECTION_H
#define UNION_N_INTERSECTION_H

#include <iostream>

using namespace std;

const int SRC_1_MAX = 10;
const int SRC_2_MAX = 10;
const int RESULT_MAX = 20;

/**
 Union and Intersection functions with integer pointers of a fixed size
 */

void Union (int *src_1_ptr, int src1_size,  int *src_2_ptr,
            int src2_size,int *union_ptr,int& union_size);
//precondition: takes two int ptrs of source arrays with their size and
//              another int ptr of an emtpy array with its maximum size
//Postcondition: the ptr of the emtpy array is set to all unique elements
//               of the two src arrays and its size is set to the number
//               of elements inside

void intersection(int *src_1_ptr, int src1_size,  int *src_2_ptr
                  , int src2_size,int *inters_ptr,int& result_size);
//precondition: takes two int ptrs of source arrays with their size and
//              another int ptr of an emtpy array with its maximum size
//Postcondition: the ptr of the emtpy array is set to all common elements
//               of the two src arrays and its size is set to the number
//               of elements inside

void print(int* arr, int size);
//Precondition: takes an int ptr to an array, and int var for size
//Postcondition: the elements of the array are printed on the screen


//==============================================================
//      function definitions
//==============================================================

void Union (int *src_1_ptr, int src1_size,  int *src_2_ptr,
                int src2_size,int *union_ptr,int& union_size)
{
    int *union_temp = union_ptr;
    int *ptr1 = src_1_ptr;
    int *ptr2 = src_2_ptr;

    while ((src_1_ptr != (ptr1 + src1_size)) && ((src_2_ptr != (ptr2 + src2_size))))
    {
        if(*src_1_ptr > *src_2_ptr)
        {//when src1 element bigger than src2 element
            *union_ptr = *src_2_ptr;
            cout << *union_ptr << " unionPtr: " << endl;
            src_2_ptr++;
            union_size++;
        }

        else if(*src_2_ptr > *src_1_ptr)
        {//when src1 element bigger than src2 element
            *union_ptr = *src_1_ptr;
            src_1_ptr++;
            union_size++;

        }

        else //when src1 element equal to src2 element
        {
            *union_ptr = *src_1_ptr;
            src_1_ptr++;
            src_2_ptr++;
            union_size++;

        }
        union_ptr++;
    }

    if ((src_1_ptr == (ptr1 + src1_size)) && (src_2_ptr < (ptr2 + src2_size) ))
    { //when src1 elements are copied but src2 has some left
        while (src_2_ptr < (ptr2 + src2_size))
        {
            *union_ptr = *src_2_ptr;
            src_2_ptr++;
            union_ptr++;
            union_size++;

        }
    }

    if ((src_2_ptr == (ptr2 + src2_size)) && (src_1_ptr < (ptr1 + src1_size) ))
    {//when src2 elements are copied but src1 has some left
        while (src_1_ptr < (ptr1 + src1_size))
        {
            *union_ptr = *src_1_ptr;
            src_1_ptr++;
            union_ptr++;
            union_size++;

        }
    }

    cout << "union_size: " << union_size << endl;
    union_size = union_ptr - union_temp ;
    cout << "union_size: " << union_size << endl;
}
void intersection(int *src_1_ptr, int src1_size,  int *src_2_ptr,
                  int src2_size,int *inters_ptr,int& inters_size)
{
    const int ZERO = 0;
    int *temp_inters = inters_ptr;
    int *ptr1 = src_1_ptr;
    int *ptr2 = src_2_ptr;

    while ( (src1_size > ZERO  && src2_size > ZERO) &&
            ((src_1_ptr <= (ptr1 + src1_size)) && (src_2_ptr <= (ptr2 + src2_size))) )
    {
        if(*src_1_ptr == *src_2_ptr)
        {//when src1 element equal to src2 element
            *inters_ptr = *src_1_ptr;
            inters_ptr++;
            src_1_ptr++;
            src_2_ptr++;
        }

        else if(*src_1_ptr > *src_2_ptr)
        {//when src1 element greater than src2 element
            src_2_ptr++;
        }

        else //when src2 element equal to src1 element
        {
            src_1_ptr++;
        }

    }
    inters_size = inters_ptr - temp_inters;
}

void print(int arr[], int size)
{

    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl << endl;

}


#endif // UNION_N_INTERSECTION_H
