/*
 * Author: Yonas Adamu
 * Project: Lab and Plane
 * Purpose: Making a dynamic 2D array using pointers and assigning values to
 *          the arrays
 *          Lab - ask user for ID , lab room number and station and log in
 *                the user at the specific location and /or log out user
 *                from system
 *          Plane - ask user for seat number and make reservations and or
 *                  cancel reservations based on user's request
 * Notes: some new functions for lab and plane were made in order to make code
 *        neat and printing designated outputs
 */


#include <iostream>

#include "../../!includes/Dynamic_Allocation/one_dimension.h"
#include "../../!includes/Dynamic_Allocation/two_dimension.h"
#include "../Lab_n_Plane/includes/lab.h"
#include "../Lab_n_Plane/includes/plane.h"

using namespace std;


void testLab();
// test function for lab project

void testPlane();
//a test function for plane project

void take_Plane_Input(int& row, char& seatNum);
//Precondition: user is asked to enter plane row and seatNum

void takeLabInput(int& lab_ID, int& lab, int& station);
//Precondition: user is asked to enter labID, lab  and station number


int main()
{
    testLab();
    //testPlane();
    return 0;
}

void take_Plane_Input(int& row, char& seatNum)
{
    cout<<"Row: ";
    cin >> row;
    while (!row)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Row: "; cin >> row;
    }
    cout<<"Seat letter: "; cin >> seatNum;
    while (!seatNum)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Seat letter: "; cin >> seatNum;
    }
    row -= 1;
    seatNum = toupper(seatNum);
}

void testPlane()
{
    int arr[15] = {4,4,4,4,4,4,4,4,4,-1};
    int* size = arr;
    int  row;
    char command, seatNum;

    bool** plane = allocate<bool>(size);
    initialize<bool>(plane, size);

    printPlane(plane, size);
    cout << "\n[R]eserve    [C]ancel      e[x]it " << endl;
    cout<<" : ";
    cin >> command;

    while(toupper(command) != 'X')
    {
        switch(toupper(command))
        {
            case 'R':
                cout<<"---- RESERVE SEAT: ------" << endl;
                printPlane(plane, size);
                cout << endl;

                take_Plane_Input(row, seatNum);
                if (is_available(size, row, seatNum )) // valid lab and station
                {
                    if (reserve(plane, row, seatNum)){ // seat is unoccupied
                        cout<< "\nSeat reserved at " << row + 1  <<seatNum <<"\n";
                    }

                    else{
                        cout << "\nSeat " << row +1 << seatNum << " is occupied\n";
                    }
                }
                else{
                    cout<< "\nSeat number " << row + 1 << seatNum << " is invalid.\n";
                }
                break;

            case 'C':
                cout<<"---- Cancel: ------"<<endl;
                printPlane(plane, size);
                cout << endl;

                take_Plane_Input(row, seatNum);
                if (is_available(size, row, seatNum )) // valid lab and station
                {
                    if (cancel(plane, row, seatNum))    // seat was reserved
                    {
                        cout << "\nReservation cancelled\n";
                    }
                    else
                    {
                        cout << "\nSeat was not reserved\n";
                    }
                }
                else
                {
                    cout<< "\nSeat number " << row + 1 << seatNum << " is invalid.\n";
                }
                break;
        }
        printPlane(plane, size);
        cout << "\n[R]eserve    [C]ancel      e[x]it \n";
        cout <<":"; cin >> command;
    }

    deallocate<bool>(plane);    // deleting the dynamic array
}

void takeLabInput(int& lab_ID, int& lab, int& station)
{
    cout<<"id: "; cin >> lab_ID;

    while(lab_ID < 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');
       cout<<"\n ID greater than 2 Digits: "; cin >> lab_ID;
    }

    cout<<"lab: "; cin >> lab;
    while(! cin >> lab)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"\nLab number: "; cin >> lab;
    }

    cout<<"station: "; cin >> station;
    while(!  cin >> station)    // check for char inputs
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Station number: " ; cin >> station;
    }

}

void testLab()
{
    int arr[10] = {5,4,3,2,-1};
    int* size = arr;
    int lab_size = 5;

    int lab_ID, lab, station;
    char command ;

    int** list = allocate<int>(size);
    initialize<int>(list, size);
    print(list, size);

    cout << "\n\n";

    cout << "\nlog[i]n    log[o]ut      e[x]it " << endl;
    cout<<" : ";
    cin >> command;
    while(toupper(command) != 'X')
    {
        switch(toupper(command))
        {
            case 'I':
                cout<<"---- LOG IN: ------" << endl;
                cout<<"labs: ";
                print( size, lab_size -1); // lab_size -1 gives the number of elements in arr before the -1
                cout << endl;
                takeLabInput(lab_ID, lab, station);

                if (is_valid(size, lab, station)) // valid lab and station
                {
                    if (login(list, size, lab, station,lab_ID)) // lab_ID not in the system AND lab & station is avaialble
                    {
                        cout<< "\nYou are logged in in lab " << lab << " station: " << station <<"\n";
                    }
                        else
                        {
                            if(read(list, lab, station ) !=  lab_ID)
                                cout << "\nlab " << lab << ", station " << station << " is occupied\n";
                            else
                                cout << "\nYour ID was found  in lab " << lab << " station: " << station <<"\n";
                        }
                }

                else
                {
                    cout<< "\n["<< lab <<"][" << station <<"] is invalid.\n";
                }
                break;

            case 'O':
                cout<<"---- LOG OUT: ------"<<endl;
                cout<<"id: "; cin >> lab_ID;

                if (logout(list, size,lab_ID))
                {
                   cout<<"\nLogout Successful\n";
                }
                else
                {
                    cout<<"\nYou are not logged in\n";
                }
                break;
        }

        print(list, size);

        cout<<"\nlog[i]n    log[o]ut      e[x]it"<<endl;

        cout <<":"; cin >> command;
    }
    deallocate<int>(list);

}
