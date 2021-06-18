#include <iostream>
#include "../../!includes/Tokenize_String/tokenize.h"
#include "../../!includes/Tokenize_String/constants.h"

using namespace std;

int main()
{
//    string str = "0.1*x*5+(3/1)Xsin(x*4)";

    string str = "Last > Freddy";
    cout << "str in Main: " << str << endl;

    Tokenize tokenize(str);
    cout << "tokenizer Ctor in Main: " << tokenize << endl;
    cout << "tokenized input in Main: " ;
    cout << tokenize.Get_Token() << endl;

    return 0;
}
