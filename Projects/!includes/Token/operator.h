#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <string>

#include "../../!includes/Token/token.h"


using namespace  std;

class Operator: public Token
{
public:

    // =======================  ctor's  ========================

    ////////////////////////////////////////////////////////////
    /// \brief Construct the operator from a string
    ///
    /// \param string  assigned to the member variable _operator
    ///
    ////////////////////////////////////////////////////////////
    Operator( std::string str );


    // ======================= accessors =======================

    ////////////////////////////////////////////////////////////
    /// \brief Get the operator
    ///
    /// \return operator as a string
    ///
    ////////////////////////////////////////////////////////////
     std::string get_operator( );

    ////////////////////////////////////////////////////////////
    /// \brief get the operator's precedence
    ///
    /// \if current string does not have a precedence, it means that
    /// current string is not operator or does not qualify as an
    /// operator for our purpose
    ///
    /// \return an int identifying the current operators precedence
    ///
    ////////////////////////////////////////////////////////////
    int get_precedence( ) const;

    ////////////////////////////////////////////////////////////
    /// \brief get operator's token type
    ///
    /// \return an enumeration tokenType that is associated with
    /// a TokenType of operators
    ///
    ////////////////////////////////////////////////////////////
    virtual Token_Type get_type( ) override;



    // ======================= display =======================

    ////////////////////////////////////////////////////////////
    /// \brief print Operator onto the console
    ///
    ////////////////////////////////////////////////////////////
    virtual void print( ) override ;


private:

    /// String to hold current operator
     std::string _operator;

    /// a type int to hold precedence for different operators
    int _precedence ;



    // ======================= modifier =======================

    ////////////////////////////////////////////////////////////
    /// \brief set a precedence as a number for different operators
    ///        based on standard mathimathical conventions such as
    ///        such as +, - , * ,etc ...
    ///
    ////////////////////////////////////////////////////////////
    void assign_precedence( );

};

#endif // OPERATOR_H
