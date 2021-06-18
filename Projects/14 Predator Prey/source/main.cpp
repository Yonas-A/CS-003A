/*
 * Author: Yonas Adamu
 * Project: a Predator - prey simulation program
 * Purpose: to practice inheritance and virtuality between classes
 *
 */

#include <time.h>

#include <iostream>

#include "../includes/grid.h"
#include "../includes/sfml/animate.h"

using namespace std;

void pp_test();

int main() {
    srand(time(nullptr));

    /// ========================================================
    /// Predator and Prey in sfml test run
    /// ========================================================

    //    Animate a;
    //    a.run();

    /// ========================================================
    /// Predator and Prey in a console test run
    /// ========================================================
    pp_test();

    return 0;
}

void pp_test() {
    Grid g;
    char command = 'a';

    int gen = 0;

    cout << endl
         << "Parents( zero generation):: " << gen << endl;
    g.Fill_Grid();
    cout << g << endl;
    cout << "       - - - - - - - - - - - - - - -" << endl
         << endl;

    while (cin.get(command) && (command != 'q' && command != 'Q')) {
        g.Step();
        gen++;

        cout << ". . . . .  Generation: " << gen << "  . . . . ."
             << endl
             << endl
             << g << endl;
        cout << "       - - - - - - - - - - - - - - -" << endl
             << endl;
    }

    cout << "Last generation was " << gen << endl;
    cout << endl
         << ". . . . . . . . . . . . . " << endl;
}
