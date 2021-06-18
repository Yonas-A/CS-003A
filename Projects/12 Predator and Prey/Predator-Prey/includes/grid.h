#ifndef GRID_H
#define GRID_H

#include <iostream>


#include "../Predator_Prey/includes/creature.h"

using namespace  std;


class Grid
{
public:

    Grid();
    // constructor for a [SIZE][SIZE] grid

    ~Grid();
    // destructor for the grid

    void Breed( );
    // calls all breed functions

    void Fill_Grid( );
    // instantiates the grid with creatures

    void Kill( );
    // calls all kill functions

    void Move( );
    // calls all move functions

    void Reset_Move( );
    // resets the move of all creature to false;

    void Step( );
    // calls move, kill and breed functions

//==================================================
/// \brief
//===================================================

    void Random_Number(int& r, int& c);
    // generated a random number for row and col
    // in the range 1-19

//===================================================
// insertion operator for Grid

    friend ostream& operator <<(ostream& outs, const Grid& g);

private:
    Creature* _grid[SIZE][SIZE];

};

#endif // GRID_H
