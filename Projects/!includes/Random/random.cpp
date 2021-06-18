#include <iostream>

#include <stdlib.h>
#include <time.h>

#include "../../!includes/Random/random.h"

using namespace std;

//-------------------------------------------------------------
//initialization of the static member variable must be
//                            done in the .cpp file.

int Random::objectCount = 0;
//--------------------------------------------------------------


Random::Random()
{
    objectCount++;

    if (objectCount == 1)
    {
        //cout << endl << "random number generator seeded..." << endl;
        //-----------------------------------------------
        srand(time(nullptr));
    }
}

int Random::Next(int low, int high)
{
    int r = rand() % ( high + 1 ) + low + 1;
//    int r = rand() % ( high - low + 1) + low;
    return r;

}















