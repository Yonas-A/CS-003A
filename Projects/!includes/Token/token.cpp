#include "../../!includes/Token/token.h"

#include <string.h>

#include <iostream>

// =========================================================
// ctor's

Token::Token() {
}

Token::Token(const std::string& str) {
    _input = str;
}

// =========================================================
// accessors

Token_Type Token::get_type() {
    return numbers;
}

// =========================================================
// display

void Token::print() {
    std::cout << " " << _input << " ";
}

std::ostream& operator<<(std::ostream& outs, Token* ptr) {
    ptr->print();
    return outs;
}
