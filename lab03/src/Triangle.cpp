#include "../include/Triangle.hpp"

#define NTRIANGLE 3

Triangle::Triangle() {
    n = NTRIANGLE;
    array = new Point[n];
}

Triangle::Triangle(Point& point1, Point& point2, Point& point3) {
    n = NTRIANGLE;
    array = new Point[n];
    array[0] = point1, array[1] = point2, array[2] = point3;
    if (!this->checkGeomValid()) {
        throw std::logic_error("This triangle is wrong");
    }
}

Triangle::~Triangle() {
    n = 0;
    delete[] array;
    array = nullptr;
}

void Triangle::operator=(const Triangle& figure) {
    n = figure.n;
    array = new Point[n];
    for (size_t i = 0; i < n; ++i) {
        array[i] = figure.array[i];
    }
}

void Triangle::operator=(Triangle&& figure) {
    n = figure.n;
    array = figure.array;
    figure.n = 0;
    figure.array = nullptr;
}

bool Triangle::operator==(const Triangle& figure) const {
    return static_cast<double>(*this) == static_cast<double>(figure);
}