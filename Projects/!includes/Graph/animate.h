#ifndef ANIMATE_H
#define ANIMATE_H

#include <SFML/Graphics.hpp>

#include "../../!includes/Graph/plot.h"
#include "../../!includes/Graph/sidebar.h"
#include "../../!includes/RPN/rpn.h"

class Animate {
   public:
    Animate(Graph_Info* g_info);

    void Draw();
    //based on the data, draw shapes on window object.

    void drawAxes();
    //draws the y and x axis of graph

    void drawGraph();
    //draws the points of a given equation

    void loadFont();
    //loads the font and sets the size of text

    void processEvents();
    // handles keyboard and mouse events

    void render();

    void run();

    void update();
    // prepare the next frame

   private:
    sf::RenderWindow window;

    Plot plot;

    Graph_Info* info;

    Sidebar sidebar;  //rectangular message sidebar

    sf::RectangleShape mypoint;  //draws all shapes on screen

    sf::Font font;  //font to draw on main screen

    sf::Text textLabel;  //text to draw on main screen

    bool mouseIn;  //mouse is in the screen
};

#endif  // ANIMATE_H
