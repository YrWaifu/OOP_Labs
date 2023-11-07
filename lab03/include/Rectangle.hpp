#pragma once

#include "../include/Figure.hpp"

class Rectangle : public Figure {
   public:
    Rectangle();
    Rectangle(Point& point1, Point& point2, Point& point3, Point& point4);

    std::string getType() const override { return "Rectangle"; }

    void operator=(const Rectangle& figure);
    void operator=(Rectangle&& figure);
    bool operator==(const Rectangle& figure) const;

    ~Rectangle();
};