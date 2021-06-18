#ifndef SORTED_TEST_H
#define SORTED_TEST_H

#include <iostream>

#include "../../!includes/Linked_List_Sorted/linked_list_sorted.h"
#include "../../!includes/Sorted_List/sorted.h"

using namespace std;


//==============================================
// all functions in this page are test functions
// for List class
//==============================================

void test_simple_iterator();
// test for sorted list iterators

void test_Ascending();
// test for ascending order sorted list

void test_Descending();
// test for descending order sorted list

void test_Unique();
// test for unique sorted list

void test_Duplicates();
// test for a case where list is not unique


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

void test_Insert(Sorted<int> &myList);
// test for Insert()

void test_Index_Of();
// test for Index_Of()

void test_Operator_Bracket();
// test for operator []()

void test_Print();
// test for Print()

void test_Remove_Node();
// test for Remove_Node()

void test_Remove_Head();
// test for Remove_Head()

void test_Search();
// test for Search()

void test_Size();
// test for Size() of list class

void test_Where_This_Goes();
// test for Where_This_Goes()


//==============================================
//  test function definitions for list.h
//==============================================

void test_simple_iterator()
{
    cout << "test_simple_iterator()" << endl;
    Sorted<int> list(true, false);
    test_Insert(list);

    cout << "- - - - printing iterator stuff - - - - "<<endl;
    cout << "It ==>";

    for(Sorted<int>::Iterator it = list.Begin();
                    it != list.End(); ++it)
    {
        cout << "["  << *it << "]->";
    }
    cout << "  ||| " << endl;
    cout<<"- - - - - - - - - - - - - - - - - - - - - - "<<endl;
}

void test_big_three()
{
    cout << "\n     ======== test _big_three ========\n\n";

    Sorted<int> list1(true, true);
    test_Insert(list1);
    cout << "list1 : " << endl << "    " << list1 ;

    cout << "\t----- copy ctor(): list2(list1)  test ------\n";
    Sorted <int> list2(list1);
    cout << "list1 " << endl << "   " << list1;
    cout << "list2 " << endl << "   " << list2 ;

    cout << "\t----- ctor = (): list3 = list1 ------\n";
    Sorted <int> list3;
    list3 = list1;
    cout << "list3 " << endl << "   " << list3 << endl;

    cout << "     ======== end of test _big_three ========\n\n";
}

void test_Ascending()
{
    cout << endl << "   = = = TEST ACSENDING ORDER = = = "  << endl;
    Sorted<int> myList;
    test_Insert(myList);
    cout << "list1 : " << endl << "    " << myList  << endl;
    cout << "   = = = end of TEST ACSENDING ORDER = = = "  << endl;
}

void test_Descending()
{
    cout << endl << "   = = = TEST DESCENDING ORDER = = = "  << endl;
    Sorted<int> list(false, false);
    test_Insert(list);
    cout << "list : " << endl << "    " << list  << endl;
    cout << "   = = = end of TEST DESCENDING ORDER = = = "  << endl;
}

void test_Unique()
{
    cout << endl << "   = = = TEST UNIQUE LIST = = = "  << endl;
    Sorted<int> list(true, true);
    test_Insert(list);
    cout << "list : " << endl << "    " << list;
    cout << "Size of list is: " << list.Size () << endl;

    cout << "\t - - - - - - - - - - - - - - - - - - -  - -" << endl;
    cout << "Adding items already in the list";
    cout << "If duplicate items are in the list, test failed" << endl;
    cout << "else test is sucessful" << endl  << endl;

    Sorted<int>::Iterator begin;
    for(int i = 1; i < 4; i++)
    {
        int r = list[i];
        cout << endl << "inserting: " << r << endl;
        begin = list.Insert (r);
        cout << "List after Insert(r): " << endl << "    " << list;
    }

    cout << "List : " << endl << "    " << list;
    cout << "Size of list is: " << list.Size () << endl;
    cout << "   = = = end of TEST UNIQUE LIST = = = "  << endl;
}

