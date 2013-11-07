---
goal:Utilisation des exceptions.
notions:exceptions
---
Rajoutez une fonction `at` qui contrôle l'accès aux éléments et envoie une exception de type `std::range_error` si l'utilisateur cherche à accèder à des éléments en dehors des bornes.

Ajoutez le test unitaire suivant pour contrôler la fonctionnalité.

	TEST(ParticleVector, OutOfBoundWithAt) {
		const ParticleVector const_particles(1);
		const_particles.at(0); // in bound : ok
		EXPECT_THROW(const_particles.at(1), std::exception);
		const_particles[1]; // accessing invalid element
		ParticleVector particles(1);
		particles.at(0); // in bound : ok
		EXPECT_THROW(particles.at(1), std::exception);
		particles[1]; // accessing invalid element
	}
