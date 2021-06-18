#ifndef LINKED_LIST_TEST_H
#define LINKED_LIST_TEST_H

#include <iostream>

#include "../../!includes/Linked_List/linked_list.h"

using namespace std;

void test_at( ) ;
//test function for _at( )  of list functions

void test_beginning( ) ;
// test function for _beginning( )  of list functions

void test_clear_list( ) ;
//test function for _clear_list( )  of list functions

void test_copy_list( ) ;
//test function for _copy_list( )  of list functions

void test_end( ) ;
// test function for _end( )  of list functions

void test_empty( ) ;
// test function for _empty( )  of list functions

void test_insert_after( ) ;
//test function for _insert_after( )  of list function

void test_insert_before( ) ;
// test function for insert_before( )  of list functions

void test_insert_head( node<int>* &head_ptr) ;
// test function for insert_head( )  of list functions

void test_insert_last( ) ;
//test function for _insert_last( )  of list function

void test_index_of( ) ;
//test function for _index_of( )  of list function

void test_previous_node( ) ;
// test for the _previous_node( )  of list functions

void test_remove_head( ) ;
// test function for remove_head( )  of list functions

void test_remove_node( ) ;
// test for the _remove_node( )  of list functions

void test_search( ) ;
// test function for _search( )  of list functions

void test_size( ) ;
// test function for _size( )  of list functions

///======================================================
///  Definition
///======================================================

void test_at( ) 
{
    cout << endl << "\t ========== Test _at( )  ==========\n" << endl;
    node <int>* head_ptr = nullptr;
    test_insert_head( head_ptr) ;

    int pos = 4;

    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;
    cout << "------- test 1: pos = " << pos << " ---------" << endl;

    int item = _at<int>( head_ptr, pos) ;
    cout << "Node @ " << pos << " = ["
         << item <<  "]" << endl << endl;

    pos = -5;

    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;
    cout << "------- test 2: pos = " << pos << " ---------" << endl;
    cout << "Since pos is invalid, assert must terminate program"
         << endl << endl;
//    item = _at<int>( head_ptr, pos) ;
    item = _at<int>( head_ptr, pos) ;
    cout << "Node @ " << pos << " = [" << item <<  "]" << endl << endl;
    cout <<  "\t ========== end of Test _at( )  ==========\n" << endl;
}

void test_beginning( ) 
{
    cout << endl;
    cout << "\t========== Test _beginning( )  ==========\n" << endl;
    node <int>* head_ptr = nullptr;

    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;
    cout << "------- test 1: empty list  ---------" << endl;
    node<int>* begin = _beginning( head_ptr) ;

    if( begin == nullptr) 
        cout << "List is empty" << endl;
    else
        cout << "Beginning node is [" << begin -> _item <<"]" << endl;


    test_insert_head( head_ptr) ;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;
    cout << "------- test 2: 5 items in the list  ---------" << endl;


    begin = _beginning( head_ptr) ;

    if( begin == nullptr) 
        cout << "List is empty" << endl << endl;
    else
        cout << "Beginning node is [" << begin -> _item <<"]\n" << endl;
    cout << "   ========= end of Test _beginning ==========\n" << endl;
}

void test_clear_list( ) 
{
    cout << "\n\t========== Test _clear_list( )  ==========\n" << endl;

    node <int>* head_ptr = nullptr;
    test_insert_head( head_ptr) ;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    _clear_list( head_ptr) ;
    cout <<"List  after _clear_list( ) : " << endl << "       " ;
    _print( head_ptr) ;

    cout << "   ======= end of Test _clear_list( )  =======\n" << endl;
}

