#pragma once

#include <stdio.h>

#include <stdexcept>

#include "Rectangle.hpp"
#include "Square.hpp"
#include "Triangle.hpp"

class Vector {
   public:
    Vector();

    ~Vector();

    void pushBack(Figure* figure);
    Figure* popByIdx(size_t idx);

    size_t getSize();
    Figure** getVector();

   private:
    size_t size;
    Figure** array;
};