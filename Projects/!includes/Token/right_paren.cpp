#include "../../!includes/Token/right_paren.h"

#include <iostream>
#include <string>

#include "../../!includes/Token/token.h"

// =========================================================
// ctor's

Right_Paren::Right_Paren(std::string s) : _r_parenthesis(s) {
}
// =========================================================
// accessors

std::string Right_Paren::get_Right_Paren() {
    return _r_parenthesis;
}

Token_Type Right_Paren::get_type() {
    return R_Parenthesis;
}

// =========================================================
// display
void Right_Paren::print() {
    std::cout << " " << _r_parenthesis << " ";
}
