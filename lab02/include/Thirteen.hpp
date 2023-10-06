#pragma once
#include <algorithm>
#include <cstring>
#include <iostream>

class Thirteen {
   private:
    size_t size;
    unsigned char *data;

   public:
    Thirteen();  // Default constructor
    size_t getSize() const;
    unsigned char *getData() const;

    Thirteen(const size_t &n, unsigned char t = 0);           // Fill constructor
    Thirteen(const std::initializer_list<unsigned char> &t);  // Initializer list constructor
    Thirteen(const std::string t);                            // Copy string cistructor
    Thirteen(const Thirteen &other);                          // Copy constructor
    Thirteen(Thirteen &&other) noexcept;                      // Move constructor

    std::ostream &print(std::ostream &os);

    Thirteen operator=(const Thirteen &other);
    Thirteen operator+(const Thirteen &other) const;
    Thirteen operator-(const Thirteen &other) const;
    bool operator==(const Thirteen &otherr) const;
    bool operator!=(const Thirteen &otherr) const;
    bool operator<(const Thirteen &otherr) const;
    bool operator<=(const Thirteen &otherr) const;
    bool operator>(const Thirteen &otherr) const;
    bool operator>=(const Thirteen &otherr) const;

    ~Thirteen() noexcept;  // Destructor
};

bool isThirteenDigit(const char &c);