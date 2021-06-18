#include "../includes/creature.h"

#include <iostream>
#include <vector>

using namespace std;

Creature::Creature(Location l) : loc(l), _moved(false) {
}

//===================================
//  virtual functions
//===================================

void Creature::breed(Creature* /*grid*/[][SIZE]) {
    // left intentionally blank
}

void Creature::_die(Creature* grid[][SIZE]) {
    delete grid[loc._row][loc._col];
    grid[loc._row][loc._col] = nullptr;
}

void Creature::kill(Creature* /*grid*/[][SIZE]) {
    //    cout << " kill me " << endl;
}

int Creature::get_type() {
    return 100;
}

void Creature::move(Creature* grid[][SIZE]) {
    vector<Location> temp = find_blank(grid);
    if (temp.size() > 0) {
        int random = rand() % temp.size();
        move_to(grid, temp[random]);
    }
}

void Creature::move_to(Creature* grid[][SIZE], const Location& local) {
    /*STEPS
     *      A grid and a location inside a grid are given
     *      point the creature at old location to new location
     *      set the old location to nullptr
     *      update the creatures location to its new location
     */

    grid[local._row][local._col] = grid[loc._row][loc._col];
    grid[loc._row][loc._col] = nullptr;
    loc._row = local._row;
    loc._col = local._col;

    // setting the _move value of creature at the location to true
    grid[loc._row][loc._col]->set_moved(true);
}

void Creature::print() {
    cout << "|C";
}

vector<Location> Creature::find_blank(Creature* grid[][SIZE]) {
    /*STEPS
     *       A grid is given
     * 1     create a vector of location
     * 2     Starting one row above current row and one col
     *       to the left of current col search for any empty space
     * 3     If empty space found push row and col of this location
     *       into the vector
     * 4     Stop the loop one row below and one col to the right
     *       of Creature's location
     * 5     return the vector of location
     */

    vector<Location> temp;  // a vector of location

    for (int row = loc._row - 1; row <= loc._row + 1; row++) {
        for (int col = loc._col - 1; col <= loc._col + 1; col++) {
            if (grid[row][col] == nullptr)
                temp.push_back(Location(row, col));
            //store row and col of empty location in the vector
        }
    }

    return temp;
}

vector<Location> Creature::find_not_this_creature(const int& creature_type, Creature* grid[][SIZE]) {
    /*STEPS
     *       A grid and a creature type to look for is given
     * 1     create a vector of location
     * 2     Starting one row above current row and one col
     *       to the left of current col search for any empty space
     * 3     If a space that doesn't have the given creature type
     *       if found store this location into the vector
     * 4     Stop the loop one row below and one col to the right
     *       of Creature's location
     * 5     return the vector of location
     */

    vector<Location> temp;
    // a vector of location to store any available locations

    for (int row = loc._row - 1; row <= loc._row + 1; row++) {
        for (int col = loc._col - 1; col <= loc._col + 1; col++) {
            if (grid[row][col] == nullptr /*&&
                     grid[row][col]->get_type() != creature_type*/
            ) {
                temp.push_back(Location(row, col));
                //inserting the row and col to our vectors of location
            }
        }
    }

    return temp;
}

vector<Location> Creature::find_this_creature(const int& creature_type, Creature* grid[][SIZE]) {
    /*STEPS
     *       A grid and a creature type to look for is given
     * 1     Create a vector of location
     * 2     Starting one row above current row and one col
     *       to the left of current col search for any empty space
     * 3     If a location with a creature matching given creature
     *          type is found store this location into the vector
     * 4     Stop the loop one row below and one col to the right
     *       of Creature's location
     * 5     Return the vector of location
     */
    vector<Location> temp;

    for (int row = loc._row - 1; row <= loc._row + 1; row++) {
        for (int col = loc._col - 1; col <= loc._col + 1; col++) {
            if (grid[row][col] != nullptr &&
                grid[row][col]->get_type() == creature_type) {
                temp.push_back(Location(row, col));
            }
        }
    }

    return temp;
}

//==========================================================

bool Creature::get_moved() const {
    return _moved;
}

void Creature::set_moved(bool move) {
    _moved = move;
}
