#include <iostream>

#include "../../!includes/Graph/animate.h"
#include "../../!includes/Graph/constants.h"
#include "../../!includes/Graph/graph_info.h"
#include "../../!includes/Graph/plot.h"

using namespace std;



Animate::Animate(Graph_Info *g_info):plot(g_info), info(g_info),
    sidebar(WORK_PANEL, SIDE_BAR)
{

    window.create(sf::VideoMode(WINDOW_MAXIMUM,SCREEN_WIDTH), "Graph!");
    window.setFramerateLimit(60);
    loadFont();

}

void Animate::Draw()
{

//    system.Draw(window);
    sidebar.draw(window);
    drawAxes();
    drawGraph();
//    window.draw(textaLabel);

}

void Animate::drawAxes()
{
    float AXIS_THICKNESS = 1;

    for (int row = info->x_origin; row < info->x_origin + 1;row++)
    {
        for (int col = 0  ; col < SCREEN_HEIGHT  ; col++)
        {
            mypoint.setSize(sf::Vector2f(AXIS_THICKNESS, AXIS_THICKNESS));
            mypoint.setPosition(sf::Vector2f(row,col));
            mypoint.setFillColor(sf::Color::Cyan);
            window.draw(mypoint);
        }
    }

    for (int row = 0 ; row <  SCREEN_WIDTH ; row++)
    {
        for(int col = info->y_origin; col < info->y_origin + 1; col++)
        {
            mypoint.setSize(sf::Vector2f(AXIS_THICKNESS, AXIS_THICKNESS));
            mypoint.setPosition(sf::Vector2f(row,col));
            mypoint.setFillColor(sf::Color::Cyan);
            window.draw(mypoint);
        }
    }
}

void Animate::drawGraph()
{
    std::vector<sf::Vector2f> temp = plot.get_coord();
//    cout << "\n\t = = = = = = = = = = = = = = = = =  \n";
//    cout << "temp.size(): " << temp.size() << endl;
//    cout << "\n\t = = = = = = = = = = = = = = = = =  \n";

    assert(!temp.empty());

    for(float i = 0; i < temp.size(); i++)
    {
        mypoint.setSize(sf::Vector2f(GRAPH_THICKNESS, GRAPH_THICKNESS));
        mypoint.setPosition(( temp.at(i) ));
        mypoint.setFillColor(sf::Color::Magenta);
        window.draw(mypoint);
    }

}

void Animate::loadFont()
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout<<"Graph Ctor:: Font failed to load"<<std::endl;
        std::cin.get();
        exit(-1);
    }

    textLabel.setFont(font);
    textLabel.setCharacterSize((20));
}


void Animate::processEvents()
{
    double zoom_scale = 1;
    bool hold = false;

    double pan_Left_Right = 0.1;    double pan_Up_Down = 0.1;

    double x_center = 0, y_center = 0;

    sf::Vector2i initial_pos;
    sf::Vector2i final_pos;

    sf::Event event;


    std::string  temp_input("");
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::KeyPressed:
            if ( event.key.code == sf::Keyboard::R )
            {
                zoom_scale = 1;
                info->min_domain = MIN_DOMAIN;
                info->max_domain = MAX_DOMAIN;
                info->x_origin = SCREEN_WIDTH/2;
                info->y_origin = SCREEN_HEIGHT /2;
            }
            break;

        case sf::Event::MouseWheelMoved:
        {

            if(event.mouseWheel.delta < 0)
                zoom_scale -= zoom_scale *0.5; //zooming out
            if(event.mouseWheel.delta > 0)
                zoom_scale += zoom_scale*0.5; // zooming in

        }
            break;

        case sf::Event::MouseButtonPressed:
        {
            initial_pos = sf::Mouse::getPosition(window);
            hold = true;
            auto pos = initial_pos;

            sidebar.setFocus(false);
            if (sidebar.contains(sf::Vector2f(pos)))
            {
                sidebar.setFocus(true);
//                sidebar.readInput(window, event);
            }
        }
            break;

        case sf::Event::MouseButtonReleased:
        {
            hold = false;
            sidebar.setFocus(false);

        }
            break;

        case sf::Event::TextEntered:
            if (sidebar.contains(sf::Vector2f(sf::Mouse::getPosition(window))))
            {
                sidebar.setFocus(true);

                sidebar.readInput(window, event);
            }

            if (event.text.unicode == '\b' &&
                    temp_input.size() > 0)
                temp_input.erase(temp_input.size() - 1, 1);
            else if (event.text.unicode < 128)
            {
                temp_input += static_cast<char>(event.text.unicode);

            }
        break;

        default:
            break;
        }
    }

    cout << " temp_input: " << temp_input << endl;
    info->scale *= zoom_scale;
    if(zoom_scale >= 0)
    {
        info->min_domain /= zoom_scale;
        info->max_domain /= zoom_scale;
    }

    if (sidebar.getInput() != "")
    {
        info->_equations  = sidebar.getInput();
    }

}

void Animate::render()
{
       window.clear();
       Draw();
       window.display();
}


void Animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
}


void Animate::update()
{
//    Draw();
}



