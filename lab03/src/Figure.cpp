#include "../include/Figure.hpp"

bool Figure::checkGeomValid() const {
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (std::round(array[i].getDistance(array[(i + 1) % n])) !=
            round(array[(i + 2) % n].getDistance(array[(i + 3) % n]))) {
            throw std::logic_error("That's not a correct figure");
            flag = false;
        }
    }

    return flag;
}

Point Figure::geomCentre() const {
    if (!this->checkGeomValid()) {
        return Point(1e8, 1e8);
    }

    Point res(0, 0);
    for (size_t i = 0; i < n; ++i) {
        res.coordX += array[i].coordX;
        res.coordY += array[i].coordY;
    }
    res.coordX /= n;
    res.coordY /= n;
    return res;
}

Figure::operator double() const {
    if (this->checkGeomValid()) {
        return (n * array[1].getDistance(array[0]) * array[2].getDistance(array[1]) / 4) *
               (1 / std::tan(M_PI / n));
    }
}

std::istream& operator>>(std::istream& is, Figure& figure) {
    std::cout << "Please enter coordinates of points in " << figure.getType()
              << " (Example: <coordX> <coordY>)\n";
    for (int i = 0; i < figure.n; i++) {
        std::cout << "Point " << i + 1 << ": ";
        is >> figure.array[i].coordX >> figure.array[i].coordY;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, Figure& figure) {
    os << "Coordinates of " << figure.getType() << ":\n";
    for (int i = 0; i < figure.n; i++) {
        os << "Point " << i + 1 << ": " << '(' << figure.array[i].coordX << ", " << figure.array[i].coordY
           << ')' << '\n';
    }
    return os;
}

size_t Figure::size() { return n; }

Point* Figure::getArray() { return array; }