
#include <cassert>
#include <iostream>
#include <sstream>

#include "../../!includes/Sorted_List/sorted.h"
#include "../includes/poly.h"
#include "../includes/term.h"


using namespace  std;

Poly::Poly(): _poly (false, true) {
    _order = 0;
    _poly.Insert (Term(0, _order));
}

Poly::Poly(int term_arr[], int order)   {
    _order = order;
    for(int i = 0; i < order + 1 ;i++)    {
        _poly.Insert (Term(term_arr[ order - i ], i));
    }
}

//======================================================
//      BIG three
//======================================================

Poly:: ~Poly() {
    const bool debug = false;
    if (debug){
        cout << endl << "~Poly() destructor" << endl;
    }
    _poly.Clear_List ();
}

Poly::Poly(const Poly& other)
{
    const bool debug = false;
    if (debug){
        cout << endl << "Poly() COPY CTOR" << endl;
    }

    _order = other._order;
    other._poly.Copy_List (_poly);
}

Poly& Poly::operator =(const Poly& rhs)
{
    const bool debug = false;
    if (debug){
        cout << endl << "Poly:: = ( )" << endl;
    }

    if(this == &rhs)
        return  *this;

    if( !_poly.Empty ())
        _poly.Clear_List ();

    _order = rhs._order;
    rhs._poly.Copy_List (_poly);
    return *this;
}

//======================================================
// Poly | Term compound assignement operator
//======================================================

Poly& Poly::operator +=(const Term& t)
{
    _poly.Insert (t);
    return *this;
}

Poly& Poly::operator -=(const Term &t)
{
    *this += -t;
//    _poly.Insert (-t);
    return *this;
}

Poly& Poly::operator *=(const Term &t)
{
    Sorted<Term>::Iterator it = _poly.Begin ();
    for ( ; it != _poly.End ();  it++)     {
        *it *= t;
    }
    return *this;
}

Poly& Poly::operator /=(const Term &t)
{
    Sorted<Term>::Iterator it = _poly.Begin ();
    for ( ; it != _poly.End ();  it++)     {
        *it /= t;
    }
    return *this;
}

//======================================================
// Poly | Poly compound assignement operator
//======================================================

Poly& Poly::operator +=(const Poly& RHS)
{
    Sorted<Term>::Iterator it = RHS._poly.Begin ();
    for ( ; it != RHS._poly.End ();  it++)     {
        *this +=  *it;
    }
    return *this;
}

Poly& Poly::operator -=(const Poly& RHS)
{
    Sorted<Term>::Iterator it = RHS._poly.Begin ();
    for ( ; it != RHS._poly.End ();  it++)     {
        *this -=  *it;
    }
    return *this;
}

Poly& Poly::operator *=(const Poly& RHS)
{
    Poly temp = *this;
    Poly hold = *this;
    *this = Poly ();
    // setting *this to default poly
    Sorted<Term>::Iterator it = RHS._poly.Begin ();
    for ( ; it != RHS._poly.End ();  it++)     {
        temp = hold;
        temp *=  *it; // multiplying _poly with terms from rhs
        *this += temp; // adding the multiplied terms to _poly
    }
    return *this;
}

Poly& Poly::operator /=(const Poly& RHS)
{
    /*
     * Steps explained
     * 1) divide lhs highest term by RHS highest term = quotient
     * 2) after this lhs becomes the difference of multiple of RHS
     *       by quotient  from itself
     * 3) add the result from step 1 to *this
     * 4) repeat this while the lhs end
     */

    Poly quotient;
    Poly hold = *this;
    *this =Poly();   // setting lhs poly to default

    Sorted<Term>::Iterator p_it = hold._poly.Begin ();
    //P_it is the highest term for the lhs
    Sorted<Term>::Iterator it = RHS._poly.Begin ();
    // it holds the highest term of RHS poly

    for ( ; p_it != hold._poly.End ();  p_it++)
    {
        quotient += *p_it/ *it;
        //dividing lhs highest term by RHS's highest term
        *this += quotient;
        // adding the quotient of the two terms to result
        hold -= quotient * RHS;
        // updating the lhs to the new poly
        quotient = Poly();
        // reseting quotient to default (0x^0)
    }
    return *this;
}

//======================================================
// Poly unary operator
//======================================================

Poly Poly:: operator -() const
{
    Poly temp;
    Sorted<Term>::Iterator it = _poly.Begin ();
    for ( ; it != _poly.End ();  it++)     {
        temp += -(*it) ;
    }
    return temp;
}

//======================================================
// Poly| Term arithmetic operator
//======================================================

Poly operator +(const Poly& lhs, const Term& t)
{
    Poly sum( lhs);
    sum += t;
    return sum;
}

Poly operator -(const Poly& lhs, const Term& t)
{
    Poly difference (lhs);
    difference -= t;
    return difference;
}

