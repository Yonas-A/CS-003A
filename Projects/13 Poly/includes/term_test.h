#ifndef TERM_TEST_H
#define TERM_TEST_H

#include "../includes/term.h"

void test_term_comparison();
// test for term comparison operators

void test_term_operators();
// test for term *, + , - , / operators

void test_other_operators();
// test for +=, -=, *= ,/= operators and unary -()

void test_term_comparison() {
    cout << endl
         << " - - - test term comparison  - - - " << endl
         << endl;
    Term a(4, 5);
    Term b(4.4, 5);

    cout << "A: " << a << "     B: " << b << endl;
    if (a > b)
        cout << "A is greater than b" << endl;
    if (a == b)
        cout << "A is equal to B" << endl;
    if (a < b)
        cout << "A is less than B" << endl;
    if (a != b)
        cout << "A is not equal to B" << endl;

    cout << "       - - - - - - - - - - - - - " << endl
         << endl;
    Term c(4, 5);
    Term d(4, 3);

    cout << "C: " << c << "     D: " << d << endl;
    if (c > d)
        cout << "C is greater than D" << endl;
    if (a == b)
        cout << "C is equal to D" << endl;
    if (a < b)
        cout << "C is less than D" << endl;
    if (a != b)
        cout << "C is not equal to D" << endl;

    Term e(2, 8);
    Term f(2, 8);
    cout << "       - - - - - - - - - - - - - " << endl
         << endl;
    cout << "E: " << e << "     F: " << f << endl;
    if (e > f)
        cout << "E is greater than F" << endl;
    if (e == f)
        cout << "E is equal to F" << endl;
    if (e < f)
        cout << "E is less than F" << endl;
    if (e != f)
        cout << "E is not equal to F" << endl;
    cout << "  - - - end of test - - - " << endl
         << endl;
}

void test_term_operators() {
    Term a(4, 5);
    Term b(4.4, 5);
    cout << "A: " << a << "     B: " << b << endl;

    cout << "A + B = " << a + b << endl;
    cout << "B + A = " << b + a << endl;
    cout << "A - B = " << a - b << endl;
    cout << "B - A = " << b - a << endl;
    cout << "A * B = " << a * b << endl;
    cout << "B * A = " << b * a << endl;
    cout << "A / B = " << a / b << endl;
    cout << "B / A = " << b / a << endl;

    cout << "       - - - - - - - - - - - - - " << endl
         << endl;
    Term e(2, 8);
    Term f(2, 8);
    cout << "E: " << e << "     F: " << f << endl;

    cout << "E + F = " << e + f << endl;
    cout << "E - F = " << e - f << endl;
    cout << "E * F = " << e * f << endl;
    cout << "E / F = " << e / f << endl;
    cout << "       - - - - - - - - - - - - - " << endl
         << endl;
}

void test_other_operators() {
    Term a(4, 5);
    Term b(9, 5);
    Term c(7, 6);
    Term d(4, 6);
    Term e(2, 1);
    Term f(2, 8);
    Term g(3, 7);
    Term h(9, 9);
    Term i(3, 9);
    Term j(2, 5);
    Term t(4, 3);

    cout << "A: " << a << "     B: " << b << endl;
    cout << "C: " << c << "     D: " << d << endl;
    cout << "E: " << e << "     F: " << f << endl;
    cout << "G: " << g << "     H: " << h << endl;
    cout << "I: " << i << "     J: " << j << endl;
    cout << "T: " << t << endl;

    a += b;
    c -= d;
    e *= f;
    g /= h;
    i /= j;

    cout << "A += B:  " << a << endl;

    cout << "C -= D:  " << c << endl;
    cout << "E *= F:  " << e << endl;
    cout << "G /= H:  " << g << endl;
    cout << "I /= J:  " << i << endl;
    cout << "-T:  " << -t << endl;
    cout << "T:  " << t << endl;

    Term s;
    cout << "Enter a term: ";

    cin >> s;
    cout << "Entered term is:  " << s;
}

#endif  // TERM_TEST_H