void test_copy_list( ) 
{
    cout << "\n\t========== Test _copy_list( )  ==========\n\n";

    node <int>* head_ptr = nullptr;
    test_insert_head( head_ptr) ;

   node<int>* dest_head_ptr = nullptr;
   node<int>* dest_end = _copy_list( head_ptr,dest_head_ptr) ;

   cout <<"src List : " << endl << "       " ;
   _print( head_ptr) ;
   cout <<"Dest List : " << endl << "       " ;
   _print( dest_head_ptr) ;

   cout << "\n-----Checking uniquness of two lists------\n";
   node<int>* src_end = _insert_last( head_ptr, 100) ;
   dest_end = _insert_last( dest_head_ptr, 200) ;

   cout << "Src list after insert_last( 100) :" << endl << "       " ;
   _print( dest_head_ptr) ;
    cout << "Dest list after insert_last( 67) :" << endl << "       " ;
   _print( dest_head_ptr) ;


   cout << "Src_end = : [" << src_end ->_item <<"]" << endl;
   cout << "Dest_edn = : [" << dest_end ->_item <<"]" << endl;

    cout << "   ========== end of test _copy_list( )  ==========\n\n";
}

void test_end( ) 
{
    cout <<"\n\t========== Test _end( )  ==========\n" << endl;
    node <int>* head_ptr = nullptr;

    cout << "------- test 1: empty list  ---------" << endl;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    node<int>* end = _end( head_ptr) ;

    if( end == nullptr) 
        cout << "List is empty" << endl << endl;
    else
        cout << "End node is [" << end -> _item <<"]\n" << endl;


    cout << "------- test 2: 5 items in the list  ---------" << endl;
    test_insert_head( head_ptr) ;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;
    end = _end( head_ptr) ;

    if( end == nullptr) 
        cout << "List is empty" << endl << endl;
    else
        cout << "End node is [" << end -> _item <<"]\n" << endl;
    cout << "\t========== end of Test _end( )  ==========\n" << endl;
}

void test_empty( ) 
{
    cout <<"\n\t========== Test _empty( )  ==========\n" << endl;
    node <int>* head_ptr = nullptr;

    cout << "------- test 1: empty list  ---------" << endl;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;
    bool is_empty = _empty( head_ptr) ;

    if( is_empty) 
        cout << "List is empty" << endl << endl;
    else
        cout << "List is not empty" << endl << endl;

    test_insert_head( head_ptr) ;
    cout << "------- test 2: 5 items in the list  ---------\n" << endl;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;
    is_empty = _empty( head_ptr) ;

    if( is_empty) 
        cout << "List is empty" << endl << endl;
    else
        cout << "List is not empty" << endl << endl;
    cout <<"\n\t========== end of Test _empty( )  ==========\n" << endl;

}

void test_insert_after( ) 
{
    cout <<"\n\t========== Test _insert_after( )  ==========\n\n";

    node <int>* head_ptr = nullptr;
    node <int>* iMarker = nullptr; // holds desired node
    node<int>* inserted = nullptr; // holds node after inserted

    int item = 120;   int key = 40;
    cout << "--- test 1: Insert " << item <<" after empty list ---\n\n";
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    inserted = _insert_after<int>( head_ptr,iMarker,item) ;
    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout <<"List after insert_after( ) : " << endl << "       " ;
    _print( head_ptr) ;

    //=   =   =   =   =   =   =   =   =   =   =


    test_insert_head( head_ptr) ;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    item = 12;     key = 120;
    cout << "--- test 2: Insert " << item <<" after ["<< key<< "]---\n\n";

    iMarker = _search( head_ptr, key) ;
    inserted = _insert_after<int>( head_ptr,iMarker,item) ;

    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout <<"List after insert_after( ) : " << endl << "       " ;
    _print( head_ptr) ;

  //=   =   =   =   =   =   =   =   =   =   =

    item = 123;     key = 20;
    cout << "--- test 3: Insert " << item <<" after ["<< key<< "]---\n\n";


    iMarker = _search( head_ptr, key) ;
    inserted = _insert_after<int>( head_ptr,iMarker,item) ;

    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout <<"List after insert_after( ) : " << endl << "       " ;
    _print( head_ptr) ;

//=  =   =   =   =   =   =   =   =   =   =
    item = 1400;
    cout << "--- test 4: Insert " << item <<" after NULL -----\n\n";
    cout << "After the next line assert from _insert_after( )  "
         << "must stop program " << endl << endl;

    iMarker = nullptr;
    inserted = _insert_after<int>( head_ptr, iMarker, item) ;
    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout <<"List after insert_after( ) : " << endl << "       " ;
    _print( head_ptr) ;

    cout << "\t======== end of test _insert_after( ) =========\n\n";
}

