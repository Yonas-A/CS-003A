#ifndef LIST_TEST_H
#define LIST_TEST_H
#include "../../!includes/List/iterated_list.h"

using namespace std;

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

void test_Operator_Bracket();
// test for operator []()

void test_Previous();
// test for Previous()

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


//===================================================================
//          Test function definition
//===================================================================


void test_big_three()
{
    cout << "\n     ======== test _big_three ========\n\n";

    cout << "\t----- Default Ctor: ------" << endl;
    List<int> myL;
    test_Insert_Head (myL);
    cout << "myL: " << endl << "     " << myL ;

    cout << "\t----- copy ctor(): list2(myL) ------\n";
    List <int> list2(myL);
    cout << "myL " << endl << "   " << myL << endl;
    cout << "list2 " << endl << "   " << list2 << endl;


    cout << "\t----- ctor = ():  list3 = myL ------\n";
    List <int> list3;
    list3 = myL;
    cout << "list3 " << endl << "   " << list3 << endl;

    cout << "     ======== end of test _big_three ========" << endl << endl;
}

//===========================================================================
//          TEST for member functions
//===========================================================================


void test_Begin()
{
    cout << endl << "\t====== Test Begin() ======" << endl;
    List<int> myList;

    List<int>::Iterator begin = myList.Begin ();

    cout << endl << "\t------- test 1: empty list ---------" << endl;
    cout << "myList: " << endl << "     " << myList ;
    if(begin)
        cout << "Beginning node is [" << *begin  <<"]" << endl << endl;
    else
        cout << "List is empty" << endl << endl;

    cout << "   ------- test 2: list with 10 items --------" << endl;
    test_Insert_Head(myList);
    cout << "myList: " << endl << "     " << myList ;
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
     List<int> myList;

     cout << endl << "------- test 1: empty list ---------" << endl;
     cout << "myList: " << endl << "     " << myList ;
     myList.Clear_List ();
     cout << "myList after Clear_List():" << endl << "     " << myList ;


     cout << "------- test 2: 10 items in list ---------" << endl;
     test_Insert_Head (myList);
     cout << "myList: " << endl << "     " << myList ;

     myList.Clear_List ();
     cout << "myList after Clear_List():" << endl << "    " << myList ;

     cout << "      ====== end of test Clear_List() ======" << endl;

}

void test_Copy_List()
{
    cout << endl << "\t====== Test Copy_List() ======" << endl;
    List<int> listA;
    test_Insert_Head(listA);
    List<int> listB;
    List<int>::Iterator end_B = listA.Copy_List (listB);


    cout << "listA: " << endl << "  " <<  listA ;
    cout << "listB: " << endl << "  " << listB  << endl;

    cout << "     - - - Check list uniqueness - - - " << endl << endl;
    *end_B = listB.Insert_Last(163);
    List<int>::Iterator end_A = listA.Insert_Last (98);

    cout << "listA after Insert_Last(98)" << endl << "    ";
    cout << listA  << endl;
    cout << "listB after Insert_Last(163)" << endl << "    ";
    cout << listB << endl;

    cout << "Last node in listA: = [" << *end_A << "]" << endl;
    cout << "Last node in listB: = [" << *end_B << "]" << endl;

    cout << endl << "\t====== end of test Copy_List() ======" << endl;
}

void test_End()
{
    cout << endl << "\t====== Test End() ======" << endl;
    List<int> myList;

    List<int>::Iterator end = myList.End();


    cout << endl << "\t- - - test 1: empty list - - -" << endl;
    cout << "myList: " << endl << "     " << myList ;

    if(end)
        cout << "Last node is [" << *end <<"]" << endl << endl;
    else
        cout << "List is empty" << endl << endl;

    test_Insert_Head(myList);
    cout << endl << "\t- - - test 2: list with 10 items - - -" << endl;
    cout << "myList: " << endl << "     " << myList ;
    end = myList.End();

    if(end)
        cout << "Last node is [" << *end <<"]" << endl << endl;
    else
        cout << "List is empty" << endl << endl ;

    cout <<"    ====== end of test End() ======" << endl;
}

