#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H

#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
struct node{

    T _item;
    node* _next;

    node(const T& item = T(), node* next = nullptr);

   template <typename U>
   friend std::ostream& operator <<(std::ostream& outs,
                                    const node<U> &printMe);

};


//===========================================
//      Definitions
//===========================================

template <typename T>
node <T>::node(const T& item, node <T>* next)
{
    _item = item;
    _next = next;
}

template <typename U>
std::ostream& operator <<(std::ostream& outs, const node<U> &printMe)
{
    outs << "[" << printMe._item << "]->" ;
    return outs;
}
//====================================================================
//          list functions declarations
//====================================================================


template <typename T>
T& _at(node<T>* head_ptr, int position);
//Precondition: takes type T head pointer to a node and position
//Postcondition: returns item at position in the list

template <typename T>
node<T>* _begin(node<T>* head_ptr);
//Precondition: takes type T head pointer to a node
//Postcondition: returns first node

template <typename T>
void _clear_list(node<T>* &head_ptr);
//Precondition: takes type T head pointer to a node
//Postcondition: releases the space occupied by list;

template <typename T>
node<T>* _copy_list(node<T>* src_head, node<T>* &dest_head);
//Precondition: takes 2 type T head_ptrs to a node
//Postcondition: copies the list to a new node and
//               returns the end node of the new_list

template <typename T>
node<T>* _end(node<T>* head_ptr);
//Precondition: takes type T head pointer to a node
//Postcondition: returns last node before nullptr

template <typename T>
bool _empty(node<T>* head_ptr);
//Precondition: takes type T head pointer to a node
//Postcondition: returns true if list is empty else false

template <typename T>
int _index_of(node<T>* head_ptr, node<T>* iMarker);
//Precondition: takes a type T head_ptr to a node
//              and a ptr to a node
//Postcondition: returns position of node

template <typename T>
node<T>* _insert(node<T>* &head_ptr, const T& insert_this,
                                     const bool order);
//Precondition: takes a type T head_ptr, aT variable to insert
//              and bool with the order of inserted items
//Postcondition: a new node with insert_this is made and is
//               inserted in an ascending or descending order
//               returns ptr to inserted node;

template <typename T>
node<T>* _insert_after(node<T>* &head_ptr, node<T>* mark,
                       const T& insert_this);
//Precondition: takes two type T ptrs, and T variable to insert
//Postcondition: a new node is made out of insert_this and
//              is inserted after node mark and
//              returns ptr to inserted node;

template <typename T>
void _insert_head(node<T>* &head_ptr, const T& insert_this);
//Precondition: takes type T ptr, and T variable to insert
//Postcondition: a new node is made out of insert_this and
//              is inserted before all other nodes at the
//              head of list


template <typename T>
node<T>* _previous_node(node<T>* head_ptr, node<T>* iMarker);
//Precondition: takes two type T node ptrs
//Postcondition: returns adress of node before iMarker node

template <typename T>
void _print(node<T>* head_ptr , ostream& outs = cout);
//Precondition: takes type T node head ptr
//Postcondition: prints all items until nullptr

template  <typename T>
T _remove_head(node<T>* &head_ptr);
//Precondition: takes type T head_ptr
//Postcondition: delete first node and returns the value item had

template  <typename T>
T _remove_node(node<T>* &head_ptr, node<T>* remove_me);
//Precondition: takes type T head_ptr, and node to be removed
//Postcondition: deletes node and returns the value item had

template <typename T>
node <T>* _search(node<T>* head_ptr, const T& key);
//Precondition: takes type T head_ptr, and item we are looking for
//Postcondition: return address of key if found or return nullptr

template  <typename T>
int _size(node<T>* head_ptr);
//Precondition: takes type T head_ptr to a list
//Postcondition: return size of the list

template  <typename T>
node<T>* _where_this_goes(node<T>* head_ptr, const T& item, bool order);
//Precondition: takes type T head_ptr, and item to be inserted and a
//              bool indicating whether order is ascending or descending
//Postcondition: returns the address after which new node'll be inserted



//====================================================================
//          list functions Definitions
//====================================================================

