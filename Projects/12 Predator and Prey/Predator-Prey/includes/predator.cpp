#include <iostream>
#include <vector>

#include "../Predator_Prey/includes/creature.h"
#include "../Predator_Prey/includes/predator.h"

using namespace  std;


Predator::Predator(Location l): Creature(l)
{
    steps_since_last_eat = 0;
    breed_steps = 0;
}

///=========================================
/// Predator::virtual functions
///=========================================

void Predator::breed(Creature* grid[][SIZE])
{
    /*CASE 1
     *      if breeding step is 3 or more
     *      look for empty grids around creature
     *      if found choose a random location and
     *      create a new creature at the location
     *      reset counter for breed_steps to zero
     * CASE 2
     *      if no empty grids were found
     *      do noting and prey was found at adjecent grids
     *      look for empty grids around predator
     *      if found choose a random location and move
     *      increment the counter for steps since eating
     *      also increment breeding_steps
     * CASE 3
     *      if no prey or  around predator was found
     *      stay at current grid and do nothing
     */

    if( get_breed_steps() >= PREDATOR_BREEDING_STEPS)
    {
        vector<Location> temp = find_blank(grid);
        if( temp.size() > 0 )
        {
            int random = rand() % temp.size();
            Location hold = Location(temp[random]);
            //creating the random location
            grid[hold._row][hold._col] = new Predator(hold);
            breed_steps = 0;
        }
    }

}

int Predator::get_type()    {
    return 2;
}

void Predator::move(Creature* grid[][SIZE])
{

    /*CASE 1
     *      look for prey on adjecent grids
     *      if found choose a random prey and
     *      eat them and take their place
     *      reset counter for steps since eating to zero
     *      increment breeding_steps
     * CASE 2
     *      if no prey was found at adjecent grids
     *      look for empty grids around predator
     *      if found choose a random location and move
     *      increment the counter for steps since eating
     *      also increment breeding_steps
     * CASE 3
     *      if no prey or empty grid around predator was found
     *      stay at current grid and do nothing
     */

    const int PREY = 1;
    // 1 represents prey

    vector<Location> temp = find_this_creature( PREY, grid);
    //stored nearest locations where Predator reside

    // if any prey on adjecent grid were found
    if(temp.size() > 0)
    {
        int random = rand() % temp.size();
        move_to(grid, temp.at(random));
        steps_since_last_eat = 0;
        breed_steps++;
    }

    //if no prey on adjecent grid was found
    else if(temp.size() <= 0)
    {
        // find an empty grid
        temp = find_blank(grid);

        //if empty grid around predator was found
        if(temp.size() > 0)
        {
           int random = rand() % temp.size();
            move_to(grid, temp.at(random));
            steps_since_last_eat++;
            breed_steps++;
        }
    }

}

void Predator::print()  {
    cout <<  "|X";
}

void Predator::kill(Creature* grid[][SIZE])
{
    /*STEPS
     *      given a grid the creature lives in
     *      if steps since last eating for that predator
     *      is greater than  or equal to 2, kill predator
     */
    if(get_steps_since_last_eat() >= PREDATOR_KILL_STEPS)
    {
        _die(grid);
    }
}


int Predator::get_steps_since_last_eat() const
{
    return steps_since_last_eat;
}

int Predator::get_breed_steps() const
{
    return breed_steps;
}
