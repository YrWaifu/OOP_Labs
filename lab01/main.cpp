#include <iostream>
#include <string>

#include "convert.hpp"

int main() {
    int hour, minute;
    std::string period;

    std::cout << "Enter time in format 'hh:mm am/pm': ";
    char colon;
    std::cin >> hour >> colon >> minute >> period;

    if ((hour < 1 || hour > 12) || (minute < 0 || minute > 59) || (period != "am" && period != "pm") ||
        colon != ':') {
        std::cout << "Incorrect input!\n";
        return 1;
    }

    std::string result = convert(hour, minute, period);
    std::cout << "The result in 24-hour format: " << result << std::endl;
}