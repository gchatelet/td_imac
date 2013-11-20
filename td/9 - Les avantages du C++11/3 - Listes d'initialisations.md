---
goal:std::initializer_list
---
En C++11 il est possible d'initialiser directement un conteneur avec des valeurs plutôt que d'appeler successivement `push_back` :
    std::vector<int> numbers = { 1, 2 };

Dans ce cas `numbers` pourrait être `const` car il serait directement initialisé avec les bonnes valeurs.