#include "point2d/Point2D.hpp"
#include "particle/Particle.hpp"
#include "force/Gravity.hpp"
#include "force/Explode.hpp"
#include "force/Composite.hpp"
#include "integrator/Integrator.hpp"
#include "console/ConsoleScreen.hpp"

#include <cstdlib>
#include <unistd.h>

float randf() {
    return float(rand()) / RAND_MAX;
}
Point2D rand_point2d() {
    return Point2D(randf(), randf());
}
Particle rand_particle() {
    return Particle(rand_point2d(), (rand_point2d() - Point2D(0.5, 0.5)));
}

bool keepInRange(float& value, const float min = 0, const float max = 1) {
    bool touched = false;
    if (value < min) {
        value = min;
        touched = true;
    }
    if (value > max) {
        value = max;
        touched = true;
    }
    return touched;
}

void keepInBox(Particle& particle, const float min = 0, const float max = 1) {
    const float damping = 0.8;
    Point2D &pos = particle.pos;
    Point2D &vel = particle.vel;
    if (keepInRange(pos.x, min, max))vel.x *= -damping;
    if (keepInRange(pos.y, min, max))vel.y *= -damping;
}

int main(int argc, char **argv) {
    const Gravity gravity;
    const Explode explode(5);

    std::vector<const Force*> forces;
    forces.push_back(&gravity);
    forces.push_back(&explode);
    const Composite composite(forces);

    std::vector<Particle> particles(5);

    const double dt = 0.02;
    double time = 0;

    for (size_t i = 0; i < particles.size(); ++i) {
        particles[i] = rand_particle();
    }

    ConsoleScreen console(40, 20);
    for (;; time += dt) {
        for (size_t i = 0; i < particles.size(); ++i) {
            Particle& particle = particles[i];
            console.setPixelRelative(particle.pos.x, particle.pos.y, '0');
            keepInBox(particle);
            particle = integrateRK4(composite, particle, time, dt);
        }
        console.show();
        console.clear();
        usleep(20 * 1000);
    }
    return EXIT_SUCCESS;
}

