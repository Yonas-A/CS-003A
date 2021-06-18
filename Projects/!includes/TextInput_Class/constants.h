#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <SFML/Graphics.hpp>


///////////////////////////////////////////////////////////
/// \brief: used to instantiate the window and screen size
///////////////////////////////////////////////////////////

const int INPUTBOX_HEIGHT = 500;

const int WINDOW_MAXIMUM = 2400;
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 1600;

const int CENTER_X = SCREEN_WIDTH / 2;
const int CENTER_Y = SCREEN_HEIGHT / 2;

const int WORK_PANEL = WINDOW_MAXIMUM *2/3 ;
const int SIDE_BAR = WINDOW_MAXIMUM *1/3 ;

const int GRAPH_THICKNESS = 3;
const int ZOOM_SCALE = 50;

const double PAN_INCREMENT = 0.5;

///////////////////////////////////////////////////
/// \brief main window or sidebar and inputbox colors
///////////////////////////////////////////////////

const int MIN_DOMAIN = -10;
const int MAX_DOMAIN = 10;

static const sf::Color SIDEBAR_COLOR(45,45,45);
static const sf::Color INPUTBOX_COLOR(50, 60, 60);


#endif // CONSTANTS_H
