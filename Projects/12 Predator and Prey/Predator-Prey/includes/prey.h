#ifndef PREY_H
#define PREY_H

#include <iostream>

#include "../Predator_Prey/includes/creature.h"


const int PREY_BREEDING_CONST = 3;
//used for breeding Prey offspring

class Prey: public Creature
{

public:

    Prey(Location l);
    //takes the grid and a location

    virtual void breed(Creature* grid[][SIZE]) override;
    //breeds every 3 steps if space exist

    virtual int get_type() override;
    //returns 2 to represent Prey

    virtual void kill(Creature* grid[][SIZE]) override;
    // doesn't do anyting since killing prey is taken care
    // of inside move function for predator

    virtual void move(Creature* grid[][SIZE]) override;
    //moves to adjecent empty spaces

    virtual void print() override;
    // prints O to represent Prey

    int get_prey_steps() const;
    // returns the steps prey has taken

private:
    int _prey_steps;
};

#endif // PREY_H
