#include <iostream>


#include "../../!includes/Dynamic_Allocation/two_dimension.h"
#include "../Lab_n_Plane/includes/lab.h"

//-------------------steps for log in ------------------//
/*
 * STEP 1: check location validity
 *  STEP 2: search entire labs for Id
 *          IF ID FOUND  return location of ID and  return false
 *  STEP 3: check if user specified location is unoccupied
 *          IF OCCUPIED: return false
 *  STEP 4:  write USER ID at specified location and return true
 *
 */

bool is_valid(int* size, int row, int col)
{
    for (int* walker = size; *walker != -1; walker++)
    {
        if(walker == size + row)
        {
            if(*walker > col)
            {
                return true; // location exist
            }
        }
    }
    return false; // location doesn't exist
}

bool login( int** labs, int* size, int& lab, int& station, const int lab_ID )
{
    int row = lab;
    int col = station;

    if (!(Find(labs,size, lab_ID, row, col)) )  // ID not found
    {
        if(read(labs, lab, station) == 0)       // lab and station is free
        {
            get(labs, lab, station) = lab_ID;   // log in user id
            return true;
        }
        else                                    // lab and station occupied by other user
            return false;
    }
    else        // ID is found at a different lab and station
    {
        lab = row;  // the lab and station user has already logged in is returned by ref
        station = col;
        return false;
    }
}

bool logout(int** labs, int* size, const int lab_ID)
{
    int lab, station;

    if(Find(labs, size, lab_ID, lab, station))  // lab_ID is found
    {
        get(labs, lab, station) = 0; // erase the id and return true
        return  true;
    }
    else
        return false;
}
