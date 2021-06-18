#include <iostream>
#include <string.h>
#include <assert.h>
#include <sstream>

#include "../Poly/includes/poly.h"
#include "../Poly/includes/term.h"
#include "../../!includes/Array_Function/array_function.h"


Poly::Poly()
{
    const bool debug = false;
    if (debug)
    {
        cout << endl << "Poly() CTOR"<<endl;
    }

    _order = 0;
    _coef = allocate<double>(_order + 1);
    initialize <double>(_coef , _order + 1);
}

Poly::Poly(double* coef, int order)
{
    const bool debug = false;
    if (debug){
        cout << endl << "Poly(double* ,int) CTOR"<<endl;
    }

    _order = order;
    delete_array(_coef);

    _coef = allocate<double>(_order + 1);
    initialize(_coef, _order + 1);
    copy(_coef, coef, order + 1 );

}

//BIG THREE

Poly::Poly(const Poly& other)
{
    const bool debug = false;
    if (debug){
        cout<<"Poly() COPY CTOR"<<endl;
    }

    _order = other._order;
    _coef = allocate<double> (_order + 1);
    copy(_coef, other._coef, _order + 1);

}

Poly& Poly:: operator =(const Poly& rhs)
{
    const bool debug = false;
    if (debug){
        cout << "Poly:: = ( )" << endl;
    }


    if( this == &rhs) // self reference
        return *this;

    if (_coef != nullptr)
        delete[] _coef;

    _order = rhs._order;
    _coef = allocate<double>(_order + 1);
    copy(_coef, rhs._coef, _order + 1);

    return *this;

 }

Poly:: ~Poly()
{
    const bool debug = false;
    if (debug){
        cout << "~Poly() destructor" << endl;
    }

    delete[] _coef;
    _coef = nullptr;
}

//=================================OPERATORS

//bracket operator to make terms from Poly
Term Poly:: operator[](int order) const
{
    return Term ( _coef[order], order);
}

//Comparison between two Poly
bool operator ==(const Poly& lhs, const Poly& rhs)
{
    // if order is different poly is not equal
    if(lhs.order() != rhs.order())
        return false;

    for(int i = 0; i < lhs.order() + 1; i++)
    {
    //comparing coefficients of each term at i
        if(lhs[i] != rhs[i])
            return false;
    }

// if two poly are identical return true
    return true;
}

bool operator !=(const Poly& lhs, const Poly& rhs)
{
    if(lhs.order() != rhs.order())
        return true;

    for(int i = lhs.order(); i >= 0; i--)
    {
     //comparing coefficients of each term at i
        if(lhs[i] != rhs[i])
            return true;
    }

// if two poly are identical return false
    return false;
}

bool operator >(const Poly& lhs, const Poly& rhs)
{
    if(lhs.order() > rhs.order())
        return true;

    else if(lhs.order() == rhs.order())
    {
        //if order is equal compare each coef
        for(int i = lhs.order(); i >= 0; i--)
        {
         //if at index i lhs coef greater than lhs coef
             if(lhs[i] > rhs[i])
                 return true;

         //if at index i lhs coef greater than lhs coef
             if(lhs[i] < rhs[i])
                return false;
        }
    }

//if lhs order less than rhs then return false
    return false;
}

bool operator <(const Poly& lhs, const Poly& rhs)
{
    if(lhs.order() < rhs.order())
        return true;

    else if(lhs.order() == rhs.order())
    {
        //if order is equal compare each coef
        for(int i = lhs.order(); i >= 0; i--)
        {
            if(lhs[i] < rhs[i])
                return true;

            if(lhs[i] > rhs[i])
                return false;
        }
    }

    //if lhs order > rhs then return false
    return false;
}


//====  + - * and / operators   =========================