template <typename T>
T& _at(node<T>* head_ptr, int position)
{
    /*
     * 1. assert list is not empty
     * 2. walk thru list till nullptr
     * 3. if position is within count of walk
     *      length return item else assert
     */
    const bool debug = false;
    assert(head_ptr != nullptr && position >= 0);

    node<T>* walker = head_ptr;
    int count = 0;

    while(walker != nullptr)
    {
        if(count == position)
        {
            if(debug)
            {
                cout << "Inside _at():" << endl;
                cout << "Node at " << position << " = ["
                     << walker -> _item << "] \n" << endl;
            }

            return walker -> _item;
        }

        walker = walker -> _next;
        count ++;
    }

    if(debug)
    {
        cout << "Inside _at():" << endl;
        cout << "Node at " << position << " doesn't exist\n";
    }
    assert(walker != nullptr);
    abort();
}

template <typename T>
node<T>* _begin(node<T>* head_ptr)
{
    /*
     * 1. return first node
     */
    node<T>* walker = head_ptr;
    return walker;

}

template <typename T>
void _clear_list(node<T>* &head_ptr)
{
    /*
     * 1. if list is not empty, remove the head node until
     *    list is empty
     * 2. set head_ptr to null
     */
    const bool debug = false;

    while(head_ptr != nullptr)
    {
        T hold = _remove_head(head_ptr);

        if(debug){
            cout << "Inside _clear_list()" << endl;
            cout << "\tRemoved node" << "[" << hold << "]" << endl;
        }

    }

    head_ptr = nullptr;
}

template <typename T>
node<T>* _copy_list(node<T>* src_head, node<T>* &dest_head)
{
    /*
     * 1. create a new head ptr;
     * 2. walk thru src_list and pass item and new head_ptr to
     *    _insert_last()
     */

    const bool debug = false;

    node<T>* src_walker = src_head;
    node<T>* dest_walker = dest_head;

    while(src_walker != nullptr)
    {
        dest_walker = _insert_after(dest_head,dest_walker, src_walker->_item);

        if(debug)
        {
            cout << "Inside _copy_list():   copying :["
                 << src_walker ->_item << "]" <<  endl;
            cout << "\tdest_walker = [" << dest_walker->_item <<"]\n";
        }
        src_walker = src_walker ->_next;
    }

    return dest_walker;

}

template <typename T>
node<T>* _end(node<T>* head_ptr)
{
    /*
     * 1. if list empty return nullptr
     * 2. else return last node
     */
    const bool debug = false;
    node<T>* walker = head_ptr;

    if(walker == nullptr)
    {
        if(debug)
        {
            cout << "Inside _end():" << endl << "List is empty"
                 << " Returning nullptr" << endl << endl;
        }
         return nullptr;
    }

    else
    {
        while( walker ->_next != nullptr)
        {
            walker = walker -> _next;
        }
        if(debug)
        {
            cout << "Inside _end():" << endl << "List exists"
                 << " returning last node" << endl << endl;
        }
        return walker;
    }
}

template <typename T>
bool _empty(node<T>* head_ptr)
{
    /*
     * 1. if list empty return true
     * 2. else return false
     */
    const bool debug = false;
    if(head_ptr == nullptr) {
        if(debug)
            cout << "Inside _empty():\t Returning true" << endl << endl;
        return true;
    }

    else {
        if(debug)
            cout << "Inside _empty():\t Returning false" << endl << endl;
        return false;
    }

}

template <typename T>
int _index_of(node<T>* head_ptr, node<T>* iMarker)
{
    /*
     * 1. get a walker and walk thru all the nodes
     * 3. look for iMarker node and
     * 4. return the position it is located at or return Null
     */

    node<T>* walker = head_ptr;
    int count = 0;
    while(walker != nullptr && iMarker != nullptr)
    {
        if(walker == iMarker)
            return count ;

        walker = walker ->_next;
        count++;
    }

    return -1;

}

template <typename T>
node<T>* _insert(node<T>* &head_ptr, const T& insert_this,
                 const bool order)
{
    const bool debug = false;

    node<T>* iMarker = _where_this_goes(head_ptr, insert_this, order);

    if(iMarker == nullptr)
    {
        if(debug){
            cout << "Inside _insert():" << endl << "    "
                 << "_insert_head()" << endl << endl;
        }
        _insert_head(head_ptr, insert_this);
        return head_ptr;
    }
    else
    {
        if(debug){
            cout << "Inside _insert():" << endl << "    "
                 << "_insert_after()" << iMarker ->_item
                 << endl << endl;
        }
        return _insert_after(head_ptr, iMarker, insert_this);
    }
}


