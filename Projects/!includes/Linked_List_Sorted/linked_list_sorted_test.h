#ifndef LIST_LIST_SORTED_TEST_H
#define LIST_LIST_SORTED_TEST_H

#include <iostream>

#include "../../!includes/Linked_List_Sorted/linked_list_sorted.h"

using namespace std;


void test_at();
//test function for _at() of list functions

void test_begin();
// test function for _beginning() of list functions

void test_clear_list();
//test function for _clear_list() of list functions

void test_copy_list();
//test function for _copy_list() of list functions

void test_end();
// test function for _end() of list functions

void test_empty();
// test function for _empty() of list functions

void test_insert();
// test functionf or _insert() of list functions

void test_insert_after();
//test function for _insert_after() of list function

void test_insert_head(node<int>* &head_ptr);
// test function for insert_head() of list functions

void test_index_of();
//test function for _index_of() of list function

void test_previous_node();
// test for the _previous_node() of list functions

void test_remove_head();
// test function for remove_head() of list functions

void test_remove_node();
// test for the _remove_node() of list functions

void test_search();
// test function for _search() of list functions

void test_size();
// test function for _size() of list functions

void test_where_this_goes();
// test function for _where_this_goes() of list functions

//=====================================
//  Definition
//=====================================

void test_at()
{
    cout << endl << "\t ========== Test _at() ==========\n" << endl;
    node <int>* head_ptr = nullptr;
    test_insert_head(head_ptr);

    int pos = 4;
    cout << "------- test 1: pos = " << pos << " ---------" << endl;

    int item = _at<int>(head_ptr, pos);
    cout << "Node @ " << pos << " = [" << item <<  "]" << endl << endl;

    pos = -5;
    cout << "------- test 2: pos = " << pos << " ---------" << endl;

    item = _at<int>(head_ptr, pos);
    cout << "Node @ " << pos << " = [" << item <<  "]" << endl << endl;
}

void test_begin()
{
    cout << endl;
    cout << "\t========== Test _begin() ==========\n" << endl;
    node <int>* head_ptr = nullptr;

    cout << "------- test 1: empty list  ---------" << endl;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    node<int>* begin = _begin(head_ptr);

    if(begin == nullptr)
        cout << "List is empty" << endl;
    else
        cout << "Beginning node is [" << begin -> _item <<"]" << endl;

    cout << "------- test 2: 5 items in the list  ---------" << endl;
    test_insert_head(head_ptr);
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    begin = _begin(head_ptr);

    if(begin == nullptr)
        cout << "List is empty" << endl;
    else
        cout << "Beginning node is [" << begin -> _item <<"]" << endl;

    cout << "\t========== end of Test _begin() ==========\n" << endl;
}

void test_clear_list()
{
    cout << "\n\t========== Test _clear_list() ==========\n" << endl;

    node <int>* head_ptr = nullptr;
    test_insert_head(head_ptr);
    cout <<"myList: " << endl << "      " ;
    _print(head_ptr);
    _clear_list(head_ptr);

    cout << "Printing list after _clear_list()" << endl;
    cout <<"myList: " << endl << "      " ;
    _print(head_ptr);
    cout << "   ========== end of test _clear_list() ==========\n" << endl;
}

void test_copy_list()
{
    cout << "\n\t========== Test _copy_list() ==========\n\n";

    node <int>* head_ptr = nullptr;
    test_insert_head(head_ptr);
    cout <<"myList: " << endl << "      " ;
    _print(head_ptr);

    node<int>* dest_head_ptr = nullptr;
    _copy_list(head_ptr,dest_head_ptr);

    cout << "========== printing src list ==========" << endl;
    cout <<"src list: " << endl << "      " ;
    _print(head_ptr);
    cout << "========== printing dest list ==========" << endl;
    cout <<"dest list: " << endl << "      " ;
    _print(dest_head_ptr);


    cout << "\n-----Checking if two list are separate lists------\n";
    _insert_head(head_ptr, 1000);
    cout << "src list after _insert_head(1000)" << endl << "     ";

    _insert_head(dest_head_ptr, 5000);
    cout << "dest list after _insert_head(5000)" << endl << "     ";
    _print(dest_head_ptr);

    cout << "   ========== end of test _copy_list() ==========\n\n";
    _print(head_ptr);
}