void test_Duplicates()
{
    cout << endl << "   = = = TEST DUPLICATES LIST = = = "  << endl;
    Sorted<int> list(true, false);
    test_Insert(list);
    cout << "list1 : " << endl << "    " << list;
    cout << "Size of list is: " << list.Size () << endl;

    cout << "\t - - - - - - - - - - - - - - - - - - -  - -" << endl;
    cout << "Adding items already in the list" << endl;
    cout << "If duplicate items are in the list, test sucessful" << endl;
    cout << "else test falied" << endl  << endl;

    Sorted<int>::Iterator begin;
    for(int i = 1; i < 4; i++)
    {
        int r = list[2*i +1 ];
        cout << endl << "inserting: " << r << endl;
        begin = list.Insert (r);
        cout << "List after Insert(r): " << endl << "    " << list;
    }

    cout << "List : " << endl << "    " << list;
    cout << "Size of list is: " << list.Size () << endl;
    cout << "   = = = end of TEST DUPLICATES LIST = = = "  << endl;
}


//=============================================================
//=============================================================
void test_Begin()
{
    cout << endl << "\t====== Test Begin() ======" << endl;
    Sorted<int> myList;
    cout << "list1 : " << endl << "    " << myList ;
    Sorted<int>::Iterator begin = myList.Begin ();

    cout << endl << "\t------- test 1: empty list ---------" << endl;

    if(begin)
        cout << "Beginning node is [" << *begin  <<"]" << endl;
    else
        cout << "List is empty" << endl;

    cout << endl << "\t------- test 2: list with 10 items --------" << endl;
    test_Insert(myList);
    begin = myList.Begin ();

    if(begin)
        cout << "Beginning node is [" << *begin  <<"]" << endl;
    else
        cout << "List is empty" << endl;

    cout << endl << "\t====== end of test Begin() ======" << endl;

}

void test_Clear_List()
{
    cout <<"\n      ====== Test Clear_List() ======" << endl;
    Sorted<int> myList;

    cout << "myList : " << endl << "    " << myList ;
    cout << endl << "------- test 1: empty list ---------" << endl;
    myList.Clear_List ();
    cout << "myList after Clear_List():" << endl << "    ";
    cout << myList  << endl;


    cout << "------- test 2: 10 items in list ---------" << endl;
    cout << "Inserting 10 items in myList" << endl;
    test_Insert(myList);
    cout << "myList : " << endl << "    " << myList ;

    myList.Clear_List ();
    cout << "myList after Clear_List():" << endl << "    ";
    cout << myList  << endl;

    cout << "      ====== end of test Clear_List() ======" << endl;

}

void test_Copy_List()
{
    cout << endl << "\t====== Test Copy_List() ======" << endl;
    Sorted<int> listA;
    test_Insert(listA);

    Sorted<int> listB;
    Sorted<int>::Iterator end_B = listA.Copy_List (listB);



    cout << "listA: " << endl << "    " << listA ;
    cout << "listB: " << endl << "    " << listB  << endl;


    cout << "\n     ----- Check list uniqueness ------" << endl << endl;
    Sorted<int>::Iterator end_A = listA.Insert(1000);
    end_B = listB.Insert(5000);


    cout << "listA after Insert_Last(1000)" << endl << "    ";
    cout << listA  << endl;
    cout << "listB after Insert_Last(5000)" << endl << "    ";
    cout << listB << endl;

    cout << "Last node in listA: = [" << *end_A << "]" << endl;
    cout << "Last node in listB: = [" << *end_B << "]" << endl;

    cout << endl << "\t====== end of test Copy_List() ======" << endl;
}

void test_End()
{
    cout << endl << "\t====== Test End() ======" << endl;
    Sorted<int> myList;

    Sorted<int>::Iterator end = myList.End();
    cout << endl << "\t------- test 1: empty list ---------" << endl;
    cout << "myList: " << endl << "    " << myList ;
    if(end)
        cout << "Last node is [" << *end <<"]" << endl << endl;
    else
        cout << "List is empty" << endl << endl;



    cout << endl << "\t------- test 2: list with 10 items --------" << endl;
    test_Insert(myList);
    cout << "myList: " << endl << "    " << myList ;
    end = myList.End();

    if(end) // if end is not null
        cout << "Last node is [" << *end <<"]" << endl << endl;
    else
        cout << "List is empty" << endl << endl;

    cout << endl << "\t====== end of test End() ======" << endl;
}

void test_Empty()
{
    cout << endl << "\t====== Test Empty() ======" << endl;
    Sorted<int> myList;

    bool is_Empty  = myList.Empty ();
    cout << endl << "\t------- test 1: empty list ---------" << endl;
    cout << "myList: " << endl << "    " << myList ;

    if(is_Empty)
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl << endl;

    cout << endl << "\t------- test 2: list with 10 items --------" << endl;
    test_Insert(myList);
    cout << "myList: " << endl << "    " << myList ;
    is_Empty  = myList.Empty ();

    if(is_Empty)
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl << endl;

    cout << endl << "\t====== end of test Empty() ======" << endl;
}

