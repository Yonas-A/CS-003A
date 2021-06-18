#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <string>

#include "../../!includes/Token/token.h"
#include "../../!includes/Token/operator.h"


class Function: public Operator
{

public:

    // ========================= ctor's ========================

    ////////////////////////////////////////////////////////////
    /// \brief Construct the Function from a string
    ///
    /// \param string         string assigned to the function
    ///
    ////////////////////////////////////////////////////////////
    Function( std::string str );



    // ======================== accessors =======================

    ////////////////////////////////////////////////////////////
    /// \brief Gets the function
    ///
    /// \return function as a string
    ///
    ////////////////////////////////////////////////////////////
    string get_operator( );

private:

    /// string to hold function
    std::string _function;

};

#endif // FUNCTION_H
