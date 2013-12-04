---
goal:Comportement particulier dans certains cas.
---
Le C++ permet de spécialiser des templates, et de définir des implémentations particulières pour des types particulier.
    template<typename T>
    T get_max(const T a, const T b) {
      return a < b ? b : a;
    }
    
    template<>
    char get_max<char>(const char a, const char b) {
      const char a_ = isupper(a) ? tolower(a) : a;
      const char b_ = isupper(b) ? tolower(b) : b;
      return a_ < b_ ? b_ : a_;
    }
Dans ce cas `get_max('A', 'z')` affichera `a` le compilateur choisira l'implémentation spécialisée.

Nous avons vu dans les cours précédents que si l'on peut calculer le modulo de deux entiers grâce à l'opérateur `%`, il faut utiliser la fonction `fmod` lorsque les opérandes sont de type flottant.

Définissez une fonction template `modulo` qui utilise `fmod` dans le cas général et l'opérateur `%` pour les types entiers.

