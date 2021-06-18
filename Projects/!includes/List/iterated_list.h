#ifndef ITERATED_LIST_H
#define ITERATED_LIST_H
#include <iostream>
#include "../../!includes/Linked_List/linked_list.h"


using namespace  std;

template <typename T>
class List
{
public:

    class Iterator{
    public:
        friend class List;

        Iterator(node<T>* p = nullptr): _ptr(p){} //DEFAULT CTOR

        T& operator *(){                 //dereference oprator
            return _ptr->_item;
        }
        T* operator ->(){
            return _ptr ->_next;
        }

        Iterator& operator++(){

            _ptr = _ptr ->_next;
            return *this;
        } //member operator:        //++it; or ++it = new_value

        friend Iterator operator++(Iterator& it,int)
        {
            Iterator temp = it;
            it._ptr = it._ptr ->_next;
            return temp;
        }
        //friend operator: it++

        operator bool()      {
            return  ( _ptr != nullptr);
            //true if _ptr not null
        }

        friend bool operator != (const Iterator& left,
                                 const Iterator& right){
            if(left._ptr != right._ptr)
                return true;
            return false;
        }

        friend bool operator == (const Iterator& left,
                                 const Iterator& right){
            if(left._ptr == right._ptr)
                return true;
            return false;
        }


    private:
        node<T>* _ptr;
    };


    List();

    //big three:
    ~List();
    List(const List<T> &other);
    List& operator =(const List& RHS);

    //member functions
    Iterator Begin() const;
    //return the head of the list

    void Clear_List() ;
    // clears the list and sets _head_ptr to null

    Iterator Copy_List(List<T> &newList) const;
    // copies old list to newList & retuns end node to new list

    Iterator End() const;
    // returns the tail end of the list

    bool Empty() const;
    //returns true if list is empty else false

    Iterator Insert_After(const T& item, Iterator marker);
    //insert  item after iMarker

    Iterator Insert_Before(const T& item, Iterator marker);
    //insert i before iMarker

    void Insert_Head(const T& item);
    //insert item at the head of list

    Iterator Insert_Last(const T& item);
    //insert i before iMarker

    int Index_Of(Iterator iMarker);
    // find the pos of iMarker of the list

    Iterator Last_Node() const;
    //returns the last node in the list;

    T& operator[](const int &index) const;
    //return the item at index

    Iterator Previous(Iterator iMarker);
    //get the previous node to iMarker

    void Print() const;
    //print the list

    T Remove_Node(Iterator iMarker);
    //removes node pointed to by iMarker

    T Remove_Head();
    // removes the head node

    Iterator Search(const T &key, Iterator here) const;
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
//    _clear_list(_head_ptr);
    _head_ptr = nullptr;
}


template <typename T>
List<T>::List(const List<T>& other)
{
    const bool debug = false;
    if (debug){
        cout<<"List () COPY CTOR"<<endl;
    }

    //copying contents of other to object
    //I could not make Copy_List work for my Copy Ctor
    // i had to use the lower level _copy_list()

    /*node<T>* Last =*/ _copy_list(other._head_ptr, _head_ptr = nullptr);
    // Last points to the last node in the new list
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
        Clear_List();
//        _clear_list(_head_ptr);

//    _copy_list(rhs._head_ptr, _head_ptr = nullptr);
    // next line works only if Copy_List is marked const
    rhs.Copy_List(*this);
    //copy contents of the rhs node

    return *this;
    //return ur self
}



//=============================================
//      List class functions similar to list_functions
//=============================================

template <typename T>
typename List<T>::Iterator List<T>::Begin() const{

    return Iterator( _head_ptr);
}

template <typename T>
void List<T>:: Clear_List ()
{
    _clear_list(_head_ptr);
    _head_ptr = nullptr;
}


template <typename T>
typename List<T>::Iterator List<T>::Copy_List(List<T> &dest_list) const
{
    const bool debug = false;
    if (debug){
        cout << "Copy_List() " << endl;
    }

    return Iterator(_copy_list(_head_ptr, dest_list._head_ptr));
}


template <typename T>
typename List<T>:: Iterator List<T>:: End() const
{
   return  Iterator ( nullptr );

}

template <typename T>
bool List<T>::Empty() const
{
    return _empty(_head_ptr);
}

template <typename T>
typename List<T>::Iterator List<T>:: Insert_After(const T& item,
                                                  Iterator iMarker)
{
    node<T>* marker = iMarker._ptr;
    return Iterator( _insert_after( _head_ptr, marker, item));
}

template <typename T>
typename List<T>::Iterator List<T>:: Insert_Before(const T& item,
                                                   Iterator iMarker)
{
    node<T>* marker = iMarker._ptr;
    return Iterator( _insert_before( _head_ptr, marker, item));
}

template <typename T>
void List<T>::Insert_Head(const T& item)
{
    _insert_head(_head_ptr, item);
}

template <typename T>
typename List<T>::Iterator List<T>::Insert_Last(const T& item)
{
    return Iterator(_insert_last(_head_ptr, item));
}

template <typename T>
int List<T>::Index_Of(Iterator iMarker)
{
    node<T>* marker = iMarker._ptr;
    return _index_of(_head_ptr, marker);
}

template <typename T>
typename List<T>::Iterator List<T>::Last_Node () const
{
    return Iterator(_end(_head_ptr));
}

template <typename T>
T& List<T>::operator[](const int &index) const
{
    return _at(_head_ptr, index);
}

template <typename T>
typename List<T>::Iterator List<T>::Previous(Iterator iMarker)
{
    node<T>* marker = iMarker._ptr;
    return Iterator(_previous_node(_head_ptr, marker));
}

template <typename T>
void List<T>::Print() const{
    _print(_head_ptr);
}

template <typename T>
T List<T>::Remove_Head()
{
    return _remove_head(_head_ptr);
}
template <typename T>
T List<T>::Remove_Node(Iterator iMarker)
{
    node<T>* marker = iMarker._ptr;
    return (_remove_node(_head_ptr, marker));
}

template <typename T>
typename  List<T>::Iterator List<T>::Search(const T& key,
                                        Iterator here) const
{
    if( !here) // if here is null then assign it to head_ptr;
        here = _head_ptr;

    node<T>* marker = here._ptr;
    return Iterator(_search( marker, key));
}


template<typename T>
int List<T>::Size() const
{
    return _size(_head_ptr);
}


#endif // ITERATED_LIST_H
