#ifndef TEST_POLY_H
#define TEST_POLY_H
#include <iostream>

#include "../../!includes/Array_Function/array_function.h"
#include "../includes/poly.h"
#include "../includes/term.h" 
// #include "../includes/poly.cpp"
// #include "../includes/term.cpp" 

using namespace std;

//==============================================================
//   user interface function declaration
//==============================================================

void display_menu();
//displays the menu

void test_Poly();
//takes all input from keyboard

void display_all(const Poly& lhs, const Poly& rhs);
//displays all the operations with poly p and q

//==============================================================
//   poly test function declaration
//==============================================================
void Poly_add(const Poly& rhs, const Poly& lhs);
// function to test Poly Plus operator

void Poly_sub(const Poly& rhs, const Poly& lhs);
// function to test Poly Minus operator and negation operator

void Poly_mult(const Poly& rhs, const Poly& lhs);
// function to test Poly operator *

void Poly_div(const Poly& rhs, const Poly& lhs);
// function to test Poly operator /

//==============================================================
//   Poly test function definitions
//==============================================================

void display_menu() {
    cout << "[P]  [Q]   E[X]IT   : ";
}

void test_Poly() {
    char command;
    bool done = false;

    Poly a;
    a = (a + Term(1, 1) + Term(4, 3)) + Term(2, 4);
    Poly b;
    b = b + Term(1, 1);

    do {
        display_all(a, b);
        display_menu();
        cin >> command;

        switch (toupper(command)) {
            case 'P':
                cout << "\nP: ";
                cin >> a;
                break;
            case 'Q':
                cout << "\nQ: ";
                cin >> b;
                break;
            case 'X':
            case 'C':
                done = true;
                break;
        }

    } while (!done);
}

void display_all(const Poly& lhs, const Poly& rhs) {
    cout << "\n     ==========================================\n";
    cout << "\nP: " << lhs << endl
         << "Q: " << rhs << endl;
    cout << endl
         << endl;

    cout << "   ================== p + q ==================\n";
    Poly_add(lhs, rhs);
    cout << "   ================== q + p ==================\n";
    Poly_add(rhs, lhs);

    cout << "   ================== p - q ==================\n";
    Poly_sub(lhs, rhs);
    cout << "   ================== q - p ==================\n";
    Poly_sub(rhs, lhs);

    cout << "   ================== p * q ==================\n";
    Poly_mult(lhs, rhs);
    cout << "   ================== q * p ==================\n";
    Poly_mult(rhs, lhs);

    cout << "   ================== p / q ==================\n";
    Poly_div(lhs, rhs);
    cout << "   ================== q / p ==================\n";
    Poly_div(rhs, lhs);
}

void Poly_add(const Poly& p, const Poly& q) {
    Poly sum = p + q;

    cout << endl;
    cout << "    " << p << " + " << q << endl
         << "    =" << sum << "     ";

    if ((sum - q) == p) {
        cout << "VERIFIED" << endl;
    }

    else {
        cout << endl
             << "\n\t   ***VERIFICATION FAILED" << endl;
        cout << "   sum - q: " << sum - q << endl;
        cout << "   =/=: " << p << endl;
    }
}

void Poly_sub(const Poly& p, const Poly& q) {
    Poly sub = p - q;
    Poly add = sub + q;

    cout << endl;
    cout << "   " << p << " - " << q << endl
         << "   = " << sub << "    ";

    if (add == p) {
        cout << "VERIFIED" << endl;
    }

    else {
        cout << endl
             << "\n   ***VERIFICATION FAILED" << endl;
        cout << "   sub + q: " << add << endl;
        cout << "   =/=: " << p << endl;
    }
    cout << endl;
}

void Poly_mult(const Poly& p, const Poly& q) {
    Poly result = p * q;
    Poly div = result / q;

    cout << endl;
    cout << "   " << p << " * " << q << endl
         << "   = " << result << "     ";

    if (div == p) {
        cout << "VERIFIED" << endl;
    }

    else {
        cout << endl
             << "\n   ***VERIFICATION FAILED" << endl;
        cout << "   result / q: " << div << endl;
        cout << "   =/=: " << p << endl;
    }
    cout << endl;
}

void Poly_div(const Poly& p, const Poly& q) {
    Poly div = p / q;
    Poly rem = p % q;

    cout << endl;
    cout << "   " << p << " / " << q << endl
         << "    ="
         << div << "  rem = " << rem << "   ";

    //if r = p / q then r * q + rem should be equal to p:
    if (div * q + rem == p) {
        cout << "VERIFIED" << endl;
    }

    else {
        cout << endl
             << "\n   ***VERIFICATION FAILED" << endl;
        cout << "   div * q: " << div * q << endl;
        cout << "   div % q: " << rem << endl;
        cout << "   div * q + rem: " << div * q + rem << "=/="
             << p << endl;
    }
    cout << endl;
}

#endif  // TEST_POLY_H
