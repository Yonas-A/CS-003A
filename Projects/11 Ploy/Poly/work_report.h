#ifndef POLY_WORK_REPORT_H
#define POLY_WORK_REPORT_H
/*

  Note to SELF
    changes so far
     in Sorted.h
     *      the where this goes >= and <= comparisions were
            changed   to > and == or < and ==
     **     Copy_List was changed to Copy_list () const
            to accomodate the copy ctor for poly which has
            const& other and copy operator=() which has
            const& rhs
     ***    the default for Sorted was changes from unique true
            and order false to unique(true) & order(false)
     ****   insert function where previously if there were two same
            items the list was updated to the new item has now been
            changed so that if it occures the two items are added
            together.example
            Poly B:    [ +2X^4 +3X^3 +4X^2 +7X^1 +0X^0 ]
            B +=Term(3,4)
            Poly B:    [ +5X^4 +3X^3 +4X^2 +7X^1 +0X^0 ]


    Features:
        -Not Implemented: None
        -Implemented:
                big three
                poly| poly, poly| term compound assignment operators
                poly| Poly, Poly| term arithmetic operators
                poly comparison operators
                Poly unary operator
                insertion and extraction
                A function to delete terms with zero coefficients
                which is useful when verifying reulsting poly
                in user interface

                all of Term struct functions

        -Partly implemented:none

    Bugs:
        -None

    Reflections:
        -Had trouble every now and then on some syntax but it was
         100% easier project that the first time I had to do this
         project with arrays.
         for Extraction Operator I wanted the user to type in the
         entire polynomial in a single line so I used a stringstream
         to change the input string to a bunch of strings and extaract
         the coefficient and the power. Only problem with this was user
         has to type in four things to make up a poly(coef,x,^ and power)
         Input must always look like 3x^4  or +3x^4 or -3x^4



 */
#endif // POLY_WORK_REPORT_H
