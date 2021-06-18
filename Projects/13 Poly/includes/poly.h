#ifndef POLY_H
#define POLY_H

#include "../../!includes/Sorted_List/sorted.h"
#include "../includes/term.h"

class Poly {
   public:
    // CTORS

    Poly();
    Poly(int term_array[], int order);

    //BIG THREE

    ~Poly();
    Poly(const Poly& other);
    Poly& operator=(const Poly& rhs);

    // Poly | Term compound assignement operator
    Poly& operator+=(const Term& t);
    Poly& operator-=(const Term& t);
    Poly& operator*=(const Term& t);
    Poly& operator/=(const Term& t);

    //Poly | Poly compound assignement operator
    Poly& operator+=(const Poly& RHS);
    Poly& operator-=(const Poly& RHS);
    Poly& operator*=(const Poly& RHS);
    Poly& operator/=(const Poly& RHS);

    Poly operator-() const;
    // returns a negative of the rhs poly

    // Poly| Term arithmetic operator
    friend Poly operator+(const Poly& lhs, const Term& t);
    friend Poly operator-(const Poly& lhs, const Term& t);
    friend Poly operator*(const Poly& lhs, const Term& t);
    friend Poly operator/(const Poly& lhs, const Term& t);

    // Poly| Poly arithmetic operator
    friend Poly operator+(const Poly& lhs, const Poly& rhs);
    friend Poly operator-(const Poly& lhs, const Poly& rhs);
    friend Poly operator*(const Poly& lhs, const Poly& rhs);
    friend Poly operator/(const Poly& lhs, const Poly& rhs);
    friend Poly operator%(const Poly& lhs, const Poly& rhs);

    // Poly comparison operator
    friend bool operator==(const Poly& lhs, const Poly& rhs);
    friend bool operator!=(const Poly& lhs, const Poly& rhs);
    friend bool operator>(const Poly& lhs, const Poly& rhs);
    friend bool operator<(const Poly& lhs, const Poly& rhs);

    // Poly insertion and extraction operators
    friend ostream& operator<<(ostream& outs, const Poly& p);
    friend istream& operator>>(istream& ins, Poly& p);

    //removes terms from Poly with zero coef
    Poly& delete_Zeros();
    // calls Remove_Node of Sorted class function
   private:
    Sorted<Term> _poly;  //descending sorted list
    int _order;
};

#endif  // POLY_H
