#include "../include/Thirteen.hpp"

bool isThirteenDigit(const char &c) {
    return (('0' <= c && c <= '9') || (c == 'A') || (c == 'B') || (c == 'C'));
}

int charToInt(const char &c) {
    if (c == 'A') {
        return 10;
    } else if (c == 'B') {
        return 11;
    } else if (c == 'C') {
        return 12;
    } else {
        return c - '0';
    }
}

char intToChar(int &n) {
    if (n == 10) {
        return 'A';
    } else if (n == 11) {
        return 'B';
    } else if (n == 12) {
        return 'C';
    } else {
        return n + '0';
    }
}

Thirteen::Thirteen() : size(0), data{nullptr} {}

Thirteen::Thirteen(const size_t &n, unsigned char t) {
    data = new unsigned char[n];
    for (size_t i = 0; i < n; ++i) {
        data[i] = t;
    }
    size = n;
}

Thirteen::Thirteen(const std::initializer_list<unsigned char> &t) {
    data = new unsigned char[t.size()];
    size = t.size();
    size_t i = size;
    for (unsigned char c : t) {
        if (!isThirteenDigit(c)) {
            throw std::logic_error("Wrong value og Thirteen number");
        }
        data[--i] = c;
    }
}

Thirteen::Thirteen(const std::string t) {
    size = t.size();
    data = new unsigned char[size];
    for (size_t i = size - 1, j = 0; j < size; --i, ++j) {
        if (!isThirteenDigit) {
            throw std::logic_error("Wrong value og Thirteen number");
        }
        data[i] = t[j];
    }
}

Thirteen::Thirteen(const Thirteen &other) {
    size = other.size;
    data = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Thirteen::Thirteen(Thirteen &&other) noexcept {
    size = other.size;
    data = other.data;
    other.size = 0;
    other.data = nullptr;
}

Thirteen Thirteen::operator=(const Thirteen &other) {
    if (&other != this) {
        delete[] data;
        size = other.size;
        data = new unsigned char[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

Thirteen Thirteen::operator+(const Thirteen &other) {
    size_t resultSize = std::max(size, other.size) + 1;
    std::string result(resultSize, '0');
    int carry = 0;

    for (size_t i = 0; i < resultSize; ++i) {
        int d1 = 0, d2 = 0;

        if (i < size) {
            d1 = charToInt(data[i]);
        }
        if (i < other.size) {
            d2 = charToInt(other.data[i]);
        }

        int sum = d1 + d2 + carry;

        if (sum >= 13) {
            carry = 1;
            sum -= 13;
        } else {
            carry = 0;
        }
        result[i] = intToChar(sum);
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());

    return Thirteen(result);
}

Thirteen Thirteen::operator-(const Thirteen &other) {
    if (*this < other) {
        throw std::logic_error("Difference can't be negative");
    }

    size_t resultSize = std::max(size, other.size);
    std::string result(resultSize, '0');
    int borrow = 0;

    for (size_t i = 0; i < resultSize; ++i) {
        int d1 = 0, d2 = 0;

        if (i < size) {
            d1 = charToInt(data[i]);
        }
        if (i < other.size) {
            d2 = charToInt(other.data[i]);
        }

        int diff = d1 - d2 - borrow;

        if (diff < 0) {
            borrow = 1;
            diff += 13;
        } else {
            borrow = 0;
        }
        result[i] = intToChar(diff);
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());

    return Thirteen(result);
}

bool Thirteen::operator==(const Thirteen &other) {
    if (&other == this) {
        return true;
    }
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool Thirteen::operator!=(const Thirteen &other) {
    if (*this == other) {
        return false;
    }
    return true;
}

bool Thirteen::operator<(const Thirteen &other) {
    if (&other == this) {
        return false;
    }

    if (size < other.size) {
        return true;
    } else if (size > other.size) {
        return false;
    } else {
        for (size_t i = size; i--;) {
            if (data[i] < other.data[i]) {
                return true;
            } else if (data[i] > other.data[i]) {
                return false;
            } else {
                continue;
            }
        }
        return false;
    }
}

bool Thirteen::operator<=(const Thirteen &other) {
    if (*this > other) {
        return false;
    }
    return true;
}

bool Thirteen::operator>(const Thirteen &other) {
    if (*this < other || *this == other) {
        return false;
    }
    return true;
}

bool Thirteen::operator>=(const Thirteen &other) {
    if (*this < other) {
        return false;
    }
    return true;
}

Thirteen::~Thirteen() noexcept {
    if (size > 0) {
        size = 0;
        delete[] data;
        data = nullptr;
    }
}

std::ostream &operator<<(std::ostream &os, const Thirteen &num) {
    for (size_t i = num.size; i > 0; --i) {
        os << num.data[i - 1];  // Выводим цифры в обратном порядке
    }
    return os;
}