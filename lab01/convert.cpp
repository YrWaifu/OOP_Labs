#include <string>

std::string convert(int hour, int minute, std::string& period) {
    if ((hour < 1 || hour > 12) || (minute < 0 || minute > 59) || (period != "am" && period != "pm")) {
        return "Invalid input";
    }

    if (period == "am" && hour == 12) {
        hour = 0;
    } else if (period == "pm" && hour != 12) {
        hour += 12;
    }

    std::string result =
        (hour < 10 ? "0" : "") + std::to_string(hour) + (minute < 10 ? "0" : "") + std::to_string(minute);

    return result;
}