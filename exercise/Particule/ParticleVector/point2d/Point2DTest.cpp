#include <gtest/gtest.h>

#include "Point2D.hpp"

TEST(Point, DefaultConstruction) {
    const Point2D a;
    EXPECT_EQ(a.x, 0);
    EXPECT_EQ(a.y, 0);
}

TEST(Point, ArgsConstruction) {
    const Point2D a(1, 2);
    EXPECT_EQ(a.x, 1);
    EXPECT_EQ(a.y, 2);
}

TEST(Point, CopyConstruction) {
    const Point2D a(1, 2);
    const Point2D b(a);
    EXPECT_EQ(b.x, a.x);
    EXPECT_EQ(b.y, a.y);
}

TEST(Point, Equality) {
    const Point2D a(1, 2), b(1, 2), c(1, 1);
    EXPECT_EQ(a, a);
    EXPECT_EQ(a, b);
    EXPECT_FALSE(a == c); // tests !(a==c)
    EXPECT_NE(a, c); // tests (a!=c)
    EXPECT_NE(b, c);
}

TEST(Point, Assignment) {
    const Point2D a(1, 2);
    Point2D b;
    EXPECT_NE(b, a);
    b = a;
    EXPECT_EQ(b, a);
}

TEST(Point, Addition) {
    const Point2D a(1, 2);
    const Point2D b = a + a;
    EXPECT_EQ(b, Point2D(2, 4));
}

TEST(Point, Substraction) {
    const Point2D a(1, 2);
    const Point2D b = a - a;
    EXPECT_EQ(b, Point2D());
}

TEST(Point, Inversion) {
    EXPECT_EQ(Point2D(), -Point2D());
    EXPECT_EQ(Point2D(1, 1), -Point2D(-1, -1));
}

TEST(Point, ScalarMult) {
    const Point2D a(1, 2);
    const Point2D b = a * 2;
    EXPECT_EQ(b, Point2D(2, 4));
}

TEST(Point, SelfAddition) {
    Point2D a(1, 2);
    a += a;
    EXPECT_EQ(a, Point2D(2, 4));
}

TEST(Point, SelfMultiplication) {
    Point2D a(1, 2);
    a *= 2;
    EXPECT_EQ(a, Point2D(2, 4));
}
