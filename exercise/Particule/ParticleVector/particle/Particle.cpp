#include "Particle.hpp"

Particle::Particle() {
}

Particle::Particle(const Point2D& pos, const Point2D& vel) :
                pos(pos), vel(vel) {
}

void Particle::UpdateEuler(const Point2D& force, const float dt) {
    vel = vel + force * dt;
    pos = pos + vel * dt;
}

void Particle::UpdateVerlet(const Point2D& force, const float dt) {
    const Point2D oldVel = vel;
    vel = vel + force * dt;
    pos = pos + (oldVel + vel) * 0.5 * dt;
}

void Particle::KeepInBox() {
    if (pos.x < 0 || pos.x > 1) vel.x = -vel.x;
    if (pos.y < 0 || pos.y > 1) vel.y = -vel.y;
}

bool Particle::operator==(const Particle& other) const {
    return pos == other.pos && vel == other.vel;
}