void test_end()
{
    cout <<"\n\t========== Test _end() ==========\n" << endl;
    node <int>* head_ptr = nullptr;

    cout << "------- test 1: empty list  ---------" << endl;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    node<int>* end = _end(head_ptr);

    if(end == nullptr)
        cout << "List is empty" << endl << endl;
    else
        cout << "End node is [" << end -> _item <<"]\n" << endl;


    cout << "------- test 2: 5 items in the list  ---------" << endl;
    test_insert_head(head_ptr);
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    end = _end(head_ptr);

    if(end == nullptr)
        cout << "List is empty" << endl << endl;
    else
        cout << "End node is [" << end -> _item <<"]\n" << endl;

    cout <<"\n\t========== end of Test _end() ==========\n" << endl;
}

void test_empty()
{
    cout <<"\n\t========== Test _empty() ==========\n" << endl;
    node <int>* head_ptr = nullptr;

    cout << "------- test 1: empty list  ---------" << endl;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    bool is_empty = _empty(head_ptr);

    if(is_empty)
        cout << "List is empty" << endl << endl;
    else
        cout << "List is not empty" << endl << endl;

    cout << "------- test 2: 5 items in the list  ---------\n" << endl;
    test_insert_head(head_ptr);
    cout << "myList = " << endl << "     ";
    _print(head_ptr);

    is_empty = _empty(head_ptr);

    if(is_empty)
        cout << "List is empty" << endl << endl;
    else
        cout << "List is not empty" << endl << endl;
    cout <<"\n\t========== end of Test _empty() ==========\n" << endl;
}

void test_insert()
{
    cout <<"\n\t========== Test _insert() ==========\n\n";

    node <int>* head_ptr = nullptr;
    node<int>* inserted = nullptr; // holds node after inserted

    _print(head_ptr);

    for(int i = 0; i < 10 ;i++)
    {
        int r = rand () % 200;
        cout << "Inserting " << r << endl;
        inserted = _insert<int>(head_ptr, r, true);
        _print(head_ptr);
    }

    cout << "\t======== end of test _insert()=========\n\n";
}

void test_insert_after()
{
    cout <<"\n\t========== Test _insert_after() ==========\n\n";

    node <int>* head_ptr = nullptr;
    node <int>* iMarker = nullptr; // holds desired node
    node<int>* inserted = nullptr; // holds node after inserted

    int item = 120;   int key = 40;
    cout << "--- test 1: Insert " << item <<" after empty list ---\n\n";
    cout << "myList after " << endl << "      ";
    _print(head_ptr);

    inserted = _insert_after<int>(head_ptr,iMarker,item);
    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout << "myList after _insert_after() " << endl << "      ";
    _print(head_ptr);

    test_insert_head(head_ptr);
    item = 12;     key = 120;
    cout << "--- test 2: Insert " << item <<" after ["<< key<< "]---\n\n";

    iMarker = _search(head_ptr, key);
    inserted = _insert_after<int>(head_ptr, iMarker, item);
    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout << "myList after _insert_after() " << endl << "      ";
    _print(head_ptr);


    item = 123;     key = 20;
    cout << "--- test 3: Insert " << item <<" after ["<< key<< "]---\n\n";

    iMarker = _search(head_ptr, key);
    inserted = _insert_after<int>(head_ptr, iMarker, item);
    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout << "myList after _insert_after() " << endl << "      ";
    _print(head_ptr);

    item = 1400;
    cout << "--- test 4: Insert " << item <<" after NULL -----\n\n";
    cout << "After the next line assert from _insert_after() "
         << "must stop program " << endl;

    iMarker = nullptr;
    inserted = _insert_after<int>(head_ptr, iMarker, item);
    cout << "Inserted node: = [" << inserted->_item <<"]" << endl;
    cout << "myList after _insert_after() " << endl << "      ";
    _print(head_ptr);

    cout << "\t======== end of test _insert_after()=========\n\n";
}

