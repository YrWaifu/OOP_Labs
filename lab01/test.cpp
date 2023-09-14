#include <gtest/gtest.h>

#include "convert.hpp"

TEST(ConvertTo24HourFormat, AMHourConversion) {
    int hour = 10;
    int minute = 30;
    std::string period = "am";
    std::string result = convert(hour, minute, period);
    ASSERT_TRUE(result == "1030");
}

TEST(ConvertTo24HourFormat, PMHourConversion) {
    int hour = 3;
    int minute = 45;
    std::string period = "pm";
    std::string result = convert(hour, minute, period);
    ASSERT_TRUE(result == "1545");
}

TEST(ConvertTo24HourFormat, MidnightConversion) {
    int hour = 12;
    int minute = 0;
    std::string period = "am";
    std::string result = convert(hour, minute, period);
    ASSERT_TRUE(result == "0000");
}

TEST(ConvertTo24HourFormat, NoonConversion) {
    int hour = 12;
    int minute = 30;
    std::string period = "pm";
    std::string result = convert(hour, minute, period);
    EXPECT_EQ(result, "1230");
}

TEST(ConvertTo24HourFormat, EdgeCase) {
    int hour = 1;
    int minute = 5;
    std::string period = "pm";
    std::string result = convert(hour, minute, period);
    ASSERT_TRUE(result == "1305");
}

TEST(ConvertTo24HourFormat, InvalidInput) {
    int hour = 13;  // Некорректный час
    int minute = 45;
    std::string period = "am";
    std::string result = convert(hour, minute, period);
    ASSERT_TRUE(result == "Invalid input");
}

TEST(ConvertTo24HourFormat, InvalidInput2) {
    int hour = 3;
    int minute = 60;  // Некорректная минута
    std::string period = "pm";
    std::string result = convert(hour, minute, period);
    ASSERT_TRUE(result == "Invalid input");
}

TEST(ConvertTo24HourFormat, InvalidInput3) {
    int hour = 12;
    int minute = 30;
    std::string period = "invalid";  // Некорректный период
    std::string result = convert(hour, minute, period);
    ASSERT_TRUE(result == "Invalid input");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
