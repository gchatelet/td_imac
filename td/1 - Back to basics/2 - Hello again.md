---
goal:Retrouver comment compiler un programme multi-fichiers et y déclarer des fonctions.
notions:déclarations de fonctions, Makefile
---
Vous devez créer deux fichiers `functions.h` et `functions.c` contenant la fonction `printHelloWorld` retournant `void` et ne prenant aucun paramètre. Cette fonction doit afficher `"Hello, World!"`. La déclaration de la fonction a lieu dans le fichier entête et la fonction elle même se trouve dans le fichier C. Ces deux fichiers doivent être ajoutés au Makefile. La fonction `main` doit faire appel à la fonction nouvellement créée.