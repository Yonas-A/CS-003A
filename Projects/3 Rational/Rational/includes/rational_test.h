#ifndef RATIONAL_TEST_H
#define RATIONAL_TEST_H


#include <iostream>
#include <string>
#include <iomanip>

#include "../Rational/includes/rational.h"

using namespace std;

void test_rational();
//a function to test the ouput of rational class
//Precondition: two rational objects are created and set to default
//              function calls display_result and display_menu
//              to output values stored in the objects and /or
//              to change values of the two rational objects

void display_result( Rational num1, Rational num2);
//Precondition: num1 and num2 are set to two rational values
//Postcondition: the values of  the two rational is printed to
//              the screen along with result of the two on
//              the four (+,-,* ,\) operators

void display_menu();
//displays the option for user to change the rational numbers
//  and/or exit program



void display_menu()
{
    cout<<"[A]  [B]   E[X]IT   : ";
}

void test_rational()
{
    cout << "\n\t======================TOP======================\n";
    char command;
    bool done = false;

    Rational A, B;

    cout << "Default Values\n"; // first output all 0/1
    do
    {
        display_result(A, B);
        display_menu();
        cin >> command;

        switch(toupper(command))
        {
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

    }while (!done);

    cout << "\n\t======================END======================\n";
}

void  display_result(Rational num1, Rational num2)
{
    cout << endl << "========================" << endl;
    cout << "A: " << num1 << "\tB: " << num2 << endl << endl;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    cout << endl << "========================" << endl;
}




#endif // RATIONAL_TEST_H
