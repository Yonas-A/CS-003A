#ifndef PREDATOR_H
#define PREDATOR_H

#include <iostream>

#include "../includes/creature.h"

const int PREDATOR_KILL_STEPS = 2;
//used for killing the creature
const int PREDATOR_BREEDING_STEPS = 8;
//used for breeding predator offspring

class Predator : public Creature {
   public:
    Predator(Location l);
    //takes a location in the grid

    virtual void breed(Creature* grid[][SIZE]) override;
    //breeds every 5 steps if space exist

    virtual int get_type() override;
    //returns 2 to represent Predator

    virtual void move(Creature* grid[][SIZE]) override;
    //moves to adjecent empty spaces

    virtual void print() override;
    // prints O to represent Prey

    virtual void kill(Creature* grid[][SIZE]) override;
    // kills Predator if predators' steps since last eat = 3

    int get_breed_steps() const;
    // returns the steps predator has taken since last
    // time they breed;

    int get_steps_since_last_eat() const;
    // steps since last eat

   private:
    int steps_since_last_eat;
    int breed_steps;
};

#endif  // PREDATOR_H
