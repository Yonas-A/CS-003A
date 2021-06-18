#include "../includes/grid.h"

#include <cassert>
#include <iostream>

#include "../includes/creature.h"
#include "../includes/predator.h"
#include "../includes/prey.h"
#include "../includes/wall.h"

Grid::Grid() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            _grid[row][col] = nullptr;
        }
    }
}

Grid::~Grid() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            delete _grid[row][col];
        }
    }
}

//==================================
// calling functions from Creature.h
//==================================

void Grid::Breed() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (_grid[row][col] != nullptr &&
                _grid[row][col]->get_type() != 0) {
                _grid[row][col]->breed(_grid);
            }
        }
    }
}

void Grid::Fill_Grid() {
    int row(0), col(0), count(0);

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if ((row == 0 || row == SIZE - 1) ||
                (col == 0 || col == SIZE - 1)) {
                // creating a wall on the edges of the grid
                _grid[row][col] = new Wall(Location(row, col));
            }
        }
    }

    // reseting col, row and count to zero
    row = 0;
    col = 0;
    count = 0;

    //creating 100 Prey and randomly placing them in the grid
    while (count < 100) {
        Random_Number(row, col);
        //generating a random number in a range 1- 21
        if (_grid[row][col] == nullptr) {
            _grid[row][col] = new Prey(Location(row, col));
            count++;
        }
    }

    //reseting col, row and count to zero
    row = 0;
    col = 0;
    count = 0;
    //creating 10 Predator and randomly placing them in the grid
    while (count < 20) {
        Random_Number(row, col);
        if (_grid[row][col] == nullptr) {
            _grid[row][col] = new Predator(Location(row, col));
            count++;
        }
    }
}

void Grid::Kill() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (_grid[row][col] != nullptr) {
                _grid[row][col]->kill(_grid);
            }
        }
    }
}

void Grid::Move() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (_grid[row][col] != nullptr &&
                _grid[row][col]->get_moved() != true) {
                _grid[row][col]->move(_grid);
            }
        }
    }
}

void Grid::Reset_Move() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (_grid[row][col] != nullptr) {
                _grid[row][col]->set_moved(false);
            }
        }
    }
}

void Grid::Step() {
    Move();
    Breed();
    Kill();
    Reset_Move();
}

//==================================
// random number generation
//=================================
void Grid::Random_Number(int& r, int& c) {
    const int HIGH = SIZE - 1;
    const int LOW = 1;

    r = (rand() % (HIGH - LOW + 1)) + LOW;
    c = (rand() % (HIGH - LOW + 1)) + LOW;
}

//==================================
// insertion operator for Grid
//=================================
ostream& operator<<(ostream& outs, const Grid& g) {
    int prey_count = 0;
    int predator_count = 0;
    int empty_count = 0;
    int wall_count = 0;
    outs << endl;

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (g._grid[row][col] == nullptr) {
                outs << "|"
                     << ".";
                empty_count++;
            } else {
                g._grid[row][col]->print();
                if (g._grid[row][col]->get_type() == 1) {
                    prey_count++;
                } else if (g._grid[row][col]->get_type() == 2) {
                    predator_count++;
                } else if (g._grid[row][col]->get_type() == 0) {
                    wall_count++;
                }
            }
        }
        outs << "|" << endl;
    }

    outs << endl;
    outs << "wall count:: " << wall_count << endl;
    outs << "empty count:: " << empty_count << endl;
    outs << "Prey count:: " << prey_count << endl;
    outs << "Predator count::  " << predator_count << endl;
    outs << "total grid size = " << wall_count + empty_count + prey_count + predator_count << endl;
    return outs;
}
