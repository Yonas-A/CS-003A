#include "textinput.h"
#include <SFML/Graphics.hpp>
#include "../../!includes/TextInput_Class/constants.h"

TextInput::TextInput()
{
    textBox.setPosition(float(x), float(y));
    textBox.setSize(sf::Vector2f(SCREEN_WIDTH, float(height)));
    textBox.setFillColor(INPUTBOX_COLOR);

}

TextInput::~TextInput()
{

}

std::string TextInput::get_input()
{
    std::string hold = current_input;
    current_input = "";
    return hold;
}

std::string TextInput:: peek_input()
{
    return current_input;
}

bool TextInput:: is_active()
{
    return focus;
}

void TextInput::set_font (sf::Font& hold_font)
{
    font = hold_font;
}

void TextInput::step(sf::RenderWindow& /*window*/,
                                sf::Event& event, bool poll)
{

    if (poll)
    {
//        if (event.type == sf::Event::KeyPressed)
//        {
//            if (event.key.code == sf::Keyboard::Enter)
//            {
//                if (!focus)
//                {
//                    current_input = "";
//                }
//                else
//                {
//                    if (temp_input.length() == 0)
//                        current_input = "";
//                    else if (temp_input.at(0) == '\r')
//                    {
//                        current_input = temp_input.substr(1);
//                    }
//                    else
//                        current_input = temp_input;
//                    temp_input = "";
//                }

//                focus = !focus;
//            }
//        }

        if (event.type == sf::Event::TextEntered)
        {
            if (focus)
            {
                if (event.text.unicode == '\b' &&
                                           temp_input.size() > 0)
                    temp_input.erase(temp_input.size() - 1, 1);
                else if (event.text.unicode < 128)
                {
                    temp_input += static_cast<char>(event.text.unicode);
                }
            }
        }
    }
}


void TextInput::render_after(sf::RenderWindow& window)
{
    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(20);
    inputText.setString(temp_input);
    inputText.setPosition(WORK_PANEL, INPUTBOX_HEIGHT);

    window.draw(inputText);
    window.draw(textBox);
}


