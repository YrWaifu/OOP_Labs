#pragma once

#include <stdio.h>

#include <cmath>

class Point {
   public:
    Point() = default;
    Point(int x, int y) : coordX(x), coordY(y){};
    ~Point() = default;

    int getDistance(Point& other);
    void operator=(Point& other);
    bool operator==(Point& other);

    int coordX;
    int coordY;
};