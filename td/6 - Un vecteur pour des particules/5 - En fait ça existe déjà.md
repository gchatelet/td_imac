---
goal:Découverte de la STL
notions:std::vector.
---
Dans votre fichier de test supprimez `#include "ParticleVector.hpp"` et insérez à la place les lignes suivantes :
	#include <vector>
	typedef std::vector<Particle> ParticleVector;

Les tests vont également passer, vous pouvez donc remplacer complètement votre `ParticleVector` par un `std::vector<Particle>`.

L'avantage de `std::vector` est qu'il s'adapte à tous les types ! Ainsi vous pouvez faire des vecteurs de `int`, de `double`, de `std::string`, de `std::vector`.

`std::vector` offre également beaucoup de fonctions très intéressante
	front(), back()
	push_front(), push_back()
	pop_front(), pop_back()
	insert(), erase()
	find()

Consultez la [documentation](http://www.cplusplus.com/reference/vector/vector/) de `std::vector` pour de plus amples informations.