#include "Composite.hpp"

Composite::Composite(const std::vector<const Force*>& forces) :
                m_Forces(forces) {
}

Point2D Composite::get(const Point2D& position, float time) const {
    Point2D result;
    for (int i = 0; i < m_Forces.size(); ++i) {
        result += m_Forces[i]->get(position, time);
    }
    return result;
}
