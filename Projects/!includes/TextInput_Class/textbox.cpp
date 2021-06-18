#include "textbox.h"

TextBox::TextBox(int size, sf::Color color, bool sel)
{
    textbox.setCharacterSize(static_cast<unsigned int> (size));
    textbox.setFillColor(color);
    isSelected = sel;

    // Check if the textbox is selected upon creation and display it accordingly:
    if(isSelected)
        textbox.setString("_");
    else
        textbox.setString("");

}

void TextBox::setFont(sf::Font &fonts)
{
    textbox.setFont(fonts);
}

void TextBox::setPosition(sf::Vector2f point)
{
    textbox.setPosition(point);
}

void TextBox::setLimit(bool ToF)
{
    hasLimit = ToF;
}

void TextBox::setLimit(bool ToF, int thisLimit)
{
    hasLimit = ToF;
    limit = thisLimit - 1;
}

void TextBox::setSelected(bool sel)
{
    isSelected = sel;

    // If not selected, remove the '_' at the end:
    if (!sel) {
        std::string t = text.str();
        std::string newT = "";
        for (unsigned int i = 0; i < t.length(); i++)
        {
            newT += t[i];
        }
        textbox.setString(newT);
    }
}

std::string TextBox::getText()
{
    return text.str();
}


void TextBox::drawTo(sf::RenderWindow &window)
{
    window.draw(textbox);
}


void TextBox::deleteLastChar()
{
    std::string t = text.str();
    std::string newT = "";
    for (unsigned int i = 0; i < t.length() - 1; i++)
    {
        newT += t[i];
    }
    text.str("");
    text << newT;
    textbox.setString(text.str() + "_");
}

void TextBox::typedOn(sf::Event input)
{
    if (isSelected)
    {
        unsigned int charTyped = input.text.unicode;

        // Only allow normal inputs:
        if (charTyped < 128)
        {
            if (hasLimit)
            {
                // If there's a limit, don't go over it:
                if ( text.str().length() <= limit)
                {
                    inputLogic(charTyped);
                }
                // But allow for char deletions:
                else if (text.str().length() > limit && charTyped == DELETE_KEY)
                {
                    deleteLastChar();
                }
            }
            // If no limit exists, just run the function:
            else
            {
                inputLogic(charTyped);
            }
        }
    }
}



void TextBox:: inputLogic(int charTyped)
{
    // If the key pressed isn't delete, or the two selection keys, then append the text with the char:
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
    {
        text << static_cast<char>(charTyped);
    }
    // If the key is delete, then delete the char:
    else if (charTyped == DELETE_KEY) {
        if (text.str().length() > 0) {
            deleteLastChar();
        }
    }
    // Set the textbox text:
    textbox.setString(text.str() + "_");
}