void test_Empty()
{
    cout << endl << "\t====== Test Empty() ======" << endl;
    List<int> myList;

    bool is_Empty  = myList.Empty ();
    cout << endl << "\t- - - test 1: empty list - - -" << endl;
    cout << "myList: " << endl << "     " << myList;
    if(is_Empty)
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl << endl;

    test_Insert_Head(myList);
    cout << endl << "\t- - - test 2: list with 10 items - - -" << endl;
    cout << "myList: " << endl << "     " << myList;
    is_Empty  = myList.Empty ();

    if(is_Empty)
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl << endl;

    cout << endl << "\t====== end of test Empty() ======" << endl;
}

void test_Insert_After()
{
    cout << endl << "\t====== Test Insert_After() ======" << endl;
    List<int> myList;

    List<int>::Iterator begin = myList.Begin();
    List<int>::Iterator  iMarker = nullptr;
    List<int>::Iterator  inserted = nullptr;


    int key = 100;   int item = 50;
    cout << "---- test 1: Insert: " << item << " in empty list ----\n";
    cout << "myList: " << endl << "     " << myList;
    iMarker = myList.Search(key, begin);
    inserted = myList.Insert_After(item, iMarker);

    cout << "List after Insert_After():" << endl << "   "
         << myList << endl;
    cout << "Inserted = [" << *inserted << "]" << endl << endl;


    test_Insert_Head(myList);
    // inserting 10 items

    cout << "myList: " << endl << "     " << myList;
    key = myList[5];   item = 123;
    cout << "---- test 2: Insert: " << item << " after ["
         << key << "] ----\n";

    iMarker = myList.Search(key, begin);
    inserted = myList.Insert_After( item, iMarker);

    cout << "List after Insert_After():" << endl << "   "
         << myList << endl;
    cout << "Inserted = [" << *inserted << "]" << endl << endl;

    cout << "       ====== end of test Insert_After() ======" << endl;

}

void test_Insert_Before()
{
    cout << endl << "\t====== Test Insert_Before() ======" << endl;
    List<int> myList;


    List<int>::Iterator begin = myList.Begin();
    List<int>::Iterator  iMarker = nullptr;
    List<int>::Iterator  inserted = nullptr;

    int key = 100;   int item = 50;

    cout << "---- test 1: insert: " << item << " in empty list ----\n";
    cout << "myList: " << endl << "     " << myList << endl;
    iMarker = myList.Search(key, begin);
    inserted = myList.Insert_Before(item, iMarker);

    cout << "Inserted Item= [" << *inserted << "]" << endl << endl;
    cout << "myList:" << endl << "      " << myList << endl;
    test_Insert_Head(myList);
    // inserting 10 items

    key = myList[3];   item = 123;
    cout << "---- test 2: insert: " << item << " before ["
         << key << "] ----"  << endl << endl;
    cout << "myList: " << endl << "     " << myList << endl;
    iMarker = myList.Search(key, begin);
    inserted = myList.Insert_Before( item, iMarker);

    cout << "Inserted Item= [" << *inserted << "]" << endl << endl;
    cout << "myList:" << endl << "      " << myList << endl;


    key = 50;   item = 750;
    cout << "---- test 3: insert: " << item << " before ["
         << key << "] ----" << endl << endl;
    cout << "myList: " << endl << "     " << myList;
    iMarker = myList.Search(key, begin);
    inserted = myList.Insert_Before( item, iMarker);

    cout << "Inserted Item= [" << *inserted << "]" << endl << endl;
    cout << "myList:" << endl << "      " << myList << endl;

    cout << "       ====== end of test Insert_Before() ======" << endl;
}

void test_Insert_Head(List<int> &myList)
{
    for (int i = 0; i < 10; i++)
    {
        int r = rand ()% 100;
        myList.Insert_Head( r);
    }
//    cout << myList << endl;
}

void test_Insert_Last()
{
    cout << "\n\t====== Test Insert_Last() ======\n" << endl;
    List<int> myList;
    List<int>::Iterator  inserted = nullptr;


    int item = 26;
    cout << "---- test 1: insert: " << item << " in empty list ----\n";
    inserted = myList.Insert_Last(item);

    cout << "Inserted = [" << *inserted << "]" << endl << endl;
    cout << "myList: " << endl << "     " << myList << endl;

    test_Insert_Head (myList);
    //inserting ten items in the list

    item = 75;
    cout << "------ test 2: Insert: " << item
         << " in a list of 10 items  --------" << endl;
    inserted = myList.Insert_Last(item);

    cout << "Inserted = [" << *inserted << "]" << endl << endl;
    cout << "myList: " << endl << "     " << myList << endl;

    cout << "\n\t====== end of test Insert_Last() ======\n" << endl;
}