Poly operator *(const Poly& lhs, const Term& t)
{
    Poly product (lhs);
    product *= t;
    return product;
}

Poly operator /(const Poly& lhs, const Term& t)
{
    Poly quotient (lhs);
    quotient /= t;
    return quotient;
}

//======================================================
// Poly| Poly arithmetic operator
//======================================================

Poly operator +(const Poly& left, const Poly& right)
{
    Poly sum(left);
    sum += right;
    // since some operations return a term with zero coef
    // we need to delete the zeros so that our verification
    // will be successful when doing poly | poly operations
    sum.delete_Zeros ();
    return sum;
}

Poly operator -(const Poly& left, const Poly& right)
{
    Poly difference (left);
    difference -= right;
    difference.delete_Zeros ();
    return difference;
}

Poly operator *(const Poly& left, const Poly& right)
{
    Poly product (left);
    product *= right;
    product.delete_Zeros ();
    return product;
}

Poly operator /(const Poly& left, const Poly& right)
{
    Poly quotient (left);
    quotient /= right;
    quotient.delete_Zeros ();
    return quotient;
}

Poly operator %(const Poly& lhs, const Poly& rhs)
{
    Poly division = lhs / rhs;
    return lhs - division *rhs;
}

//======================================================
// Poly comparison operator
//======================================================

bool operator ==(const Poly& lhs, const Poly& rhs)
{
    // if order is different poly is not equal
    if(lhs._order != rhs._order)
        return false;

    Sorted<Term>::Iterator left_it = lhs._poly.Begin ();
    Sorted<Term>::Iterator right_it = rhs._poly.Begin ();
    while(left_it != lhs._poly.End() && right_it != rhs._poly.End() )
    {
        //comparing coefficients of each term at
        if(*left_it != *right_it)
            return false;
        left_it++;
        right_it++;
    }
    return true;
}

bool operator !=(const Poly& lhs, const Poly& rhs)
{
    // if order is different poly is not equal
    if(lhs._order != rhs._order)
        return true;

    Sorted<Term>::Iterator left_it = lhs._poly.Begin ();
    Sorted<Term>::Iterator right_it = rhs._poly.Begin ();
    while(left_it != lhs._poly.End() && right_it != rhs._poly.End() )
    {
        //comparing coefficients of each term at
        if(*left_it != *right_it)
            return true;
        left_it++;
        right_it++;
    }
    return false;
}

bool operator >(const Poly& lhs, const Poly& rhs)
{
    if(lhs._order > rhs._order)
        return true;

    else if(lhs._order == rhs._order)
    {
        Sorted<Term>::Iterator left_it = lhs._poly.Begin ();
        Sorted<Term>::Iterator right_it = rhs._poly.Begin ();
        while(left_it != lhs._poly.End() && right_it != rhs._poly.End() )
        {
            if(*left_it > *right_it)
                return true;
            if(*left_it < *right_it)
                return false;

            right_it++;
            left_it++;
        }
    }
    //if lhs order < rhs then return false
    return false;
}

bool operator <(const Poly& lhs, const Poly& rhs)
{
    if(lhs._order < rhs._order)
        return true;
    else if(lhs._order == rhs._order)
    {
        Sorted<Term>::Iterator left_it = lhs._poly.Begin ();
        Sorted<Term>::Iterator right_it = rhs._poly.Begin ();
        while(left_it != lhs._poly.End() && right_it != rhs._poly.End() )
        {
            if(*left_it < *right_it)
                return true;
            if(*left_it > *right_it)
                return false;

            right_it++;
            left_it++;
        }
    }
    //if lhs order > rhs then return false
    return false;
}

//======================================================
// Poly insertion and extraction operators
//======================================================

ostream& operator <<(ostream& outs, const Poly& p)
{
    outs << "[ " ;
    Sorted<Term>::Iterator it = p._poly.Begin ();
    for ( ; it != p._poly.End ();  it++)
    {
        outs <<  *it << " " ;
    }
    outs << "]" ;
    return outs;
}

istream& operator >>(istream& ins, Poly& p)
{
    /*
     * Note input must always be like 3x^4  or +3x^4 or -3x^4
     * input like x^2 or x or 5 are not accepted
     * it must be in the format like number x ^ number
     * coef x ^ power even if coef was 1 or power was 0 or 1
     */
    ins.clear();
    ins.ignore(1000, '\n');

    string str;
    getline(ins, str);
    stringstream ss(str);


    Term t;
    Poly input;

    while(ss >> t)   {
        input += t;
    }

    p = input;
    return ins;
}

//======================================================
//  function to remove terms with zero coeffecient
//======================================================

Poly& Poly:: delete_Zeros()
{
    Sorted<Term>::Iterator it = _poly.Begin();
    for( ;it != _poly.End (); it++)
    {
        Term t(*it);
        if( t._exp != 0 && t._coef == 0)
            _poly.Remove_Node (it);
    }
    return *this;
}

