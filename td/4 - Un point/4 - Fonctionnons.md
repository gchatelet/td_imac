---
goal:Implémenter des fonctions au sein d’une classe.
notions:déclarations de fonctions membre
---
Votre `Point2D` n’est pour l’instant pas très utile.
Ajoutez des fonctions membres suivantes :
- norm() : calcule la distance à l'origine
- normalize() : normalise le point en ramenant sa `norm` à 1.
- addition avec un autre `Point2D`
- multiplication par un scalaire

Réflechissez bien aux paramètres et valeurs de retour de ces fonctions.

**Questions**
- Que veut dire le mot clef `const` si il est associé à une fonction membre.
- Quelles fonctions membres de votre classe doivent être `const` ?

**Plus de travail**

On veut pouvoir additionner des `Point2D` facilement. Implémenter les fonctions précédentes grâce à la surcharge d'opérateur lorsque c'est pertinent.
    Point2D a(1,2), b(3,4);
    Point2D c = a + b;