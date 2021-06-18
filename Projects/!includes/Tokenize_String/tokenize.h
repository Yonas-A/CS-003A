#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <string.h>

#include <iostream>

#include "../../!includes/Queue/queue.h"
#include "../../!includes/Token/token.h"

using namespace std;

class Tokenize {
   public:
    Tokenize(std::string equation);
    //tokenize ctor with a string argument

    bool Find(string str, string string_type);
    //finds the first letter of str  inside string find

    int FindNotAny(string str, string string_type);
    //finds the first letter of str  inside string find

    Queue<Token*> Get_Token();
    // returns a tokenized queue

    void remove_space();
    // removes space if theres any white space character;

    void to_lower();
    //converts the input into lower case letters

    Token_Type type(string str);
    // returns the token type of string str to given size;

    friend ostream& operator<<(ostream& outs, const Tokenize& t);
    // prints the input equation

   private:
    string _equation;
};

#endif  // TOKENIZE_H
