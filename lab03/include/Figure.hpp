#pragma once

#include <string.h>

#include <cmath>
#include <iostream>
#include <stdexcept>

#include "../include/Point.hpp"

class Figure {
   public:
    Figure() = default;
    virtual ~Figure() = default;

    virtual std::string getType() const;
    operator double() const;
    Point geomCentre() const;
    bool checkGeomValid() const;

    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, Figure& figure);

    size_t size();
    Point* getArray();

   protected:
    size_t n;
    Point* array;
};
