#pragma once

#include "../include/Figure.hpp"

class Square : public Figure {
   public:
    Square();
    Square(Point& point1, Point& point2, Point& point3, Point& point4);

    std::string getType() const override { return "Square"; }

    void operator=(const Square& figure);
    void operator=(Square&& figure);
    bool operator==(const Square& figure) const;

    ~Square() {
        n = 0;
        delete[] array;
        array = nullptr;
    }
};