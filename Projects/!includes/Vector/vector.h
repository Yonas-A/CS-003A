#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <iomanip>
#include <iostream>

#include "../../!includes/Add_Entry/add_entry.h"

using namespace  std;

template < typename T >
class Vector
{
    
public:

    // ==================================================================
    // ctor

    Vector( );
    /// a default vector ctor

    Vector( std::initializer_list<T> list ) ;
    /// a vector ctor that uses a list of items separated by a comma and
    /// curly braces to initalize this class' private mem variable _vector

    // ==================================================================
    //            BIG 3

    Vector( const Vector<T>& other );
    /// copy ctor

    Vector<T>& operator =( const Vector<T>& rhs );
    /// assignment operator

    ~Vector( );
    /// dtor

    // ==================================================================
    //member access functions:

    const T& operator [](const int index) const;
    /// \if index < vector's size, \return a const reference to item at index
    /// \else index >= size of vector, \assert assert()

    T& operator [](const int index);
    /// \if index < vector's size, \return a reference to item at index
    /// \else index >= size of vector, \assert assert()


    T& at(int index);
    /// \if index < vector's size, \return a reference to item at index
    /// \else index >= size of vector, \assert assert()

    const T& at(int index) const;
    /// \if index < vector's size, \return a const reference to item at index
    /// \else index >= size of vector, \assert assert()

    T& front( ) const;
    /// return item at position 0.

    T& back() const;
    ///return item at the last position

    // ==================================================================
    //Push and Pop functions

    void operator += (const T& item);
    /// insert item into this vector in a pushback way

    void push_back (const T& item);
    /// append item to the end

    T pop_back();
    /// \if size is greater than 0, remove last item and \return removed item
    /// \else size == 0, \return nothing
    
    // ==================================================================
    //Insert and Erase:

    void insert(int insert_here, const T& item );
    /// insert item at this position pos

    void erase( int erase_index );
    /// \if positon is less than vector size, erase item
    /// \else positon is greater or equal to vector size, do nothing

    // ==================================================================
    // index

    int index_of( const T& item );
    ///\if item exists in the vector , \return its index
    ///\else item doesn't exists in the vector , \return its -1

    // ==================================================================
    //size and capacity:

    int capacity( ) const;
    /// capacity of the vector
    int size( ) const;
    /// actual size of vector

    // ==================================================================
    // mutate size and capacity

    void set_capacity( int capacity );
    /// set the capacity of vector to this number
    void set_size( int size );
    /// set the size of this vector object to the number

    // ==================================================================
    // status of vector

    bool empty( ) const;
    /// \if size of vector is 0 \return true
    /// \else size > 0          \return false

    // ==================================================================
    //insertion operator:

    template<typename U>
    friend ostream& operator << (ostream& outs, const Vector<U>& a);
    
private:
    const int RSRV_CAP = 10;
    /// reserve capacity when we start our vector object

    int _capacity;
    int _size;
    T* _vector;

};


// ==================================================================
//            vector class definintion
// ==================================================================
// default ctor and a ctor with an initializer list of type T

template <typename T>
Vector<T>::Vector(): _capacity( RSRV_CAP), _size( 0 )
{
    const bool DEBUG = false;
    if(DEBUG)
        cout << "Vector<T>::Vector()" << endl;

    _vector = allocate<T>( _capacity );
}

template <typename T>
Vector<T>::Vector(initializer_list<T> l):_capacity(RSRV_CAP), _size( l.size( ) )
{
    const bool DEBUG = false;
    if( DEBUG )
        cout << "Vector<T>::Vector(initializer_list<T>)" << endl;

    /// if size of l is greater than default capacity
    if ( _size > _capacity)
    {
        _capacity = _size << 1;
        /// set capacity to twice that of size of l
        _vector = allocate<T>( _capacity );
        /// allocate an array of total capacity [ l.size() * 2 ]
    }
    else
        _vector = allocate<T>( _capacity );
        ///\else size of l is less than default capacity
        /// allocate an array of total capacity [ capacity ]

    size_t i = 0;
    for ( auto &item: l)
        _vector[i++] = item;
    /// insert all items of l into our vector starting at _vector[0]
    /// through vector [ l size - 1]

}

// ==================================================================
// copy ctor, assignment operator and dtor

template <typename T>
Vector<T>::Vector( const Vector<T>& other )
{
    const bool DEBUG = false;
    if(DEBUG)
        cout << "Vector<T>::Vector( const Vector<T>& other ) " << endl;
    
    _size = other._size;
    _capacity = other._capacity;
    
    _vector = allocate<T>( _capacity );
    copy(_vector, other._vector, _size);
}

