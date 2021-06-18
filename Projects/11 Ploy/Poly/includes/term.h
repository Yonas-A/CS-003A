#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;



struct Term
{
public:

    double _coef;
    int _exp;

    Term(double coeff, int exp);
    Term();


    Term& operator +=(const Term& rhs);
    Term& operator -=(const Term& rhs);
    Term& operator *=(const Term& rhs);
    Term& operator /=(const Term& rhs);

    Term operator -() const;
    //returns the negative of the term

    friend Term operator +( const Term& rhs, const Term& lhs);
    friend Term operator -( const Term& rhs, const Term& lhs);
    friend Term operator *( const Term& rhs, const Term& lhs);
    friend Term operator /( const Term& lhs, const Term& rhs);


    friend bool operator ==(const Term& lhs, const Term& rhs);
    friend bool operator !=(const Term& lhs, const Term& rhs);
    friend bool operator >(const Term& lhs, const Term& rhs);
    friend bool operator <(const Term& lhs, const Term& rhs);


    friend ostream& operator <<(ostream& outs, const Term& t);
    friend istream& operator >>(istream& ins,  Term& t);

};

#endif // TERM_H
