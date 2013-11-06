#pragma once

#include "Force.hpp"

class Gravity : public Force {
public:
    virtual Point2D get(const Point2D& position, float time) const;
};
