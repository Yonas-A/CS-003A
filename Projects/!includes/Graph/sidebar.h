#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <iostream>
#include <vector>

#include <string.h>

#include <SFML/Graphics.hpp>

using namespace std;


class Sidebar
{

public:

    Sidebar();

    Sidebar(float left, float width);

    void LoadFont();

    void draw(sf::RenderWindow& window);

    std::string getInput();

    void readInput(sf::RenderWindow& window, sf::Event& event);

    void setFocus(bool focus);

    bool contains(sf::Vector2f point) const;


private:

    sf::RectangleShape rect;      //sidebar rectangle

    sf::RectangleShape inputBox;  // input bar in rect

    sf::Font font;               //used to draw text

    sf::Text inputText;       //used to draw strings on the window object

    bool text_focus;

    std::string input_equation;

    std::string last_equation;

    float _left;

    float _width;

};

#endif // SIDEBAR_H
