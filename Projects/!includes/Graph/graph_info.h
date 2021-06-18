#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../!includes/Graph/constants.h"

struct Graph_Info {
    std::string _equations;

    int window_H_dim = 1600;  // window height

    int window_W_dim = 1600;  // window width

    double x_origin = SCREEN_WIDTH / 2;  // x axis origin

    double y_origin = SCREEN_HEIGHT / 2;  // y axis origin

    double scale = 0;

    double zoom = 1;  // zooming factor

    double max_domain = 10;  // max domain of graph

    double min_domain = -10;  // min domain of graph

    double angle = 45;

    double total_points = 50000;  // # of points to plot
};

#endif  // GRAPH_INFO_H