Poly operator +(const Poly& lhs, const Term& t)
{
    Poly result(lhs);

    if(t._exp > lhs.order())
    {
        //if term exponent is greater, need a large space for result

        result._order = t._exp;
        result._coef = resize<double>(result._coef, lhs.order() + 1,
                                      result.order() + 1);
        //resizing the space for result poly
    }

    result._coef[t._exp] = result._coef[t._exp] +  t._coef;
    // add two coefs from lhs and t
    return result;
}

Poly operator +(const Poly& lhs, const Poly& rhs)
{
    Poly result(lhs); // make result  using copy COTR

    if(rhs > lhs)
    {

// if rhs is greater than lhs result must equal rhs
        result = rhs;
        for (int i = 0; i < lhs.order() + 1; i++)
        {
            result = result + lhs[i] ;
            //adding each term in lhs to result Poly
            result.fix_order();
        }
        result.fix_order();
        return result;
    }

    for (int i = 0; i < rhs.order() + 1; i++)
    {
        //adding each term in rhs to result Poly
        result = result + rhs[i] ;
    }

    result.fix_order();
    return result;
}


Poly operator -(const Poly& p)
{
    Poly result(p);
    for(int i = 0; i < result.order() + 1; i++)
    {
        result._coef[i] *= -1;
//making each coef in result Poly a negative
    }

    return result;
}

Poly operator -(const Poly& lhs, const Poly& rhs)
{

    Poly result;
    Poly temp = -rhs;
//    for (int i = 0; i < lhs.order() + 1; i++)
//    {
        result = lhs + temp;
//    }

    result.fix_order();
    return result;

}


Poly operator *(const Poly& lhs, const Term& t)
{
    Poly result;

    //reallocating result Poly to a size equal to
    //the sum of the lhs order and terms._exp + 1;
    result._coef = resize<double>(result._coef, result.order() + 1,
                            lhs.order() + t._exp + 1);

    result._order = lhs.order() + t._exp ;
//result order becomes result array size - 1;

    for (int i = 0; i < lhs.order() + 1; i++)
    {
        result._coef[t._exp + i] = lhs._coef[i] * t._coef;
//multiplying lhs coef at index by terms coef

    }

    return result;
}

Poly operator *(const Poly& lhs, const Poly& rhs)
{
    Poly result;

    for (int i = 0; i  < rhs.order() + 1; i++)
    {
        result = result + lhs * rhs[i];
    //adding the product of polynomial lhs and term rhs[i] to
    //result. result is reallocated automatically by Poly * term
    }
    result.fix_order();
    return result;

}

Poly operator /(const Poly& lhs, const Poly& rhs)
{
    Poly result;
    Poly hold(lhs);

    for (int i = 0; i < result.order() + 1; i++)
    {
        result = result + (hold[hold.order() ] / rhs[rhs.order()]);

        hold = hold - ( rhs * result[result.order() -i]);
        hold.fix_order();

    }
    result.fix_order();
    return result;
}

Poly operator %(const Poly& lhs, const Poly& rhs)
{
    Poly div = lhs/rhs;
    //returning the remainder of Poly div
    return  lhs - div * rhs;
}


//accessor for order
int Poly:: order() const
{
    return _order;
}

// erases all highest terms with zero coefs
void Poly:: fix_order()
{
    for (int i = 0; i < _order +1; i++)
    {
        if( _coef[_order] == 0.0)
        {
            _order--;
        }
    }
}


//Extraction and insertion operators
ostream& operator <<(ostream& outs, const Poly& p)
{
    outs << "[ " ;
    for (int i = p.order(); i >= 0; i --)
    {
        outs <<  p[i] <<" " ;
    }
    outs << "]" ;
    return outs;
}

istream& operator >>(istream& ins, Poly& p)
{
    ins.clear();
    ins.ignore(1000, '\n');

    Term t;
    Poly input;
    bool end = true;


    while(end)
    {
        ins >> t;
        input = input + t;

        if(t._coef == 0.0)
        {
            end = false;
        }
    }

    p = input;
    return ins;
}















