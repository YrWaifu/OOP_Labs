#pragma once

#include <cmath>
#include <iostream>

using namespace std;

template <typename T>

concept Countable = is_arithmetic_v<T>;

template <Countable T>

class Figure {
   public:
    using point = pair<T, T>;

    virtual point geomCentre() const = 0;
    virtual operator double() const = 0;
    virtual inline ostream& operator<<(ostream& os) const = 0;
    virtual inline istream& operator>>(istream& is) = 0;
    virtual ~Figure() = default;
};