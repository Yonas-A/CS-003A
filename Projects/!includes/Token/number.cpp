#include "../../!includes/Token/number.h"

#include <iostream>
#include <string>

#include "../../!includes/Token/token.h"

// =========================================================
// ctor

Number::Number(double n) : _num(n) {
}

Number::Number(std::string s) : _num(stod(s)) {
}

// =========================================================
// accessors

double Number::get_num() {
    return _num;
}

Token_Type Number::get_type() {
    return numbers;
}

// =========================================================
// displays

void Number::print() {
    std::cout << " " << _num << " ";
}
