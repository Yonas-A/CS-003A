#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <string.h>

#include <iostream>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Token/token.h"

class Shunting_Yard {
   public:
    Shunting_Yard();

    Shunting_Yard(Queue<Token*> input);

    Queue<Token*> Post_Fix();

    friend ostream& operator<<(ostream& outs, const Shunting_Yard& s) {
        outs << s._infix << endl;
        return outs;
    }

   private:
    Queue<Token*> _infix;
};

#endif  // SHUNTING_YARD_H