void test_insert_head(node<int>* &head_ptr)
{
    for(int i = 0; i < 10; i++)    {
        _insert_head<int>(head_ptr, i*10);
    }
}

void test_index_of()
{
    cout << "\n    ========== Test _index_of() ==========\n\n";

    node <int>* head_ptr = nullptr;
    test_insert_head(head_ptr);
    node <int>* iMarker = nullptr; // holds address of inserted node

    int key = 70;
    cout << "---- test 1: Index of ["<< key <<"] ---" << endl << endl;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    iMarker = _search(head_ptr, key);
    int pos = _index_of(head_ptr, iMarker);

    if(pos < 0)
        cout << key <<" key is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    key = 40;
    cout << "----- test 2: Index of ["<< key <<"] -----" << endl << endl;
    iMarker = _search(head_ptr, key);
    pos = _index_of(head_ptr, iMarker);

    if(pos < 0)
        cout << key <<" key is not in the list" << endl << endl;
    else
        cout << "Index of [" << key << "] is " << pos << endl << endl;

    cout << "    ========= end of test _index_of() =========\n" << endl;
}

void test_previous_node()
{
    cout <<"\n   ======== Test _previous_node() ========" << endl;
    node<int>* head_ptr = nullptr;
    test_insert_head(head_ptr);
    cout << "myList = " << endl << "     ";
    _print(head_ptr);

    int key = 40;
    cout << "----- test 1: previous to [" << key << "]-------" << endl;
    node<int>* iMarker = _search<int>(head_ptr, key);
    node<int>* previous = _previous_node(head_ptr, iMarker);

    if(previous == iMarker)
        cout << "No previous node: head_ptr only" << endl << endl;
     else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;

    key = 0;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    cout << "----- test 2: previous to [" << key << "]-------" << endl;
    iMarker = _search<int>(head_ptr, key);
    previous = _previous_node(head_ptr, iMarker);

    if(previous == iMarker)
        cout << "No previous node: head_ptr only" << endl << endl;
     else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;


    key = 90;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    cout << "----- test 3: previous to [" << key << "]-------" << endl;
    iMarker = _search<int>(head_ptr, key);
    cout << "After this line assert from _previous_node must"<< endl
         << "end program since node doesn't exist" << endl << endl;
    previous = _previous_node(head_ptr, iMarker);

    if(previous == iMarker)
        cout << "No previous node: head_ptr only" << endl << endl;
     else
        cout << "Node before [" << iMarker->_item << "] is: ["
             << previous ->_item << "]" << endl << endl;


//    key = 70;
//    cout << "----- test 4: previous to [" << key << "]-------" << endl;
//    iMarker = new node<int>(key);
//    //     giving it a new node that exists but not in the same list
//    cout << "iMarker is a node but it does't exist in the list";

//    cout << "After this assert from _previous_node must end"<< endl
//         << "program since node is not in the same list" << endl << endl;

//    previous = _previous_node(head_ptr, iMarker);

//    if(previous == iMarker)
//        cout << "No previous node: head_ptr only" << endl << endl;
//     else
//        cout << "Node before [" << iMarker->_item << "] is: ["
//             << previous ->_item << "]" << endl << endl;

    cout << "    ========== END OF test_previous_node()==========\n\n";
}

void test_remove_head()
{
    cout << "\n\t========== Test _remove_head() ==========\n" << endl;
    node <int>* head_ptr = nullptr;
    test_insert_head(head_ptr);
    cout << "myList = " << endl << "     ";
    _print(head_ptr);

    for(int i = 0;  i < 6; i++) // list only has 5 elements
    {
        int item_removed = _remove_head<int>(head_ptr);

        if(item_removed < 0)
            cout << "list is empty" << endl;
        else
        {
            cout << "Printing removed item: "  << item_removed << endl;
            cout << "myList = " << endl << "     ";
            _print(head_ptr);
        }
    }

    cout <<"\n\t======== end of test _remove_head() ========\n" << endl;
}

