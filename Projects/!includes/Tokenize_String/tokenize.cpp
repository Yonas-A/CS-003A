#include "../../!includes/Tokenize_String/tokenize.h"

#include <string.h>

#include <iostream>
#include <sstream>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Token/function.h"
#include "../../!includes/Token/left_paren.h"
#include "../../!includes/Token/number.h"
#include "../../!includes/Token/operator.h"
#include "../../!includes/Token/right_paren.h"
#include "../../!includes/Token/token.h"
#include "../../!includes/Token/variable.h"
#include "../../!includes/Tokenize_String/constants.h"

Tokenize::Tokenize(string equation) : _equation(equation) {
    to_lower();
    remove_space();
}

bool Tokenize::Find(string str, string string_type) {
    /*  STEPS
 *  iterate through the string string_type
 *  find the occurence of first letter of str in string_type
 *  if found return true
 *  else false
 */

    for (unsigned int i = 0; i < string_type.length(); i++) {
        if (str.front() == string_type[i])
            return true;
    }

    return false;
}

int Tokenize::FindNotAny(string str, string string_type) {
    /*  STEPS
 *  iterate through the string str
 *  call find function to find find the occurence
 *                  of str[i]in string_type
 *  if the consecutive letters belonge to same string_type
 *          continue
 *  else return position last letter belonging string_type
 *
 *  if by chance str has only one element and cant be iterated
 *      return -1 to identify that it is the last letter in str;
 */

    for (unsigned int i = 0; i < str.length(); i++) {
        string a;
        a = str.at(i);

        if (Find(a, string_type) == false)
            return i;
        else
            continue;
    }
    return -1;
    //had to figure out this after a very long debugging session
}

Queue<Token*> Tokenize::Get_Token() {
    Queue<Token*> input;
    string temp = _equation;

    while (temp.length() > 0) {
        Token_Type t_type = type(temp);
        switch (t_type) {
            case variables:
                input.Push(new Variable(temp.substr(0, 1)));
                temp = temp.substr(1);
                break;
            case L_Parenthesis:
                input.Push(new Left_Paren(temp.substr(0, 1)));
                temp = temp.substr(1);
                break;
            case R_Parenthesis:
                input.Push(new Right_Paren(temp.substr(0, 1)));
                temp = temp.substr(1);
                break;
            case operators:
                if (FindNotAny(temp, OP) == -1) {
                    input.Push(new Operator(temp.substr(0, 1)));
                    temp = temp.substr(1);
                    break;
                } else {
                    int oper_length = FindNotAny(temp, OP);
                    input.Push(new Operator(temp.substr(0, oper_length)));
                    temp = temp.substr(oper_length);
                    break;
                }

            case numbers:
                if (FindNotAny(temp, NUM) == -1) {
                    input.Push(new Number(temp));
                    temp = temp.substr(1);
                    //                temp = "";
                    break;
                } else {
                    int num_length = FindNotAny(temp, NUM);
                    input.Push(new Number(temp.substr(0, num_length)));
                    temp = temp.substr(num_length);
                    break;
                }
        }
    }

    return input;
}

Token_Type Tokenize::type(string str) {
    if (str == "*")
        return numbers;
    if (Find(str, NUM) == true) {
        return numbers;
    } else if (Find(str, VAR) == true) {
        return variables;
    } else if (Find(str, OP) == true) {
        return operators;
    } else if (Find(str, TRIG) == true) {
        return operators;
    } else if (Find(str, LEFTP) == true) {
        return L_Parenthesis;
    } else if (Find(str, RIGHTP) == true) {
        return R_Parenthesis;
    } else if (Find(str, WORD) == true) {
        return numbers;
    }

    else
        assert(false);
}

void Tokenize::remove_space() {
    stringstream ss(_equation);
    string hold("");
    string temp = _equation;
    while (ss >> temp) {
        hold += temp;
    }
    _equation = hold;
}

void Tokenize::to_lower() {
    string temp("");
    for (unsigned int i = 0; i < _equation.length(); i++) {
        temp += tolower(_equation[i]);
    }
    _equation = temp;
}

ostream& operator<<(ostream& outs, const Tokenize& t) {
    outs << t._equation << endl;
    return outs;
}
