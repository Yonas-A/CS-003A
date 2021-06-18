#ifndef TEXTINPUT_H
#define TEXTINPUT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../!includes/TextInput_Class/constants.h"

class TextInput
{
public:

    TextInput();

    ~TextInput();

    std::string get_input();

    std::string peek_input();

    bool is_active();

    void set_font(sf::Font& hold_font);

    void step(sf::RenderWindow& window, sf::Event& event,
              bool poll);

    void render_after(sf::RenderWindow& window);


private:

    double height = 30;
    double x = 0;

    double y = SCREEN_HEIGHT - height;

    bool focus = false;

    std::string current_input = "";
    std::string temp_input = "";
    sf::RectangleShape textBox;
    sf::Font font;

};

#endif // TEXTINPUT_H