template <typename T>
Vector<T>& Vector<T>::operator =(const Vector<T>& rhs)
{
    bool DEBUG = false;
    if(DEBUG)
        cout << "Vector<T>::operator =(const Vector<T>& rhs)" << endl;

    if(this == &rhs) // self reference
        return *this;

    if ( _vector != nullptr)
        deallocate( _vector );

    _size = rhs._size;
    _capacity = rhs._capacity;

    _vector = allocate<T>( _capacity );
    copy( _vector, rhs._vector, _size );

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
   const bool DEBUG = false;
    if( DEBUG )
        cout << "Vector<T>::~Vector()" << endl;
    
    deallocate( _vector );
    _capacity = 0;
    _size = 0;
}

// ==================================================================
// element accessors

template <typename T>
const T& Vector<T>:: operator [](const  int index) const
{
    assert( _size > 0 && "vector::[ ]const: size < 0 no elements in vector ");
    return _vector[ index ];
}

template <typename T>
T& Vector<T>:: operator [](const int index)
{
    assert( _size > 0 && "vector::[ ] : size < 0 vector has no elements");

    return _vector[index];
}

template <typename T>
T& Vector<T>::at( int index )
{
    assert( _size > 0 && "vector::at(): size < 0 vector has no elements");
    return _vector[ index ];
}

template <typename T>
const T& Vector<T>::at(int index) const
{
    assert( _size>0 && "vector::at() const: size < 0 vector has no elements");
    return _vector[ index ];
}

template <typename T>
T& Vector<T>::front() const
{
    assert( _size > 0 && "vector::front(): size < 0 vector has no front");
    return  _vector[ 0 ];
}

template <typename T>
T& Vector<T>::back() const
{
    assert( _size > 0 && "vector::back(): size < 0 vector has no back");
    return  _vector[ _size -1];
}

// ==================================================================
//  push and pop functions

template <typename T>
void Vector<T>:: operator +=( const T& item )
{
    _vector = add_entry<T>( _vector, item, _size, _capacity);
}

template <typename T>
void Vector<T>::push_back( const T& item )
{
    _vector = add_entry<T>( _vector, item, _size, _capacity);
}

template <typename T>
T Vector<T>::pop_back()
{
    assert( _size > 0 && "vector::pop_back(): size < 0 vector has element");

    T hold = _vector[ _size - 1];
    _vector = remove_entry<T>( _vector, hold, _size, _capacity);
    return hold;
}

// ==================================================================
//  Insert and erase functions

template <typename T>
void Vector<T>::insert( int insert_here, const T& insert_this)
{
   const bool DEBUG = false;

   cout << "insert_here: "  << insert_here << endl;

    assert( _size < insert_here );// && "vector::insert() size > index to insert");

//    if( insert_here == size() )
//    {
//        push_back( insert_this );
//        return;
//    }
    
    if( size() >= capacity() )
    {
        set_capacity( 2 * size( ) );
        T* temp = _vector;
        /// copy this vector into a temporary vector
        _vector = allocate<T>(capacity());
        ///allocating new capacity for _vector
        copy( _vector, temp, size() );
        /// copy back all items in temp vector to _vector object
        deallocate (temp);
        /// delete temp
        if( DEBUG )
            cout << "vector::insert() new capacity: " << capacity() << endl;
    }

    _vector = shift_Right<T>( _vector, insert_here, _size);
    _vector[insert_here] = insert_this;
}

template <typename T>
void Vector<T>::erase( int erase_index )
{
    const  bool DEBUG = false;
    T temp = _vector[erase_index];
    
    if( DEBUG )
        cout << endl << "Erase: " << temp << endl;
    
    _vector = remove_entry<T>( _vector, temp, _size, _capacity);
    /// remove item at erase_index
}

// ==================================================================
// index

template <typename T>
int Vector<T>::index_of(const T& item)
{
    int* ptr = Find( _vector, item, _size);

    if( ptr != nullptr)
        return ( ptr - _vector);
    else
        return (-1);
}

// ==================================================================
// mutate size and capacity

template <typename T>
void Vector<T>::set_capacity( int capacity )
{
    _capacity = capacity;
}

template <typename T>
void Vector<T>::set_size(int size)
{
    _size = size;
}

// ==================================================================
// size and capacity

template <typename T>
int Vector<T>::capacity() const
{
    return _capacity;
}

template <typename T>
int Vector<T>::size() const
{
    return _size;
}
// ==================================================================
//
template <typename T>
bool Vector<T>::empty() const
{
    return ( size() == 0 );
}

// ==================================================================
// insertion operator

template  <typename U>
ostream& operator <<(ostream& outs, const Vector<U>& a)
{
    for (int i= 0; i< a._size; i++)
    {
        outs << a._vector[i] << "   ";
    }
    return outs;
}

#endif // VECTOR_H
