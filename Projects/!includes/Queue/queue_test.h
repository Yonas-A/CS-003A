#ifndef QUEUE_TEST_H
#define QUEUE_TEST_H
#include <iostream>

#include "../../!includes/Linked_List/linked_list.h"
#include "../../!includes/Queue/queue.h"


void simple_Iterator_test( ) ;
// test for the iterator postfix and prefix
void test_big_three( ) ;
// test for the big three i.e. copy ctor,
// assignement operator and destructor

void test_Empty( ) ;
// test for Emtpy( ) 

void test_Front( ) ;
// test for Front( ) 

void test_Front_Overloaded( ) ;
// test for Front( int) 

void test_Push( Queue<int> &myQ) ;
// test for Push( ) ;

void test_Operator_Bracket( ) ;
// test for opeator[]( ) 

void test_Pop( ) ;
// test for Pop( ) 

void test_Search( ) ;
// test for Search( ) 

void test_Size( ) ;
// test for Size( ) 


//==============================================
//  test function definitions for list.h
//==============================================

void simple_Iterator_test( ) 
{
    cout << "- - - simple_Iterator_test - - - " << endl << endl;
    Queue<int> q;
    test_Push ( q) ;
    cout << "q: " << endl << "  " << q << endl;
    cout << "- - - - Printing iterator stuff - - - " << endl << endl;
    cout << "It ==>";
    Queue<int>::Iterator it;
    for ( it = q.Front ( ) ; it != q.End ( ) ; it++)
    {
        cout << "[" << *it << "]" << "->";
    }

    cout << "|||" << endl << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - -" << endl;


}

void test_big_three( ) 
{
    cout << "\n     ======== test _big_three ========\n\n";

    cout << "\t----- default ctor( ) : myQ ------\n";
    Queue<int> myQ;
    test_Push( myQ) ;
    cout << "myQ " << endl << "   " << myQ << endl;

    cout << "\t----- copy ctor( ) : myQ2( myQ)  ------\n";
    Queue <int> myQ2( myQ) ;

    cout << "myQ " << endl << "   " << myQ << endl;
    cout << "myQ2 " << endl << "   " << myQ2 << endl;


    int key = 625;
    cout << "changing the front of myQ2 with " << key << endl << endl;

    Queue<int>::Iterator front = myQ2.Front ( ) ;
    *front= -15;
    cout << "myQ " << endl << "   " << myQ << endl;
    cout << "myQ2 " << endl << "   " << myQ2 << endl;

    cout << "\t----- ctor = ( )  myQ2 = myQ2 ------\n";
    Queue <int> myQ3;
    myQ3 = myQ2;
    cout << "myQ3 " << endl << "   " << myQ3 << endl;

    cout << "     ======== end of test _big_three ========\n\n";
}

void test_Empty( ) 
{
    cout << endl << "\t====== test Empty( )  =======" << endl;
    Queue<int> myQ;
    cout << "myQ " << myQ << endl;

    cout << ( myQ.Empty() ? "Queue is empty" : "Queue is not empty")
         << endl << endl;


    test_Push( myQ) ;
    cout << "myQ " << myQ << endl;

    cout << ( myQ.Empty() ? "Queue is empty" : "Queue is not empty")
         << endl << endl;

    cout << endl << "\t====== end of test Empty( )  ======" << endl;
}

void test_Front( ) 
{
    cout << endl << "\t====== Test Front( )  =======" << endl;
    Queue<int> myQ;
    Queue<int>::Iterator front =  myQ.Front ( ) ;

    cout << endl << "\t------- test 1: empty list ---------" << endl;

    if( front) 
        cout << "Front node is [" << *front <<"]" << endl;

    else
        cout << "No front node found. List is empty" << endl;

    cout << endl << "\t------- test 2: list with 10 items --------" << endl;

    test_Push( myQ) ;
    front = myQ.Front ( ) ;

    if( front) 
        cout << "Front node is [" << *front <<"]" << endl;

    else
        cout << "No front node found. List is empty" << endl;

    cout << "changing the front of myQ" << endl << endl;
    *front = rand( )  % 1000;
    cout << myQ;

    cout << endl << "\t====== end of test Front( )  ======" << endl;

}

void test_Front_Overloaded( ) 
{
    cout << endl << "\t====== Test Front( int)  =======" << endl;
    Queue<int> myQ;
    test_Push ( myQ) ;
    cout << "myQ " << endl << "   " << myQ << endl;

    int front =  myQ.Front ( 0) ;
    cout << "Item at the front node is: " << front << endl;
    cout << "-  -   - end of test Front( int)  - - - " << endl << endl;
}