void test_Index_Of()
{
    cout << "\n\t====== Test Index_Of() ======\n" << endl;
    List<int> myList;
    test_Insert_Head(myList);
    List<int>::Iterator begin = myList.Begin();
    List<int>::Iterator  iMarker = nullptr;


    int key = 70;
    cout << "---- test 1: Index of ["<< key <<"] ---" << endl << endl;
    cout << "myList: " << endl << "     " << myList << endl;
    iMarker = myList.Search(key, begin);
    int pos = myList.Index_Of(iMarker);

    if(pos < 0)
        cout << key <<" key is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    key = myList[5];
    cout << "----- test 2: Index of ["<< key <<"] -----" << endl << endl;
    cout << "myList: " << endl << "     " << myList << endl;
    iMarker = myList.Search(key, begin);
    pos = myList.Index_Of(iMarker);

    if(pos < 0)
        cout << key <<" key is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    cout << "    ========= end of test _index_of() =========\n" << endl;
}

void test_Operator_Bracket()
{
    cout << "\n\t====== Test operator [] ======\n" << endl;
    List<int> myList;
    test_Insert_Head(myList);

    int pos = 9;
    cout <<"    ------ test 1: pos = " << pos << " ------" << endl;
    cout << "myList: " << endl << "     " << myList << endl;
    int item = myList[pos];
    cout << "Node at " << pos << " = [" << item<<  "]" << endl << endl;


    pos = -5;
    cout <<"    ------ test 2: pos = " << pos << " ------" << endl;
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "Pos is a non existing position in the list" << endl;
    cout << "Assert from _at() in list_functions.h must terminate"
         << " program" << endl;

    item = myList[pos];
    cout << "Node at " << pos << " = [" << item<<  "]" << endl << endl;

}

void test_Previous()
{
    cout << endl << "\t====== Test Previous() ======" << endl << endl;
    List<int> myList;
    test_Insert_Head(myList);
    int key;
    List<int>::Iterator begin = myList.Begin();
    List<int>::Iterator  iMarker = nullptr;
    List<int>::Iterator  previous = nullptr;


    key = myList[3];
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "----- test 1: previous to [" << key << "]-------" << endl;

    iMarker = myList.Search(key, begin);
    previous = myList.Previous(iMarker);

    if(previous)
        cout << "Node before [" << *iMarker << "] is: ["
             << *previous  << "]" << endl << endl;
    else
        cout << "No previous node: head_ptr only" << endl << endl;

    key = myList[9];
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "----- test 2: previous to [" << key << "]-------" << endl;
    iMarker = myList.Search(key, begin);
    previous = myList.Previous(iMarker);

    if(previous)
        cout << "Node before [" << *iMarker << "] is: ["
             << *previous  << "]" << endl << endl;
    else
        cout << "No previous node: head_ptr only" << endl << endl;


    key = myList[0];
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "----- test 3: previous to [" << key << "]-------" << endl;
    iMarker = myList.Search(key, begin);
    previous = myList.Previous(iMarker);

    if(previous)
        cout << "Node before [" << *iMarker << "] is: ["
             << *previous  << "]" << endl << endl;
    else
        cout << "No previous node: head_ptr only" << endl << endl;

    key = 1500;
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "----- test 4: previous to [" << key << "]-------" << endl;
    iMarker = myList.Search(key, begin);
    cout << "After this line assert from _previous_node must"<< endl
         << "end program since node doesn't exist" << endl << endl;
    previous = myList.Previous(iMarker);

    if(previous)
        cout << "Node before [" << *iMarker << "] is: ["
             << *previous  << "]" << endl << endl;
    else
        cout << "No previous node: head_ptr only" << endl << endl;

    cout <<"    ====== end of  Test Previous() ======" << endl << endl;

}

void test_Print()
{
    cout << endl << "\t====== Test Print() ======" << endl << endl;
    List<int> myList;
    test_Insert_Head(myList);
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "Printing list using Print()" << endl;
    myList.Print();
    cout << endl << "\t====== end of test Print() ======" << endl << endl;

}

