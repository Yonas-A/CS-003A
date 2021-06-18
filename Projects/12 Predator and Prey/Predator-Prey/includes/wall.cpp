#include <iostream>

#include "../Predator_Prey/includes/creature.h"
#include "../Predator_Prey/includes/wall.h"

Wall::Wall(Location l): Creature(l)
{

}

///=========================================
/// Prey::virtual functions
///=========================================
void Wall::breed(Creature* /*grid*/[][SIZE])
{
// intentionally left blank since wall doesn't do anything
}



int Wall::get_type()
{
    return 0;
}

void Wall::kill (Creature* /*grid*/[][SIZE])
{
//intentionally left blank since wall doesn't do anything
}

void Wall::move(Creature* /*grid*/[][SIZE])
{
// intentionally left blank since wall doesn't do anything
}

void Wall::print()
{
    cout << "|Z" ;
}
