#include "Integrator.hpp"

Particle integrateE(const Force& force, const Particle& initial, const float time, const float dt) {
    Particle output;
    output.vel = initial.vel + force.get(initial.pos, time) * dt;
    output.pos = initial.pos + output.vel * dt;
    return output;
}

Particle integrateV(const Force& force, const Particle& initial, const float time, const float dt) {
    Particle output;
    output.vel = initial.vel + force.get(initial.pos, time) * dt;
    output.pos = initial.pos + (initial.vel + output.vel) * 0.5 * dt;
    return output;
}

struct Derivative {
    Point2D dx, dv;
};

Derivative evaluate(const Force& force, const Particle& initial, const float time) {
    Derivative output;
    output.dx = initial.vel;
    output.dv = force.get(initial.pos, time);
    return output;
}

Derivative evaluate(const Force& force, const Particle& initial, const float time, float dt, const Derivative &d) {
    Particle state(initial.pos + d.dx * dt, initial.vel + d.dv * dt);
    Derivative output;
    output.dx = initial.vel;
    output.dv = force.get(initial.pos, time + dt);
    return output;
}

Particle integrateRK4(const Force& force, const Particle& initial, const float time, const float dt) {
    const Derivative a = evaluate(force, initial, time);
    const Derivative b = evaluate(force, initial, time, dt * 0.5f, a);
    const Derivative c = evaluate(force, initial, time, dt * 0.5f, b);
    const Derivative d = evaluate(force, initial, time, dt, c);

    const Point2D dxdt = (a.dx + (b.dx + c.dx) * 2.0 + d.dx) * (1.0f / 6.0f);
    const Point2D dvdt = (a.dv + (b.dv + c.dv) * 2.0 + d.dv) * (1.0f / 6.0f);

    return Particle(initial.pos + dxdt * dt, initial.vel + dvdt * dt);
}
