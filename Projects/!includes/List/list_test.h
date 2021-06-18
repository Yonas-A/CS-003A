#ifndef LIST_TEST_H
#define LIST_TEST_H

#include <iostream>

#include "../../!includes/Linked_List/linked_list.h"
#include "../../!includes/List/list.h"

using namespace std;


//==============================================
// all functions in this page are test functions
// for List class
//==============================================


void test_big_three();
// test for big three()
// destructor(), copy ctor() and ctor=();

//===================================
// test functions to other functions
//==================================

void test_Begin();
// test for Begin()

void test_Clear_List();
// test for Clear_List()

void test_Copy_List();
// test for Copy_List()

void test_End();
// test for End()

void test_Empty();
// test for Empty()

void test_Insert_After();
// test for Insert_After()

void test_Insert_Before();
// test for Insert_Before()

void test_Insert_Head(List<int>& thisList);
// test for Insert_Head()
// will be used in most of other test functions

void test_Insert_Last();
// test for Insert_Last()

void test_Index_Of();
// test for Index_Of()

void test_Operator_bracket();
// test for operator []()

void test_Prev();
// test for Prev()

void test_Print();
// test for Print()

void test_Remove();
// test for Remove()

void test_Search();
// test for Search()

void test_Size();
// test for Size() of list class

//==============================================
//  test function definitions for list.h
//==============================================

void test_big_three()
{
    cout << "\n     ======== test _big_three ========\n\n";

    List<int> myList;
    test_Insert_Head (myList);

    cout << "\t----- copy ctor() test ------\n";
    List <int> secondList(myList);
    cout << "myList " << endl << "   " << myList << endl;
    cout << "secondList " << endl << "   " << secondList << endl;


    cout << "\t----- ctor = () test ------\n";
    List <int> thirdList;
    thirdList = myList;
    cout << "thirdList " << endl << "   " << thirdList << endl;

    cout << "     ======== end of test _big_three ========\n\n";
}

void test_Begin()
{
    cout << endl << "\t====== Test Begin() ======n" << endl;
    List<int> myList;
    node<int>* begin = myList.Begin ();

    cout << endl << "\t------- test 1: empty list ---------" << endl;

    if(begin == nullptr)
        cout << "List is empty" << endl;
    else
        cout << "Beginning node is [" << begin -> _item <<"]" << endl;

    cout << endl << "\t------- test 2: list with 10 items --------" << endl;
    test_Insert_Head(myList);
    begin = myList.Begin ();

    if(begin == nullptr)
        cout << "List is empty" << endl;
    else
        cout << "Beginning node is [" << begin -> _item <<"]" << endl;

    cout << endl << "\t====== end of test Begin() ======n" << endl;

}

void test_Clear_List()
{
    cout <<"\n      ====== Test Clear_List() ======" << endl;
     List<int> myList;

     cout << endl << "------- test 1: empty list ---------" << endl;
     myList.Clear_List ();
     cout << "myList after Clear_List():    " << myList << endl;

     cout << "------- test 2: 10 items in list ---------" << endl;
     cout << "Inserting 10 items in myList" << endl;
     test_Insert_Head (myList);

     myList.Clear_List ();
     cout << "myList after Clear_List():    " << myList << endl;

     cout << "      ====== end of test Clear_List() ======" << endl;

}

void test_Copy_List()
{
    cout << endl << "\t====== Test Copy_List() ======n" << endl;
    List<int> oldList;
    test_Insert_Head(oldList);
    List<int> newList;
    node<int>* N_end = oldList.Copy_List (newList);


    cout << "Printing oldList"  << endl << "    ";
    cout << oldList  << endl;
    cout << "Printing newList"  << endl << "    ";
    cout << newList  << endl;
    cout << "Last node in newList: = [" << N_end->_item << "]" << endl;

    cout << "\n     ----- Check list uniqueness ------" << endl << endl;
    N_end = newList.Insert_Last(163);
    node<int>* O_end = oldList.Insert_Last (98);

    cout << "oldList after Insert_Last(98)" << endl << "    ";
    cout << oldList  << endl;
    cout << "newList after Insert_Last(163)" << endl << "    ";
    cout << newList << endl;

    cout << "Last node in oldList: = [" << O_end->_item << "]" << endl;
    cout << "Last node in newList: = [" << N_end->_item << "]" << endl;

    cout << endl << "\t====== end of test Copy_List() ======n" << endl;
}

