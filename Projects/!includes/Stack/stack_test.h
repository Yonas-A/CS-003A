#ifndef STACK_TEST_H
#define STACK_TEST_H
#include <iostream>

#include "../../!includes/Linked_List/linked_list.h"
#include "../../!includes/Stack/stack.h"


void simple_Iterator_test( ) ;
// test for the iterator prefix and postfix

void test_big_three( ) ;
// test for the big three i.e. copy ctor,
// assignement operator and destructor


void test_Empty( ) ;
// test for Emtpy( ) 

void test_Push( Stack<int> &myS) ;
// test for Insert( ) ;

void test_Operator_Bracket( ) ;
// test for operator[]( ) 

void test_Pop( ) ;
// test for Pop( ) 

void test_Search( ) ;
// test for Search( ) 

void test_Size( ) ;
// test for Size( ) 

void test_Top( ) ;
// test for Top( ) 

void test_Top_Overloaded( ) ;
// test for Top( int) 

//==============================================
//  test function definitions for list.h
//==============================================

void simple_Iterator_test( ) 
{
    cout << endl << "- - - simple_test_Iterator - - - " << endl << endl;
    Stack<int> s;
    test_Push ( s) ;
    cout << "s: " << endl << "  " << s << endl;
    cout << "- - - Printing iterator: POSTFIX - - - " << endl << endl;
    cout << "It ==>";
    for ( Stack<int>::Iterator it = s.Top ( ) ;
                            it != s.Bottom ( ) ; it++) {
        cout << "[" << *it << "]" << "->";
    }

    cout << "|||" << endl << endl;

    cout << "- - - Printing iterator: PREFIX - - - " << endl << endl;
    cout << "It ==>";
    for ( Stack<int>::Iterator it = s.Top ( ) ;
                            it != s.Bottom ( ) ; ++it) {
        cout << "[" << *it << "]" << "->";
    }

    cout << "|||" << endl << endl;

    cout << "   - - - - - - - - - - - - - - - - - - - - - " << endl;
}

void test_big_three( ) 
{
    cout <<  "   = = = Test big_three( )  = = = " << endl << endl;

    cout << "- - - default ctor( ) : Stack<int> s - - -" << endl;
    Stack<int> s;
    test_Push( s) ;
    cout << "s " << endl << "   " << s << endl;

    cout << "   - - - Copy Ctor: myS2( s)  - - - " << endl;
    Stack <int> myS2( s) ;

    cout << "myS2 " << endl << "   " << myS2 ;
    cout << "changing the first item of myS2 to " << -15
         << endl << endl;
    Stack<int>::Iterator top = myS2.Top ( ) ;
    *top = -15;

    cout << "s " << endl << "   " << s ;
    cout << "myS2 " << endl << "   " << myS2 ;

    cout << "   - - - Ctor = ( ) : myS3 = myS2 - - - " << endl;
    Stack <int> myS3;
    myS3 = myS2;
    cout << "myS3 " << endl << "   " << myS3 ;

    cout <<  "   = = = end of Test big_three( )  = = = " << endl
          << endl;
}

void test_Empty( ) 
{
    cout << endl << "   = = = Test Empty( )  = = = " << endl << endl;
    Stack<int> myS;
    cout << "myS " << myS << endl;

    cout << ( myS.Empty() ? "Stack is empty" : "Stack is not empty")
         << endl << endl;


    test_Push( myS) ;
    cout << "myS " << myS << endl;

    cout << ( myS.Empty() ? "Stack is empty" : "Stack is not empty")
         << endl << endl;


    cout <<"   = = = end of Test Empty( )  = = = " << endl;
}

void test_Operator_Bracket( ) 
{
    cout << endl << "   = = = Test operator[]( )  = = = " << endl;
    Stack<int> myS;
    test_Push ( myS) ;
    cout << "myS " << endl << "   " << myS ;

    int item;
    int pos = 4;

    cout << "- - - test 1: item at index = " << pos <<" - - -"
         << endl;
    item = myS[pos];

    if( item) 
        cout << "item at myS[" << pos <<"] = " << item << endl
             << endl;
    else
        cout << "Index out of bounds/ list doesn't exist" << endl
             << endl;


    pos = 8;
    Stack<int> s;
    cout << "s " << endl << "   " << s ;
    cout << "- - - test 2: item at index = " << pos <<" - - -"
         << endl;
    cout << "list is empty" << endl;
    cout << "Since list is empty assert must terminate program"
         << endl;
    item = myS[pos];

    if( item) 
        cout << "item at myS[" << pos <<"] = " << item << endl
             << endl;
    else
        cout << "Index out of bounds/ list doesn't exist" << endl
             << endl;

    cout << "   = = = end of Test operator[]( )  = = = " << endl;
}

