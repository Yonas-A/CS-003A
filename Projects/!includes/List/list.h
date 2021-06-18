#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "../../!includes/Linked_List/linked_list.h"

using namespace  std;

template <typename T>
class List
{
public:

    List();

    //big three:

    ~List();
    List(const List<T> &other);
    List& operator =(const List& RHS);



    //member functions

    node<T>* Begin() const;
    //return the head of the list

    void Clear_List() ;
    // clears the list and sets _head_ptr to null

    node<T>* Copy_List(List<T> &new_List);
    // copies old list to newList & retuns end node to new list

    node<T>* End( ) const;
    // returns the tail end of the list

    bool Empty( ) const;
    //returns true if list is empty else false

    node<T>* Insert_After( const T& item, node<T>* iMarker );
    //insert  item after iMarker

    node<T>* Insert_Before(const T& item, node<T>* iMarker);
    //insert i before iMarker

    void Insert_Head(const T& item);
    //insert item at the head of list

    node<T>* Insert_Last(const T& item);
    //insert i before iMarker

    int Index_Of(node<T>* iMarker);
    // find the pos of iMarker of the list

    T& operator[](const int &index) const;
    //return the item at index

    node<T>* Prev(node<T>* iMarker);
    //get the previous node to iMarker

    void Print() const;
    //print the list

    T Remove(node<T>* iMarker);
    //removes node pointed to by iMarker

    node<T>* Search(const T &key, node<T>* here) const;
    //return pointer to node containing key. NULL if not there

    int Size() const;
    // returns size of the list;


    friend ostream& operator <<(ostream& outs, const List<T>& l)    {
        _print(l._head_ptr, outs);
        return outs;
    }

private:
    node<T>* _head_ptr;
};

//================================
//  Default Ctor
//================================

template <typename T>
List<T>::List()
{
    _head_ptr = nullptr;
}

//=============================================
//            Big three
//=============================================

template <typename T>
List<T>::~List()
{
    const bool debug = false;
    if (debug) {
        cout << "~List() destructor" << endl;
    }

    Clear_List();
    _clear_list(_head_ptr);
    _head_ptr = nullptr;
}


template <typename T>
List<T>::List(const List<T>& other)
{
    const bool debug = false;
    if ( debug )
    {
        cout << "List () COPY CTOR" << endl;
    }

    _copy_list(other._head_ptr, _head_ptr = nullptr);
    /// returns the last node in the list

}

template <typename T>
List<T>& List<T>::operator =(const List& rhs)
{
    const bool debug = false;
    if (debug){
        cout << "List:: = ( )" << endl;
    }

    if(this == &rhs) //self reference
        return *this;

    //clean up of the existing object
    if(_head_ptr != nullptr)
        _clear_list(_head_ptr);

    _copy_list(rhs._head_ptr, _head_ptr = nullptr);
    //copy contents of the rhs node

    return *this;
    //return ur self
}






//=============================================
//      List class functions similar to list_functions
//=============================================

template <typename T>
node<T>* List<T>:: Begin() const
{
    return _beginning(_head_ptr);
}

template <typename T>
void List<T>:: Clear_List ()
{
    _clear_list(_head_ptr);
    _head_ptr = nullptr;
}

template <typename T>
node<T>* List<T>::Copy_List (List<T> &dest_list)
{
    const bool debug = false;
    if (debug){
        cout << "Copy_List() " << endl;
    }
    return _copy_list( _head_ptr, dest_list._head_ptr );

}

template <typename T>
node<T>* List<T>:: End() const
{
    return _end(_head_ptr);
}

template <typename T>
bool List<T>::Empty() const
{
    return _empty(_head_ptr);
}

template <typename T>
node<T>* List<T>:: Insert_After(const T& item, node<T>* iMarker)
{
    return _insert_after( _head_ptr, iMarker, item);
}

template <typename T>
node<T>* List<T>:: Insert_Before(const T& item, node<T>* iMarker)
{
    return _insert_before( _head_ptr, iMarker, item);
}

template <typename T>
void List<T>::Insert_Head(const T& item)
{
    _insert_head(_head_ptr, item);
}

template <typename T>
node<T>* List<T>::Insert_Last(const T& item)
{
   return _insert_last(_head_ptr, item);
}

template <typename T>
int List<T>::Index_Of (node<T>* iMarker)
{
    return _index_of(_head_ptr, iMarker);
}

template <typename T>
T& List<T>::operator[](const int &index) const
{
    return _at(_head_ptr, index);
}

template <typename T>
node<T>* List<T>:: Prev(node<T>* iMarker)
{
    return _previous_node(_head_ptr , iMarker);
}

template <typename T>
void List<T>::Print() const
{
    _print(_head_ptr);
}

template <typename T>
T List<T>:: Remove(node<T>* iMarker)
{
    return _remove_node(_head_ptr, iMarker);
}

template <typename T>
node<T>* List<T>::Search(const T& key, node<T>* here) const
{
    if(here == nullptr)
        here = _head_ptr;
    return _search( here, key);
}

template<typename T>
int List<T>::Size() const
{
    return _size(_head_ptr);
}




#endif // LIST_H