template <typename T>
node<T>* _insert_after(node<T>* &head_ptr, node<T>* mark,
                       const T& insert_this)
{
    /* CASE 1
     * if list is empty(head is null), insert node as the head node
     * CASE 2
     * 1. create a new node
     * 2. new node's next points to where afterThis is pointing to
     * 3. afterThis points to the new node
     */

    const bool debug = false;

    if( head_ptr == nullptr)
    {
        if(debug)
        {
            cout << endl<< "Inside _insert_after()" << endl;
            cout << "   head_ptr is null. _insert_head()\n" << endl;
        }
        _insert_head(head_ptr, insert_this);
        return head_ptr;
    }
    assert(mark != nullptr);
    // asserts mark is in the list


    node <T>* temp = new node<T> (insert_this);
    temp -> _next = mark-> _next;
    mark-> _next = temp;
    if(debug)
    {
        cout << endl << "Inside _insert_after()" << endl;
        cout << "       Inserting [" << insert_this <<"] after ["
             << mark ->_item << "]" << endl << endl;
    }
    return temp;
}

template <typename T>
void _insert_head( node<T>* &head_ptr, const T& insert_this)
{
    /*
     * 1. create a new node
     * 2. new node's next points to where head_ptr is pointing to
     * 3. head_ptr points to the new node
     */

    node <T>* temp = new node<T> (insert_this);
    temp -> _next = head_ptr;
    head_ptr = temp;
}

template <typename T>
node<T>* _previous_node(node<T>* head_ptr, node<T>* iMarker)
{
    /*
     * 1. get a walker and walk thru all the nodes
     * 2. assert walker(head_ptr) is not null or list is not empty
     * 3. look for node before mark
     * 4. if it exists return adress assert mark is not in list
     */
    const bool debug = false;

    node<T>* walker = head_ptr;
    if(walker == iMarker)
    {
        if(debug)
        {
            cout << "\nInside _previousNode():" << endl;
            cout << "   iMarker is the head node" << endl << endl;
        }
        return iMarker; // ***
    }


    /*
     *  NOTE TO SELF
     *  FOR THE PURPOSE OF THE USER INTERFACE THE LINE return mark
     *  HAS BEEN CHANGED FROM return nullptr
     *  WITH THE USER INTERFACE  PREVIOUS OF THE HEAD NODE DOESN'T
     *  DO ANYTHING TO THE OUTPUT SO IT HAS BEEN CHANGED TO ACCOMODATE
     *  THIS.
     *  HOW EVER IF THIS WAS ANOTHER TIME, return nullptr WOULD HAVE
     *  BEEN GOOD SO THAT PROGRAMMER KNOWS THAT THERE IS NO PREVIOUS
     *  NODE TO A HEAD PTR
     */


    assert(walker != nullptr && iMarker != nullptr);
    // //must assert list exists and mark item is not null

    while(walker != nullptr && walker ->_next != iMarker)
    {
        walker = walker ->_next;
    }
    assert(walker != nullptr);// mark is not in this list

    if(debug)
    {
        cout << "\nInside _previousNode():" << endl;
        cout << "    walker -> _next = iMarker" << endl << endl;
    }
    return walker;
}

template  <typename T>
void _print(node <T>* head_ptr, ostream& )
{
    /*
     * 1. get a walker to walk thru all nodes
     * 2. send *walker to ostream for all nodes
     */

    cout<<"H->";
    node <T>* walker = head_ptr;
    while( walker!= nullptr)
    {
        cout << *walker;
        walker = walker ->_next;
    }
    cout << "|||" << endl;
    cout << "\t - - - - - - - - - - - - - - - - - - - -" << endl << endl;
}

template  <typename T>
T _remove_head(node <T>* &head_ptr)
{
    /*
     * 1. create a T var to hold item from node being removed
     * 2. copy item of removed node to T var
     * 3. remove node
     * 4. return item;
     */

    node <T>* walker =  head_ptr;
    if(walker != nullptr)
    {
        head_ptr = walker ->_next;
        T hold = walker ->_item;
        delete walker;

        return hold;
    }

    return T(); // if head_ptr points to null

}