void test_End()
{
    cout << endl << "\t====== Test End() ======n" << endl;
    List<int> myList;

    node<int>* last = myList.End ();
    cout << endl << "\t------- test 1: empty list ---------" << endl;

    if(last == nullptr)
        cout << "List is empty" << endl;
    else
        cout << "Last node is [" << last -> _item <<"]" << endl;

    cout << endl << "\t------- test 2: list with 10 items --------" << endl;
    test_Insert_Head(myList);
    last = myList.End ();

    if(last == nullptr)
        cout << "List is empty" << endl;
    else
        cout << "Last node is [" << last -> _item <<"]" << endl;

    cout << endl << "\t====== end of test End() ======n" << endl;
}

void test_Empty()
{
    cout << endl << "\t====== Test Empty() ======n" << endl;
    List<int> myList;

    bool is_Empty  = myList.Empty ();
    cout << endl << "\t------- test 1: empty list ---------" << endl;

    if(is_Empty)
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl << endl;

    cout << endl << "\t------- test 2: list with 10 items --------" << endl;
    test_Insert_Head(myList);
    is_Empty  = myList.Empty ();

    if(is_Empty)
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl << endl;

    cout << endl << "\t====== end of test Empty() ======n" << endl;
}

void test_Insert_After()
{
    cout << endl << "\t====== Test Insert_After() ======" << endl;
    List<int> myList;

    node<int>* here = nullptr;
    node<int>* iMarker = nullptr;
    node<int>* inserted = nullptr;

    int key = 100;   int item = 50;
    cout << "---- test 1: insert: " << item << " in empty list ----\n";

    here = myList.Begin ();
    iMarker = myList.Search(key, myList.Begin ());
    inserted = myList.Insert_After(item, iMarker);

    cout << "Printing list after Insert_After()" << endl << endl;
    cout << myList << endl;
    cout << "inserted = [" << inserted ->_item << "]" << endl << endl;


    test_Insert_Head(myList);
    // inserting 10 items

    key = 300;   item = 123;
    cout << "---- test 2: insert: " << item << " after ["
         << key << "] ----\n";

    here = myList.End();
    iMarker = myList.Search(key, here->_next);
    inserted = myList.Insert_After( item, iMarker);

    cout << "Printing list after Insert_After()" << endl << endl;
    cout << myList << endl;
    cout << "inserted = [" << inserted ->_item << "]" << endl << endl;

    cout << "       ====== end of test Insert_After() ======" << endl;

}

void test_Insert_Before()
{
    cout << endl << "\t====== Test Insert_Before() ======" << endl;
    List<int> myList;


    node<int>* here = nullptr;
    node<int>* iMarker = nullptr;
    node<int>* inserted = nullptr;

    int key = 100;   int item = 50;

    cout << "---- test 1: insert: " << item << " in empty list ----\n";

    here = myList.Begin ();
    iMarker = myList.Search(key, myList.Begin ());
    inserted = myList.Insert_Before(item, iMarker);

    cout << "Printing list after Insert_Before()" << endl << endl;
    cout << myList << endl;
    cout << "inserted = [" << inserted ->_item << "]" << endl << endl;

    test_Insert_Head(myList);
    // inserting 10 items

    key = 300;   item = 123;
    cout << "---- test 2: insert: " << item << " before ["
         << key << "] ----\n";

    here = myList.End();
    iMarker = myList.Search(key, here->_next);
    inserted = myList.Insert_Before( item, iMarker);

    cout << "Printing list after Insert_Before()" << endl << endl;
    cout << myList << endl;
    cout << "Inserted = [" << inserted ->_item << "]" << endl << endl;


    key = 50;   item = 750;
    cout << "---- test 3: insert: " << item << " before ["
         << key << "] ----\n";


    here = myList.End();
    iMarker = myList.Search(key, here->_next);
    inserted = myList.Insert_Before( item, iMarker);

    cout << "Printing list after Insert_Before()" << endl << endl;
    cout << myList << endl;
    cout << "Inserted = [" << inserted ->_item << "]" << endl << endl;

    cout << "       ====== end of test Insert_Before() ======" << endl;
}

