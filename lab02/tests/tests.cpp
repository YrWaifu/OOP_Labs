#include <gtest/gtest.h>

#include "../include/Thirteen.hpp"

TEST(TestConstructors, CopyConstructorTest) {
    Thirteen num1("A15");
    Thirteen num2(num1);
    ASSERT_TRUE(num1 == num2);
}

TEST(TestConstructors, AssignmentTest) {
    Thirteen num1({'1', 'A', '4', '7'});
    Thirteen num2 = num1;
    ASSERT_TRUE(num1 == num2);
}

TEST(TestConstructors, InitListConstructorTest) {
    Thirteen num1("12A4");
    Thirteen num2({'1', '2', 'A', '4'});
    ASSERT_TRUE(num1 == num2);
}

TEST(TestBoolOps, EqualTest) {
    Thirteen num1("AA34");
    Thirteen num2({'A', '3', '3', '4'});
    ASSERT_FALSE(num1 == num2);
}

TEST(TestBoolOps, UnequalTest1) {
    Thirteen num1("AA34");
    Thirteen num2({'2', '4', '6', '4'});
    ASSERT_TRUE(num1 != num2);
}

TEST(TestBoolOps, UnequalTest2) {
    Thirteen num1("7324");
    Thirteen num2({'7', '3', '2', '4'});
    ASSERT_FALSE(num1 != num2);
}

TEST(TestBoolOps, LessTest) {
    Thirteen num1("74");
    Thirteen num2({'1', 'A', '2'});
    ASSERT_TRUE(num1 < num2);
}

TEST(TestBoolOps, LessEqualTest) {
    Thirteen num1("12A54");
    Thirteen num2({'3', '5'});
    ASSERT_FALSE(num1 <= num2);
}

TEST(TestBoolOps, MoreTest) {
    Thirteen num1("543");
    Thirteen num2({'A'});
    ASSERT_TRUE(num1 > num2);
}

TEST(TestBoolOps, MoreEqualTest) {
    Thirteen num1("A73");
    Thirteen num2({'A', '7', '3'});
    ASSERT_TRUE(num1 >= num2);
}

TEST(TestArithmeticOps, AddittionTest) {
    Thirteen num1("5A");
    Thirteen num2({'1', '6'});
    ASSERT_TRUE((num1 + num2) == Thirteen("75"));
}

TEST(TestArithmeticOps, SubstractionTest1) {
    Thirteen num1("76");
    Thirteen num2({'7'});
    ASSERT_TRUE((num1 - num2) == Thirteen("6A"));
}

TEST(TestArithmeticOps, SubstractionTest2) {
    Thirteen num1("A31");
    Thirteen num2({'7'});
    ASSERT_TRUE((num1 - num2) == Thirteen("A25"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}