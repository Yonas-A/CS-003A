#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>

#include <string.h>

#include "../../!includes/Token/token.h"


class Variable : public Token
{
public:

    // ========================= ctor's ========================

    ////////////////////////////////////////////////////////////
    /// \brief Construct the Variable from a string
    ///
    /// \param string  assigned to the member variable _operator
    ///
    ////////////////////////////////////////////////////////////
    Variable( std::string var);



    // ======================== accessors =======================

    ////////////////////////////////////////////////////////////
    /// \brief Get the variable
    ///
    /// \return variable as a string
    ///
    ////////////////////////////////////////////////////////////
    std::string get_var();

    ////////////////////////////////////////////////////////////
    /// \brief get Variable's token type
    ///
    /// \return an enumeration tokenType that is associated with
    /// a TokenType of Variables
    ///
    ////////////////////////////////////////////////////////////
    virtual Token_Type get_type() override;



    // ======================== display =======================

    ////////////////////////////////////////////////////////////
    /// \brief print operator onto the console
    ///
    ////////////////////////////////////////////////////////////
    virtual void print() override ;


private:

    /// a string to hold variable
    std::string _var;

};

#endif // VARIABLE_H