template  <typename T>
T _remove_node(node<T>* &head_ptr, node<T>* remove_me)
{
    /*
     * 1. assert remove_me is in the list
     * 2. create a node to hold item from node being removed
     * 3. copy item of node to be removed
     * 4. node before remove_me's next points to where remove_me is
     *    pointing to
     * 5. remove node
     * 6. return item;
     */

    const bool debug = false;

//    assert(head_ptr != nullptr);
    if(head_ptr == nullptr)
    {
        if(debug){
            cout <<"\nInside _remove_node():      head_ptr"
                 << "is nullptr" << endl << endl;
        }
        return T();
    }


    /*
     *  NOTE TO SELF 2
     *  FOR THE USER INTERFACE THE LINE
     * if(head_ptr == nullptr)
            return NULL;
        was added in the place of assert(head_ptr != nullptr)
     *  preventing the program from crashing when attempting
     * to remove a node from an empty list
     */

    node<T>* previous = _previous_node(head_ptr, remove_me);

    if(previous == remove_me)
    {
        if(debug){
            cout << endl <<"Inside _remove_node():      No previous"
                 << " node found.\n\t Removing head node" << endl << endl;
        }
        // if no node is before remove_me call _remove_head
        return _remove_head(head_ptr);
    }

    else
    {
        if(debug){
            cout << "\nInside _remove_node():    remove_me"
                 << " = previous -> _next" << endl ;
            cout << "\tRemoving node" << "[" << remove_me ->_item
                 << "]" << endl << endl;
        }
        T hold_item = remove_me ->_item;
        previous -> _next = remove_me -> _next;
        delete remove_me;
        return hold_item;
    }
}

template <typename T>
node <T>* _search(node <T>* head_ptr, const T& key)
{
    /*
     * 1. get a walker to walk thru all nodes
     * 2. search each node for key
     * 3. return address or return null if not found
     */
    const bool debug = false;
    node <T>* walker = head_ptr;

    while(walker != nullptr)
    {
        if(walker ->_item  == key)
        {
            if(debug)
                cout << "\nInside _search(): \titem is found\n" << endl;
            return walker;
        }
        walker = walker ->_next;
    }

    if(debug)
        cout << "\nInside _search(): \tItem is not found\n" << endl;
    return nullptr;

}

template  <typename T>
int _size(node<T>* head_ptr)
{
    /*
     * 1. walk thru all the nodes
     * 2. count number of nodes
     * 3. return count;
     */

    node<T>* walker = head_ptr;
    int count = 0;
    while(walker != nullptr )
    {
        walker = walker ->_next;
        count++;
    }
    return count;
}

template  <typename T>
node<T>* _where_this_goes(node<T>* head_ptr, const T& item, bool order)
{
    const bool debug = false;
    node<T>* walker(nullptr);
    node<T>* follower(nullptr);

    if(order == true)
    {
        if(head_ptr == nullptr || (head_ptr ->_item > item ||
                                   head_ptr->_item == item ))
        {
            if(debug)
                cout << "Inside _where_this_goes:   order(true)"
                     << "nullptr" << endl << endl;
            return nullptr;
        }
        else
        {
            walker = head_ptr-> _next;
            follower = head_ptr;
            while(walker != nullptr)
            {
                if((follower->_item < item || follower ->_item == item )
                                            && walker ->_item > item)
                    break;
                follower = follower ->_next;
                walker = walker ->_next;
            }
            if(debug)
                cout << "Inside _where_this_goes:   order(true)" << endl
                     << "returning follower: "<< *follower <<"\n\n";
            return  follower;
        }
    }
    else
    {
        if(head_ptr == nullptr || (head_ptr ->_item < item ||
                                   head_ptr ->_item == item))
        {
            if(debug)
                cout << "Inside _where_this_goes:   order(false)"
                     << "nullptr" << endl << endl;
            return nullptr;
        }
        else
        {
            walker = head_ptr-> _next;
            follower = head_ptr;
            while(walker != nullptr)
            {
                if((follower->_item > item || follower -> _item == item)
                                        && walker ->_item < item)
                    break;
                follower = follower ->_next;
                walker = walker ->_next;
            }
            if(debug)
                cout << "Inside _where_this_goes:   order(false)" << endl
                     << "returning follower: "<< *follower <<"\n\n";
            return  follower;
        }
    }

}

#endif // LIST_FUNCTIONS_H
