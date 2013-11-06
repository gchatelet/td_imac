#pragma once
#include "Force.hpp"

#include <vector>

class Composite : public Force {
    std::vector<const Force*> m_Forces;
public:
    Composite(const std::vector<const Force*>& forces);
    virtual Point2D get(const Point2D& position, float time) const;
};
