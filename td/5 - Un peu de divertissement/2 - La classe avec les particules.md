---
goal:Créer une classe représentant une particule et permettant de gérer son mouvement.
notions:struct, class, référence, construction, variables et fonctions membres.
---
Cette classe doit avoir deux variables membres : une position `pos` et une vélocité `vel`.

**Questions**
- Cette classe possède-t-elle un état qu'il faut protéger ?
- Cette classe doit-elle être étendu par d'autre classes ? (polymorphisme)
- Finalement cette classe doit-elle être une `class` ou une `struct` ?

**A faire**
- Dotez cette classe de fonctions `UpdateEuler` et `UpdateVerlet` - adaptez les signatures pour utiliser la vélocité et la position de la particule.
- Ajoutez quelques tests, par exemple :
    - la position et la vitesse doivent rester constantes si dt=0.
    - faire dt=1 puis dt=-1 devrait revenir au même emplacement.
- Ajoutez une fonction `void KeepInBox()` qui empêche la particule de sortir de l'espace [0,1]².
    - pour ce faire vous inverserez la composante de la vitesse qui ferait sortir la particule.
- Ajoutez quelques tests pour vérifiez le comportement.