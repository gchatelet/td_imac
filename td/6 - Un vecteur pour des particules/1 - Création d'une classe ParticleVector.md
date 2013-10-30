---
goal:Aborder l'encapsulation des données.
notions: Révision de la surcharge d'opérateurs, du passage par référence et les tests unitaires.
---
Créer une classe `ParticleVector` qui permette de faire passer les tests unitaires suivants :

	TEST(ParticleVector, Construction) {
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
    
	TEST(ParticleVector, AccessingBadElement) {
		ParticleVector particles(1);
		ASSERT_THROW(particles[1], std::range_error);
	}

**Questions**
- Quelles seront les variables membres de la classe ? Ses méthodes ?
- Cette classe doit elle être une `class` ou une `struct` ?
    - Cette classe a-t-elle un état à protéger du client ? ( la classe peut elle être dans un état invalide ? )
    - Cette classe doit-elle être étendue ? ( utilisation du polymorphisme )
