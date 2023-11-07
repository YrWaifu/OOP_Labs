#pragma once

#include <string.h>

#include <cmath>
#include <iostream>
#include <stdexcept>

#include "Point.hpp"

class Figure {
   public:
    virtual std::string getType() const = 0;
    operator double() const;
    Point geomCentre() const;
    bool checkGeomValid() const;

    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, Figure* figure);

    size_t size();
    Point* getArray();

    virtual ~Figure() = default;

   protected:
    size_t n;
    Point* array;
};
