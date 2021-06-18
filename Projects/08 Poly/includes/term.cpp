#include "../includes/term.h"

#include <assert.h>

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

//used in Poly division operator
Term operator/(const Term& lhs, const Term& rhs) {
    if (rhs._exp > lhs._exp) {
        //if lhs exponent is less than rhs exp
        //then since we dont want negative exponent
        //we must return a term with 0 exp i.e [ 1x^0]
        return Term();
    } else {
        return Term(lhs._coef / rhs._coef, lhs._exp - rhs._exp);
    }
}

bool operator==(const Term& lhs, const Term& rhs) {
    assert(lhs._exp == rhs._exp);

    if (lhs._coef == rhs._coef) {
        return true;
    }
    return false;
}

bool operator!=(const Term& lhs, const Term& rhs) {
    assert(lhs._exp == rhs._exp);
    if (lhs._coef != rhs._coef) {
        return true;
    }
    return false;
}

bool operator>(const Term& lhs, const Term& rhs) {
    assert(lhs._exp == rhs._exp);
    if (lhs._coef > rhs._coef) {
        return true;
    }
    return false;
}

bool operator<(const Term& lhs, const Term& rhs) {
    assert(lhs._exp == rhs._exp);
    if (lhs._coef < rhs._coef) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& outs, const Term& t) {
    char Plus = '+';
    if (t._coef < 0)
        Plus = '\0';

    if (t._coef == 0.0) {
        outs << "";
    } else {
        outs << Plus << t._coef << "x^" << t._exp;
    }

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
