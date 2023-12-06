#include <gtest/gtest.h>

#include "include/Vector.hpp"

using namespace std;

TEST(test_01, copy_and_compare_overloaded_operators_tri_test) {
    Point pt1(0, 0);
    Point pt2(1, 1);
    Point pt3(0, 1);

    Triangle tr1(pt1, pt2, pt3);

    Triangle tr2;
    tr2 = tr1;

    ASSERT_TRUE(tr1 == tr2);
}

TEST(test_02, copy_and_compare_overloaded_operators_sq_test) {
    Point pt1(0, 0);
    Point pt2(1, 1);
    Point pt3(0, 1);
    Point pt4(1, 0);

    Square fig1(pt1, pt2, pt3, pt4);

    Square fig2;
    fig2 = fig1;

    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_03, copy_and_compare_overloaded_operators_rect_test) {
    Point pt1(0, 0);
    Point pt2(4, 6);
    Point pt3(0, 6);
    Point pt4(4, 0);

    Rectangle fig1(pt1, pt2, pt3, pt4);

    Rectangle fig2;
    fig2 = fig1;

    ASSERT_TRUE(fig1 == fig2);
}

TEST(test_04, compare_square_and_rectangle) {
    Point pt1_rect(0, 0), pt2_rect(0, 4), pt3_rect(4, 4), pt4_rect(4, 0);

    Point pt1_sq(0, 0), pt2_sq(4, 0), pt3_sq(4, 4), pt4_sq(0, 4);

    Square sq(pt1_sq, pt2_sq, pt3_sq, pt4_sq);
    Rectangle rect(pt1_rect, pt2_rect, pt3_rect, pt4_rect);

    Point pt1 = sq.geomCentre();
    Point pt2 = rect.geomCentre();

    double area1 = sq;
    double area2 = rect;

    ASSERT_TRUE(pt1 == pt2 && area1 == area2);
}

TEST(test_05, error_constructing_recrangle) {
    Point pt1(0, 0);
    Point pt2(4, 0);
    Point pt3(77, 6);
    Point pt4(8, 4);

    ASSERT_THROW(Rectangle rq(pt1, pt2, pt3, pt4), std::logic_error);
}

TEST(test_06, error_constructing_triangle) {
    Point pt1(0, 0);
    Point pt2(4, 0);
    Point pt3(77, 6);

    ASSERT_THROW(Triangle tr(pt1, pt2, pt3), std::logic_error);
}

TEST(test_07, ex_ch_rot_fig_test) {
    bool correct = true;

    // not a rotatable triangle
    Point pt1(0, 0);
    Point pt2(1, 2);
    Point pt3(0, 2);

    try {
        Triangle fig(pt1, pt2, pt3);
    } catch (exception &ex) {
        correct = false;
    }

    ASSERT_TRUE(!correct);
}

TEST(test_08, def_constr_gcen_test) {
    Square sq;

    ASSERT_THROW(sq.geomCentre(), std::logic_error);
}

TEST(test_09, error_constructing_square) {
    Point pt1(0, 0);
    Point pt2(4, 0);
    Point pt3(4, 6);
    Point pt4(0, 6);

    ASSERT_THROW(Square sq(pt1, pt2, pt3, pt4), std::logic_error);
}

TEST(test_10, gcen_test) {
    Point pt1_rect(0, 0), pt2_rect(4, 6), pt3_rect(0, 6), pt4_rect(4, 0);

    Point pt1_sq(0, 0), pt2_sq(4, 0), pt3_sq(4, 4), pt4_sq(0, 4);

    Square sq(pt1_sq, pt2_sq, pt3_sq, pt4_sq);
    Rectangle rect(pt1_rect, pt2_rect, pt3_rect, pt4_rect);

    Point pt1 = sq.geomCentre();
    Point pt2 = rect.geomCentre();

    Point res1 = Point(2, 2), res2 = Point(2, 3);

    ASSERT_TRUE(pt1 == res1 and pt2 == res2);
}

TEST(test_11, area_test) {
    bool checked = false;

    Point pt1_rect(0, 0), pt2_rect(0, 6), pt3_rect(4, 6), pt4_rect(4, 0);

    Point pt1_sq(0, 0), pt2_sq(4, 0), pt3_sq(4, 4), pt4_sq(0, 4);

    Square sq(pt1_sq, pt2_sq, pt3_sq, pt4_sq);
    Rectangle rect(pt1_rect, pt2_rect, pt3_rect, pt4_rect);

    double area1 = sq;
    double area2 = rect;

    ASSERT_TRUE((int)area1 == 16 and (int) area2 == 24);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}