void test_Remove_Node()
{
    cout << endl << "\t====== Test Remove_Node() ======" << endl << endl;
    List<int> myList;
    test_Insert_Head(myList);

    List<int>::Iterator begin = myList.Begin();
    List<int>::Iterator  iMarker ;
    int removed;
    int key;

    key = myList[4];
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "----- test 1: remove  [" << key << "]-------" << endl;
    iMarker = myList.Search(key, begin);
    removed = myList.Remove_Node(iMarker);
                        //searching node to find address for

    cout << "Removed item = " <<  removed << endl;
    cout << "myList: " << endl << "     " << myList << endl;

    key = 200;
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "----- test 2: remove  [" << key << "]-------" << endl;
    iMarker = myList.Search(key, begin);

    cout << "Node doesn't exist. Assert from _previous_node()" << endl
         << "\tmust terminate program" << endl << endl;

    removed = myList.Remove_Node(iMarker);

    cout << "Removed item = " <<  removed << endl;
    cout << "myList: " << endl << "     " << myList << endl;

    cout <<"\t====== end of test Remove_Node() ======" << endl << endl;
}

void test_Remove_Head()
{
    cout << endl << "\t====== Test Remove_Head() ======" << endl << endl;
    List<int> myList;
    test_Insert_Head(myList);
    cout << "myList: " << endl << "     " << myList << endl;
    int removed;

    cout << "----- test  remove  [head]-------" << endl;

    for(int i = 0; i < 15; i++)
    {
        removed = myList.Remove_Head();
        cout << "Removing item number " << i << endl;
        if(removed )
        {
            cout << "Removed head item = " <<  removed << endl;
            cout << "new list: " << endl << "     " << myList << endl;

        }
        else
        {
            cout << "List is empty. No head to delete. Break loop" << endl;
            break;
        }
    }

   cout <<"\t====== end of test Remove_Head() ======" << endl << endl;
}

void test_Search()
{
    cout << endl << "\t====== Test Search() ======" << endl;
    List<int> myList;

    List<int>::Iterator begin = myList.Begin();
    List<int>::Iterator  end = myList.End();
    List<int>::Iterator  mySearch = nullptr;


    int key = 400;
    cout << "myList: " << endl << "     " << myList << endl;
    cout <<"    - - - test 1: search " << key <<" in empty list - - -";
    mySearch = myList.Search(key, begin);

    if(mySearch )
        cout <<  endl << "MySearch = " << *mySearch  << endl << endl;
    else
        cout << endl << key << " is not found in the list" << endl << endl;

    test_Insert_Head (myList);
    // inserting 10 items in the list

    key = myList[1];
    cout << "myList: " << endl << "     " << myList << endl;
    cout <<"    - - - test 2: search " << key <<" in myList - - -";
    mySearch = myList.Search(key, begin);

    if(mySearch )
        cout <<  endl << "MySearch = " << *mySearch  << endl << endl;
    else
        cout << endl << key << " is not found in the list" << endl << endl;

    key = 500;
    cout << "myList: " << endl << "     " << myList << endl;
    cout <<"    - - - test 3: search " << key <<" in myList - - -";

    mySearch = myList.Search(key, end);

    if(mySearch )
        cout <<  endl << "MySearch = " << *mySearch  << endl << endl;
    else
        cout << endl << key << " is not found in the list" << endl << endl;

    cout << endl << "\t====== end of test Search() ======" << endl;
}

void test_Size()
{
    cout << endl << "\t========== Test Size() ==========" << endl;
    List<int> myList;
    int size = myList.Size();

    cout << "myList: " << endl << "     " << myList << endl;
    cout << "--------- test 1: empty list -----------" << endl;
    cout << "Size of list is: " << size << endl << endl;

    cout << "Inserting 10 items " << endl;
    test_Insert_Head(myList);
    cout << "myList: " << endl << "     " << myList << endl;
    cout << "--------- test 2: a list of 10 items -----------" << endl;
    size = myList.Size();
    cout << "Size of list is:  " << size << endl << endl;

    cout << "   ========== end of test Size() ==========" << endl;
}

#endif // LIST_TEST_H
