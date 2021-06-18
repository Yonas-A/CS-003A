#ifndef POLY_INTERFACE_H
#define POLY_INTERFACE_H

#include <iostream>

#include "../includes/poly.h"
#include "../includes/term.h"

using namespace std;

void addition(const Poly& p, const Poly& q);

void display_result(const Poly& p, const Poly& q);

void division(const Poly& p, const Poly& q);

void main_Interface();

void menu();

void multiplication(const Poly& p, const Poly& q);

void subtraction(const Poly& p, const Poly& q);

//================================================
//      function definitions
//================================================

void addition(const Poly& p, const Poly& q) {
    Poly sum = p + q;
    cout << endl
         << " " << p << " + " << q << endl
         << "       =" << sum << endl;

    if ((sum - q) == p) {
        cout << "\t\t       VERIFIED" << endl
             << endl;
    } else {
        cout << endl
             << "\n\t   ***VERIFICATION FAILED" << endl;
        cout << "   sum - q: " << sum - q << endl;
        cout << "   =/=: " << p << endl
             << endl;
    }
}

void display_result(const Poly& left, const Poly& right) {
    cout << endl
         << "      - - - - - - - - -  - - - -  " << endl;
    cout << endl
         << "P:     " << left;
    cout << endl
         << "Q:     " << right;
    cout << endl
         << endl;

    cout << "   = = = = = = = = = = p + q = = = = = = = = = =" << endl;
    addition(left, right);
    cout << "   = = = = = = = = = = q + p = = = = = = = = = =\n";
    addition(right, left);

    cout << "   = = = = = = = = = = p - q = = = = = = = = = =\n";
    subtraction(left, right);
    cout << "   = = = = = = = = = = q - p = = = = = = = = = =\n";
    subtraction(right, left);

    cout << "   = = = = = = = = = = p * q = = = = = = = = = =\n";
    multiplication(left, right);
    cout << "   = = = = = = = = = = q * p = = = = = = = = = =\n";
    multiplication(right, left);

    cout << "   = = = = = = = = = = p / q = = = = = = = = = =\n";
    division(left, right);
    cout << "   = = = = = = = = = = q / p = = = = = = = = = =\n";
    division(right, left);
}

void division(const Poly& p, const Poly& q) {
    Poly div = p / q;
    Poly rem = p % q;

    cout << endl
         << " " << p << " / " << q << endl
         << "       =" << div << endl
         << "             "
         << "rem  = " << rem << endl;

    //if r = p / q then r * q + rem should be equal to p:
    if (div * q + rem == p) {
        cout << "\t\t       VERIFIED" << endl
             << endl;
    }

    else {
        cout << endl
             << "\t\t        ***VERIFICATION FAILED"
             << endl;
        cout << "   div * q: " << div * q << endl;
        cout << "   div % q: " << rem << endl;
        cout << "   div * q + rem: " << div * q + rem
             << "=/=" << p << endl
             << endl;
    }
}

void main_Interface() {
    char command;
    bool done = false;

    Poly P;
    P += Term(4, 3);
    Poly Q;
    Q += Term(1, 1);
    P.delete_Zeros();
    Q.delete_Zeros();

    do {
        display_result(P, Q);
        menu();
        cin >> command;

        switch (toupper(command)) {
            case 'P':
                cout << "\nP: ";
                cin >> P;
                break;
            case 'Q':
                cout << "\nQ: ";
                cin >> Q;
                break;
            case 'X':
            case 'C':
                done = true;
                break;
        }
        //removing any terms with zero coefficents
        if (P != Poly() && Q != Poly()) {
            P.delete_Zeros();
            Q.delete_Zeros();
        }

    } while (!done);

    cout << endl
         << "\t=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=\n"
         << endl;
}

void menu() {
    cout << "[P]  [Q]   E[X]IT   : ";
}

void multiplication(const Poly& p, const Poly& q) {
    Poly result = p * q;
    Poly div = result / q;

    cout << endl
         << " " << p << " * " << q << endl
         << "       = " << result << endl;

    if (div == p)
        cout << "\t\t       VERIFIED" << endl
             << endl;

    else {
        cout << endl
             << "\t\t       ***VERIFICATION FAILED"
             << endl;
        cout << "   result / q: " << div << endl;
        cout << "   =/=: " << p << endl
             << endl;
    }
}

void subtraction(const Poly& p, const Poly& q) {
    Poly difference = p - q;
    Poly sum = difference + q;

    cout << endl
         << " " << p << " - " << q << endl
         << "       = " << difference << endl;

    if (sum == p)
        cout << "\t\t       VERIFIED" << endl
             << endl;

    else {
        cout << endl
             << "\t\t       ***VERIFICATION FAILED"
             << endl;
        cout << "   sub + q: " << sum << endl;
        cout << "   =/=: " << p << endl
             << endl;
    }
}

#endif  // POLY_INTERFACE_H
