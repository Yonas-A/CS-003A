#ifndef PLOT_H
#define PLOT_H

#include <iostream>

#include "../../!includes/Graph/constants.h"
#include "../../!includes/Graph/graph_info.h"
#include "../../!includes/RPN/rpn.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Token/token.h"
#include "../../!includes/Tokenize_String/tokenize.h"


class Plot
{

public:

    Plot(Graph_Info * info);

    std::vector<sf::Vector2f> get_coord();

    std::string to_String(double value);

    sf::Vector2f transform(float x, float y);

    std::vector<sf::Vector2f> get_lable();

    void update_Equation();

private:

    Graph_Info* _info;
    Token _token;
    Tokenize  _tokenized;
    RPN _rpn;
    Shunting_Yard _sh_yard;

};

#endif // PLOT_H
