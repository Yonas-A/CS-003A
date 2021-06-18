#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

#include <string.h>


enum Token_Type { numbers = 1, variables = 2, operators = 3,
                  L_Parenthesis = 4, R_Parenthesis = 5 };

class Token
{

public:

    // =======================  ctor's  ========================

    ////////////////////////////////////////////////////////////
    /// \brief default Construct creates an empty token
    ///
    ////////////////////////////////////////////////////////////
    Token( );

    ////////////////////////////////////////////////////////////
    /// \brief Construct Token from a type string
    ///
    /// \param string assigned to member variable _input
    ///
    ////////////////////////////////////////////////////////////
    Token( const std::string& str );



    // ======================= accessors =======================

    ////////////////////////////////////////////////////////////
    /// \brief Get the Token's token
    ///
    /// \return an enumeration tokenType that is associated with
    ///         a TokenType of Number
    ///
    ////////////////////////////////////////////////////////////
    virtual Token_Type get_type();



    // ======================= displays =========================

    ////////////////////////////////////////////////////////////
    /// \brief print Token onto the console
    ///
    ////////////////////////////////////////////////////////////
    virtual void print( ) ;

    ////////////////////////////////////////////////////////////
    /// \brief print Token onto the console
    ///
    ////////////////////////////////////////////////////////////
    friend std::ostream& operator <<(std::ostream& outs, Token* ptr);


private:

    /// a string that'll hold Token
    std::string _input;

};

#endif // TOKEN_H
