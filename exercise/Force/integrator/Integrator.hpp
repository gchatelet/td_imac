#pragma once

#include "particle/Particle.hpp"
#include "force/Force.hpp"

Particle integrateE(const Force& force, const Particle& initial, const float time, const float dt);
Particle integrateV(const Force& force, const Particle& initial, const float time, const float dt);
Particle integrateRK4(const Force& force, const Particle& initial, const float time, const float dt) ;
