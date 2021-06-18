#ifndef RPN_TEST_H
#define RPN_TEST_H

#include <iostream>
#include <cmath>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/RPN/rpn.h"
#include "../../!includes/Token/function.h"
#include "../../!includes/Token/left_paren.h"
#include "../../!includes/Token/operator.h"
#include "../../!includes/Token/number.h"
#include "../../!includes/Token/right_paren.h"
#include "../../!includes/Token/variable.h"



void test_exponent()
{
    Queue<Token*> postfix;
    postfix.Push(new Variable("X"));
    postfix.Push(new Variable("X"));
    postfix.Push(new Operator("^"));

    RPN temp(postfix);
    cout << '\t' << ".. ... .... ..... ...... " << endl << endl;

    cout << "Postfix: " << postfix  << endl;
    cout << "RPN: " << temp << endl;


    double y = temp(5);
    cout << "RPN: " << temp << endl;
    cout << "Result rpn  = " << y << endl;
    cout << "\t . . . . . .  end of test exponent . . . . " << '\n' ;
}

void test_simple()
{
    Queue<Token*> postfix;

//    1 2 3 + 4 5 6 × – 7 × + – 8 9 × +


    postfix.Push(new Number("1"));
    postfix.Push(new Number("2"));
    postfix.Push(new Number("3"));
    postfix.Push(new Operator("+"));
    postfix.Push(new Number("4"));
    postfix.Push(new Variable("X"));
    postfix.Push(new Number("6"));
    postfix.Push(new Operator("*"));
    postfix.Push(new Operator("-"));
    postfix.Push(new Number("7"));
    postfix.Push(new Operator("*"));
    postfix.Push(new Operator("+"));
    postfix.Push(new Operator("-"));
    postfix.Push(new Number("8"));
    postfix.Push(new Number("9"));
    postfix.Push(new Operator("*"));
    postfix.Push(new Operator("+"));
    // answer must result 250


    cout << '\t' << ".. ... .... ..... ...... " << endl << endl;
    RPN temp(postfix);
    cout << "Postfix: " << postfix  << endl;
    cout << "RPN: " << temp << endl;

    double y = temp(5);
    cout << "RPN: " << temp << endl;
    cout << "Result rpn  = " << y << endl;
    cout << "\t . . . . . .  end of test simple . . . . " << '\n' ;
}

void test_trig()
{
    Queue<Token*> postfix;
    postfix.Push(new Variable("X"));
    postfix.Push(new Operator( "atan"));
    RPN temp(postfix);

    cout << '\t' << ".. ... .... ..... ...... " << endl << endl;
    cout << "Postfix: " << postfix  << endl;
    cout << "RPN: " << temp << endl;

    double y = temp(90);
    cout << "RPN: " << temp << endl;
    cout << "Result rpn  = " << y << endl;

    cout << '\t' << ".. ... .... ..... ...... " << endl << endl;

    cout << "\t . . . . . .  end of test trig . . . . " << '\n' ;
    cout << (atan(90)) ;
    cout << endl;

}


#endif // RPN_TEST_H
