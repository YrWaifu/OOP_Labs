#include "../include/Point.hpp"

int Point::getDistance(Point &other) {
    return std::round(std::sqrt(std::pow(coordX - other.coordX, 2) + std::pow(coordY - other.coordY, 2)));
}

void Point::operator=(Point &other) {
    coordX = other.coordX;
    coordY = other.coordY;
}

bool Point::operator==(Point &other) { return ((coordX == other.coordX) && (coordY == other.coordY)); }