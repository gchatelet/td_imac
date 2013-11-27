---
goal:foreach
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
