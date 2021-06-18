#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <string>

using namespace std;


class Rational
{
public:

    Rational();

    Rational(int num, int denom);

    Rational(int w); // whole numbers


    // mutators
    void set(int num, int denom); // _num is set to the value of num
                                  // and _denom is set to denom value
    void set_num(int n);// _num is set to the value of n
    void set_denom(int d);// _denom is set to the value  of d

    // accessors
    int get_num() const;    //returns the numerator
    int get_denom() const;  //returns the denominator

    // error handling routines
    int error() const; // returns error state
    int is_error(); // checks for error and returns the error code
    string error_discription(); // gives brief about error


    void clear( ); // resets number to 0/1 and clears error state'


    //will return object whose error state is set
    //   if one of the operands is in error.
    friend Rational operator +(const Rational &num1,
                               const Rational &num2);
    friend Rational operator -(const Rational &num1,
                               const Rational &num2);
    friend Rational operator *(const Rational &num1,
                               const Rational &num2);
    friend Rational operator /(const Rational &num1,
                               const Rational &num2);


    //will print UNDEFINED if num is in error.
    friend ostream& operator <<(ostream &outs,
                                const Rational &num);
    friend istream& operator >>(istream &ins, Rational &num);


private:

    int _n; // numerator
    int _d; // denominator
    int _error; // error number

};

#endif // RATIONAL_H