void test_remove_node()
{
    cout << "\n\t========== Test _remove_head() ==========\n" << endl;
    node<int>* head_ptr = nullptr;

    int key = 30;
    cout << "----test 1: remove[" << key <<"] from empty list" << endl;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    node<int>* nodeToRemove = _search<int>(head_ptr, key);

    int removed_item = _remove_node(head_ptr, nodeToRemove);

    if(removed_item){
        cout << "Removed item = " <<  removed_item << endl;
        cout << "Printing new list:" << endl;
        _print(head_ptr);
    }
    else
        cout << "Nothing to remove from list" << endl << endl;

    test_insert_head(head_ptr);
    cout << "myList = " << endl << "     ";
    _print(head_ptr);

    key = 40;
    cout << "---------test 2: remove [" << key <<"]---------" << endl;
    nodeToRemove = _search<int>(head_ptr, key);
    assert(nodeToRemove != nullptr);
    removed_item = _remove_node(head_ptr, nodeToRemove);

    if(removed_item){
        cout << "Removed item = " <<  removed_item << endl;
        cout << "Printing new list:" << endl;
        _print(head_ptr);
    }
    else
        cout << "Nothing to remove from list" << endl << endl;

    key = 0;
    cout << "---------test 3: remove [" << key <<"]---------" << endl;
    nodeToRemove = _search<int>(head_ptr, key);
    assert(nodeToRemove != nullptr);
    removed_item = _remove_node(head_ptr, nodeToRemove);

    if(removed_item)
        cout << "Nothing to remove from list" << endl << endl;
    else{
        cout << "Removed item = " <<  removed_item << endl;
        cout << "Printing new list:" << endl;
        _print(head_ptr);
    }

    key = 10;
    cout << "---------test 4: remove [" << key <<"]---------" << endl;
    nodeToRemove = _search<int>(head_ptr, key);
    assert(nodeToRemove != nullptr);
    removed_item = _remove_node(head_ptr, nodeToRemove);

    if(removed_item){
        cout << "Removed item = " <<  removed_item << endl;
        cout << "Printing new list:" << endl;
        _print(head_ptr);
    }
    else
        cout << "Nothing to remove from list" << endl << endl;


    key = 60;
    cout << "---------test 5: remove [" << key <<"]---------" << endl;
    nodeToRemove = _search<int>(head_ptr, key);
    cout << "Node doesn't exist. Assert from _previous_node()" << endl
         << "must terminate program" << endl << endl;
    removed_item = _remove_node(head_ptr, nodeToRemove);

    if(removed_item){
        cout << "Removed item = " <<  removed_item << endl;
        cout << "Printing new list:" << endl;
        _print(head_ptr);
    }
    else
        cout << "Nothing to remove from list" << endl << endl;


    cout << "========== END OF test_remove_node =========="
         << endl << endl;

}

void test_search()
{
    cout <<"\n\n\t=========== test _search() ===========\n" << endl;
    node <int>* head_ptr = nullptr;
    test_insert_head(head_ptr);

    int key = 12;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    cout << "---------- Test 1: key = " << key<< " ----------" << endl;
    node<int>* temp = _search<int>(head_ptr, key);

    if( temp  == nullptr)
        cout << key << " is not found" << endl << endl;
    else
        cout << "searched item = " << temp->_item << endl << endl;

     key = 40;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
     cout << "---------- Test 2: key = " << key<< " ----------" << endl;

     temp = _search<int>(head_ptr, key);

    if( temp  == nullptr)
        cout <<key << " is not found" << endl << endl;
    else
        cout << "searched item = " << temp->_item << endl << endl;

    key = 0;
    cout << "---------- Test 3: key = " << key << " ----------\n";
    temp = _search<int>(head_ptr, key);

     if( temp  == nullptr)
         cout <<key << " is not found" << endl << endl;
     else
        cout << "searched item = " << temp->_item << endl << endl;

    cout << "\t============ end of test_search ============\n" << endl;

}

