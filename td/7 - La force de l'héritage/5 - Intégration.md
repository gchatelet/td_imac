---
goal:Mise en pratique
---
Modifier la fonction `UpdateVerlet` de votre particule pour qu'elle prenne une `Force` au lieu d'un `Point2D`.
Passez-lui maintenant la composition d'une gravité et d'une explosion. Lancez la simulation.

**Questions**
 - Votre classe `Particle` dépend désormais de `Force`, c'est une mauvaise chose car vous ne pouvez plus utiliser `Particle` sans implémenter une `Force`, que pouvez-vous faire pour contrer ce problème ?