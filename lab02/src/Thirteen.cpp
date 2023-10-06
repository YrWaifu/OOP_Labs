#include "../include/Thirteen.hpp"

bool isThirteenDigit(const char &c) {
    return (('0' <= c && c <= '9') || (c == 'A') || (c == 'B') || (c == 'C'));
}

Thirteen::Thirteen() : size(0), data{nullptr} {}

size_t Thirteen::getSize() const { return size; }

unsigned char *Thirteen::getData() const { return data; }

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
    size_t i{size};
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

Thirteen Thirteen::operator+(const Thirteen &other) const {
    size_t resultSize = std::max(other.size, size) + 1;
    std::string result(resultSize, '0');
    int temp = 0;
    for (size_t i = 0; i < resultSize; ++i) {
        int d1 = (i < size)
                     ? (data[i] != 'A' ? (data[i] != 'B' ? (data[i] != 'C' ? (data[i] - '0') : 12) : 11) : 10)
                     : 0;
        int d2 =
            (i < other.size)
                ? (other.data[i] != 'A'
                       ? (other.data[i] != 'B' ? (other.data[i] != 'C' ? (other.data[i] - '0') : 12) : 11)
                       : 10)
                : 0;
        int sum = d1 + d2 + temp;
        result[i] = ((sum % 13) != 12)
                        ? (((sum % 13) != 11) ? (((sum % 13) != 10) ? (sum % 13) + '0' : 'A') : 'B')
                        : 'C';
        temp = sum / 13;
    }
    if (temp > 0) {
        result[resultSize - 1] =
            (temp != 12) ? ((temp != 11) ? ((temp != 10) ? temp + '0' : 'A') : 'B') : 'C';
    }
    if (result[resultSize - 1] == '0') {
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return Thirteen(result);
}

Thirteen Thirteen::operator-(const Thirteen &other) const {
    if (*this < other) {
        throw std::logic_error("Difference can't be negative");
    }
    size_t resultSize = std::max(other.size, size) + 1;
    std::string result(resultSize, '0');
    int temp = 0;
    for (size_t i = 0; i < resultSize; ++i) {
        int d1 = (i < size)
                     ? (data[i] != 'A' ? (data[i] != 'B' ? (data[i] != 'C' ? (data[i] - '0') : 12) : 11) : 10)
                     : 0;
        int d2 =
            (i < other.size)
                ? (other.data[i] != 'A'
                       ? (other.data[i] != 'B' ? (other.data[i] != 'C' ? (other.data[i] - '0') : 12) : 11)
                       : 10)
                : 0;

        int diff = d1 - d2 - temp;
        if (diff < 0) {
            diff += 13;
            temp = 1;
        } else {
            temp = 0;
        }
        result[i] = (diff != 12) ? ((diff != 11) ? ((diff != 10) ? diff + '0' : 'A') : 'B') : 'C';
    }
    if (result[resultSize - 1] == '0') {
        result.erase(resultSize - 1, 1);
    }
    std::reverse(result.begin(), result.end());
    return Thirteen(result);
}

bool Thirteen::operator==(const Thirteen &other) const {
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

bool Thirteen::operator!=(const Thirteen &other) const {
    if (*this == other) {
        return false;
    }
    return true;
}

bool Thirteen::operator<(const Thirteen &other) const {
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

bool Thirteen::operator<=(const Thirteen &other) const {
    if (*this > other) {
        return false;
    }
    return true;
}

bool Thirteen::operator>(const Thirteen &other) const {
    if (*this < other || *this == other) {
        return false;
    }
    return true;
}

bool Thirteen::operator>=(const Thirteen &other) const {
    if (*this < other) {
        return false;
    }
    return true;
}

std::ostream &Thirteen::print(std::ostream &os) {
    for (size_t i = size; --i;) {
        os << data[i];
    }
    return os;
}

Thirteen::~Thirteen() noexcept {
    if (size > 0) {
        size = 0;
        delete[] data;
        data = nullptr;
    }
}