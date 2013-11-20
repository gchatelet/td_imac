---
goal:lambda
---
Il est possible de déclarer une fonction anonyme et de la mettre dans une variable
    auto foo = [](const int num){ std::cout << "called with " << num << std::endl; };
    foo(1); 
    foo(2);
Notez l'utilisation de `auto` pour simplifier l'écriture de la signature (`void(*foo)(int)`)
Les lambdas (fonctions anonymes) peuvent capturer leur environnement par copie avec `=`
    const int number = 1;
    auto foo = [=](){ std::cout << "called with " << number << std::endl; };
ou par référence
    const std::string line = "this is a line";
    auto foo = [&](){ std::cout << "called with " << line << std::endl; };

Les lambdas deviennent extrêmement intéressantes en conjonction avec les algorithmes de la STL
    const std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const auto odd_count = std::count_if(
                               numbers.begin(),
                               numbers.end(),
                               [](int value){ return (value%2)==1; }
                           );