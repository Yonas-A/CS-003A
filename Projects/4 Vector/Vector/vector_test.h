#ifndef VECTOR_TEST_H
#define VECTOR_TEST_H
#include <iostream>
#include "../../!includes/Vector/vector.h"

using namespace std;


void test_big_three();
// test for big three functions

void const_test(const Vector<int>& v);
// test for const functions

void non_const_test(Vector<int>& v);
// test for non const functions

//====================================================
//
void simple_insertion(Vector<int>& v);
// a simple insert function called when needed

//====================================================

void test_at_front_back();
// test function for at(), front() & back()

void test_erase();
// test function for erase()

void test_index_of();
// test function for index_of()

void test_insert();
//test function for insert()

void test_operator_PlusEqual();
// test function for operator +=()

void test_pop_back();
// test function for pop_back()

void test_push_back();
// test function for push_back


//=========================================================
//            Functions definintion
//=========================================================

void test_big_three()
{
    cout << " = = = = test big 3() = = = = \n";

    Vector<int> v1;
    v1.push_back(4);
    v1.push_back(6);
    cout << "---------  v2 = v1 copy ctor -----------" << endl;

    Vector<int> v2 = v1;
    cout << v2 << endl;

    cout << "--------- assigning v3 = v2:  -----------" << endl;
    Vector<int> v3;
    v3 = v2; ;

    cout << " \n= = = = exiting big 3() = = = = \n";

}

void non_const_test( Vector<int>& v)
{
    cout << " = = = = = = non const test = = = = = =" << endl;

    for(int i = 13 ; i < 17; i++)
    {
        v.push_back(i);
    }
    cout << v << endl;

    cout << "changing the first element to 5: " << endl;
    v.at(0) = 5;
    cout << endl << v << endl;

    cout << " = = = = exiting non const test = = = =" << endl;

}

void const_test( const Vector <int>& v)
{
    cout << " = = = = = = const test = = = = = =" << endl;
    cout << v << endl;
    cout << "here is the first element of v: " << endl;
    cout << v.at(0) << endl;

    cout << " = = = = exiting const test = = = =" << endl;
}

//====================================================
//
//====================================================
void simple_insertion( Vector<int>& v1)
{
    const bool DEBUG = false;
    for( unsigned int i = 10; i < 20; i++)
    {
        v1.push_back(i);
        if(DEBUG)
        {
            cout << "size " << v1.size() << endl;
            cout << "V1: " << v1 << endl;
        }
    }

    cout << "vector: " << v1 << endl << "size: " << v1.size()
         << "   capacity: " << v1.capacity() << endl << endl;

}


void test_at_front_back()
{
    cout << " = = = = test at() = = = ="<< endl << endl;

    Vector<int> v1;
    simple_insertion(v1);


    cout << "v1.at(3): " << v1.at(3) << endl;
    cout << "v1.at(10): " << v1.at(10) << endl;
    cout << "v1.at(4): " << v1.at(4) << endl;
    cout << "v1.at(1): " << v1.at(1) << endl;
    cout << "v1.at(0): " << v1.at(0) << endl;

    cout << "v1.front(): " << v1.front() << endl;
    cout << "v1.back(): " << v1.back() << endl;

    cout << "= = = = exiting at() test= = = =" << endl << endl;
}

void test_erase()
{
    cout << " = = = = test erase() = = = ="<< endl << endl;

    Vector<int> v1;
    simple_insertion(v1);

    v1.erase(0);
    cout << "size " << v1.size() << endl;
    cout << "V1: " << v1 << endl;

    v1.erase(4);
    cout << "size " << v1.size() << endl;
    cout << "V1: " << v1 << endl;

    v1.erase(5);
    cout << "size " << v1.size() << endl;
    cout << "V1: " << v1 << endl;

    v1.erase(7);
    cout << "size " << v1.size() << endl;
    cout << "V1: " << v1 << endl;

    v1.erase(0);
    cout << "size " << v1.size() << endl;
    cout << "V1: " << v1 << endl;

    v1.erase(2);
    cout << "size " << v1.size() << endl;
    cout << "V1: " << v1 << endl;

    cout << "= = = exiting erase() test = = =" << endl << endl;
}

void test_index_of()
{
    cout << "= = = = test index_of() = = = =" << endl << endl;
    Vector<int> v1;
    simple_insertion(v1);

    cout << "v1.index_of(15): " << v1.index_of(15) << endl;
    cout << "v1.index_of(100): " << v1.index_of(100) << endl;

    cout << "= = = = exiting index_of() test = = = ="<< endl << endl;

}

void test_insert( )
{
    cout << " = = = = test insert() = = = =" << endl << endl;
    Vector<int> vec;

    int high = 100, low = 0,  index_high = 30;
    for ( int i = 0 ; i < 50 ; i ++ )
    {
        int item = rand() % ( high - low + 1 ) + low ;
        int index = rand( ) % ( index_high - low + 1 ) + low ;
        cout << "index: "  << index << "    item:  " << item << endl;
        vec.insert( index, item );
        cout << "=  =   =   =  VECTOR    =   =   =   " << endl ;
        cout <<  vec  << endl << endl;
        cout << "Size: " << vec.size() << " Cap: " << vec.capacity() << endl;

    }
    cout << "=  =   =   =  FINAL VECTOR   =   =   =   " << endl;
    cout << endl << vec  << endl << endl;
    cout << "Size: " << vec.size() << " Cap: " << vec.capacity() << endl;


    cout << "= = = = exiting insert() = = = =" << endl << endl;

}

void test_operator_PlusEqual()
{
    cout << "= = = = test vector +=() = = = =" << endl << endl;
    Vector<int> v1;

    for( unsigned int i = 201; i < 209; i++)
    {
        v1 += i;
    }
    cout << "vector: " << v1 << endl << "size " << v1.size()
         << "   capacity: " << v1.capacity() << endl;

    cout << "= = = exiting vector +=() test = = =" << endl << endl;
}

void test_pop_back()
{
    cout << " = = = = test pop_back() = = = =" << endl << endl;
    Vector<int> v1;
    simple_insertion(v1);
    for( unsigned int i = 1; i < 10; i++)
    {
        int value = v1.pop_back();
        cout << "item: " << value << endl;
        cout << "size " << v1.size() << "   capacity: "
             << v1.capacity() << endl;
        cout << "V1: " << v1 << endl;
    }

    cout << "= = = = exiting pop_back() = = = =" << endl << endl;
}

void test_push_back()
{
    cout << " = = = = test push_back() = = = =" << endl << endl;

    Vector<int> v1;
    for( unsigned int i = 22; i > 11; --i)
    {
        v1.push_back(i);
    }
    cout << "vector: " << v1 << endl << "size " << v1.size()
         << "   capacity: " << v1.capacity() << endl;

    cout << "= = = = test push_back() = = = =" << endl << endl;
}

#endif // VECTOR_TEST_H
