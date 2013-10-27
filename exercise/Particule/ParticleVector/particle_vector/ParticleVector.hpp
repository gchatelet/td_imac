#pragma once

#include "particle/Particle.hpp"

#include <stddef.h>

class ParticleVector {
public:
    ParticleVector(size_t size);
    ParticleVector(const ParticleVector& other);
    ~ParticleVector();

    Particle& operator[](size_t at);
    const Particle& operator[](size_t at) const;

    Particle& at(size_t at);
    const Particle& at(size_t at) const;

    size_t size() const;
private:
    void checkAccess(size_t at) const;

    const unsigned m_Size;
    Particle* const m_pParticles;
};
