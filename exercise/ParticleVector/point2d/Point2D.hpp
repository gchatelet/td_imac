#pragma once

struct Point2D {
    float x, y;

    Point2D();
    Point2D(float x, float y);

    Point2D(const Point2D& other);
    Point2D& operator=(const Point2D& other);

    Point2D& operator*=(const float alpha);
    Point2D& operator+=(const Point2D& other);

    Point2D operator+(const Point2D& other) const;
    Point2D operator-(const Point2D& other) const;
    Point2D operator*(const float alpha) const;
    Point2D operator-() const;

    bool operator==(const Point2D& other) const;
    bool operator!=(const Point2D& other) const;
};

