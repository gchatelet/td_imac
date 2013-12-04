---
goal:Policy based design
---
`Andrei Alexandrescu` a révolutionné la meta programmation en 2001 avec son livre `Modern C++ Design`.
Il parle notamment du `policy base design`, cette pratique consiste à customiser des parties orthogonales de designs dans un template par héritage de classes ou d'autre templates.

- Implémentez [l'exemple sur wikipedia](http://en.wikipedia.org/wiki/Policy-based_design#Simple_example).
- Ajouter une police `OutputPolicyWriteToCerr` pour écrire sur la sortie d'erreur.
- Ajouter une police `LanguagePolicyFrench` qui retournera 'Bonjour monde!'.
- Ajouter une police `LanguagePolicyNumber` qui retournera un `unsigned long` plutôt qu'une `std::string`, notez comment le design s'adapte à ce nouveau type.