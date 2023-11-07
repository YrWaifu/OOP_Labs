#include "../include/Vector.hpp"

size_t Vector::getSize() { return size; }

Figure** Vector::getVector() { return array; }

void Vector::pushBack(Figure* figure) {
    if (figure == nullptr) {
        return;
    }

    size_t newSize = size + 1;
    Figure** newArray = new Figure*[newSize];

    for (size_t i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }

    newArray[size] = figure;

    delete[] array;
    array = newArray;
    size = newSize;
}

Figure* Vector::popByIdx(size_t idx) {
    if (idx >= size) {
        throw std::logic_error("Index is larger then the size of the array.");
        return nullptr;
    }

    Figure* removedFigure = array[idx];

    size_t newSize = size - 1;
    Figure** newArray = new Figure*[newSize];

    for (size_t i = 0, j = 0; i < size; ++i) {
        if (i != idx) {
            newArray[j++] = array[i];
        }
    }

    delete[] array;
    array = newArray;
    size = newSize;

    return removedFigure;
}

Vector::Vector() {
    size = 0;
    array = nullptr;
}

Vector::~Vector() {
    size = 0;
    delete[] array;
    array = nullptr;
}