void test_insert_before( ) 
{
    cout <<"\n\t========== Test _insert_before( )  ==========\n\n";

    node <int>* head_ptr = nullptr; // head to the list
    node <int>* iMarker = nullptr; // holds the address to insert before
    node <int>* inserted = nullptr; // holds address to the inserted node


    int item = 120;   // item to be inserted
    int key = 40;    // item previous to soon to be inserted node
    cout << "--- test 1: Insert " << item <<" before empty list ---\n\n";
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    inserted = _insert_before<int>( head_ptr,iMarker,item) ;

    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout <<"List after insert_before( ) : " << endl << "       " ;
    _print( head_ptr) ;


    test_insert_head( head_ptr) ;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

//----------------------------------------------------------------
    item = 360;     key = 0;
    cout << "--- test 2: Insert " << item <<" before ["<< key<< "]---\n\n";
    iMarker = _search( head_ptr, key) ;
    inserted = _insert_before<int>( head_ptr, iMarker, item) ;


    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout <<"List after insert_before( ) : " << endl << "       " ;
    _print( head_ptr) ;

//----------------------------------------------------------------
    item = 720;     key = 40;
    cout << "--- test 3: Insert " << item <<" before ["<< key<< "]---\n\n";
    iMarker = _search( head_ptr, key) ;
    inserted = _insert_before<int>( head_ptr, iMarker, item) ;

    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

//----------------------------------------------------------------
    item = 24;     key = 70;
    cout << "--- test 4: Insert " << item <<" before ["<< key<< "]---\n\n";
    iMarker = _search( head_ptr, key) ;

    cout << "After this assert from _previous_node( )  must" << endl
          << "terminate program since iMarker is not in the list\n";
    inserted = _insert_before<int>( head_ptr, iMarker, item) ;

    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout <<"List after insert_before( ) : " << endl << "       " ;
    _print( head_ptr) ;

    cout << "\n\t======== end of test _insert_before( ) =========\n\n";

}

void test_insert_head( node<int>* &head_ptr) 
{

    cout << "Inserting 5 items" << endl;
    for( int i = 0; i < 5; i++) 
    {
        _insert_head<int>( head_ptr, i*10) ;
    }

//    cout <<"List : " << endl << "       " ;
//    _print( head_ptr) ;
}

void test_insert_last( ) 
{
    cout <<"\n\t======== Test _insert_last( )  ========" << endl;
    node<int>* head_ptr = nullptr;

    int key = 60;

    cout << "List :" << endl << "        ";
    _print( head_ptr) ;
    cout << "----- Test 1: insert ["<< key <<"] in an emtpy list" << endl;
    node<int>* end_node = _insert_last<int>( head_ptr, key) ;

    cout << "Last node: = [" << end_node->_item <<"]" << endl;
    cout << "List after _insert_last( ) " << endl << "        ";
    _print( head_ptr) ;

    test_insert_head( head_ptr) ;
    cout << "List after _insert_head( ) :" << endl << "        ";
    _print( head_ptr) ;

//-----------------------------------------------------------------
    key = 24;
    cout << "----- Test 2: insert ["<<key<<"] in a list of 6 items\n";
    end_node = _insert_last<int>( head_ptr, key) ;

    cout << "Last node: = [" << end_node->_item <<"]" << endl;
    cout << "List after _insert_last( ) " << endl << "        ";
    _print( head_ptr) ;

    cout << "\n\t========== end of test _insert_last( ) ==========\n";
}

void test_index_of( ) 
{
    cout << "\n    ========== Test _index_of( )  ==========\n\n";

    node <int>* head_ptr = nullptr;
    test_insert_head( head_ptr) ;
    node <int>* iMarker = nullptr; // holds address of inserted node

    int key = 70;
    cout << "---- test 1: Index of ["<< key <<"] ---" << endl << endl;
    cout << "List :" << endl << "        ";
    _print( head_ptr) ;

    iMarker = _search( head_ptr, key) ;
    int pos = _index_of( head_ptr, iMarker) ;

    if( pos < 0) 
        cout << key <<" key is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    key = 40;
    cout << "----- test 2: Index of ["<< key <<"] -----" << endl << endl;
    cout << "List: " << endl << "        ";
    _print( head_ptr) ;

    iMarker = _search( head_ptr, key) ;
    pos = _index_of( head_ptr, iMarker) ;

    if( pos < 0) 
        cout << key <<" key is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    cout << "    ========= end of test _index_of( )  =========\n" << endl;
}

