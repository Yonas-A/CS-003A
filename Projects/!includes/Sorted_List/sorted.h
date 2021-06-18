#ifndef SORTED_H
#define SORTED_H

#include <iostream>

#include "../../!includes/Linked_List_Sorted/linked_list_sorted.h"

using namespace  std;

template <typename T>
class Sorted
{
public:
    class Iterator
    {
    public:

        friend class Sorted;

        Iterator(node<T>* p = nullptr): _ptr(p){
        } //DEFAULT CTOR

        T& operator *(){                    //dereference oprator
            return _ptr->_item;
        }

        T* operator ->(){
            return _ptr->_next;
        }

        Iterator& operator++()  {//++it;

            _ptr = _ptr->_next;
            return *this;
        }


        friend Iterator operator++(Iterator& it,int )
        {
            Iterator hold = it;
            it._ptr = it._ptr -> _next;
            return hold;
        }           //friend operator: it++

        operator bool()      {
            return  (_ptr != nullptr);
        }

        friend bool operator !=(const Iterator& left,
                                const Iterator& right)  {
            if( left._ptr != right._ptr)
                return true;

            return false;
        }

        friend bool operator ==(const Iterator& left,
                                const Iterator& right) {
            if( left._ptr == right._ptr)
            return true;

            return false;
        }


    private:
        node<T>* _ptr;
    };

    // changed from true and false to false , true to accomodate Poly
    Sorted(bool order = false, bool unique = true);

    //big three:
    ~Sorted();
    Sorted(const Sorted<T> &other);
    Sorted& operator =(const Sorted& RHS);

    //member functions
    Iterator Begin() const;
    //return the head of the list

    void Clear_List() ;
    // clears the list and sets _head_ptr to null

    Iterator Copy_List(Sorted<T> &destList) const;
    // copies old list to newList & retuns end node to new list

    Iterator End() const;
    // returns the tail end of the list

    bool Empty() const;
    //returns true if list is empty else false

    int Index_Of(Iterator iMarker);
    // find the pos of iMarker of the list

    Iterator Insert(const T &item);
    // inserts item in the list

    Iterator Last_Node() const;
    // returns the last node unlike End() which returns nullptr

    T& operator[](const int &index) const;
    //return the item at index

    void Print() const;
    //print the list

    T Remove_Node(Iterator iMarker);
    //removes node pointed to by iMarker

    T Remove_Head();
    // removes the head node

    Iterator Search(const T& key, Iterator here) const;
    //return pointer to node containing key. NULL if not there

    int Size() const;
    // returns size of the list;


    Iterator Where_This_Goes(const T& key);
    // returns node after which item will be inserted

    friend ostream& operator <<(ostream& outs, const Sorted<T>& l)    {
        _print(l._head_ptr, outs);
        return outs;
    }

private:
    node<T>* _head_ptr;
    bool _order;
    bool _unique;
};


//================================
//  Default Ctor
//================================

template <typename T>
Sorted<T>::Sorted(bool order, bool unique)
{
    _head_ptr = nullptr;
    _order = order; // ascending order
    _unique = unique;
}

//=============================================
//            Big three
//=============================================

template <typename T>
Sorted<T>::~Sorted()
{
    const bool debug = false;
    if (debug) {
        cout << "~Sorted() destructor" << endl;
    }

    Clear_List();
    _clear_list(_head_ptr);
    _head_ptr = nullptr;
}

template <typename T>
Sorted<T>::Sorted(const Sorted<T>& other)
{
    const bool debug = false;
    if (debug)  {
        cout << "Sorted () COPY CTOR"<<endl;
    }

    //copying contents of other to object
    _order = other._order;
    _unique = other._unique;
     _copy_list(other._head_ptr, _head_ptr = nullptr);
    // Last points to the last node in the new list
}

template <typename T>
Sorted<T>& Sorted<T>::operator =(const Sorted& rhs)
{
    const bool debug = false;
    if (debug)  {
        cout << "Sorted:: = ( )" << endl;
    }

    if(this == &rhs) //self reference
        return *this;

    //clean up of the existing object
    if(_head_ptr != nullptr)
        _clear_list(_head_ptr);

    _order = rhs._order;
    _unique = rhs._unique;

    _copy_list(rhs._head_ptr, _head_ptr = nullptr);
    //copy contents of the rhs node

    return *this;
}

//=============================================
//      List class functions similar to list_functions
//=============================================


template <typename T>
typename Sorted<T>::Iterator Sorted<T>::Begin() const{
    return Iterator(_head_ptr);
}

template <typename T>
void Sorted<T>:: Clear_List ()
{
    _clear_list(_head_ptr);
    _head_ptr = nullptr;
}

template <typename T>
typename Sorted<T>::Iterator Sorted<T>::Copy_List
                            (Sorted<T> &dest_list) const
{
    const bool debug = false;
    if (debug){
        cout << "Copy_List() " << endl;
    }
    return Iterator(_copy_list(_head_ptr, dest_list._head_ptr));
}

template <typename T>
typename Sorted<T>:: Iterator Sorted<T>:: End() const
{
    return Iterator (nullptr);
}

template <typename T>
bool Sorted<T>::Empty() const
{
    return _empty(_head_ptr);
}

template <typename T>
int Sorted<T>::Index_Of(Iterator iMarker)
{
    node<T>* marker = iMarker._ptr;
    return _index_of(_head_ptr, marker);
}

template <typename T>
typename Sorted<T>::Iterator Sorted<T>::Insert(const T& item)
{
    Iterator temp = _search(_head_ptr, item);
    if( _unique  && temp)
    {
        *temp = *temp + item;
        return Iterator (_head_ptr);
    }

    else
        return Iterator(_insert(_head_ptr, item, _order));
}

template <typename T>
typename Sorted<T>:: Iterator Sorted<T>:: Last_Node () const
{
   return  Iterator (_end(_head_ptr));
}


template <typename T>
T& Sorted<T>::operator[](const int &index) const
{
    return _at(_head_ptr, index);
}

template <typename T>
void Sorted<T>::Print() const
{
    _print(_head_ptr);
}

template <typename T>
T Sorted<T>::Remove_Head()
{
    return _remove_head(_head_ptr);
}

template <typename T>
T Sorted<T>::Remove_Node(Iterator iMarker)
{
    node<T>* marker = iMarker._ptr;
    return (_remove_node(_head_ptr, marker));
}

template <typename T>
typename  Sorted<T>::Iterator Sorted<T>::Search(const T& key,
                                        Iterator here) const
{
    if( here == nullptr) // if here is null then assign it to head_ptr;
        here = _head_ptr;

    node<T>* marker = here._ptr;
    return Iterator( _search( marker, key) );
}

template<typename T>
int Sorted<T>::Size() const
{
    return _size(_head_ptr);
}

template <typename T>
typename  Sorted<T>::Iterator Sorted<T>::Where_This_Goes (
                                    const T& key)
{
    return Iterator( _where_this_goes(_head_ptr, key, _order));
}


#endif // SORTED_H
