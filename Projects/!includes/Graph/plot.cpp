#include <iostream>
#include <sstream>

#include <string.h>
#include <math.h>

#include <SFML/Graphics.hpp>

#include "../../!includes/Graph/plot.h"
#include "../../!includes/Graph/constants.h"
#include "../../!includes/Graph/graph_info.h"
#include "../../!includes/RPN/rpn.h"
#include "../../!includes/Token/token.h"
#include "../../!includes/Tokenize_String/tokenize.h"
#include "../../!includes/Shunting_Yard/shunting_yard.h"
#include "../../!includes/Queue/queue.h"


using namespace  std;

Plot::Plot(Graph_Info* info):_info(info),_tokenized(info->_equations)
{
    const bool debug = false;
}

std::string Plot::to_String(double value)
{
    std::stringstream ss;
    std::string temp;
    ss << value;
    ss >> temp;
    return temp;
}

void Plot::update_Equation()
{
    _tokenized = _info->_equations;

    cout << "info->equation: " << _info->_equations << endl;
    Queue<Token*> TOKENIZED = _tokenized.Get_Token();
    // tokenizing equation

    _sh_yard = Shunting_Yard( TOKENIZED );
    ///passing the tokenized queue to shunting yard ctor

    Queue<Token*> shunted = _sh_yard.Post_Fix( );
    /// tokenized queue passing through shunting yard

    _rpn = RPN( shunted );

}

vector <sf::Vector2f> Plot::get_coord()
{
    const bool debug = false;

    std::vector<sf::Vector2f> coord;
    vector<double> y_coord;
    update_Equation();
    /// updates the info->equation struct to latest equation


    float delta = ( _info->max_domain - _info->min_domain) /
            ( _info ->total_points - 1 );

    for (float i = _info->min_domain; i < _info->max_domain;
         i += delta)
    {
        if(debug)
        {
            cout << "\n\t - - - - - - - -- - - - - - - - - - - \n";
            cout << "I: " << i << endl;
        }

        double yValue = _rpn(i);
        coord.push_back(transform(i, yValue));
    }

    if(debug)
    {
        cout << "x_origin: " << _info->x_origin << endl;
        cout << "y_origin: " << _info->y_origin << endl;
        cout << "Max_domain: " << _info->max_domain << endl;
        cout << "min_domain: " << _info-> min_domain << endl;
        cout << "total_Points: " << _info->total_points << endl;
        cout << "delta: " << delta << endl << endl << endl;
        cout << "\n\t - - - - - - - -- - - - - - - - - - - \n";
        cout << "coord.size(): " << coord.size() << endl;
        cout << "\n\t - - - - - - - -- - - - - - - - - - - \n";
    }

    assert(coord.size() != 0);
    return coord;
}

vector <sf::Vector2f> Plot::get_lable()
{
    const bool debug = false;
    std::vector<sf::Vector2f> lable;
    vector<double> y_coord;

    float delta = ( _info->max_domain - _info->min_domain) / 10;

    for (float i = _info->min_domain; i < _info->max_domain; i += delta)
    {
        double yValue = _rpn(i);
        lable.push_back(transform(i, yValue));
    }

    assert(lable.size() != 0);
    return lable;


}

sf::Vector2f Plot::transform(float x_coord, float y_coord)
{
    // transforms a value on real world to the given screen coordinate
    // based on the minimum and maximum domain for both x and y values
    float x_trans = ( _info-> window_W_dim /
                      (_info->max_domain - _info->min_domain) )
            * (x_coord - _info->min_domain);

    float y_trans  = ( _info->window_H_dim /
                       (_info->max_domain - _info->min_domain) )
            * ( _info->max_domain - y_coord  );

    return (sf::Vector2f (x_trans,  y_trans));
}


