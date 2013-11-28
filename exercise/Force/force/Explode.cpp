#include "Explode.hpp"

#include <cmath>

Explode::Explode(float every) :
                m_Every(every) {
}

Point2D Explode::get(const Point2D& position,
                     float time) const {
    const bool explosion = fmod(time, m_Every) <= 0.1;
    if(!explosion)
        return Point2D();
    const Point2D diff = position - Point2D(0.0, -0.5);
    const float norm =
          sqrt(diff.x * diff.x + diff.y * diff.y);
    if (norm == 0)
        return Point2D();
    return diff * (60 / norm);
}
