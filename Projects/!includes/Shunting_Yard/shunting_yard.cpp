#include <iostream>

#include <string.h>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Token/function.h"
#include "../../!includes/Token/left_paren.h"
#include "../../!includes/Token/number.h"
#include "../../!includes/Token/operator.h"
#include "../../!includes/Token/right_paren.h"
#include "../../!includes/Token/variable.h"


Shunting_Yard::Shunting_Yard( )
{

}

Shunting_Yard::Shunting_Yard( Queue<Token *> input): _infix(input)
{

}

Queue<Token*> Shunting_Yard::Post_Fix()
{

 /**
  * STEPS:
  * if token is number or variable push into postfix queue
  * if left paranthesis push it into operator stack
  * if Right_paren, while top of operator stack is not
        left_parenthesis, push operators into postfix queue
        pop the left parenthesis and discard it
  * if token is operator, while operator stack is not empty
  *     and top of operator stack is not left_parenthesis
  *     and top of operator stack has same or greater
  *                precedence as operator
  *     pop operator stack and push into postfix queue
  */

    int unused(0);
    Queue<Token*> post_fix;    // holds the post_fix expression
    Stack<Token*> operator_stack;  //hold operators while converting

    while( !_infix.Empty( ) )
    {
        Token* item = _infix.Pop();

        if(item->get_type() == numbers || item->get_type() == variables )
        {
            post_fix.Push(item);
        }

        else if( item ->get_type() == operators )
        {
            while( ( !operator_stack.Empty() ) &&
          ( operator_stack.Top( unused )->get_type() != L_Parenthesis )
                   &&
                 ( static_cast<Operator*>( operator_stack.Top(unused))->
                            get_precedence() >=
                  static_cast<Operator*>(item)->get_precedence() )   )
            {
                Token* operands = operator_stack.Pop();
                post_fix.Push(operands);
            }

            operator_stack.Push(item);
        }

        else if( item->get_type() == L_Parenthesis )
        {
            operator_stack.Push(item);
        }

        else if( item->get_type() == R_Parenthesis )
        {
            while( operator_stack.Top(unused)->get_type()
                   != L_Parenthesis )
            {
                Token* operands = operator_stack.Pop();
                post_fix.Push(operands);
            }
            operator_stack.Pop();
        }
    }

    while( ! operator_stack.Empty())
    {
        if( operator_stack.Top(unused)->get_type() == L_Parenthesis )
        {
            operator_stack.Pop();
        }

        else
        {
            Token* operands = operator_stack.Pop();
            post_fix.Push(operands);

        }
    }

    return post_fix;
}
