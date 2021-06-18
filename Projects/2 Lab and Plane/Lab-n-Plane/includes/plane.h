#ifndef PLANE_H
#define PLANE_H

#include <iostream>

bool is_available(int* size, int row, const char seat);
//Precondition: size points to an array with int elements, while row and seat hold
//               user input for plane seat
//Postcondition: the seat number user entered is checked to see if it exists
//               returns true if exist, else false

bool reserve(bool** plane, const int row, const char seat);
//Precondition: plane points to a ptr that points to an array with bool elements, while row and seat hold
//               user input for plane seat
//Postcondition: function calls is_available function to check for existance. if seat exists,
//               it checks to see if seat is free. if free function puts true on seat and returns true
//               else returns false

bool cancel(bool** plane, const int row, const char seat);
//Precondition: plane points to a ptr that points to an array with bool elements, while row and seat hold
//               user input for plane seat
//Postcondition: if seat was occupied, function puts false on location and returns true
//               if seat was empty, function returns false

void printPlane(bool** plane, int* size);
//Precondition: plane points to a ptr that points to an array with bool elements, arr[*size]
//Postcondition: function calls printPlane with a ptr and size elements of the function are printed to the screen

void printPlane(bool* plane, int size);
//Precondition: plane ptr points to a dynamic array  with size with bool elements, arr[size]
//Postcondition: function changes the '0' to 'A','B','C','D' and '1' to 'X' to indicate empty seats
//               from occupied seats, the changes are printed to the screen

#endif // PLANE_H
