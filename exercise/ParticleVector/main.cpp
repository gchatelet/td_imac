#include "point2d/Point2D.hpp"
#include "particle/Particle.hpp"
#include "particle_vector/ParticleVector.hpp"
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
    return Particle(rand_point2d(), rand_point2d() - Point2D(.5,.5));
}

int main(int argc, char **argv) {
    const float dt = 0.02;
    const Point2D gravity(0, -9.81);
    const Point2D initialPos(0.5, 0.5);
    const Point2D initialVel(1, 3);
    ParticleVector particles(20);

    for (size_t i = 0; i < particles.size(); ++i) {
        particles[i] = rand_particle();
    }

    ConsoleScreen console(60, 30);
    for (;;) {
        for (size_t i = 0; i < particles.size(); ++i) {
            Particle& particle = particles[i];
            console.setPixelRelative(particle.pos.x, particle.pos.y, 'o');
            particle.UpdateVerlet(gravity, dt);
            particle.KeepInBox();
        }
        console.show();
        console.clear();
        usleep(20 * 1000);
    }
    return EXIT_SUCCESS;
}

