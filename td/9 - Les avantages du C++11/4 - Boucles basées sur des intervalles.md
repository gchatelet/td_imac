---
goal:'foreach'
---
Les boucles `for` sont simplifiées
    const std::set<std::string> strings = {"one", "two", "three"};
    
    for(const auto& aString : strings) {
        std::cout << aString << std::endl;
    }
parfois dramatiquement
    for(const auto& aString : {"one", "two", "three"}) {
        std::cout << aString << std::endl;
    }
En fait, la boucle précédente est réécrite par le compilateur de la manière suivante
    const auto container = {"one", "two", "three"};
    for(auto itr(std::begin(container)), end(std::end(container)); itr != end; ++itr) {
      const auto& aString = *itr;
      std::cout << aString << std::endl;
    }

`std::begin(container)` et `std::end(container)` sélectionnent le premier et le dernier élément du conteneur respectivement (le plus souvent en faisant suivre à `container.begin()` et `container.end()`).