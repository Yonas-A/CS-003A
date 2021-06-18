#ifndef POLY_TEST_H
#define POLY_TEST_H

#include <iostream>

#include "../includes/poly.h"

using namespace std;

void test_big_three();

void test_delete_Zeros();

void test_Poly_arithmetic_Term();

void test_Poly_arithmetic_Poly();

void test_Poly_compound_term();

void test_Poly_compound_Poly();

void test_Poly_extraction();

void test_Poly_unary();

/*=================================
 simple test functions definitions
=================================*/

void test_big_three() {
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    cout << "       Poly Big three " << endl;
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;

    cout << endl
         << " - - - Default Ctor Poly A - - - " << endl;
    Poly A;
    A += Term(1, 3);
    A += Term(3, 5);
    cout << "Poly A:    " << A << endl
         << endl;

    cout << endl
         << " - - - Ctor(array, order): Poly B - - - " << endl;
    int arr[5] = {2, 3, 4, 9, 5};
    Poly B(arr, 4);
    cout << endl
         << "Poly B:    " << B << endl
         << endl;

    cout << "   - - - Copy ctor: Poly C(B) - - - " << endl;
    Poly C(B);
    cout << "Poly B:    " << B << endl;
    cout << "Poly C:    " << C << endl
         << endl;

    cout << "  - - - Poly operator =(): Poly D = B - - - " << endl;
    Poly D;
    D = B;
    cout << "Poly B:    " << B << endl;
    cout << "Poly D:    " << D << endl
         << endl;

    cout << "   - - - B = A - - - " << endl;
    B = A;
    cout << "Poly B:    " << B << endl;
    cout << "Poly A:    " << A << endl;
}

void test_delete_Zeros() {
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    cout << "       delete_Zeros()" << endl;
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    int arr[5] = {2, 3, 4, 9, 7};
    int b_arr[5] = {
        2,
        3,
        4,
        6,
        7,
    };
    Poly A(arr, 4);
    Poly B(b_arr, 4);

    cout << "Poly A:    " << A << endl;
    cout << "Poly B:    " << B << endl;

    cout << endl
         << "   - - - - - - - - - - - - - - " << endl;

    cout << endl
         << "    - - - C = A - B - - - " << endl;
    Poly C = A - B;
    cout << A << " + [" << B << "]" << endl
         << endl;
    cout << "  =  " << C << endl;
    C.delete_Zeros();
    cout << "After delete_Zeros " << endl;
    cout << "Poly C = " << C << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;
}

void test_Poly_arithmetic_Term() {
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    cout << "       Poly | Term arithmetic operator" << endl;
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    int arr[5] = {2, 3, 4, 9, 5};
    int b_arr[4] = {
        2,
        3,
        4,
        7,
    };
    Poly A(arr, 4);
    Poly B(b_arr, 3);
    Term x(4, 5);
    Term t(3, 4);

    cout << "Poly A:    " << A << endl;
    cout << "Poly B:    " << B << endl;
    cout << "Term x:    " << x << endl;
    cout << "Term t:    " << t << endl;

    cout << endl
         << "   - - - - - - - - - - - - - - " << endl;

    cout << endl
         << "    - - - C = A + x - - - " << endl;
    Poly C = A + x;
    cout << A << " + [" << x << "]" << endl
         << endl;
    cout << "  =  " << C << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "    - - - D = B - t - - - " << endl;
    Poly D = B - t;
    cout << B << " - [" << t << "]" << endl
         << endl;
    cout << "  =  " << D << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    Poly E;
    E = D * t;
    cout << endl
         << "    - - - E = D * t - - - " << endl;
    cout << D << " * [" << t << "]" << endl
         << endl;
    cout << "  =  " << E << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    Poly F;
    F = E / t;
    cout << endl
         << "    - - - F = E / t - - - " << endl;
    cout << E << " / [" << x << "]" << endl
         << endl;
    cout << "  =  " << F << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;
}

void test_Poly_arithmetic_Poly() {
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    cout << "       Poly | Poly arithmetic operator" << endl;
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    int arr[5] = {2, 3, 4, 9, 5};
    int b_arr[4] = {
        2,
        3,
        4,
        7,
    };
    Poly A(arr, 4);
    Poly B(b_arr, 3);

    cout << "Poly A:    " << A << endl;
    cout << "Poly B:    " << B << endl;

    cout << endl
         << "   - - - - - - - - - - - - - - " << endl;

    cout << endl
         << "    - - - C = A + B - - - " << endl;
    Poly C = A + B;
    cout << A << " + " << B << endl
         << endl;
    cout << "  =  " << C << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "    - - - D = B - A + Term(8,9) - - - " << endl;
    Poly D = B - A + Term(8, 9);
    cout << B << " - " << A << " + [" << Term(8, 9) << "]" << endl
         << endl;
    cout << "  =  " << D << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "    - - - E = D * B - - - " << endl;
    Poly E;
    cout << D << " * " << B << endl
         << endl;
    E = D * B;
    cout << "  =  " << E << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "    - - - F = E / B - - - " << endl;
    Poly F;
    cout << E << " / " << B << endl
         << endl;
    F = E / B;
    cout << "  =  " << F << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;
}

