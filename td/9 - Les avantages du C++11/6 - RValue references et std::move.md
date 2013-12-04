---
goal:Comprendre le déplacement d'objet
---
Dans le code suivant un vecteur avec dix millions de chaînes de caractères est crée dans `create`, en C++03 ce vecteur est copié dans `load`.
A un instant donné, nous avons donc vingt millions de chaînes de caractères en mémoire∗

    vector<string> create() {
      return vector<string>(10 * 1024 * 1024, "big vector with 10M strings");
    }
    
    int main() {
      const vector<string> load = create(); // 10M strings copied
      return EXIT_SUCCESS;
    }

Or il est clair que le vecteur crée dans `create` est temporaire et ne peut être utilisé par personne d'autre que le code appelant.

En C++11, les conteneurs de la STL (_Standard Template Library_) ont désormais un nouveau constructeur appelé **move constructor**
    vector<T>::vector(T&& temporary)

Ce constructeur permet de voler le contenu de la variable temporaire pour son propre compte.
Concrêtement `load` va échanger son contenu avec celui de la variable temporaire, puis la variable temporaire va être détruite.
Les dix millions de chaînes de caractères sont alors transferées dans `load` (simple échange de pointeurs), il n'y a pas d'allocation ni de copie.

En C++03 on peut seulement **copier** des types ou y accéder grâce à un pointeur∗∗ et même dans ce cas on **copie** le pointeur.
L'opération de déplacement (_move semantic_) en C++11 permet de déplacer une implémentation d'un objet à un autre.

Il est intéressant pour retourner de gros objets comme dans l'exemple précédent ou transférer des objets à une fonction comme dans l'exemple suivant :
    void process(vector<string> && v) {
      // content of v allocated in main will be destroyed at the end of this scope
    }
    
    int main() {
      vector<string> load(10 * 1024 * 1024, "big vector with 10M strings");
      process(std::move(load)); // explicitly transferring ownership to 'process'
      // load can't be used anymore, it is in an undefined state
      return EXIT_SUCCESS;
    }


∗ _dans ce cas particulier le compilateur peut parfois utiliser le [Return Value Optimization](http://en.wikipedia.org/wiki/Return_value_optimization) et éluder la copie, mais ce n'est pas garanti par le standard_

∗∗ _ou une référence mais soyons clair : ce n'est qu'un pointeur déguisé_