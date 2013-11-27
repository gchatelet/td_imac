---
goal:Utilisation d'un conteneur associatif simple
notions:iterator, std::set, size()
---
`std::set` est un conteneur qui définit un ensemble d'éléments uniques.
Insérez tous les éléments du vecteur précédent dans un `std::set<std::string>`, puis utilisez la méthode membre `size()` pour savoir précisément le nombre de mots uniques dans le texte.

**Questions**
 - Combien faut-il de comparaisons pour savoir si un mot en particulier se trouve dans un conteneur associatif ?
     - lorsque ce conteneur contient 10 mots ?
     - lorsque ce conteneur contient un million de mots ?
     - lorsque ce conteneur contient un milliard de mots ?
 - Quelle est la complexité d'une recherche dans un conteneur associatif en général ?
 - Pour garantir cette complexité, quelle propriété doit possèder le type de la clef ( `std::string` dans notre cas )
 - Une comparaison de chaînes de caractères peut être coûteuse, cette comparaison est fonction de `min(length(a), length(b))`
     - pourrait-on s'arranger pour que la comparaison soit en temps constant ?
     - quelle serait alors la conséquence pour la propriété évoquée plus haut ?
