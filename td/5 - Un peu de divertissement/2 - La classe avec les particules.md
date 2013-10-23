---
goal:Créer une classe représentant une particule permettant de gérer son mouvement.
notions:struct, class, référence, construction, variables et fonctions membres.
---
Créez une classe `Particule` possèdant deux variables membres : une position `pos` et une vélocité `vel`.

**Questions**
- Cette classe possède-t-elle un état qu'il faut protéger ?
- Cette classe doit-elle être étendue par d'autre classes ? (polymorphisme)
- Finalement cette classe doit-elle être une `class` ou une `struct` ?

**À faire**
- Dotez cette classe de fonctions `UpdateEuler` et `UpdateVerlet` - adaptez les signatures pour utiliser la vélocité et la position de la particule.
- Ajoutez quelques tests, par exemple :
    - la position et la vitesse doivent rester constantes si `dt`=0.
    - faire `dt`=1 puis `dt`=-1 devrait revenir au même emplacement.