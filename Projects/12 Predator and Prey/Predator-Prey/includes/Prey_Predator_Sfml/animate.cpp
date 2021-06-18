#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../../!includes/Random/random.h"
#include "../Predator_Prey/includes/Prey_Predator_Sfml/animate.h"
#include "../Predator_Prey/includes/Prey_Predator_Sfml/constants.h"
#include "../Predator_Prey/includes/predator.h"
#include "../Predator_Prey/includes/prey.h"
#include "../Predator_Prey/includes/wall.h"



Animate::Animate()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                  "Predator - Prey!");
    window.setFramerateLimit(30);
    Initialize();
    Fill_First_Time();

}

void Animate::Initialize()
{
    for (int row = 0; row < GRID_HEIGHT ; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            _grid[row][col] = nullptr;
        }
    }
}

void Animate::Create_Creatures(int creature_type, int total)
{
    for(int i = 0; i < total; i++)
    {
        Random r ;
        int row = r.Next(0,GRID_HEIGHT);
        int col = r.Next(0, GRID_WIDTH);

        if(_grid[row][col] == nullptr)
        {
            if(creature_type == 1)
            {
                _grid[row][col] = new Prey(Location(row, col));
                break;
            }
            else if(creature_type == 2)
            {
                _grid[row][col] = new Predator (Location(row, col));
                break;
            }
            else
                _grid[row][col] = nullptr;
                break;
        }

    }
}

void Animate::Fill_First_Time()
{
    const int STARTING_PREDATOR_TOTAL = 200;
    const int STARTING_PREY_TOTAL = 1000;

    for (int row = 0; row < SIZE ; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if(( row == 0  || row == SIZE -1 ) ||
                    (col == 0  || col == SIZE -1 ))
            {
                // creating a wall on the edges of the grid
                _grid[row][col]  = new Wall (Location(row, col));
            }
        }
    }

    const int prey = 1;   const int predator = 2;
    Create_Creatures(prey, STARTING_PREY_TOTAL);
    Create_Creatures(predator , STARTING_PREDATOR_TOTAL);
}

sf::Color Animate::Get_Color(int type)
{
    if(type == 0)
        return wall_color;
    else if( type  == 1)
        return prey_color;
    else if(type == 2)
        return predator_color;
    else
        return blank_grid;
}

void Animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
        step_count++;
    }
}

void Animate::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                std::cout << "the right button was pressed" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
            else
                std::cout<<"left button?"<<std::endl;
            break;
        default:
            break;
        }
    }
}

void Animate::update()
{
    Move();
    Breed();
    Kill();
    Print();
    count();
    refill();
}

void Animate::render()
{
    window.clear();
    ShowShapes();
    window.display();
}

void Animate::ShowShapes()
{
    for (int row = 0; row < GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            window.draw(shapeArray[row][col]);
        }
    }
}

void Animate::Print()
{
    for(int row = 0; row < GRID_HEIGHT; row++)
    {
        for(int col = 0; col < GRID_WIDTH; col++)
        {
            if(_grid[row][col] != nullptr )
            {
                Random r;
                int color = _grid[row][col]->get_type();
                int vectorY = row*(CELL_SIZE + 1);
                int vectorX = col*(CELL_SIZE + 1);

                shapeArray[row][col].setSize(sf::Vector2f
                                             (CELL_SIZE,CELL_SIZE));
                shapeArray[row][col].setPosition(sf::Vector2f
                                                 (vectorX,vectorY));
                shapeArray[row][col].setFillColor(sf::Color
                                             (Get_Color(color)));
            }
            else
            {
                Random r;
                int vectorY = row*(CELL_SIZE + 1);
                int vectorX = col*(CELL_SIZE + 1);

                shapeArray[row][col].setSize(sf::Vector2f
                                            (CELL_SIZE,CELL_SIZE));
                shapeArray[row][col].setPosition(sf::Vector2f
                                            (vectorX,vectorY));
                shapeArray[row][col].setFillColor(sf::
                                            Color((blank_grid)));
            }
        }
    }

}

void Animate::Move()
{
    for(int row = 0; row < GRID_HEIGHT; row++)
    {
        for(int col = 0; col < GRID_WIDTH; col++)
        {
            if(_grid[row][col] != nullptr )
            {
                _grid[row][col] -> move(_grid);
            }
        }
    }

}

void Animate::Kill()
{
    for (int row = 0; row <  GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            if(_grid[row][col] != nullptr )
            {
                _grid[row][col] -> kill(_grid);
            }
        }
    }
}

void Animate::Breed()
{

    for (int row = 0; row <  GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            if( _grid[row][col] != nullptr &&
                    _grid[row][col] ->get_type() != 0)
            {
                _grid[row][col] -> breed(_grid);
            }
        }
    }

}

void Animate::count()
{
    prey_count = 0; // total number of preys in the grid
    predator_count = 0; // total number of preys in the grid
    int wall_count = 0;
    blank_count = 0; // total number of empty grids

    for (int row = 0; row <  GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            if( _grid[row][col] != nullptr )
            {
                if (_grid[row][col] ->get_type() == 1)
                    prey_count++;
                else if(_grid[row][col] ->get_type() == 2)
                    predator_count++;
                else
                    wall_count++;
            }

            else
            {
                blank_count++;
            }
        }
    }

//    cout << endl ;
//    cout << "Blank count:: " << blank_count << "  ";
//    cout << "Wall count:: " << wall_count << endl;
//    cout << "Prey count:: " << prey_count << "  " ;
//    cout << "Predator count:: " << predator_count << endl;
//    cout << "total grid size = " << blank_count + wall_count
//            + prey_count + predator_count << endl;

}

void Animate::refill()
{
    if(predator_count <= 20)
    {
        Create_Creatures(2, 50);
    }

    else if(prey_count <= 100)
    {
        Create_Creatures(1, 100);
    }

    else if(blank_count > 500)
    {
         Create_Creatures(1,  blank_count - 50  /predator_count);
         Create_Creatures(2,  blank_count - 50 /prey_count);
    }


}