void test_size()
{
    cout <<"\n\n    =========== test _size() ===========\n" << endl;
    node <int>* head_ptr = nullptr;


    cout << "---------- Test 1: empty list ----------" << endl;
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    int size = _size<int>(head_ptr);
    cout << "\nSize of the list is: " << size << endl << endl;

    test_insert_head(head_ptr); //inserting 5 items in list
    cout << "myList = " << endl << "     ";
    _print(head_ptr);
    cout << "---------- Test 2: list of 10 items----------" << endl;
    size = _size<int>(head_ptr);
    cout << "\nSize of the list is: " << size << endl << endl;

    cout <<"    =========== end of test _size() ===========\n" << endl;
}

void test_where_this_goes()
{
    cout << endl << "\t ======= Test _where_this_goes() ======\n" << endl;
    node<int>* head_ptr = nullptr;
    node<int>* iMarker = nullptr;
    int key ;   bool order;


    cout << "   TEST I: ACSENDING ORDER " << endl;

    key = 25;       order = true;
    cout << "----------- Test 1: ----------- " << endl;
    _print(head_ptr);
    cout << "Where " << key << " go in empty list" << endl;

    iMarker = _where_this_goes<int>(head_ptr, key, order);
    if(iMarker)
        cout << "It goes after " << iMarker ->_item << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;

    key = 25;
    cout << "----------- Test 2: ----------- " << endl;
    cout << "Inserting the following items: " << endl << "  ";
    for(int i = 0; i < 15; i++)
    {
        int num = rand() % 300;
        cout << ": "  << num;
        _insert(head_ptr, num , true);
//        _print(head_ptr);
    }
    cout << endl;
    _print(head_ptr);

    cout << "Where " << key << " go in a list of 15 item list" << endl;

    iMarker = _where_this_goes<int>(head_ptr, key, order);
    if(iMarker)
        cout << "It goes after " << iMarker ->_item << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;


    key = -40;
    cout << "----------- Test 3: ----------- " << endl;
    _print(head_ptr);
    cout << "Where " << key << " go in a list of 5 item list" << endl;


    iMarker = _where_this_goes<int>(head_ptr, key, order);
    if(iMarker)
        cout << "It goes after " << iMarker ->_item << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;


    order = false;
    cout << "==================================================\n"
         << "==================================================\n";
    cout << "       TEST II: DESCENDING ORDER " << endl << endl;
    _clear_list(head_ptr);
    _print(head_ptr);


    cout << "----------- Test 1: ----------- " << endl;
    key = -40;
    cout << "Where " << key << " go in empty list" << endl;

    iMarker = _where_this_goes<int>(head_ptr, key, order);
    if(iMarker)
        cout << "It goes after " << iMarker ->_item << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;
    _insert(head_ptr, key, false);


    cout << "----------- Test 2: ----------- " << endl;
    key = -55;
    cout << "Inserting the following items: " << endl << "  ";
    for(int i = 0; i < 15; i++)
    {
        int num = rand() % 300;
        cout << ": "  << num;
        _insert(head_ptr, num , false);
    }
    cout << endl;
    _print(head_ptr);

    cout << "Where " << key << " go in a list of 15 item list" << endl;

    _insert(head_ptr, key, false);
    iMarker = _where_this_goes<int>(head_ptr, key, order);
    if(iMarker)
        cout << "It goes after " << iMarker ->_item << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;



    cout << "----------- Test 3: ----------- " << endl;
    key = -20;
    _print(head_ptr);
    cout << "Where " << key << " go in a list of 5 item list" << endl;

    iMarker = _where_this_goes<int>(head_ptr, key, order);
    if(iMarker != nullptr)
        cout << "It goes after " << iMarker ->_item << endl << endl;
    else
        cout << "It goes as head ptr " << endl << endl;

    cout << "     ======= end of test _where_this_goes() ======\n" << endl;

}


#endif // LIST_LIST_SORTED_TEST_H
