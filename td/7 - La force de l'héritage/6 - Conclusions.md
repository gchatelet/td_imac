---
goal:Comprendre l'intérêt et les limitations de l'héritage.
notions:open/close principle, abstraction, bénéfices/inconvénients de l'héritage.
---
L'héritage permet d'étendre à l'infini un point de design (principe [ouvert/fermé](http://fr.wikipedia.org/wiki/Principe_ouvert/ferm%C3%A9)).
On pourrait par exemple déclencher l'explosion sur des évènements extérieurs ou rajouter du vent.
La force appliquée aux particules a été **abstraite**, la simulation est indépendante du code qui contrôle la force.


L'interface `Force` est désormais le point de rencontre du code calculant la force et de la simulation : **tout changement de cette interface impacte les deux parties du code** ( c'est à dire toutes les classes dérivées de `Force` et tout le code qui utilise `Force`).
Il est donc primordial de faire très attention à la confection de ces interfaces, elles doivent être minimalistes et changer le moins souvent possible.