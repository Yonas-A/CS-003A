#include <iostream>
#include "../../!includes/Token/number.h"
#include "../../!includes/Token/token.h"
#include "../../!includes/Token/variable.h"
#include "../../!includes/Token/operator.h"
#include "../../!includes/Token/right_paren.h"
#include "../../!includes/Token/left_paren.h"
#include "../../!includes/Token/function.h"

using namespace std;



void simple_function_test();

void simple_number_test();

void simple_operator_test();

void simple_parenthesis_test();

void simple_variable_test();



int main()
{
    simple_function_test();

//    simple_number_test();

//    simple_operator_test();

//    simple_parenthesis_test();

//    simple_variable_test();

    return 0;
}




void simple_function_test()
{

    Function sine("sin");
    cout << "\t- - - - - - - - - - - - - - - - - " << endl;
    sine.print();
    cout << " Function.Print()" << endl;
    cout << "f.get_precedence(): " << sine.get_precedence() << endl;
    cout << "f.get_operator(): " << sine.get_operator() << endl;

    Function cosine("acos");
    cout << "\t- - - - - - - - - - - - - - - - - " << endl;
    cosine.print();
    cout << "  -> cosine.Print()" << endl;
    cout << "get_precedence(): " << cosine.get_precedence() << endl;
    cout << "get_operator(): " << cosine.get_operator() << endl;

    cout << "\t- - - - - end of Function test - - - - - " << endl;
}

void simple_number_test()
{
    Number a("564");
    a.print();
    cout << "Number.Print()" << endl;


    Number b("564");
    b.print();
    cout << "Number.Print()" << endl;
    cout << "\t- - - - - end of number test - - - - - " << endl;
}

void simple_operator_test()
{

    Operator add("+");
    cout << "\t- - - - - - - - - - - - - - - - - " << endl;
    add.print();
    cout << " Operator.Print()" << endl;
    cout << "get_operator(): " << add.get_operator() << endl;
    cout << "get_precedence(): " << add.get_precedence() << endl;


    Operator minus("-");
    cout << "\t- - - - - - - - - - - - - - - - - " << endl;
    minus.print();
    cout << " Operator.Print()" << endl;
    cout << "get_operator(): " << minus.get_operator() << endl;
    cout << "get_precedence(): " << minus.get_precedence() << endl;


    Operator multiply("*");
    cout << "\t- - - - - - - - - - - - - - - - - " << endl;
    multiply.print();
    cout << " Operator.Print()" << endl;
    cout << "get_operator(): " << multiply.get_operator() << endl;
    cout << "get_precedence(): " << multiply.get_precedence() << endl;


    Operator divide("/");
    cout << "\t- - - - - - - - - - - - - - - - - " << endl;
    divide.print();
    cout << " Operator.Print()" << endl;
    cout << "get_operator(): " << divide.get_operator() << endl;
    cout << "get_precedence(): " << divide.get_precedence() << endl;

    Operator power("^");
    cout << "\t- - - - - - - - - - - - - - - - - " << endl;
    power.print();
    cout << " Operator.Print()" << endl;
    cout << "get_operator(): " << power.get_operator() << endl;
    cout << "get_precedence(): " << power.get_precedence() << endl;



    cout << "\t- - - - - end of operator test - - - - - " << endl;
}

void simple_parenthesis_test()
{
    Left_Paren left("(");
    left.print();
    cout << " Left_Paren.Print()" << endl;

    Right_Paren right(")");
    right.print();
    cout << " Right_Paren.Print()" << endl;
    cout << "\t- - - - - end of parenthesis test - - - - - " << endl;
}

void simple_variable_test()
{

    Variable var("x");
    var.print();
    cout << " Variable.print()" << endl;
    cout << "\t- - - - - end of variable test - - - - - " << endl;

}
