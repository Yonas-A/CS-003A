#include "../../!includes/RPN/rpn.h"

#include <math.h>

#include <iostream>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/Token/function.h"
#include "../../!includes/Token/left_paren.h"
#include "../../!includes/Token/number.h"
#include "../../!includes/Token/operator.h"
#include "../../!includes/Token/right_paren.h"
#include "../../!includes/Token/token.h"
#include "../../!includes/Token/variable.h"

using namespace std;

RPN::RPN() {
}

RPN::RPN(Queue<Token*> input) : _rpn(input) {
}

double RPN::operator()(const double& value) {
    const bool debug = false;

    Stack<double> temp;
    Queue<Token*> rpn_temp(_rpn);  // uses the copy ctor from Queue

    while (!rpn_temp.Empty()) {
        Token* item = rpn_temp.Pop();

        if (item->get_type() == numbers) {
            double hold = static_cast<Number*>(item)->get_num();
            temp.Push(hold);
        }

        else if (item->get_type() == variables) {
            temp.Push(value);
        }

        else if (item->get_type() == operators) {
            string hold = static_cast<Operator*>(item)->get_operator();

            if (hold == "*") {
                double rhs = temp.Pop();
                double lhs = temp.Pop();
                temp.Push(lhs * rhs);
            }

            else if (hold == "/") {
                double rhs = temp.Pop();
                double lhs = temp.Pop();
                temp.Push(lhs / rhs);
            } else if (hold == "+") {
                double rhs = temp.Pop();
                double lhs = temp.Pop();
                temp.Push(lhs + rhs);
            } else if (hold == "-") {
                double rhs = temp.Pop();
                double lhs = temp.Pop();
                temp.Push(lhs - rhs);
            } else if (hold == "^") {
                double rhs = temp.Pop();
                double lhs = temp.Pop();
                temp.Push(pow(lhs, rhs));
            } else if (hold == "sin" || hold == "cos" || hold == "tan" || hold == "csc" || hold == "sec" || hold == "cot" || hold == "asin" || hold == "acos" || hold == "atan") {
                double value = temp.Pop();
                temp.Push(eval_trig(hold, value));
            } else
                cout << "Error::RPN(x)" << endl;
        }
    }

    if (debug) {
        cout << "DEBUG::RPN()::Size of result Stack is "
             << temp.Size() << endl;
        cout << " temp.rpn: " << rpn_temp << endl;
        cout << "_rpn: " << _rpn << endl;
    }
    return temp.Pop();
}

double RPN::eval_trig(const string& trig, const double& x) {
    if (trig == "sin")
        return sin(x);

    else if (trig == "cos")
        return cos(x);

    else if (trig == "tan")
        return tan(x);

    else if (trig == "csc")
        return (1 / sin(x));

    else if (trig == "sec")
        return (1 / cos(x));

    else if (trig == "cot")
        return (cos(x) / sin(x));

    else if (trig == "acos")
        return (acos(x));

    else if (trig == "asin")
        return (asin(x));

    else if (trig == "atan")
        return (atan(x));

    else
        assert(false);
}
