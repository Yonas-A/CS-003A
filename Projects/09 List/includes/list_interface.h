#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../../!includes/Linked_List/linked_list.h"
#include "../../!includes/List/list.h"

using namespace std;

//====================================================
//          FUNCTION DECLERATION FOR USER INTERFACE
//====================================================

void display_menu();
//display prompt to user

void Main_menu();
//calls functions and does everything

void move_cursor(List<int> const& myList, node<int>* const iMarker,
                 const int pos);
// based on the prompt it shows the current position of cursor
// with a curly braces

void next(List<int> myList, node<int>*& iMarker);
// changes the cursor to the next place
// if at the end of list, cursor stays there
// it doesn't fall of or crash

void Random_insert(List<int>& myList, node<int>*& iMarker);
// inserts a random number at after the current position of cursor

void search_move(List<int>& myList, node<int>*& iMarker,
                 const int item);
// will move the cursor to the position of the key if it is found.
//No change in cursor position if key is not found in the list.

void start_up(List<int>& myList);
//displays default interface to user upon running program

//====================================================
//          FUNCTION DEFINTION
//====================================================

void display_menu() {
    cout << "[R]andom [A]fter [B]efore [D]elete [P]revious "
         << "[N]ext  [H]ome [E]nd [S]earch [Q]uit:     ";
}

void Main_menu() {
    cout << "\n\t======================TOP======================\n\n";
    bool done = false;
    char command;

    List<int> myList;
    start_up(myList);

    int input;
    node<int>* iMarker = myList.Begin();
    int pos = 0;

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
                if (!(myList.Empty()))
                    pos++;
                iMarker = myList.Insert_After(input, iMarker);

                break;

            case 'B':  // insert item from user before cursor
                cout << ": ";
                cin >> input;
                iMarker = myList.Insert_Before(input, iMarker);
                //                 for insert before position of cursor stays same since
                //                 new item is inserted at the position of cursor
                break;

            case 'D':  // delete item at pos
                myList.Remove(iMarker);
                iMarker = myList.Begin();
                pos = 0;
                break;

            case 'E':  // go to end of lis
                iMarker = myList.End();
                pos = myList.Index_Of(iMarker);
                break;

            case 'H':  //go home
                iMarker = myList.Begin();
                pos = 0;
                break;

            case 'N':  //go to next
                next(myList, iMarker);
                if (pos < myList.Size() - 1)
                    pos++;
                break;

            case 'P':  // go to previous
                iMarker = myList.Prev(iMarker);
                if (pos > 0)
                    pos--;
                break;

            case 'R':  //add random after cursor
                Random_insert(myList, iMarker);
                pos++;
                break;

            case 'S':  // search
                cout << ": ";
                cin >> input;
                if (myList.Size() > 0) {
                    search_move(myList, iMarker, input);

                    if (iMarker)
                        pos = myList.Index_Of(iMarker);
                }
                break;

            case 'Q':  // Quit program
                done = true;
                break;
        }
        move_cursor(myList, iMarker, pos);
    } while (!done);

    cout << "\n\t======================END======================\n";
}

void move_cursor(List<int> const& myList, node<int>* const iMarker,
                 const int pos) {
    node<int>* walker = myList.Begin();
    cout << "H->";
    while (walker != nullptr) {
        if (walker == iMarker)
            cout << "{" << myList[pos] << "}->";
        else
            cout << *walker;
        walker = walker->_next;
    }
    cout << "|||" << endl;
}

void next(List<int> myList, node<int>*& iMarker) {
    node<int>* walker = myList.Begin();
    node<int>* temp = iMarker;
    while (walker != nullptr && temp->_next != nullptr) {
        if (temp->_next != nullptr) {
            iMarker = temp->_next;
        }
        walker = walker->_next;
    }
}

void Random_insert(List<int>& myList, node<int>*& iMarker) {
    int randomNum = rand() % 1000;
    node<int>* temp = iMarker;
    iMarker = myList.Insert_After(randomNum, temp);
}

void search_move(List<int>& myList, node<int>*& iMarker, const int item) {
    node<int>* start_here = myList.Begin();
    if (iMarker->_next != nullptr)
        start_here = iMarker->_next;
    //      if iMarker is not the last node then
    //      searching startd from the next node
    //      else search starts from first node

    node<int>* temp = myList.Search(item, start_here);

    //if node is not found starting from iMarker
    // then start a second search from beginning node
    if (temp == nullptr)
        temp = myList.Search(item, start_here);

    // if item is found then iMarker points to this node
    if (temp)
        iMarker = temp;
}

void start_up(List<int>& myList) {
    for (int i = 0; i < 5; i++) {
        int randomNum = rand() % 100;
        myList.Insert_Head(randomNum);
    }
    node<int>* iMarker = myList.Begin();
    move_cursor(myList, iMarker, 0);
}

#endif  // LIST_INTERFACE_H
