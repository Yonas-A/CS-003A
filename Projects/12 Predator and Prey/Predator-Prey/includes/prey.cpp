#include <iostream>
#include <vector>

#include "../Predator_Prey/includes/creature.h"
#include "../Predator_Prey/includes/prey.h"


using namespace std;

Prey::Prey(Location l): Creature(l)
{
    _prey_steps = 0;
}

///=========================================
/// Prey::virtual functions
///=========================================

void Prey::breed(Creature* grid[][SIZE])
{
    /*STEPS
     *       A grid the creature lives is given
     * 1     if steps for prey is greater or equal to 3
     * 2     Create a vector of location and call find_blank()
     *       to the left of current col search for any empty space
     * 3     If empty locations are found select random a location
     * 4     Create a new Prey and place it in the location
     * 5     Reset prey step counter
     */


    if(get_prey_steps() >= PREY_BREEDING_CONST )
    {
        vector<Location> temp = find_blank(grid);
        if(temp.size() > 0)
        {
            int random = rand() % temp.size();

            Location hold = Location(temp[(random)]);

            grid[hold._row][hold._col] = new Prey(hold);
            _prey_steps = 0;

        }
    }
}

int Prey::get_type()    {
    return 1;
}

void Prey::kill(Creature* /*grid*/[][50])
{
    //intentionlly left blank
}

void Prey::move(Creature* grid[][SIZE])
{
    /*CASE 1
     *      look for grids that don't have predators
     *      if found choose a random location  and
     *      move to that location
     *      increment steps taken for prey
     * CASE 2
     *      if no grids without predator were found
     *      look for empty grids around
     *      if found choose a random location and
     *      move to that location
     *      increment steps taken for prey
     * CASE 3
     *      if predator is around  or no empty grid was found
     *      stay at current grid and do nothing
     */

    const int AVOID_PREDATOR = 2;
    // 2 represents Predator

    vector<Location> temp =
            find_not_this_creature(AVOID_PREDATOR, grid);

    if(temp.size() > 0)
    {
        int random = rand() % temp.size();
        move_to(grid, temp [random]);
        _prey_steps++;
    }

    else if(temp.size() <= 0 )
    {
        temp = find_blank(grid);
        if(temp.size() > 0)
        {
            int random = rand() % temp.size();
            move_to(grid, temp[random]);
            _prey_steps++;
        }
    }
}

void Prey::print()  {
    cout <<  "|O";
}

int Prey::get_prey_steps() const
{
    return _prey_steps;
}
