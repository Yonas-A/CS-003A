/*
 * Author: Yonas Adamu
 * Project: Polynomials Class
 * Purpose: Make a class named Poly that takes two pairs polynomials
 *          of different or same order and performes addition,
 *          subtraction, multiplication and division and checks if
 *          the results are correct
 *
 * NOTE: input extraction works if the end is marked with 0x^0 only.
 */

#include <iostream>

#include "../includes/polynomial_test.h"

using namespace std;

//=================================================================//

//-----------------------------------------------------------------//
int main() {
    test_Poly();
    cout << "\n\t= = = = = = = END TEST = = = = = = = = = =" << endl;

    return 0;
}
