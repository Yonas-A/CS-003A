#include<iostream>

#include "../../!includes/Dynamic_Allocation/two_dimension.h"
#include "../Lab_n_Plane/includes/plane.h"


bool is_available(int* size, int row, const char seat)
{
    int col = int (seat - 65); // col must be between 1 and 4
     for (int* walker = size; *walker != -1; walker++)
    {
        if(walker == size + row)
        {
            if(col == 0 || col == 1 || col== 2 || col == 3) // since col starts from 0 - 3
            {
                return true;
            }
        }
    }
    return false; // seat number doesn't exist
}

bool reserve(bool** plane, int row, char seat)
{
    int col = int(seat) - 65; // converting char to int from 1-4;
    int flag = 1;
    if ( read(plane, row, col) == 0)     // seat is not occupied
    {
        get(plane, row, col) = flag;
            return true;
    }
    return false;
}

bool cancel(bool** plane , int row, char seat)
{
    int col = int(seat) - 65;
    int flag  = 1;
    if (read (plane, row, col) == flag)     // seat is not occupied
    {
        get(plane, row, col) = 0;
            return true;
    }
    else                                            // seat is not found
        return false;
}

void printPlane(bool** plane, int* size)
{
    int i = 1;
    for (bool** walker = plane; *walker != nullptr; walker++)
    {
        cout << i <<":  ";          // i prints the row number for seat
        printPlane( *walker, *size);
        size++;
        i++;
    }
}

void printPlane(bool* dest, int size)
{
    for (int i = 0; i  < size; i++)
    {
        if(*dest == 1)
            cout << 'X' << "     ";         // X replaces seats reserved
        else
            cout <<  char(*dest + 65 + i)<<  "     ";   // prints the seat letters as A B C and D
        dest++;
    }
    cout << "\n";
}
