#include "../Rational/includes/rational.h"

using namespace std;

/*====================
    CTORs:
====================*/
Rational::Rational():_n(0), _d(1), _error(0)
{

}

Rational::Rational(int num, int denom):_n(num), _d(denom), _error(is_error())
{

}

Rational::Rational(int w): _n(w), _d(1), _error(is_error())
{

}


/*====================
    mutators
====================*/

void Rational:: set(int num, int denom)
{
    if(!is_error())
    {
        _n = num;
        _d = denom;
    }

    else
    {
        _error = is_error();
    }
}

void Rational::set_num(int n)
{
    _n = n;
}

void Rational::set_denom(int d)
{
    if(!is_error())
        _d = d;

    else
    {
        _d = 0;
        _error = 1;
    }
}

/*====================
   accessors:
====================*/

int Rational::get_num() const
{
    return _n;
}

int Rational::get_denom() const
{
    return _d;
}
/*====================
    Error check:
====================*/

int Rational::error() const
{
    return _error;
}

int Rational::is_error()
{
    if( _d == 0)
        return 1;
    else
        return 0;

} // checks for error (if denom is zero) and returns the error code

string Rational::error_discription()
{
    return "UNDEFINED";
}

void Rational::clear() // resets number to 0/1 and clears error state
{
    _n = 0;
    _d = 1;
    _error = 0;
}

/*====================
 Overloaded operators:
====================*/
Rational operator +(const Rational &num1, const Rational &num2)
{
    if (num1.error() || num2.error())
    {
        return Rational(0, 0);
    }
    else
    {
       return Rational(num1.get_num() * num2.get_denom() +
                       num2.get_num() * num1.get_denom(),
                       num1.get_denom() * num2.get_denom());
    }

}

Rational operator -(const Rational &num1, const Rational &num2)
{

    if ( num1.error() || num2.error())
    {
        return Rational(0 , 0);
    }
    else
    {
        return Rational( num1.get_num() * num2.get_denom() -
                                num2.get_num() * num1.get_denom(),
                                num1.get_denom() * num2.get_denom());
    }

}

Rational operator *(const Rational &num1, const Rational &num2)
{

    if (num1.error() || num2.error())
    {
        return Rational(0, 0);
    }
    else
    {
       return Rational(num1.get_num() * num2.get_num() ,
                                num1.get_denom() * num2.get_denom());
    }

}

Rational operator /(const Rational &num1, const Rational &num2)
{
    if (num1.error() || num2.error())
    {
        return Rational(0 , 0); // makes rational UNDEFINED
    }
    else
    {
       return Rational(num1.get_num() * num2.get_denom() ,
                                    num1.get_denom() * num2.get_num());
    }

}

// ===============================================================
// insertion & extraction:

ostream& operator << ( ostream &outs, const Rational &num )
{
    if ( num._error != 0 )
            outs << "UNDEFINED";
    else
        outs << num.get_num() << "/" << num.get_denom();

    return outs;
}

istream& operator >>(istream &ins, Rational &num)
{
    char slash; // holds the division sign
    num.clear();  // value of object gets cleared

    ins >> num._n >> slash >> num._d;
    num.set_num(num._n);
    num.set_denom(num._d);

    return ins;
}
