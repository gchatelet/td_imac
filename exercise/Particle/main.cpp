#include "point2d/Point2D.hpp"
#include "particle/Particle.hpp"
#include "console/ConsoleScreen.hpp"

#include <cstdlib>
#include <unistd.h>

int main(int argc, char **argv) {
    const float dt = 0.02;
    const Point2D gravity(0, -9.81);
    const Point2D initialPos(0.5, 0.5);
    const Point2D initialVel(1, 3);
    Particle euler(initialPos, initialVel);
    Particle verlet(initialPos, initialVel);

    ConsoleScreen console(40, 20);
    for (;;) {
        console.setPixelRelative(euler.pos.x, euler.pos.y, 'E');
        console.setPixelRelative(verlet.pos.x, verlet.pos.y, 'V');
        console.show();
        console.clear();
        euler.UpdateEuler(gravity, dt);
        euler.KeepInBox();
        verlet.UpdateVerlet(gravity, dt);
        verlet.KeepInBox();
        usleep(20 * 1000);
    }
    return EXIT_SUCCESS;
}

