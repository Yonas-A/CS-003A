#include "../../!includes/Token/operator.h"

#include <iostream>
#include <string>

#include "../../!includes/Token/token.h"

// =========================================================
// ctor

Operator::Operator(std::string s) : _operator(s) {
    this->assign_precedence();
}

// =========================================================
// accessors

string Operator::get_operator() {
    return _operator;
}

int Operator::get_precedence() const {
    return _precedence;
}

Token_Type Operator::get_type() {
    return operators;
}

// =========================================================
// displays

void Operator::print() {
    cout << " " << _operator << " ";
}

// =========================================================
// private modifiers

void Operator::assign_precedence() {
    if (_operator == "or" || _operator == "||")
        _precedence = 0;

    else if (_operator == "and" || _operator == "&&")
        _precedence = 1;

    else if (_operator == "==" || _operator == "=" || _operator == "!=")
        _precedence = 2;

    else if (_operator == "<" || _operator == ">" || _operator == "<=" || _operator == ">=")
        _precedence = 3;

    else if (_operator == "+" || _operator == "-")
        _precedence = 4;

    else if (_operator == "*" || _operator == "/")
        _precedence = 5;

    else if (_operator == "^")
        _precedence = 6;

    else if (_operator == "sin" || _operator == "asin" ||
             _operator == "cos" || _operator == "acos" ||
             _operator == "tan" || _operator == "atan" ||
             _operator == "csc" || _operator == "sec" ||
             _operator == "cot")
        _precedence = 7;

    else
        assert(false);
}
