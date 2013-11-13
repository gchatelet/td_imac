---
goal:Utilisation d'un conteneur associatif
notions:iterator, std::map
---
Nous voulons désormais connaître quel est le mot le plus utilisé dans Hamlet.
Pour cela, nous allons utiliser une table d'association (`std::map<std::string, size_t>`) qui fera correspondre pour chaque mot, le nombre de fois qu'il apparait dans Hamlet.

Remplissez cette table en iterant sur le vecteur précédent grâce aux fonctions membres `begin()` et `end()` de `std::vector`.

Au fur et à mesure que vous remplissez cette table, gardez une trace du mot dont la fréquence est la plus élevée. Finalement, affichez ce mot et la fréquence associée.

**Questions**
 - Si la table d'association contient 10 mots, combien faut-il de comparaisons pour trouver un mot en particulier ?
 - Combien faut-il de comparaisons si la table contient un million de mots ? 1 milliard ?
 - Quelle est la complexité d'une recherche dans une table d'association en général ?
 - Pour garantir cette complexité, quelle propriété doit avoir le type de la clef ( `std::string` dans notre cas )
 - Une comparaison de chaînes de caractères peut être couteuse, cette comparaison est fonction de `min(length(a), length(b))`
     - pourrait-on s'arranger pour que la comparaison soit en temps constant ?
     - quelle serait alors la conséquence pour la propriété évoquée plus haut ?