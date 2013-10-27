#pragma once

#include "point2d/Point2D.hpp"

struct Particle {
    Point2D pos, vel;

    Particle() ;
    Particle(const Point2D& pos, const Point2D& vel);

    void UpdateEuler(const Point2D& force, const float dt);
    void UpdateVerlet(const Point2D& force, const float dt);
    void KeepInBox();

    bool operator==(const Particle& other) const;
};
