---
goal:Itération sur un conteneur associatif
notions:iterator, std::map
---
Il s'agit maintenant d'afficher les 10 mots les plus utilisés dans Hamlet, pour ce faire nous allons inverser le tableau associatif précédent. Pour chaque paire mot/fréquence, nous allons insérer une paire fréquence/mot dans un autre tableau associatif.

Le tableau associatif sera donc de type `std::map<size_t, std::string>`.

Attention, n'oubliez pas que nous voulons maintenant afficher les 10 mots les plus fréquents, les clefs devront donc être triées par ordre décroissant. La STL nous permet de spécifier comment les clefs sont comparées, en passant un troisième paramètre `Compare` lors de la spécification du type.

Une fois ce tableau rempli, itérez les 10 premières valeurs et afficher les couples fréquence/mot.

**Question**
 - La fonction inverse que nous venons d'appliquer ici est-elle [bijective](http://fr.wikipedia.org/wiki/Bijection) ?
 - Quelle est la conséquence sur notre résultat ?

**Exercice supplémentaire**
 - Affichez également les 10 mots les moins fréquents sans recalculer le tableau associatif, regardez du coté des fonctions `rbegin()`, `rend()`