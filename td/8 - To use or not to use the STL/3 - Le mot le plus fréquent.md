---
goal:Utilisation d'un conteneur associatif
notions:iterator, std::map
---
Nous voulons désormais connaître quel est le mot le plus utilisé dans Hamlet.
Pour cela, nous allons utiliser une table d'association (`std::map<std::string, size_t>`) qui fera correspondre pour chaque mot, le nombre de fois qu'il apparaît dans Hamlet.

Remplissez cette table en iterant sur le vecteur précédent grâce aux fonctions membres `begin()` et `end()` de `std::vector`.

Au fur et à mesure que vous remplissez cette table, gardez une trace du mot dont la fréquence est la plus élevée. Finalement, affichez ce mot et la fréquence associée.