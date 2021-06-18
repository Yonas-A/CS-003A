#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../!includes/Graph/animate.h"
#include "../../!includes/Graph/graph_info.h"

using namespace std;

int main() {
    srand(time(0));

    Graph_Info info;

    info._equations = "sin(X)*X+5+(3/2)";
    Animate p(&info);
    p.run();

    return 0;
}
