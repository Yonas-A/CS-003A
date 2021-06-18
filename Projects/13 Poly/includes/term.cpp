#include "../includes/term.h"

#include <cassert>
#include <iostream>

using namespace std;

Term::Term() {
    _coef = 0;
    _exp = 0;
}

Term::Term(double coeff, int exp) {
    _coef = coeff;
    _exp = exp;
}

//===================================================================
//  Term|Term compound assignment
//===================================================================

Term& Term::operator+=(const Term& rhs) {
    assert(_exp == rhs._exp);
    _coef = _coef + rhs._coef;
    return *this;
}

Term& Term::operator-=(const Term& rhs) {
    assert(_exp == rhs._exp);
    _coef = _coef - rhs._coef;
    return *this;
}

Term& Term::operator*=(const Term& rhs) {
    _exp = _exp + rhs._exp;
    _coef = _coef * rhs._coef;
    return *this;
}

Term& Term::operator/=(const Term& rhs) {
    if (rhs._exp > _exp) {
        _coef = 0;
        _exp = 0;
        return *this;
    } else {
        _exp = _exp - rhs._exp;
        _coef = _coef / rhs._coef;
        return *this;
    }
}

//===================================================================
//  Term |Unary minus
//===================================================================

Term Term::operator-() const {
    return Term(_coef * -1, _exp);
}

//===================================================================
//  Term|Term Arithmetic operators
//===================================================================

Term operator+(const Term& lhs, const Term& rhs) {
    assert(lhs._exp == rhs._exp);
    return Term(lhs._coef + rhs._coef, lhs._exp);
}

Term operator-(const Term& lhs, const Term& rhs) {
    assert(lhs._exp == rhs._exp);
    return Term(lhs._coef - rhs._coef, lhs._exp);
}

Term operator*(const Term& lhs, const Term& rhs) {
    return Term(lhs._coef * rhs._coef, lhs._exp + rhs._exp);
}

Term operator/(const Term& lhs, const Term& rhs) {
    if (rhs._exp > lhs._exp) {
        //if lhs exponent is less than rhs exp
        //then since we dont want negative exponent
        //we must return a term with 0 exp i.e [ 1x^0]
        return Term();
    } else
        return Term(lhs._coef / rhs._coef, lhs._exp - rhs._exp);
}

//===================================================================
//     Term|Term comparison operators
//===================================================================
bool operator==(const Term& lhs, const Term& rhs) {
    // for this project two terms are equal
    // if their exp is equal else they are not equal
    if (lhs._exp == rhs._exp)
        return true;
    return false;
}

bool operator!=(const Term& lhs, const Term& rhs) {
    if (lhs._exp != rhs._exp)
        return true;

    return false;
}

bool operator>(const Term& lhs, const Term& rhs) {
    if (lhs._exp > rhs._exp)
        return true;
    // for this project since two terms are equal
    // if their exp is equal we do not need to compare
    // their coefficeint because we are using a unique
    // sorted list and that means if their exponent is
    // equal we  just add the terms as one for some
    // poly operators

    return false;
}

bool operator<(const Term& lhs, const Term& rhs) {
    if (lhs._exp < rhs._exp)
        return true;

    return false;
}

//===================================================================

//===================================================================

ostream& operator<<(ostream& outs, const Term& t) {
    string Plus = "+";
    if (t._coef < 0)
        Plus = "";

    string var = "X^";

    if (t._exp == 1)
        outs << Plus << t._coef << "X";
    else if (t._exp == 0)
        outs << Plus << t._coef;
    else
        outs << Plus << t._coef << "X^" << t._exp;

    return outs;
}

istream& operator>>(istream& ins, Term& t) {
    int degree;   // takes the power of each term from input
    double coef;  // takes coef of each term
    char trash;

    ins >> coef >> trash >> trash >> degree;
    t = Term(coef, degree);
    return ins;
}
