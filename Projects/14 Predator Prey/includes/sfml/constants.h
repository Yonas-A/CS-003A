#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML/Graphics.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief: used to instantiate the window and screen size
////////////////////////////////////////////////////////////////////////////////////////////////////

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 1200;
//const int WORK_PANEL = SCREEN_WIDTH*4/5;
//const int SIDE_BAR = SCREEN_WIDTH*1/5;

//////////////////////////////////////////////////////////////////////
/// \brief: used to instantiate the grid size and sizes of creatures
/////////////////////////////////////////////////////////////////////
const int CREATURE_GRID_WIDTH = 50;
const int CREATURE_GRID_HEIGHT = 50;

const int GRID_WIDTH = 50;
const int GRID_HEIGHT = 50;

const int SFML_GRID_WIDTH = 200;
const int SFML_GRID_HEIGHT = 200;

const int CELL_SIZE = 15;

///////////////////////////////////////////////////////////////////
/// \brief: color used for separating the types of creatures
///////////////////////////////////////////////////////////////////

static const sf::Color wall_color(31, 185, 208);   // sky blue
static const sf::Color prey_color(0, 255, 0);      // green
static const sf::Color predator_color(255, 0, 0);  // red
static const sf::Color blank_grid(0, 0, 0);        // white

#endif  // CONSTANTS_H