void test_previous_node( ) 
{
    cout <<"\n   ======== Test _previous_node( )  ========" << endl;
    node<int>* head_ptr = nullptr;
    test_insert_head( head_ptr) ;

    int key = 40;
    cout << "List: " << endl << "        ";
    _print( head_ptr) ;
    cout << "----- test 1: previous to [" << key << "]-------" << endl;
    node<int>* iMarker = _search<int>( head_ptr, key) ;
    node<int>* previous = _previous_node( head_ptr, iMarker) ;

    if( previous == iMarker) 
        cout << "No previous node: head_ptr only" << endl << endl;
     else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;

    key = 0;
    cout << "List: " << endl << "        ";
    _print( head_ptr) ;
    cout << "----- test 2: previous to [" << key << "]-------" << endl;
    iMarker = _search<int>( head_ptr, key) ;
    previous = _previous_node( head_ptr, iMarker) ;

    if( previous == iMarker) 
        cout << "No previous node: head_ptr only" << endl << endl;
     else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;


    key = 90;
    cout << "----- test 3: previous to [" << key << "]-------" << endl;
    iMarker = _search<int>( head_ptr, key) ;
    cout << "After this line assert from _previous_node must"<< endl
         << "end program since node doesn't exist" << endl << endl;
    previous = _previous_node( head_ptr, iMarker) ;

    if( previous == iMarker) 
        cout << "No previous node: head_ptr only" << endl << endl;
     else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;


//    key = 70;
//    cout << "----- test 4: previous to [" << key << "]-------" << endl;
//    iMarker = new node<int>( key) ;
//    //     giving it a new node that exists but not in the same list
//    cout << "iMarker is a node but it does't exist in the list";

//    cout << "After this assert from _previous_node must end"<< endl
//         << "program since node is not in the same list" << endl
//    << endl;

//    previous = _previous_node( head_ptr, iMarker) ;

//    if( previous == iMarker) 
//        cout << "No previous node: head_ptr only" << endl << endl;
//     else
//        cout << "Node before [" << iMarker->_item << "] is: ["
//             << previous ->_item << "]" << endl << endl;

    cout << "    ========== END OF test_previous_node( ) ==========\n\n";
}

void test_remove_head( ) 
{
    cout << "\n\t========== Test _remove_head( )  ==========\n" << endl;
    node <int>* head_ptr = nullptr;

    test_insert_head( head_ptr) ;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    for( int i = 0;  i < 7; i++)  // list only has 5 elements
    {
        int removed = _remove_head<int>( head_ptr) ;
        cout << "Removed item number = " << i << endl;

        if(  removed ) {
            cout << "Removed item = " <<  removed << endl;
            cout << "List after remove_node:" << endl;
            _print( head_ptr) ;
        }

        else{
            cout << "Nothing to remove from list. Break loop"
                 << endl << endl;
            break;
        }
    }

    cout << "    ======== end of test _remove_head( )  ========\n" << endl;
}

