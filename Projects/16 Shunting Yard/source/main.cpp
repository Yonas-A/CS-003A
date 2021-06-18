
#include <iomanip>
#include <iostream>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Token/function.h"
#include "../../!includes/Token/left_paren.h"
#include "../../!includes/Token/number.h"
#include "../../!includes/Token/operator.h"
#include "../../!includes/Token/right_paren.h"
#include "../../!includes/Token/variable.h"

using namespace std;

void simple_test();
// a simple test for shunting yard

void new_test() {
    Queue<Token*> temp;

    //    temp.Push( new  Token ("Last") );
    //    temp.Push( new class Operator ("<"));
    //    temp.Push( new  Token ("Jones"));

    //    temp.Push( new class Operator ("||"));

    //    temp.Push( new  Token ("Age"));
    //    temp.Push( new class Operator (">"));
    //    temp.Push( new  Token ("27"));

    temp.Push(new Number("1"));
    temp.Push(new Operator("-"));
    temp.Push(new Number("2"));
    temp.Push(new class Operator("="));
    temp.Push(new Number("-2"));

    //    temp.Push( new class Operator ("&&"));

    //    temp.Push( new  Token ("Gender"));
    //    temp.Push( new class Operator ("="));
    //    temp.Push( new  Token ("M"));

    Queue<Token*> q;
    Shunting_Yard input(temp);
    cout << "Shunting Yard: " << input << endl;
    q = input.Post_Fix();
    cout << endl
         << "input.Post_Fix(): " << endl
         << q << endl;

    cout << std::setfill('=') << setw(80) << "=" << endl;
}

int main() {
    new_test();

    //    simple_test();

    return 0;
}

void simple_test() {
    Queue<Token*> temp;

    //    1 – (2 + 3 + (4 – 5 × 6) × 7) + 8 × 9
    //    1 – (2 + 3 + (4 – X * 6) * 7) + 8 * 9
    //    1 2 3 + 4 5 6 × – 7 × + – 8 9 × +

    temp.Push(new Number("1"));
    temp.Push(new Operator("-"));
    temp.Push(new Left_Paren("("));
    temp.Push(new Number("2"));
    temp.Push(new Operator("+"));
    temp.Push(new Number("3"));
    temp.Push(new Operator("+"));
    temp.Push(new Left_Paren("("));
    temp.Push(new Number("4"));
    temp.Push(new Operator("-"));
    temp.Push(new Variable("X"));
    //    temp.Push(new Number ("5"));
    temp.Push(new Operator("*"));
    temp.Push(new Number("6"));
    temp.Push(new Right_Paren(")"));
    temp.Push(new Operator("*"));
    temp.Push(new Number("7"));
    temp.Push(new Right_Paren(")"));
    temp.Push(new Operator("+"));
    temp.Push(new Number("8"));
    temp.Push(new Operator("*"));
    temp.Push(new Number("9"));
    //    temp.Push(new Operator("+"));
    //    temp.Push(new Number("3"));
    //    temp.Push(new Operator("^"));
    //    temp.Push(new Number("2"));

    //    temp.Push( new Left_Paren("("));
    //    temp.Push( new class Function ("sin"));
    //    temp.Push(new Number ("2"));
    //    temp.Push(new Right_Paren(")"));
    //    temp.Push(new class Operator ("+"));
    //    temp.Push(new Number("6"));

    Queue<Token*> q;
    Shunting_Yard input(temp);
    cout << "Shunting Yard: " << input << endl;
    q = input.Post_Fix();
    cout << endl
         << "input.Post_Fix(): " << endl
         << q << endl;

    cout << std::setfill('=') << setw(80) << "=" << endl;
}
