#pragma once

#include "point2d/Point2D.hpp"

class Force {
public:
    virtual ~Force() {
    }

    // Computes the force at position and time
    virtual Point2D get(const Point2D& position, float time) const = 0;
};
