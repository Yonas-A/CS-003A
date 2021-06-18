#ifndef WALL_H
#define WALL_H

#include <iostream>

#include "../includes/creature.h"

class Wall : public Creature {
   public:
    Wall(Location l);
    //takes the grid and a location

    virtual void breed(Creature* grid[][SIZE]) override;
    //doesn't breed at all

    virtual int get_type() override;
    //returns 3 to represent Wall

    virtual void kill(Creature* grid[][SIZE]) override;
    //doesn't die unless when terminating program

    virtual void move(Creature* grid[][SIZE]) override;
    //Wall doesn't move

    virtual void print() override;
    // prints ".' for wall
};

#endif  // WALL_H
