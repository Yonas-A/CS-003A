#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <stdlib.h>
#include <time.h>

#include <iostream>

#include "../../!includes/List/iterated_list.h"

using namespace std;

//====================================================
//          FUNCTION DECLERATION FOR USER INTERFACE
//====================================================

void display_menu();
//display prompt to user

void Main_menu();
//calls functions and does everything

void move_cursor(List<int> const &myList,
                 List<int>::Iterator const &iMarker);
// based on the prompt it shows the current position of cursor
// with a curly braces

void next(List<int> &myList, List<int>::Iterator &iMarker);
// changes the cursor to the next place
// if at the end of list, cursor stays there
// it doesn't fall of or crash

void Random_insert(List<int> &myList, List<int>::Iterator &iMarker);
// inserts a random number at after the current position of cursor

void search_move(List<int> &myList, List<int>::Iterator &iMarker,
                 const int item);
// will move the cursor to the position of the key if it is found.
//No change in cursor position if key is not found in the list.

void start_up(List<int> &myList);
//displays default interface to user upon running program

//====================================================
//          FUNCTION DEFINTION
//====================================================

void display_menu() {
    cout << "[R]andom [A]fter [B]efore [D]elete [P]revious "
         << "[N]ext  [H]ome [E]nd [S]earch [Q]uit:     ";
}

void end(List<int> &mylist, List<int>::Iterator &iMarker) {
    List<int>::Iterator it = mylist.Begin();
    while (it != mylist.End())
        ++it;
    iMarker = it;
}

void Main_menu() {
    cout << endl
         << "       "
         << "== == == == == == == == TOP == == == == == == == \n\n";
    bool done = false;
    char command;

    List<int> myList;
    start_up(myList);

    int input;
    List<int>::Iterator iMarker = myList.Begin();

    do {
        display_menu();
        cin >> command;
        cout << "..   ..   ..   ..   ..   ..   ..   ..   ..   "
             << "..   ..   ..   ..   ..   ..   .." << endl
             << endl;

        switch (toupper(command)) {
            case 'A':  // insert item from user before cursor
                cout << ": ";
                cin >> input;
                iMarker = myList.Insert_After(input, iMarker);
                break;

            case 'B':  // insert item from user before cursor
                cout << ": ";
                cin >> input;
                iMarker = myList.Insert_Before(input, iMarker);

                break;

            case 'D':  // delete item at pos
                myList.Remove_Node(iMarker);
                iMarker = myList.Begin();
                break;

            case 'E':  // go to end of lis
                iMarker = myList.Last_Node();
                break;

            case 'H':  //go home
                iMarker = myList.Begin();
                break;

            case 'N':  //go to next
                next(myList, iMarker);
                break;

            case 'P':  // go to previous
                iMarker = myList.Previous(iMarker);
                break;

            case 'R':  //add random after cursor
                Random_insert(myList, iMarker);
                break;

            case 'S':  // search
                cout << ": ";
                cin >> input;
                search_move(myList, iMarker, input);
                break;

            case 'Q':  // Quit program
                done = true;
                break;
        }
        move_cursor(myList, iMarker);
    } while (!done);

    cout << "\n       == == == == == == == == END == == == == == == == \n";
}

void move_cursor(List<int> const &myList,
                 List<int>::Iterator const &iMarker) {
    List<int>::Iterator it;
    cout << "H->";
    for (it = myList.Begin(); it != myList.End(); it++) {
        if (it == iMarker)
            cout << "{" << *it << "}->";
        else
            cout << "[" << *it << "]->";
    }
    cout << "|||" << endl;
}

void next(List<int> &myList, List<int>::Iterator &iMarker) {
    List<int>::Iterator end = myList.End();
    List<int>::Iterator temp = iMarker;
    if (iMarker != end && ++temp != end)
        //if iMarker is not null and next node exists
        // just increment iMarker
        iMarker++;
}

void Random_insert(List<int> &myList, List<int>::Iterator &iMarker) {
    int randomNum = rand() % 100;
    List<int>::Iterator temp = iMarker;
    iMarker = myList.Insert_After(randomNum, temp);
}

void search_move(List<int> &myList, List<int>::Iterator &iMarker,
                 const int item) {
    if (myList.Empty() == true)
        //if list is empty dont search anything
        return;

    List<int>::Iterator start_here = myList.Begin();
    List<int>::Iterator hold = iMarker;
    List<int>::Iterator temp;

    //search starts from the next node to imarker if
    // next node exists
    if (++hold) {
        start_here = hold;
    }
    temp = myList.Search(item, start_here);

    //if next node to iMarker is null start search from head
    if (temp == nullptr && start_here != myList.Begin()) {
        start_here = myList.Begin();
        temp = myList.Search(item, start_here);
    }

    // if item is found then iMarker points to this node
    if (temp) {
        iMarker = temp;
    }
}

void start_up(List<int> &myList) {
    for (int i = 0; i < 5; i++) {
        int randomNum = rand() % 100;
        myList.Insert_Head(randomNum);
    }
    List<int>::Iterator iMarker = myList.Begin();
    move_cursor(myList, iMarker);
}

#endif  // USER_INTERFACE_H