void test_remove_node( ) 
{
    cout << "\n\t========== Test _remove_head( )  ==========\n" << endl;
    node<int>* head_ptr = nullptr;

    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    int key = 30;
    cout << "----test 1: remove[" << key <<"] from empty list" << endl;

    node<int>* nodeToRemove = _search<int>( head_ptr, key) ;

    int removed_item = _remove_node( head_ptr, nodeToRemove) ;

    if( removed_item ) {
        cout << "Removed item = " <<  removed_item << endl;
        cout << "List after remove_node:" << endl;
        _print( head_ptr) ;
    }

    else
        cout << "Nothing to remove from list" << endl << endl;


    test_insert_head( head_ptr) ;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    key = 40;
    cout << "---------test 2: remove [" << key <<"]---------" << endl;
    nodeToRemove = _search<int>( head_ptr, key) ;
    assert( nodeToRemove != nullptr) ;
    removed_item = _remove_node( head_ptr, nodeToRemove) ;

    if ( removed_item )    {
        cout << "Removed item = " <<  removed_item << endl;
        cout << "Printing new list:" << endl;
        _print( head_ptr) ;
    }

    else
        cout << "Nothing to remove from list" << endl << endl;

    key = 0;
    cout << "---------test 3: remove [" << key <<"]---------" << endl;
    nodeToRemove = _search<int>( head_ptr, key) ;
    assert( nodeToRemove != nullptr) ;
    removed_item = _remove_node( head_ptr, nodeToRemove) ;

    if( removed_item) 
        cout << "Nothing to remove from list" << endl << endl;
    else{
        cout << "Removed item = " <<  removed_item << endl;
        cout << "Printing new list:" << endl;
        _print( head_ptr) ;
    }

    key = 10;
    cout << "---------test 4: remove [" << key <<"]---------" << endl;
    nodeToRemove = _search<int>( head_ptr, key) ;
    assert( nodeToRemove != nullptr) ;
    removed_item = _remove_node( head_ptr, nodeToRemove) ;

    if ( removed_item )   {
        cout << "Removed item = " <<  removed_item << endl;
        cout << "Printing new list:" << endl;
        _print( head_ptr) ;
    }
    else
        cout << "Nothing to remove from list" << endl << endl;

    key = 60;
    cout << "---------test 5: remove [" << key <<"]---------" << endl;
    nodeToRemove = _search<int>( head_ptr, key) ;
    cout << "Node doesn't exist. Assert from _previous_node( ) " << endl
         << "must terminate program" << endl << endl;
    removed_item = _remove_node( head_ptr, nodeToRemove) ;

    if ( removed_item )   {
        cout << "Removed item = " <<  removed_item << endl;
        cout << "Printing new list:" << endl;
        _print( head_ptr) ;
    }
    else
        cout << "Nothing to remove from list" << endl << endl;

    cout << "========== END OF test_remove_node =========="
         << endl << endl;

}

void test_search( ) 
{
    cout <<"\n\n\t=========== test _search( )  ===========\n" << endl;
    node <int>* head_ptr = nullptr;
    test_insert_head( head_ptr) ;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;


    int key = 12;
    cout << "---------- Test 1: key = " << key<< " ----------" << endl;
    node<int>* temp = _search<int>( head_ptr, key) ;

    if(  temp  == nullptr) 
        cout << key << " is not found" << endl << endl;
    else
        cout << "printing searched item: " << *temp << endl << endl;

     key = 40;
     cout <<"List : " << endl << "       " ;
     _print( head_ptr) ;

     cout << "---------- Test 2: key = " << key<< " ----------" << endl;

     temp = _search<int>( head_ptr, key) ;

    if(  temp  == nullptr) 
        cout <<key << " is not found" << endl << endl;
    else
        cout << "printing searched item: " << *temp << endl << endl;

    key = 0;
    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    cout << "---------- Test 3: key = " << key << " ----------\n";
    temp = _search<int>( head_ptr, key) ;

     if(  temp  == nullptr) 
         cout <<key << " is not found" << endl << endl;
     else
         cout << "printing searched item: " << *temp << endl << endl;

    cout << "\t============ end of test_search ============\n" << endl;

}

void test_size( ) 
{
    cout <<"\n\n    =========== test _size( )  ===========\n" << endl;
    node <int>* head_ptr = nullptr;

    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;

    cout << "---------- Test 1: empty list ----------" << endl;
    int size = _size<int>( head_ptr) ;
    cout << "\nSize of the list is: " << size << endl << endl;

    test_insert_head( head_ptr) ; //inserting 5 items in list

    cout <<"List : " << endl << "       " ;
    _print( head_ptr) ;
    cout << "---------- Test 2: list of 5 items----------" << endl;
    size = _size<int>( head_ptr) ;
    cout << "\nSize of the list is: " << size << endl << endl;

    cout <<"    =========== end of test _size( )  ===========\n" << endl;
}


#endif // LINKED_LIST_TEST_H