void test_Push( Queue<int> &myQ) 
{
    //    cout << endl << "-  -   - test Push( )  - - - " << endl << endl;
    const bool DEBUG = false;
    Queue<int>::Iterator last ;
    for ( int i = 1; i < 11; i++) 
    {
        last = myQ.Push(  i*10) ;
        if( DEBUG) 
        {
            cout << "Pushing: " << i*10 << endl << "    ";
            cout << "End of list is : " << *last << endl;
        }
    }
//    cout << "Queue: " << endl << "  " << myQ << endl;
//    cout << "-  -   - end of test Push( )  - - - " << endl << endl;

}

void test_Operator_Bracket( ) 
{
    cout << endl << "\t====== Test operator[]( )  ======" << endl << endl;

    Queue<int> myQ;
    cout << "myQ " << endl << "   " << myQ << endl;
    int item;
    int pos = 7;

    cout << "----- test 1: item at index = " << pos <<" -------" << endl;
    cout << "list is empty" << endl;
    item = myQ[pos];

    if( item) 
        cout << "Item at myQ[" << pos <<"] = " << item << endl << endl;
    else
        cout << "Index out of bounds/ list doesn't exist" << endl << endl;

    test_Push ( myQ) ;
    cout << "myQ " << endl << "   " << myQ << endl;

    pos = 3;
    cout << "----- test 2: item at index = " << pos <<" -------" << endl;
    cout << "list has 10 items" << endl;
    item = myQ[pos];

    if( item) 
        cout << "Item at myQ[" << pos <<"] = " << item << endl << endl;
    else
        cout << "Index out of bounds/ list doesn't exist" << endl << endl;

    cout <<"\t====== end of test operator[]( )  ======" << endl << endl;
}

void test_Pop( ) 
{
    cout << endl << "\t====== Test Pop( )  ======" << endl << endl;

    Queue<int> myQ;
    test_Push( myQ) ;
    Queue<int>::Iterator last = myQ.End ( ) ;
    Queue<int>::Iterator front =  myQ.Front ( ) ;
    int removed ;

    cout << "----- test 1: pop 15 items from  10 item queue -------" << endl;
    for( int i = 0; i < 15; i++) 
    {
        removed = myQ.Pop ( ) ;
        last = myQ.End ( ) ;
        front = myQ.Front ( ) ;

        cout << "Delting item number: " << i  << endl;
        if( removed) 
        {
            cout << "Removed item = " <<  removed << endl;
//            if( last != nullptr ||front != nullptr ) 
//                cout << "head_ptr: " << *front << " end_ptr "
//                     << *last << " after remove_item( ) " << endl;
            cout << "new queue:" << endl <<"       "<< myQ << endl ;


        }
        else
            cout << "Queue is empty. Nothing to remove"
                 << endl << endl;
    }

    cout << "- - -  check for _head and end ptr - - -" << endl <<endl;
    if( front != nullptr || last != nullptr) {
        cout << "head_ptr: " << *front << " end_ptr " << *last << endl;
    }
    else
    {
        cout << "head and end are set to  null after "
             << " deleting all items" << endl << endl;
    }
    cout <<"\t====== end of test Pop( )  ======" << endl << endl;
}

void test_Search( ) 
{
    cout << endl << "\t====== Test Search( )  =======" << endl;
    Queue<int> myQ;
    Queue<int>::Iterator search;

    int item = 10;
    cout << "- - - test 1: search " << item << " in empty list - - -\n";
    cout << "myQ " << endl << "   " << myQ << endl;
     search = myQ.Search ( item) ;
    if( search) 
        cout << "Searched item is: " << *search << endl;
    else
        cout << "Cannot find item in list " << endl << endl;

    item = 100;
    cout << "- - - test 2: search " << item << " in 10 item list - - -\n";
    test_Push( myQ) ;
    cout << "myQ " << endl << "   " << myQ << endl;

    search = myQ.Search ( item) ;
    if( search) 
        cout << "Searched item is: " << *search << endl;
    else
        cout << "Cannot find item in list " << endl << endl;


    cout << endl << "\t====== end of test Search( )  ======" << endl;
}

void test_Size( ) 
{
    cout << endl << "\t====== Test Size( )  =======" << endl;
    Queue<int> myQ;
    cout << "myQ " << endl << "   " << myQ << endl;


    cout << "\t- - - - test 1: empty list - - - -" << endl;
    int size = myQ.Size ( ) ;
    if( size) 
        cout << "Size of list is: " << size << endl;
    else
        cout << "List is empty. Size is " << size << endl;


    cout << "\t- - - test 2: list with 10 items - - - " << endl;
    test_Push( myQ) ;
    cout << "myS " << endl << "   " << myQ << endl;


    size = myQ.Size ( ) ;
    if( size) 
        cout << "Size of list is: " << size << endl;
    else
        cout << "List is empty. Size is " << size << endl;

    cout << endl << "\t====== end of test Size( )  ======" << endl;
}

#endif // QUEUE_TEST_H
