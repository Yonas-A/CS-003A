#ifndef RPN_H
#define RPN_H

#include <iostream>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Stack/stack.h"
#include "../../!includes/Token/token.h"

class RPN
{
public:

    RPN( );

    RPN( Queue<Token*> input);

    void Print();

    double operator ()(const double &value);

    double eval_trig(const string& trig, const double& x);

    friend ostream& operator << (ostream& outs, const RPN& value)
    {
        outs << value._rpn<< endl;
        return outs;
    }


private:

    Queue<Token*> _rpn;
};

#endif // RPN_H
