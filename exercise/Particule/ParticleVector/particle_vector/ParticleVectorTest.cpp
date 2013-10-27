#include "particle/Particle.hpp"
#include "ParticleVector.hpp"

#include <gtest/gtest.h>

//#include <vector>
//typedef std::vector<Particle> ParticleVector;

TEST(ParticleVector, EmptyConstruction) {
    ParticleVector particles(0);
    EXPECT_EQ(particles.size(), 0);
}

TEST(ParticleVector, Assignment) {
    ParticleVector particles(1);
    EXPECT_EQ(particles.size(), 1);
    EXPECT_EQ(particles[0], Particle());
    Particle other(Point2D(1, 2), Point2D(3, 4));
    particles[0] = other;
    EXPECT_EQ(particles[0], other);
}

TEST(ParticleVector, Constness) {
    const ParticleVector particles(1);
    EXPECT_EQ(particles.size(), 1);
    Particle other(particles[0]);
    EXPECT_EQ(other, Particle());
}

TEST(ParticleVector, OutOfBoundWithAt) {
    const ParticleVector const_particles(1);
    const_particles.at(0); // in bound : ok
    EXPECT_THROW(const_particles.at(1), std::range_error);
    const_particles[1]; // accessing invalid element
    ParticleVector particles(1);
    particles.at(0); // in bound : ok
    EXPECT_THROW(particles.at(1), std::range_error);
    particles[1]; // accessing invalid element
}

TEST(ParticleVector, Copie) {
    const Particle zero;
    const Particle random(Point2D(1, 2), Point2D(3, 4));

    ParticleVector particles(1);
    EXPECT_EQ(particles[0], zero);
    particles[0] = random;

    const ParticleVector copy(particles);

    ASSERT_EQ(particles.size(), copy.size());
    ASSERT_EQ(particles[0], copy[0]);
    particles[0] = zero;
    ASSERT_EQ(particles[0], zero);
    ASSERT_EQ(copy[0], random);
}
