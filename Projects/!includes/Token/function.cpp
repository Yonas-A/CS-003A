
#include "../../!includes/Token/function.h"
#include "../../!includes/Token/operator.h"


// =========================================================
// ctor

Function::Function( std::string str ): Operator(str), _function(str)
{

}

// =========================================================
// accessors

std::string Function::get_operator()
{
    return _function;
}


