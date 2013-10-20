---
goal:Comprendre le mécanisme de construction.
notions:Constructeur par défaut, contructeur avec valeurs.
---
**Point technique**
- La notion de construction s'étend à tous les types, ici un entier

        int a(1); // construit 'a' avec la valeur 1
        …
        int a = 1;// construit 'a' avec la valeur 1
        …
        int a; // construit 'a' par défaut
        a = 1; // affecte 1 à 'a'

- Certains qualificateurs empêche la construction par défaut

        const int a;     // invalide : 'a' doit avoir une valeur
        const int a(1);  // valide
        const int a = 1; // valide également
        
        int &a;          // invalide : 'a' doit être initialisée
        int value;
        int &a = value;  // valide
        int &a(value);   // valide

**A faire**

  Si ce n’est pas encore fait, dotez votre `Point2D` d’un constructeur par défaut et d'un constructeur associant des valeurs aux coordonnées.
  
  Dans ces constructeurs, vous construirez également les variables membres `x` et `y` directement avec leur valeurs sans passer par une affectation.

**Questions**
  1. Dans quel cas est créé le constructeur par défaut?
  2. Rappelez la signification du mot clé `this`.