void test_Pop( ) 
{
    cout << endl << "   = = = Test Pop( )  = = = " << endl;

    Stack<int> myS;
    test_Push ( myS) ;
    cout << "myS " << endl << "   " << myS ;

    Stack<int>::Iterator bottom = myS.Bottom ( ) ;
    Stack<int>::Iterator top =  myS.Top ( ) ;
    int removed;

    cout << "- - - test 1: pop 15 items from  10 item Stack - - - "
         << endl;
    for( int i = 0; i < 15; i++) 
    {
        removed = myS.Pop ( ) ;
        bottom = myS.Bottom ( ) ;
        top = myS.Top ( ) ;

        cout << "Delting item number: " << i  << endl;
        if( removed) 
        {
            cout << "Removed item = " <<  removed << endl;
            if( bottom != nullptr || top != nullptr ) {
                cout << "After Pop( item) ->:   head_ptr: " << *top
                     << "   end_ptr: " << *bottom << endl;
            }
            cout << "new Stack:" << endl <<"       "<< myS ;

        }
        else
            cout << "Stack is empty. Nothing to remove"
                 << endl << endl;
    }

    cout << "- - -  check for _head and end ptr - - -" << endl
         <<endl;
    if( top != nullptr || bottom != nullptr) 
        cout << "head_ptr: " << *top << " end_ptr " << *bottom
             << endl;

    else
        cout << "head and end are set to  null after "
             << " deleting all items" << endl << endl;

    cout << endl << "   = = = end of test Pop( )  = = = " << endl;

}

void test_Push( Stack<int> &myS) 
{
//cout << endl << "-  -   - test Insert( )  - - - " << endl << endl;
    const bool DEBUG = false;
//    cout << " Insert head for Stack" << endl;
    Stack<int>::Iterator front ;

    for( int i = 0; i < 11; i++) 
    {
        int r = rand ( ) % 100;
        front = myS.Push(  r) ;
        if( DEBUG) 
        {
            cout << "Inserting: " << r << endl << "    ";
            cout << "Top of stack is : " << *front << endl;
        }
    }
    if( DEBUG)  {
    cout << "Stack: " << endl << "  " << myS << endl;
    cout << "-  -   - end of test Insert( )  - - - " << endl << endl;
    }
}

void test_Search( ) 
{
    cout << endl << "   = = = Test Search( )  = = = " << endl;
    Stack<int> myS;

    int item = 10;
    cout << "- - - test 1: search " << item << " in empty list - - - \n";
    cout << "myS " << endl << "   " << myS ;
    Stack<int>::Iterator search = myS.Search ( item) ;

    if( search) 
        cout << "Searched item is: " << *search << endl << endl;
    else
        cout << "Cannot find item in list " << endl << endl;

    test_Push( myS) ;
    item = myS[3];
    cout << "- - - test 2: search " << item << " in 10 item list - - -\n";

    cout << "myS " << endl << "   " << myS;

    search = myS.Search ( item) ;
    if( search) 
        cout << "Searched item is: " << *search << endl << endl;
    else
        cout << "Cannot find item in list " << endl << endl;

    cout << endl << "   = = = end of test Search( )  = = = " << endl;

}

void test_Size( ) 
{
    cout << endl << "   = = = Test Size( )  = = = " << endl;
    Stack<int> myS;

    cout << endl << "\t------- test 1: empty list ---------" << endl;
    cout << "myS " << endl << "   " << myS ;
    int size = myS.Size ( ) ;

    if( size) 
        cout << "Size of list is: " << size << endl << endl;
    else
        cout << "List is empty. Size is " << size << endl << endl;


    cout << "   - - - test 2: list with 10 items - - - " << endl;
    test_Push( myS) ;
    cout << "myS " << endl << "   " << myS;

    size = myS.Size ( ) ;
    if( size) 
        cout << "Size of list is: " << size << endl << endl;
    else
        cout << "List is empty. Size is " << size << endl << endl;

    cout << endl << "   = = = end of test Size( )  = = = " << endl;
}

void test_Top( ) 
{
    cout << endl << "   = = = Test Top( )  = = = " << endl;
    Stack<int> myS;

    Stack<int>::Iterator top  = myS.Top ( ) ;

    cout << endl << "\t------- test 1: empty list ---------" << endl;
    cout << "myS " << endl << "   " << myS;
    if( top == nullptr) 
        cout << "No top node found. List is empty" << endl << endl;
    else
        cout << "Top node is [" << *top <<"]" << endl << endl;

    cout << "   - - - test 2: list with 10 items - - - " << endl;
    test_Push( myS) ;
    cout << "myS " << endl << "   " << myS << endl;
    top = myS.Top ( ) ;

    if( top == nullptr) 
        cout << "No top node found. List is empty" << endl << endl;
    else
        cout << "Top node is [" << *top <<"]" << endl << endl;

    cout << "   = = =  end of test Top( )  = = = " << endl;
}


void test_Top_Overloaded( ) 
{
    cout << endl << "   = = = Test Top( int )  = = = " << endl;
    Stack<int> myS;

    cout << "   - - - test 1: list with 10 items - - - " << endl;
    test_Push( myS) ;
    cout << "myS " << endl << "   " << myS << endl;
    int top = myS.Top ( 0) ;
    cout << "Item at the Top node is [" << top <<"]" << endl << endl;
    cout << "   = = =  end of test Top( int)  = = = " << endl;
}


#endif // STACK_TEST_H
