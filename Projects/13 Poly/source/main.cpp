/**
 * Author: Yonas Adamu
 * Project: Polynomial Class with a descending unique sorted list
 * Purpose: write Poly class that has the power to perform multiplication
 *          addition, division and subtractions
 *
 * NOTE: input extraction works only if the inputs are in the format
 *          coef x ^ power without space.
 */

#include <iostream>

#include "includes/poly_test.h"
#include "includes/term_test.h"
#include "interface/poly_interface.h"

using namespace std;

int main() {
    // ==================================================================
    // test for polynomial interface
    // ==================================================================

    main_Interface();

    // ==================================================================
    //      simple test functions for Term
    // ==================================================================

    //    test_term_comparison();
    //    test_term_operators ();
    //    test_other_operators ();

    // ==================================================================
    //      simple test functions for Poly
    // ==================================================================

    //    test_big_three ();
    //    test_delete_Zeros ();
    //    test_Poly_arithmetic_Term ();
    //    test_Poly_arithmetic_Poly ();
    //    test_Poly_compound_term ();
    //    test_Poly_compound_Poly();
    //    test_Poly_extraction();
    //    test_Poly_unary ();

    return 0;
}
