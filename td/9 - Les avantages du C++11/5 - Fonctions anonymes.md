---
goal:lambda
---
Il est possible de déclarer une fonction anonyme et de la mettre dans une variable
    auto foo = [](const int num){ std::cout << "called with " << num << std::endl; };
    foo(1); 
    foo(2);
Sans l'utilisation de `auto` la signature de la fonction serait plus compliquée
    void(*foo)(int) = [](const int num){ std::cout << "called with " << num << std::endl; };

Les lambdas (fonctions anonymes) peuvent capturer leur environnement par copie avec `=`
    const int number = 1;
    auto foo = [=](){ std::cout << "called with " << number << std::endl; };
ou par référence
    const std::string line = "this is a line";
    auto foo = [&](){ std::cout << "called with " << line << std::endl; };

Les lambdas deviennent extrêmement intéressantes en conjonction avec les [algorithmes de la STL](http://www.cplusplus.com/reference/algorithm/)
    // Count the odd numbers
    const std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const auto odd_count = std::count_if(
                               std::begin(numbers),
                               std::end(numbers),
                               [](int value){ return (value%2) == 1; }
                           );
    
    // Are all those numbers between 0 and 10
    const int array[] = {2, 3, 5, 2, 1};
    const auto all_between_zero_and_ten = std::all_of(
                                              std::begin(array),
                                              std::end(array),
                                              [](int value){ return value>=0 && value<=10; }
                                          );

