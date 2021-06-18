#ifndef POLY_H
#define POLY_H

#include "../Poly/includes/term.h"

class Poly
{
public:

    // CTORS
    Poly();

    Poly(double* coef, int order);

//BIG THREE

    Poly(const Poly& other);
    Poly& operator =(const Poly& rhs);
    ~Poly();


    //OPERATORS

    Term operator[](int order) const;
    // creates a term from polynomial at index [order]


    friend bool operator ==(const Poly& lhs, const Poly& rhs);
    friend bool operator !=(const Poly& lhs, const Poly& rhs);
    friend bool operator >(const Poly& lhs, const Poly& rhs);
    friend bool operator <(const Poly& lhs, const Poly& rhs);


    friend Poly operator +(const Poly& lhs, const Term& t);
    friend Poly operator +(const Poly& lhs, const Poly& rhs);

    friend Poly operator -(const Poly& p);
    friend Poly operator - (const Poly& lhs, const Poly& rhs);

    friend Poly operator *(const Poly& lhs, const Term& t);
    friend Poly operator *(const Poly& lhs, const Poly& rhs);

    friend Poly operator /(const Poly& lhs, const Poly& rhs);
    friend Poly operator %(const Poly& lhs, const Poly& rhs);

    friend ostream& operator << (ostream& outs, const Poly& p);
    friend istream& operator >> (istream& ins, Poly& p);

    int order() const; // returns _order

private:
    int _order;
    double* _coef;
    void fix_order();

};

#endif // POLY_H
