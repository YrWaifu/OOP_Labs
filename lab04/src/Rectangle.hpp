#include "Figure.hpp"
#pragma once

template <Countable T>

class Rectangle : public Figure<T> {
   public:
    using point = pair<T, T>;
    point pt1, pt2, pt3, pt4;
    T side1, side2;

    Rectangle() {
        pt1.first = 0, pt2.first = 0, pt3.first = 0, pt4.first = 0;
        pt1.second = 0, pt2.second = 0, pt3.second = 0, pt4.second = 0;

        side1 = 0, side2 = 0;
    }

    Rectangle(point first, point second, point third, point fourth) {
        bool check =
            (round(sqrt(pow(third.first - second.first, 2) + pow(third.second - second.second, 2))) ==
             round(sqrt(pow(first.first - fourth.first, 2) + pow(first.second - fourth.second, 2)))) and
            (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) ==
             round(sqrt(pow(fourth.first - third.first, 2) + pow(fourth.second - third.second, 2))));
        if (check) {
            pt1.first = first.first, pt2.first = second.first, pt3.first = third.first,
            pt4.first = fourth.first;
            pt1.second = first.second, pt2.second = second.second, pt3.second = third.second,
            pt4.second = fourth.second;

            side1 = abs(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2)));
            side2 = abs(sqrt(pow(third.first - second.first, 2) + pow(third.second - second.second, 2)));
        } else {
            throw logic_error("Try another points (or check given order)");
        }
    }

    virtual point geomCentre() const override {
        point result;

        result.first = (pt1.first + pt2.first + pt3.first + pt4.first) / 4;
        result.second = (pt1.second + pt2.second + pt3.second + pt4.second) / 4;

        return result;
    }

    virtual operator double() const override { return static_cast<double>(side1 * side2); }

    virtual inline ostream& operator<<(ostream& os) const override {
        os << "Points of Rectangle:";
        os << "\nPoint 1: (" << pt1.first << ", " << pt1.second << ")";
        os << "\nPoint 2: (" << pt2.first << ", " << pt2.second << ")";
        os << "\nPoint 3: (" << pt3.first << ", " << pt3.second << ")";
        os << "\nPoint 4: (" << pt4.first << ", " << pt4.second << ")";
        return os;
    }

    virtual inline istream& operator>>(istream& is) override {
        point first, second, third, fourth;
        cout << "Please type in coordinates of points in Rectangle(Ex: <x_val> <y_val>):";
        is >> first.first >> first.second;
        is >> second.first >> second.second;
        is >> third.first >> third.second;
        is >> fourth.first >> fourth.second;

        bool check =
            (round(sqrt(pow(third.first - second.first, 2) + pow(third.second - second.second, 2))) ==
             round(sqrt(pow(first.first - fourth.first, 2) + pow(first.second - fourth.second, 2)))) and
            (round(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2))) ==
             round(sqrt(pow(fourth.first - third.first, 2) + pow(fourth.second - third.second, 2))));

        if (check) {
            pt1.first = first.first, pt2.first = second.first, pt3.first = third.first,
            pt4.first = fourth.first;
            pt1.second = first.second, pt2.second = second.second, pt3.second = third.second,
            pt4.second = fourth.second;

            side1 = abs(sqrt(pow(second.first - first.first, 2) + pow(second.second - first.second, 2)));
            side2 = abs(sqrt(pow(third.first - second.first, 2) + pow(third.second - second.second, 2)));
        } else {
            throw logic_error("Try another points (or check given order)");
        }
        return is;
    }

    void operator=(const Rectangle<T>& fig) {
        pt1.first = fig.pt1.first, pt2.first = fig.pt2.first, pt3.first = fig.pt3.first,
        pt4.first = fig.pt4.first;
        pt1.second = fig.pt1.second, pt2.second = fig.pt2.second, pt3.second = fig.pt3.second,
        pt4.second = fig.pt4.second;

        side1 = fig.side1;
        side2 = fig.side2;
    }
    bool operator==(const Rectangle<T>& other) const {
        return round(static_cast<double>(*this)) == round(static_cast<double>(other));
    }
};