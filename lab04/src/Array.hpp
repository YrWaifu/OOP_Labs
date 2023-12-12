#pragma once
#include <concepts>
#include <memory>

#include "Rectangle.hpp"
#include "Square.hpp"
#include "Triangle.hpp"

template <typename T>

class Array {
   public:
    size_t size;
    shared_ptr<T[]> array;

    Array() : size(0), array(nullptr) {}
    Array(const initializer_list<T>& list) {
        shared_ptr<T[]> newArray = make_shared<T[]>(list.size);
        size_t i{0};

        for (auto elem : list) {
            newArray[i] = elem;
            ++i;
        }

        if (newArray != nullptr) {
            array = newArray;
            size = list.size();
        }
    }

    void push_back(T elem) {
        size_t newSize = size + 1;
        shared_ptr<T[]> newArray = make_shared<T[]>(newSize);

        for (size_t i{0}; i < size; ++i) {
            newArray[i] = array[i];
        }
        newArray[size] = elem;
        if (newArray != nullptr) {
            array = newArray;
            size = newSize;
        }
    }

    T pop_by_ind(size_t ind) {
        T fig;

        if (ind >= size) {
            throw logic_error("No elem so high (try lower index)");
        }

        if (ind < 0) {
            throw logic_error("Negative index");
        }

        const size_t newSize = size - 1;
        shared_ptr<T[]> newArray = make_shared<T[]>(newSize);

        for (size_t i{0}; i < ind; ++i) {
            newArray[i] = array[i];
        }

        fig = array[ind];
        for (size_t i{ind}; i < newSize; ++i) {
            newArray[i] = array[i + 1];
        }

        if (newArray != nullptr) {
            array = newArray;
            size = newSize;
        }

        return fig;
    }

    T get_by_ind(size_t ind) {
        T fig;

        if (ind >= size) {
            throw logic_error("No elem so high (try lower index)");
        }
        if (ind < 0) {
            throw logic_error("Negative index");
        } else {
            fig = array[ind];
        }

        return fig;
    }

    ~Array() = default;
};