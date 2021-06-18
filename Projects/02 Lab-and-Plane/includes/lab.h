#ifndef LAB_H
#define LAB_H

#include <iostream>

bool is_valid(int* size, int row, int col);
//Precondition: ptr size points to an array that holds the number of column for each
//              new array, row and col are hold the user input for lab and station numbers
//Postcondition: the given row and col are checked to see if the dynamic array has the specific
//               location, returns true if space is valid, else false

bool login(int** labs,int* size, int& lab, int& station, const int lab_ID);
//Precondition: labs points to a ptr which points to a dynamic array of *size
//              row and col are hold the user input for lab and station numbers and lab_ID holds
//              the user id
//Postcondition: function searchs for ID within the 2d array and if found returns false
//               else it calls is_valid function to check for the space given by user
//               and then checks if space is free, if free then id is registered at the space and
//               function returns true else function returns false and passed the location of the user id

bool logout(int** labs, int* size, const int lab_ID);
//Precondition: labs points to a ptr which points to a dynamic array of *size
//              lab_ID holds the user id
//Postcondition: function searchs for ID within the 2d array and if found, erases id and  returns true
//               else returns true

#endif // LAB_H
