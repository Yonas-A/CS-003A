#ifndef ANIMATE_H
#define ANIMATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>

#include "../includes/creature.h"
#include "../includes/sfml/constants.h"

class Animate {
   public:
    Animate();

    void Initialize();
    // initalized the grid to nullptr;

    void Create_Creatures(int creature_type, int how_many);
    // creates the given creature type in the grid

    void Fill_First_Time();
    // fills the grid with a number of different creatures

    sf::Color Get_Color(int type);
    //returns a color type for the creature type

    void processEvents();
    //handle keyboard and mouse events

    void render();
    //draw and display the next frame

    void run();
    //call process, update, and render

    void ShowShapes();

    void update();
    //prepare the next frame
    // calls move, kill and breed

    void Print();

    //////////////////////////////////////////////////////////////
    /// \brief following functions take care of moving, breeding
    ///        moving and refilling grid after each iteration
    //////////////////////////////////////////////////////////////
    void refill();
    void Move();
    void Breed();
    void Kill();
    void count();
    //counts each creature and empty_grids

   private:
    sf::RenderWindow window;
    sf::RectangleShape shapeArray[GRID_HEIGHT][GRID_WIDTH];
    Creature* _grid[GRID_HEIGHT][GRID_WIDTH];

    int prey_count = 0;
    int predator_count = 0;
    int step_count = 0;
    int blank_count = 0;
};

#endif  // ANIMATE_H
