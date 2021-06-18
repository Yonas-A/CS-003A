#include <iostream>

#include <string.h>

#include "../../!includes/Token/token.h"
#include "../../!includes/Token/variable.h"

// =========================================================
// ctor

Variable::Variable( std::string v ): _var( v)
{

}

// =========================================================
// accessors

std::string Variable::get_var()
{
    return  _var;
}

Token_Type Variable::get_type()
{
    return variables;
}

// =========================================================
// displays

void Variable::print()
{
    std::cout << " " << _var << " " ;
}


