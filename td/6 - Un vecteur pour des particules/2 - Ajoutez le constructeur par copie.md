---
goal:Gérer la construction par copie avec allocation dynamique.
notions:pointeurs
---
Ajouter un constructeur par copie qui permette de faire passer le test unitaire suivant. 

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