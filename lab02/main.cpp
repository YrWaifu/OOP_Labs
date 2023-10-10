#include <iostream>

#include "include/Thirteen.hpp"

int main() {
    std::string num1str, num2str;
    std::cin >> num1str >> num2str;
    Thirteen num1(num1str);
    Thirteen num2(num2str);
    std::cout << "Sum: " << num1 + num2 << std::endl;
    std::cout << "Diff: " << num1 - num2 << std::endl;
}