void test_Index_Of()
{
    cout << "\n\t====== Test Index_Of() ======\n" << endl;
    Sorted<int> myList;
    test_Insert(myList);
    Sorted<int>::Iterator begin = myList.Begin();
    Sorted<int>::Iterator  iMarker = nullptr;

    cout << "myList: " << endl << "    " << myList ;

    int key = 70;
    cout << "---- test 1: Index of ["<< key <<"] ---" << endl << endl;
    iMarker = myList.Search(key, begin);
    int pos = myList.Index_Of(iMarker);

    if(pos < 0)
        cout << key <<" is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    key = myList[4];
    cout << "----- test 2: Index of ["<< key <<"] -----" << endl << endl;
    iMarker = myList.Search(key, begin);
    pos = myList.Index_Of(iMarker);

    if(pos < 0)
        cout << key <<" is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    cout << "    ========= end of test _index_of() =========\n" << endl;
}

void test_Insert(Sorted<int> &myList)
{
    Sorted<int>::Iterator  inserted = nullptr; // holds node after inserted

    cout << "Inserting " << endl << "     " ;
    for(int i = 0; i < 10; i++)
    {
        int r = rand () % 100;
        cout << " : " << r ;
        inserted = myList.Insert (r);
    }
    cout << endl << "        - - - - - - - - - - " << endl;
}

