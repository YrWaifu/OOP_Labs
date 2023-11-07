#include "../include/Square.hpp"

#define NSQUARE 4

Square::Square() {
    n = NSQUARE;
    array = new Point[n];
}

Square::Square(Point& point1, Point& point2, Point& point3, Point& point4) {
    n = NSQUARE;
    array = new Point[n];
    array[0] = point1, array[1] = point2, array[2] = point3, array[3] = point4;
    if (!this->checkGeomValid()) {
        throw std::logic_error("This square is wrong");
    }
}

Square::~Square() {
    n = 0;
    delete[] array;
    array = nullptr;
}

void Square::operator=(const Square& figure) {
    n = figure.n;
    array = new Point[n];
    for (size_t i = 0; i < n; i++) {
        array[i] = figure.array[i];
    }
}

void Square::operator=(Square&& figure) {
    n = figure.n;
    array = figure.array;
    figure.n = 0;
    figure.array = nullptr;
}

bool Square::operator==(const Square& figure) const {
    return static_cast<double>(*this) == static_cast<double>(figure);
}