---
goal:Récursion et méta programmation
---
Etudiez le code suivant, il permet de calculer le factoriel d'un nombre lors de la compilation :
    template<int N>
    struct Factorial {
      enum { value = N * Factorial<N - 1>::value };
    };
    
    template<>
    struct Factorial<0> {
      enum { value = 1 };
    };
    
    int foo() {
      const int x = Factorial<4>::value; // == 24
      const int y = Factorial<0>::value; // == 1
      return x;
    }

`x` et `y` ont pour valeur 24 et 1 respectivement.

- Compilez le code ci-dessus avec `g++` sans faire l'édition des liens, vous nommerez le fichier objet résultant `assembly.o`
- Utilisez ensuite le programme `objdump` pour inspecter l'assembleur généré pour cette fonction `foo`. Il est alors clair que cette fonction se résume au strict minimum.
- g++ permet d'optimiser plus ou moins le code généré
    - regardez l'assembleur généré sans optimisation flag `-O0`
    - regardez l'assembleur généré au niveau d'optimisation maximum `-O4` 

