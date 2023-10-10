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

    Thirteen(const size_t &n, unsigned char t = 0);           // Fill constructor
    Thirteen(const std::initializer_list<unsigned char> &t);  // Initializer list constructor
    Thirteen(const std::string t);                            // Copy string cistructor
    Thirteen(const Thirteen &other);                          // Copy constructor
    Thirteen(Thirteen &&other) noexcept;                      // Move constructor

    // std::ostream &print(std::ostream &os);
    friend std::ostream &operator<<(std::ostream &os, const Thirteen &num);

    Thirteen operator=(const Thirteen &other);
    Thirteen operator+(const Thirteen &other);
    Thirteen operator-(const Thirteen &other);
    bool operator==(const Thirteen &other);
    bool operator!=(const Thirteen &other);
    bool operator<(const Thirteen &other);
    bool operator<=(const Thirteen &other);
    bool operator>(const Thirteen &other);
    bool operator>=(const Thirteen &other);

    ~Thirteen() noexcept;  // Destructor
};

bool isThirteenDigit(const char &c);
int charToInt(const char &c);
char intToChar(int &n);