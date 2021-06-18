
#include "../../!includes/Graph/constants.h"
#include "../../!includes/Graph/sidebar.h"


Sidebar::Sidebar()
{
}

Sidebar::Sidebar(float left, float width):_left(left), _width(width)
{
    // setting the sidebar rectangle
    rect.setPosition(sf::Vector2f(left , INPUTBOX_HEIGHT ));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT - INPUTBOX_HEIGHT));
    rect.setFillColor(SIDEBAR_COLOR);
    LoadFont();

    // setting the input box on the rectangle
    inputBox.setPosition(sf::Vector2f(left , 0 ));
    inputBox.setSize(sf::Vector2f(width, INPUTBOX_HEIGHT));
    inputBox.setFillColor(INPUTBOX_COLOR);
    inputBox.setOutlineColor(sf::Color::Blue);

}

void Sidebar::LoadFont()
{
    if (!font.loadFromFile("Roboto-Thin.ttf"))
    {
        cout << "Sidebar() CTOR: Font failed to load" <<endl;
        exit(-1);
    }
    // setting the font
    inputText.setFont(font);
    inputText.setCharacterSize(20);
    inputText.setStyle(sf::Text::Bold);
    inputText.setFillColor(sf::Color::Black);

}

void Sidebar::draw(sf::RenderWindow& window)
{
//    const double VERTICAL_LINE_SPACING = 5.0;
//    const double LEFT_MARGIN = 10.0;
//    float height = 10;

    window.draw(rect);
    window.draw(inputBox);
    window.draw(inputText);
}

string Sidebar::getInput()
{
    string temp = input_equation;
    input_equation = "";
    return temp;
}

void Sidebar::readInput(sf::RenderWindow &window, sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Enter)
        {
            cout << " hello 1 " << endl;
            if (!text_focus)
            {
                input_equation = "sin(x)";
                cout << " hello" << endl;
            }

            else
            {
                if (input_equation.length() == 0)
                    input_equation = "";
                else
                    input_equation = last_equation;
                last_equation = "";
            }

            text_focus = !text_focus;
            setFocus(text_focus);
        }
    }

    if (event.type == sf::Event::TextEntered )
    {
        if (text_focus)
        {
            if (event.text.unicode == '\b' &&
                    input_equation.size() > 0)
                input_equation = input_equation.substr(0, input_equation.size() - 1);

            else if (event.text.unicode < 128)
            {
                setFocus(true);
                input_equation += static_cast<char>(event.text.unicode);

                cout << "input_equation: " << input_equation << endl;
            }
        }
    }




}

void Sidebar::setFocus(bool focus)
{
    text_focus = focus;
    if (focus)    {
        inputBox.setOutlineColor(sf::Color::Blue);
    }

    else    {
        inputBox.setOutlineColor(sf::Color(127, 127, 127)); // Gray color
    }
}

bool Sidebar::contains(sf::Vector2f point) const
{
    return inputBox.getGlobalBounds().contains(point);
}