void test_Operator_Bracket()
{
    cout << "\n\t====== Test operator [] ======\n" << endl;
    Sorted<int> myList;
    test_Insert(myList);
    cout << "myList: " << endl << "     " << myList << endl;

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

void test_Print()
{
    cout << endl << "\t====== Test Print() ======" << endl << endl;
    Sorted<int> myList(false,false);
    test_Insert(myList);
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "Printing list using Print()" << endl<< "   ";
    myList.Print();
    cout << endl << "\t====== end of test Prev() ======" << endl << endl;

}

void test_Remove_Node()
{
    cout << endl << "\t====== Test Remove_Node() ======" << endl << endl;
    Sorted<int> myList;
    test_Insert(myList);

    Sorted<int>::Iterator begin = myList.Begin();
    Sorted<int>::Iterator  iMarker ;
    int removed;
    int key;

    cout << "myList: " << endl << "     " << myList << endl;
    key = myList[3];
    cout << "----- test 1: remove  [" << key << "]-------" << endl;
    iMarker = myList.Search(key, begin);
    removed = myList.Remove_Node(iMarker);
                        //searching node to find address for

    cout << "Removed item = " <<  removed << endl;
    cout << "myList = " << endl << "     " << myList << endl;

    key = 200;
    cout << "----- test 2: remove  [" << key << "]-------" << endl;
    iMarker = myList.Search(key, begin);

    cout << "Node doesn't exist. Assert from _previous_node()" << endl
         << "\tmust terminate program" << endl << endl;

    removed = myList.Remove_Node(iMarker);

    cout << "Removed item = " <<  removed << endl;
    cout << "Printing new list:" << endl;
    cout << myList << endl << endl;

    cout <<"\t====== end of test Remove_Node() ======" << endl << endl;


    cout <<"\t====== end of test Remove() ======" << endl << endl;
}

void test_Remove_Head()
{
    cout << endl << "\t====== Test Remove_Head() ======" << endl << endl;
    Sorted<int> myList;
    test_Insert(myList);
    int removed;


    cout << "----- test 1: remove  [head]-------" << endl;
    cout << "myList: " << endl << "     " << myList << endl;
    for(int i = 0; i < 15; i++)
    {
        removed = myList.Remove_Head();
        cout << "Removed item number " << i  << endl;

        if(removed){
            cout << "Removed head item = " <<  removed << endl;
            cout << "list:" << endl << "    " << myList << endl;
        }

        else {
            cout << "Empty list.No head to delete. Break loop"
                 << endl << endl;
            break;
       }
    }

    cout << "= = = end of test Remove_Head() = = =" << endl << endl;
}

void test_Search()
{
    cout << endl << "\t====== Test Search() ======" << endl;
    Sorted<int> myList;
    Sorted<int>::Iterator begin = myList.Begin();
    Sorted<int>::Iterator  end = myList.End();
    Sorted<int>::Iterator  mySearch = nullptr;


    int key = 400;
    cout <<"\n\t----- test 1: search " << key <<" in empty list ------\n";
    cout << "myList: " << endl << "     " << myList << endl;
    mySearch = myList.Search(key, begin);

    if(mySearch )
    {
        cout <<  "MySearch is item #" << myList.Index_Of(mySearch)+1
             <<  " in the list" << endl << endl;
    }
    else
        cout << key << " is not found in the list" << endl << endl;

    test_Insert(myList);
    // inserting 10 items in the list

    key = myList[1];
    cout <<"\n\t----- test 2: search " << key <<" in the list ------\n";
    cout << "myList: " << endl << "     " << myList << endl;
    mySearch = myList.Search(key, begin);

    if(mySearch )
        cout <<  "MySearch is item #" << myList.Index_Of(mySearch)+1
             <<  " in the list" << endl << endl;
    else
        cout << key << " is not found in the list" << endl << endl;

    key = 500;
    cout <<"\n\t----- test 3: search " << key <<" in the list ------\n";
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "second ptr is null so search starts from head_ptr\n";

    mySearch = myList.Search(key, end);

    if(mySearch )
        cout <<  "MySearch is item #" << myList.Index_Of(mySearch)+1
             <<  " in the list" << endl << endl;
    else
        cout << key << " is not found in the list" << endl << endl;

    cout << endl << "\t====== end of test Search() ======" << endl;
}

void test_Size()
{
    cout << endl << "\t========== Test Size() ==========" << endl;

    Sorted<int> myList;
    cout << "myList: " << endl << "     " << myList << endl;

    int size = myList.Size();
    cout << "--------- test 1: empty list -----------" << endl;
    cout << "Size of list is: " << size << endl;

    test_Insert(myList);
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "--------- test 2: a list of 10 items -----------" << endl;
    size = myList.Size();
    cout << "Size of list is:  " << size << endl;
}

void test_Where_This_Goes()
{
    cout << endl << "\t ======= Test _where_this_goes() ======\n" << endl;
    Sorted<int> myList;
    Sorted<int>::Iterator  iMarker = nullptr;
    int key ;

    cout << "   TEST I: ACSENDING ORDER " << endl;

    key = 98;
    cout << "----------- Test 1: ----------- " << endl;
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "Where " << key << " go in empty list" << endl;

    iMarker = myList.Where_This_Goes(key);
    if(iMarker)
        cout << "It goes after " << *iMarker << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;

    key = 25;
    cout << "----------- Test 2: ----------- " << endl;
    test_Insert (myList);
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "Where " << key << " go in a 10 item list" << endl;

    iMarker = myList.Where_This_Goes(key);
    if(iMarker)
        cout << "It goes after " << *iMarker << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;


    key = -40;
    cout << "----------- Test 3: ----------- " << endl;
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "Where " << key << " go in a 10 item list" << endl;

    iMarker = myList.Where_This_Goes(key);
    if(iMarker)
        cout << "It goes after " << *iMarker << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;

    cout << "       TEST II: DESCENDING ORDER " << endl << endl;

    Sorted<int> myList2(false, true);
    key = 98;
    cout << "----------- Test 1: ----------- " << endl;
    cout << "myList2: " << endl << "     " << myList2 << endl;
    cout << "Where " << key << " go in empty list" << endl;

    iMarker = myList2.Where_This_Goes(key);
    if(iMarker)
        cout << "It goes after " << *iMarker << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;

    key = 25;
    cout << "----------- Test 2: ----------- " << endl;
    test_Insert (myList2);
    cout << "myList2: " << endl << "     " << myList2 << endl;
    cout << "Where " << key << " go in a 10 item list" << endl;

    iMarker = myList2.Where_This_Goes(key);
    if(iMarker)
        cout << "It goes after " << *iMarker << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;


    key = -40;
    cout << "----------- Test 3: ----------- " << endl;
    cout << "myList2: " << endl << "     " << myList2 << endl;
    cout << "Where " << key << " go in a 10 item list" << endl;

    iMarker = myList2.Where_This_Goes(key);
    if(iMarker)
        cout << "It goes after " << *iMarker << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;

}

#endif // SORTED_TEST_H
