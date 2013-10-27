#include "Point2D.hpp"

Point2D::Point2D() :
                x(0), y(0) {
}

Point2D::Point2D(float x, float y) :
                x(x), y(y) {
}

Point2D::Point2D(const Point2D& other) :
                x(other.x), y(other.y) {
}
Point2D& Point2D::operator=(const Point2D& other) {
    x = other.x;
    y = other.y;
    return *this;
}
Point2D& Point2D::operator*=(const float alpha) {
    x *= alpha;
    y *= alpha;
    return *this;
}
Point2D& Point2D::operator+=(const Point2D& other) {
    x += other.x;
    y += other.y;
    return *this;
}
Point2D Point2D::operator+(const Point2D& other) const {
    return Point2D(x + other.x, y + other.y);
}
Point2D Point2D::operator-(const Point2D& other) const {
    return Point2D(x - other.x, y - other.y);
}
Point2D Point2D::operator*(const float alpha) const {
    return Point2D(x * alpha, y * alpha);
}
Point2D Point2D::operator-() const {
    return Point2D(-x, -y);
}
bool Point2D::operator==(const Point2D& other) const {
    return x == other.x && y == other.y;
}
bool Point2D::operator!=(const Point2D& other) const {
    return !(*this == other);
}
