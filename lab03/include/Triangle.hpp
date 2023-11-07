#pragma once

#include "Figure.hpp"

class Triangle : public Figure {
   public:
    Triangle();
    Triangle(Point& point1, Point& point2, Point& point3);

    std::string getType() const override { return "Triangle"; }

    void operator=(const Triangle& figure);
    void operator=(Triangle&& figure);
    bool operator==(const Triangle& figure) const;

    ~Triangle() {
        n = 0;
        delete[] array;
        array = nullptr;
    };
};