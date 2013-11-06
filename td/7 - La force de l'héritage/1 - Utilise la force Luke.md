---
goal:Déclaration d'un interface
---
On veut désormais que la force qui s'applique sur les particules soit gérée en dehors de notre code.
Pour cela définissez une classe `Force` qui contient la méthode

    virtual Point2D get(const Point2D& position, float time) const = 0;

`Force` agit comme une **interface**, vous pourrez vous en servir sans vous soucier de la manière dont elle est implémentée.

**Questions**
 - Expliquez les différentes mots clefs de la signature : `virtual`, `const`, `= 0`.
 - Le destructeur est un peu particulier, renseignez-vous et déclarez/implémentez le correctement.
 - Devez-vous utiliser une `class` une `struct` ? Aidez-vous des questions classiques pour décider :
    - Cette classe a-t-elle un état à protéger du client ? ( la classe peut elle être dans un état invalide ? )
    - Cette classe doit-elle être étendue ? ( utilisation du polymorphisme )
 - Quel est le code généré par le compilateur dans le cas ou la classe contient une méthode `virtual` ?