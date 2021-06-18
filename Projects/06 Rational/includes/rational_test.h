#ifndef RATIONAL_TEST_H
#define RATIONAL_TEST_H

#include <iomanip>
#include <iostream>
#include <string>

#include "../includes/rational.cpp"

using namespace std;

/**
 * @brief Creates two Rational objects, calls display_result and display_menu to
 *  output two Rations to console and/or to change values of the two Rational
 */
void test_rational();

/**
 * @brief Performs the four Rational operations (+, -, *, /) on the two Rational
 * objects and displays each results to the console
 * @param num1 the first Rational object.
 * @param num2 the second Rational object.
 */
void display_result(Rational num1, Rational num2);

/**
 * @brief Displays the menu options to the console
 */
void display_menu();

void display_menu() {
    cout << "[A]  [B]   E[X]IT   : ";
}

void test_rational() {
    cout << "\n\t======================TOP======================\n";
    char command;
    bool done = false;

    Rational A, B;

    cout << "Default Values\n";  // first output all 0/1
    do {
        display_result(A, B);
        display_menu();
        cin >> command;

        switch (toupper(command)) {
            case 'A':
                cout << "\nA: ";
                cin >> A;
                break;

            case 'B':
                cout << "\nB: ";
                cin >> B;
                break;

            case 'X':
            case 'Q':
                done = true;
                break;
        }

    } while (!done);

    cout << "\n\t======================END======================\n";
}

void display_result(Rational num1, Rational num2) {
    cout << endl
         << "========================" << endl;
    cout << "A: " << num1 << "\tB: " << num2 << endl
         << endl;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    cout << endl
         << "========================" << endl;
}

#endif  // RATIONAL_TEST_H
