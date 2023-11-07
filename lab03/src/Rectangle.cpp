#include "../include/Rectangle.hpp"

#define NRectangle 3

Rectangle::Rectangle() {
    n = NRectangle;
    array = new Point[n];
}

Rectangle::Rectangle(Point& point1, Point& point2, Point& point3, Point& point4) {
    n = NRectangle;
    array = new Point[n];
    array[0] = point1, array[1] = point2, array[2] = point3, array[3] = point4;
    if (!this->checkGeomValid()) {
        throw std::logic_error("This Rectangle is wrong");
    }
}

Rectangle::~Rectangle() {
    n = 0;
    delete[] array;
    array = nullptr;
}

void Rectangle::operator=(const Rectangle& figure) {
    n = figure.n;
    array = new Point[n];
    for (size_t i = 0; i < n; ++i) {
        array[i] = figure.array[i];
    }
}

void Rectangle::operator=(Rectangle&& figure) {
    n = figure.n;
    array = figure.array;
    figure.n = 0;
    figure.array = nullptr;
}

bool Rectangle::operator==(const Rectangle& figure) const {
    return static_cast<double>(*this) == static_cast<double>(figure);
}