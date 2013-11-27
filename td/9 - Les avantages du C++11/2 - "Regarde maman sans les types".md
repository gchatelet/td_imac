---
goal:utilisation du mot clefs auto
---
`auto` permet de laisser le compilateur déduire le type à notre place lorsqu'il est non ambiguë.

    std::vector<std::string> strings;
    // C++03
    std::vector<std::string>::const_iterator itr = strings.begin();
    // C++11
    auto itr = strings.begin();

le mot clef `auto` peut être qualifié avec `const`, `&` ou `*` si l'ont veut forcer une interprétation particulière.

    std::string strings[] = {"word"};
    const auto& string = strings[0]; // string is of type 'const string&'