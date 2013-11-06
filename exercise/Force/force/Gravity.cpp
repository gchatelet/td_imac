#include "Gravity.hpp"

Point2D Gravity::get(const Point2D& position, float time) const {
    return Point2D(0, -9.81);
}
