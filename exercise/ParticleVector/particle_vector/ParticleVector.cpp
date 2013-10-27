#include "ParticleVector.hpp"

#include <stdexcept>

ParticleVector::ParticleVector(size_t size) :
                m_Size(size), m_pParticles(new Particle[m_Size]) {
}

ParticleVector::ParticleVector(const ParticleVector& other) :
                m_Size(other.m_Size), m_pParticles(new Particle[m_Size]) {
    for (size_t i = 0; i < m_Size; ++i)
        m_pParticles[i] = other.m_pParticles[i];
}

ParticleVector::~ParticleVector() {
    delete[] m_pParticles;
}

Particle& ParticleVector::operator[](size_t at) {
    return m_pParticles[at];
}

const Particle& ParticleVector::operator[](size_t at) const {
    return m_pParticles[at];
}

Particle& ParticleVector::at(size_t at) {
    checkAccess(at);
    return (*this)[at];
}

const Particle& ParticleVector::at(size_t at) const {
    checkAccess(at);
    return (*this)[at];
}

void ParticleVector::checkAccess(size_t at) const {
    if (at >= m_Size) throw std::range_error("out of bound exception");
}

size_t ParticleVector::size() const {
    return m_Size;
}
