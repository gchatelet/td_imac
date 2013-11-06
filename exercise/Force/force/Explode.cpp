#include "Explode.hpp"

#include <cmath>

Explode::Explode(float every) :
                m_Every(every) {
}

Point2D Explode::get(const Point2D& position, float time) const {
    const bool explosion = fmod(time, m_Every) <= 0.1;
    const Point2D difference = position - Point2D(0.0, -0.5);
    const float norm = sqrt(difference.x * difference.x + difference.y * difference.y);
    if (norm == 0 || !explosion) return Point2D();
    return difference * (60 / norm);
}