void test_Insert_Head(List<int> &myList)
{
    for (int i = 1; i < 11; i++)
    {
        myList.Insert_Head( i*100);
    }
    cout << myList << endl;
}

void test_Insert_Last()
{
    cout << "\n\t====== Test Insert_Last() ======\n" << endl;
    List<int> myList;
    node<int>* inserted = nullptr;

    int item = 1500;

    cout << "\t--------- test 1: insert: " << item
         << " in an empty list --------" << endl;
    inserted = myList.Insert_Last(item);

    cout <<"Printing inserted : [" << inserted ->_item <<"]\n" << endl;
    cout << "Printing list after Insert_Last(): " << endl;
    cout << myList << endl;


    test_Insert_Head (myList);
    //inserting ten items in the list


    item = 75;
    cout << "\t--------- test 2: insert: " << item
         << " in a list of ten items  --------" << endl;
    inserted = myList.Insert_Last(item);

    cout <<"Printing inserted : [" << inserted ->_item <<"]\n" << endl;
    cout << "Printing list after Insert_Last(): " << endl;
    cout << myList << endl;

    cout << "\n\t====== end of test Insert_Last() ======\n" << endl;
}

void test_Operator_bracket()
{
    cout << "\n\t====== Test operator [] ======\n" << endl;
    List<int> myList;
    test_Insert_Head(myList);

    int pos = 4;
    cout <<"    ------ test 1: pos = " << pos << "------" << endl;
    int item = myList[pos];
    cout << "Node at " << pos << " = [" << item<<  "]" << endl << endl;


    pos = -5;
    cout <<"    ------ test 2: pos = " << pos << "------" << endl;
    cout << "Pos is a non existing position in the list" << endl;
    cout << "Assert from _at() in list_functions.h must terminate"
         << " program" << endl;

    item = myList[pos];
    cout << "Node at " << pos << " = [" << item<<  "]" << endl << endl;

}

void test_Index_Of()
{
    cout << "\n\t====== Test Index_Of() ======\n" << endl;
    List<int> myList;
    test_Insert_Head(myList);


    int key = 70;
    cout << "---- test 1: Index of ["<< key <<"] ---" << endl << endl;
    node<int>* iMarker = myList.Search(key, myList.Begin ());
    int pos = myList.Index_Of(iMarker);

    if(pos < 0)
        cout << key <<" key is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    key = 400;
    cout << "----- test 2: Index of ["<< key <<"] -----" << endl << endl;
    iMarker = myList.Search(key, myList.End() ->_next );
    pos = myList.Index_Of(iMarker);

    if(pos < 0)
        cout << key <<" key is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    cout << "    ========= end of test _index_of() =========\n" << endl;
}

