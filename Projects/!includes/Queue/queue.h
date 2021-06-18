#ifndef QUEUE_H
#define QUEUE_H

#include "../../!includes/Linked_List/linked_list.h"



template <typename T>
class Queue
{
public:
    class Iterator {

    public:
        friend class Queue;

        Iterator( node<T>* p = nullptr) : _ptr( p) {

        } //default CTOR

        T& operator *( ) {             //dereference operator
            return _ptr->_item;
        }

        T* operator ->( ) {
            return _ptr->_next;
        }

        Iterator& operator++( )   {   //prefix ; ++it;

            _ptr = _ptr->_next;
            return *this;
        }


        friend Iterator operator++( Iterator& it,int ) 
        {
            Iterator hold = it;
            it._ptr = it._ptr ->_next;
            return hold;
        }           //friend operator: it++ ( postfix) 

        operator bool( )       {
            return  ( _ptr != nullptr) ;
        }

        friend bool operator !=(const Iterator& left, const Iterator& right)
        {
            return ( left._ptr != right._ptr );

        }

        friend bool operator ==( const Iterator& left,const Iterator& right)
        {
            return ( left._ptr == right._ptr );
        }


    private:
        node<T>* _ptr;
    };

    Queue( ) ;

    //big three:
    ~Queue( ) ;
    Queue( const Queue<T> &other) ;
    Queue& operator =( const Queue& RHS) ;


    bool Empty( )  const;
    // returns true if list is empty else false

    Iterator End( ) ;
    // returns a nullptr

    Iterator Front( ) ;
    // returns the first node in the list if it exists
    // else returns nullptr

    T Front(  int )  const;
    // overloaded function that returns the item at the front


    Iterator Push( const T& item) ;
    // inserts a new node with ( item)  at the end of list
    // returns the last node

    T operator []( const int &index) ;
    // returns the item in the list at pos = index

    T Pop( ) ;
    // removes the  first node and returns  removed item

    Iterator Search( const T& item)  const;
    // returns the node with the item;

    int Size( )  const;
    // retuns the size of the list


    friend ostream& operator <<( ostream& outs, const Queue<T>& l)     {
        _print( l._head_ptr, outs) ;
        return outs;
    }

private:
   node<T>* _head_ptr;
   node<T>* _end_ptr;

};



//================================
//  Default Ctor
//================================

template <typename T>
Queue<T>::Queue( ) 
{
    _head_ptr = nullptr;
    _end_ptr = nullptr;
}

//=============================================
//            Big three
//=============================================

template <typename T>
Queue<T>::~Queue( ) 
{
    const bool DEBUG = false;
    if ( DEBUG)  {
        cout << "~Queue( )  destructor" << endl;
    }



    _clear_list( _head_ptr) ;
    _head_ptr = nullptr;
    _end_ptr = nullptr;
}

template <typename T>
Queue<T>::Queue( const Queue<T>& other) 
{
    const bool DEBUG = false;
    if ( DEBUG) {
        cout << "Queue::Queue( const Queue<T>& other)"<<endl;
    }
    
    _end_ptr = _copy_list( other._head_ptr, _head_ptr = nullptr) ;
    // Last points to the last node in the new list
}

template <typename T>
Queue<T>& Queue<T>::operator =( const Queue& rhs) 
{
    const bool DEBUG = false;
    if ( DEBUG) {
        cout << "Queue:: = (  ) " << endl;
    }

    if( this == &rhs)  //self reference
        return *this;

    //clean up of the existing object
    if( _head_ptr != nullptr) 
    {
        _clear_list( _head_ptr) ; // clearing everyting in list
        _head_ptr = nullptr;  // setting the head_ptr to null
        _end_ptr = nullptr; // setting the end ptr to null
    }

   _end_ptr =  _copy_list( rhs._head_ptr, _head_ptr = nullptr) ;
    //copy contents of the rhs node

    return *this;
    //return ur self
}


template  <typename T>
bool Queue<T>::Empty ( )  const
{
    return _empty( _head_ptr) ;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::End ( ) {
//    return Iterator ( _end_ptr) ;
// the above line was used for testing remove node
// to see if end_ptr was set to nullptr after removing all items
// from a list

    return Iterator( nullptr) ;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>:: Front( ) 
{
    return Iterator ( _beginning( _head_ptr) ) ;
}

template <typename T>

T Queue<T>::Front( int )  const
{
    return * Iterator ( _beginning( _head_ptr) ) ;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>:: Push ( const T& item) 
{
    _end_ptr = _insert_last( _head_ptr, item) ;
    return Iterator ( _end_ptr) ;
}

template <typename T>
T Queue<T>:: operator[] ( const int &index) 
{
    if( index < Size( ) ) 
        return _at( _head_ptr, index) ;
    else
        return T( ) ;
}

template <typename T>
T Queue<T>::Pop ( ) 
{
    T item = _remove_head( _head_ptr) ;

    if( _empty( _head_ptr) ) 
        _end_ptr = nullptr;
    // setting the _end ptr to null if no list exists;

    return item;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::Search ( const T& item)  const
{
    return Iterator (  _search( _head_ptr, item) ) ;
}


template <typename T>
int Queue<T>:: Size( )  const
{
    return _size( _head_ptr) ;
}



#endif // QUEUE_H
