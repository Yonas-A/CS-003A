#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

using namespace std;

const int SIZE = 50;

struct Location {
    int _row;
    int _col;

    Location(const int row = int(), const int col = int()) {
        _row = row;
        _col = col;
    }

    friend ostream& operator<<(ostream& outs, const Location& l) {
        outs << "Row: " << l._row << endl;
        outs << "Col: " << l._col << endl;
        return outs;
    }
};

class Creature {
   public:
    Creature(Location l);
    //Creature CTOR:: takes a location in the grid

    virtual void breed(Creature* grid[][SIZE]);
    //breed creatures and places them in the grid

    void _die(Creature* grid[][SIZE]);
    // checks if its time to die and kills creature

    virtual int get_type();
    //returns integer representing creature

    virtual void kill(Creature* grid[][SIZE]);
    //kill this creature and clean up thier location

    virtual void move(Creature* grid[][SIZE]);
    // moves creature to new locations in the grid

    void move_to(Creature* grid[][SIZE], const Location& local);
    // given grid and location, moves creature to the location

    virtual void print();
    //prints the creature

    //==========================================================
    /// \brief functions search locations around a creature
    ///        and store these locations in a vector of locations
    //==========================================================
    vector<Location> find_blank(Creature* grid[][SIZE]);
    // returns an array of location with blanks around a creature

    vector<Location> find_not_this_creature(const int& creature_type,
                                            Creature* grid[][SIZE]);
    //find empty space away from creature_type c

    vector<Location> find_this_creature(const int& creature_type,
                                        Creature* grid[][SIZE]);
    // finds empty space around creature c

    //==========================================================
    /// \brief accessor and mutator function for _moved
    //==========================================================
    bool get_moved() const;
    //returns the value of _move

    void set_moved(bool move);
    //sets _move to the value of move

   private:
    Location loc;
    bool _moved;
};

#endif  // CREATURE_H
