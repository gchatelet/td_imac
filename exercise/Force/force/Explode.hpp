#pragma once

#include "Force.hpp"

class Explode : public Force {
    const float m_Every;
public:
    Explode(float every);
    virtual Point2D get(const Point2D& position, float time) const;
};
