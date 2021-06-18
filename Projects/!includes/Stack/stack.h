#ifndef STACK_H
#define STACK_H

#include "../../!includes/Linked_List/linked_list.h"


template <typename T>
class Stack
{
public:
    class Iterator {
    public:
        friend class Stack;

        Iterator( node<T>* p = nullptr) : _ptr( p) {  } //default CTOR

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


        friend Iterator operator++( Iterator& it,int )         {
            Iterator hold = it;
            it._ptr = it._ptr ->_next;
            return hold;
        }           //friend operator: it++ ( postfix) 

        operator bool( )       {
            return  ( _ptr != nullptr) ;
        }

        friend bool operator !=( const Iterator& LHS, const Iterator& RHS)   {
             return ( LHS.it != RHS.it );
        }

        friend bool operator ==( const Iterator& LHS, const Iterator& RHS)   {
            return ( LHS.it == RHS.it );
        }


    private:
        node<T>* _ptr;
    };

    Stack( ) ;

    //big three:
    ~Stack( ) ;
    Stack( const Stack<T> &other) ;
    Stack& operator =( const Stack& rhs) ;


    Iterator Bottom( )  const;
    // returns nullptr  //same as End( )  in queue

    bool Empty( )  const;
    // returns true if list is empty else false

    Iterator Push( const T& item) ;
    // inserts a new node with ( item)  at the end of list
    // returns the last node

    T operator []( const int &index) ;
    // returns the item in the list at pos = index

    T Pop( ) ;
    // removes the  first node and returns  removed item

    Iterator Search( const T& item)  const;
    // returns the node with the item;

    /// retuns the size of the list
    int Size( )  const;

    Iterator Top( )  const;
    // returns the first node in the list if it exists
    // else returns nullptr

    T Top( int)  const;
    // overloaded function that returns the item at the top


    friend ostream& operator <<( ostream& outs, const Stack<T>& s)     {
        _print( s._head_ptr, outs) ;
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
Stack<T>::Stack( ) 
{
    _head_ptr = nullptr;
    _end_ptr = nullptr;
}

//=============================================
//            Big three
//=============================================

template <typename T>
Stack<T>::~Stack( ) 
{
    const bool DEBUG = false;
    if ( DEBUG)  {
        cout << "~Stack( )  destructor" << endl;
    }

    _clear_list( _head_ptr) ;
    _head_ptr = nullptr;
    _end_ptr = nullptr;
}

template <typename T>
Stack<T>::Stack( const Stack<T>& other) 
{
    const bool DEBUG = false;
    if ( DEBUG) {
        cout<<"Stack ( )  COPY CTOR"<<endl;
    }

    _end_ptr = _copy_list( other._head_ptr, _head_ptr = nullptr) ;
    // Last points to the last node in the new list
}

template <typename T>
Stack<T>& Stack<T>::operator =( const Stack& rhs) 
{
    const bool DEBUG = false;
    if ( DEBUG) {
        cout << "Stack:: = (  ) " << endl;
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

//=============================================
//  member functions
//=============================================

template <typename T>
typename Stack<T>::Iterator Stack<T>::Bottom ( )  const
{
//    return Iterator ( _end_ptr) ;
// the above line was used for testing remove node to see if
// end_ptr was set to nullptr after removing all items from list
    return Iterator ( nullptr) ;
}

template  <typename T>
bool Stack<T>::Empty ( )  const
{
    return _empty( _head_ptr) ;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::Push ( const T& item) 
{
    _insert_head( _head_ptr, item) ;
    _end_ptr = _end( _head_ptr) ;
    return Iterator ( _head_ptr) ;
}


template <typename T>
T Stack<T>:: operator[] ( const int &index) 
{
    assert( index < Size ( ) ) ;
    return _at( _head_ptr, index) ;
}

template <typename T>
T Stack<T>::Pop ( ) 
{
    const bool DEBUG = false;

    T item = _remove_head( _head_ptr) ;
    if( _empty( _head_ptr) ) 
        _end_ptr = nullptr;
    // setting the _end ptr to null if no list exists;

    if( DEBUG && _head_ptr != nullptr) 
    {
        cout << "Inside Pop( ) :      _head_ptr = " << _head_ptr ->_item
             << "   _end_ptr = " << _end_ptr->_item << endl << endl;
    }

    return item;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::Search ( const  T& item)  const
{
    return Iterator ( _search( _head_ptr, item) ) ;
}

template <typename T>
int Stack<T>:: Size( )  const
{
    return _size( _head_ptr) ;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::Top( )  const
{
    return Iterator ( _beginning( _head_ptr) ) ;
}

template <typename T>
T Stack<T>::Top( int)  const
{
    return *Iterator ( _beginning( _head_ptr) ) ;
}

#endif // STACK_H
