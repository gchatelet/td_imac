---
goal:Iteration sur un conteneur multi-associatif
notions:std::multimap
---
Notre inversion à l'exercice précédent ne fonctionne pas correctement. En effet si le texte était `"two words"`, nous aurions le tableaux suivants :
    two   1
    words 1

`std::map` comme `std::set` garantit l'unicité des clefs, l'inversion _perdrait_ une valeur et donnerait :
    1     words

Pour permettre l'utilisation de plusieurs clefs identiques vous utiliserez le conteneur `std::multimap` et afficherez les 10 mots les moins fréquents.