#include <gtest/gtest.h>

#include "Particle.hpp"

TEST(Particle, DefaultConstruction) {
    const Particle p;
    EXPECT_EQ(p.pos, Point2D(0, 0));
    EXPECT_EQ(p.vel, Point2D(0, 0));
}

Particle integrateEuler(const Point2D& force, const float dt, const Point2D& initialVelocity = Point2D()) {
    Particle p(Point2D(), initialVelocity);
    p.UpdateEuler(force, dt);
    return p;
}

Particle integrateVerlet(const Point2D& force, const float dt, const Point2D& initialVelocity = Point2D()) {
    Particle p(Point2D(), initialVelocity);
    p.UpdateVerlet(force, dt);
    return p;
}

TEST(Particle, MovementCheck) {
    const Point2D force(1, 1);
    const Point2D no_force(0, 0);
    const float dt(1);
    const float no_dt(0);
    // if no time, no movement
    EXPECT_EQ(integrateEuler(force, no_dt), Particle());
    EXPECT_EQ(integrateVerlet(force, no_dt), Particle());
    // if no force and no initial velocity, no movement
    EXPECT_EQ(integrateEuler(no_force, dt), Particle());
    EXPECT_EQ(integrateVerlet(no_force, dt), Particle());
    // if no force but initial velocity : movement
    const Point2D dx(1, 0);
    EXPECT_EQ(integrateEuler(no_force, dt, dx).pos, dx);
    EXPECT_EQ(integrateVerlet(no_force, dt, dx).pos, dx);
}

TEST(Particle, BackAndForthInTimeEuler) {
    const Point2D force(1, 1);
    const float dt(1);
    Particle p;
    p.UpdateEuler(force, dt);
    p.UpdateEuler(force, -dt);
    // we would expect the following to work but it is
    // not the case because Euler method is too coarse.
    // EXPECT_EQ(p, Particle());
}

TEST(Particle, BackAndForthInTimeVerlet) {
    const Point2D force(1, 1);
    const float dt(1);
    Particle p;
    p.UpdateVerlet(force, dt);
    p.UpdateVerlet(force, -dt);
    EXPECT_EQ(p, Particle());
}