void test_Poly_compound_term() {
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    cout << "       Poly | Term compound operator" << endl;
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    int arr[5] = {2, 3, 4, 9, 5};
    int b_arr[4] = {
        2,
        3,
        4,
        7,
    };
    Poly A(arr, 4);
    Poly B(b_arr, 3);
    Term x(4, 5);
    Term t(3, 4);

    cout << "Poly A:    " << A << endl;
    cout << "Poly B:    " << B << endl;
    cout << "Term x:    " << x << endl;
    cout << "Term t:    " << t << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "    - - - A += (t) - - - " << endl;
    cout << A << "  +=  " << t << endl;
    A += t;
    cout << "   A =   " << A << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "    - - - B += x - - - " << endl;
    cout << B << " +=  " << x << endl;
    B += x;
    cout << "   B =  " << B << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "    - - - A -=(t) - - - " << endl;
    cout << A << "     -=  " << t << endl;
    A -= t;
    cout << "   A =  " << A << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "    - - - B *= (t) - - - " << endl;
    cout << B << "     *=  " << t << endl;
    B *= t;
    cout << "   B =  " << B << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "    - - - B /= (x) - - - " << endl;
    cout << B << "     /=  " << x << endl;
    B /= x;
    cout << "   B =  " << B << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;
}

void test_Poly_compound_Poly() {
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    cout << "       Poly | Poly Compound operator" << endl;
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    int arr[5] = {2, 3, 4, 9, 5};
    int b_arr[4] = {
        2,
        3,
        4,
        7,
    };
    Poly A(arr, 4);
    Poly B(b_arr, 3);
    Term x(4, 5);
    Term t(3, 4);

    cout << "Poly A:    " << A << endl;
    cout << "Poly B:    " << B << endl;
    cout << "Term x:    " << x << endl;
    cout << "Term t:    " << t << endl;

    cout << endl
         << "   - - - - - - - - - - - - - - " << endl;

    cout << endl
         << "    - - - A += B - - - " << endl;
    cout << A << " += " << B << endl
         << endl;
    A += B;
    cout << "  A =  " << A << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    cout << endl
         << "   - - - B -= (A) - - - " << endl;
    cout << B << " -= " << A << endl
         << endl;
    B -= A;
    cout << "  B =  " << B << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    Poly C;
    C += Term(1, 3);
    C += Term(3, 5);
    cout << "Poly C:    " << C << endl;

    cout << endl
         << " - - - B *= (C) - - - " << endl;
    cout << B << " *= " << C << endl
         << endl;
    B *= C;
    cout << "  B =  " << B << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;

    B += Term(6, 9);
    cout << endl
         << " - - - B /= (C) - - - " << endl;
    cout << B << " /= " << C << endl
         << endl;
    B /= C;
    cout << "  B =  " << B << endl;
    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;
}

void test_Poly_extraction() {
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    cout << "       Poly extraction " << endl;
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;

    cout << endl
         << " - - - Default Ctor Poly A - - - " << endl;
    Poly A;
    cout << "Please enter a Poly" << endl;
    cin >> A;
    cout << "Poly A:    " << A << endl
         << endl;
}

void test_Poly_unary() {
    cout << endl
         << "   - - - - - - - - - - - - - - \n"
         << endl;
    int arr[5] = {2, 3, 4, 9, 5};
    Poly A(arr, 4);
    Poly B;
    cout << "Poly A:    " << A << endl;
    cout << "Poly B:    " << B << endl;

    cout << endl
         << "   - - - - - - - - - - - - - - " << endl;

    cout << endl
         << "    - - - B = (-A)  - - - " << endl;
    cout << "       Before" << endl;
    cout << "  A =  " << A << endl;
    cout << "  B =  " << B << endl;
    B = -A;
    cout << "       After" << endl;
    cout << "  A =  " << A << endl;
    cout << "  B =  " << B << endl;

    cout << endl
         << "   - - - - - - - - - - - - - -" << endl;
}

#endif  // POLY_TEST_H