void test_Prev()
{
    cout << endl << "\t====== Test Prev() ======" << endl << endl;
    List<int> myList;
    test_Insert_Head(myList);

    int key = 1000;
    node<int>* previous = nullptr;
    node<int>* iMarker = nullptr;

    cout << "----- test 1: previous to [" << key << "]-------" << endl;
    iMarker = myList.Search(key, myList.Begin ());
    previous = myList.Prev(iMarker);

    if(previous == nullptr)
        cout << "No previous node: head_ptr only" << endl << endl;
    else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;

    key = 100;
    cout << "----- test 2: previous to [" << key << "]-------" << endl;
    iMarker = myList.Search(key, myList.Begin ());
    previous = myList.Prev(iMarker);

    if(previous == nullptr)
        cout << "No previous node: head_ptr only" << endl << endl;
    else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;


    key = 600;
    cout << "----- test 1: previous to [" << key << "]-------" << endl;
    iMarker = myList.Search(key, myList.Begin ());
    previous = myList.Prev(iMarker);

    if(previous == nullptr)
        cout << "No previous node: head_ptr only" << endl << endl;
    else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;

    key = 1500;
    cout << "----- test 4: previous to [" << key << "]-------" << endl;
    iMarker = myList.Search(key, myList.Begin ());
    cout << "After this line assert from _previous_node must"<< endl
         << "end program since node doesn't exist" << endl << endl;
    previous = myList.Prev(iMarker);

    if(previous == nullptr)
        cout << "No previous node: head_ptr only" << endl << endl;
    else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;

    cout <<"    ====== end of  Test Prev() ======" << endl << endl;

}

void test_Print()
{
    cout << endl << "\t====== Test Print() ======" << endl << endl;
    List<int> myList;
    test_Insert_Head(myList);
    cout << "Printing list using Print()" << endl;
    myList.Print();
    cout << endl << "\t====== end of test Prev() ======" << endl << endl;

}

void test_Remove()
{
    cout << endl << "\t====== Test Remove() ======" << endl << endl;
    List<int> myList;
    test_Insert_Head(myList);

    node<int>* iMarker = nullptr;
    int removed;
    int key = 300;

    cout << "----- test 1: remove  [" << key << "]-------" << endl;
    iMarker = myList.Search(key, myList.Begin ());
    removed = myList.Remove (iMarker);
                        //searching node to find address for

    cout << "Removed item = " <<  removed << endl;
    cout << "Printing new list:" << endl;
    cout << myList << endl << endl;

    key = 300;
    cout << "----- test 2: remove  [" << key << "]-------" << endl;
    iMarker = myList.Search(key, myList.Begin ());

    cout << "Node doesn't exist. Assert from _previous_node()" << endl
         << "\tmust terminate program" << endl << endl;

    removed = myList.Remove (iMarker);

    cout << "Removed item = " <<  removed << endl;
    cout << "Printing new list:" << endl;
    cout << myList << endl << endl;

    cout <<"\t====== end of test Remove() ======" << endl << endl;
}

void test_Search()
{
    cout << endl << "\t====== Test Search() ======n" << endl;
    List<int> myList;
    node<int>* here = nullptr;
    node<int>* mySearch = nullptr;


    int key = 400;
    cout <<"\n\t----- test 1: search " << key <<" in empty list ------\n";
    here = myList.End();
    mySearch = myList.Search(key, here);

    if( mySearch == nullptr )
        cout << key << " is not found in the list" << endl << endl;
    else
        cout << key << " is found in the list" << endl << endl;

    test_Insert_Head (myList);
    // inserting 10 items in the list

    key = 100;
    cout <<"\n\t----- test 2: search " << key <<" in the list ------\n";
    here = myList.End();
    mySearch = myList.Search(key, here);

    if(mySearch == nullptr)
        cout << key << " is not found in the list" << endl << endl;
    else
        cout << key << " is found in the list" << endl << endl;

    key = 500;
    cout <<"\n\t----- test 3: search " << key <<" in the list ------\n";
    cout << "second ptr is null so search starts from head_ptr\n";
    here = nullptr;
    mySearch = myList.Search(key, here);

    if(mySearch == nullptr)
        cout << key << " is not found in the list" << endl << endl;
    else
        cout << key << " is found in the list" << endl << endl;

    cout << endl << "\t====== end of test Search() ======n" << endl;
}

void test_Size()
{
    cout << endl << "\t========== Test Size() ==========" << endl;

    List<int> myList;

    int size = myList.Size();
    cout << "--------- test 1: empty list -----------" << endl;
    cout << "Size of list is: " << size << endl;

    test_Insert_Head(myList);
    cout << "--------- test 2: a list of 10 items -----------" << endl;
    size = myList.Size();
    cout << "Size of list is:  " << size << endl;
}


#endif // LIST_TEST_H
