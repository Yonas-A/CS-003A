/*
 * Author: Yonas Adamu
 * Project: Stack and Queue Classs
 * Purpose: Make two separate classes, ( Stack and Queue) 
 *          that access the linked list functions and performs
 *          different operations based on the Stack and Queue
 *          concepts

 */
#include <iostream>
#include <ctime>

/// uncomment when testing Queue class
#include "../../!includes/Queue/queue_test.h"

/// uncoment when testing Stack class
// #include "../../!includes/Stack/stack_test.h"

using namespace std;

int main( ) 
{
    srand( time( nullptr) ) ;

// ============= Queue class unique testing function =============

//    Queue <int> myQ;          test_Push ( myQ) ;

//    test_Front ( ) ;

//    test_Front_Overloaded( ) ;

// ========= Stack and Queue class common testing function =========

    simple_Iterator_test( ) ;

//    test_big_three ( ) ;

//    test_Empty ( ) ;

//    test_Operator_Bracket ( ) ;

//    test_Pop ( ) ;

//    test_Search ( ) ;

//    test_Size( ) ;

// ============= Stack class unique testing function =============

//    Stack <int> myS;           test_Push ( myS) ;

//    test_Top ( ) ;

//    test_Top_Overloaded( ) ;

//=========================================



    return 0;
}
