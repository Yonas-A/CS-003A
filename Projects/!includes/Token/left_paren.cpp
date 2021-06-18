#include "../../!includes/Token/left_paren.h"

#include <iostream>
#include <string>

#include "../../!includes/Token/token.h"

// =========================================================
// ctor

Left_Paren::Left_Paren(std::string s) : _l_parenthesis(s) {
}

// =========================================================
// accessors

std::string Left_Paren::get_Left_Paren() {
    return _l_parenthesis;
}

Token_Type Left_Paren::get_type() {
    return L_Parenthesis;
}

// =========================================================
// displays

void Left_Paren::print() {
    std::cout << " " << _l_parenthesis << " ";
}
