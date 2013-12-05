---
goal:activer la nouvelle norme
---
Les différents compilateurs ont implémenté la norme à des vitesses différentes, en général il faut passer un flag pour activer cette norme (sauf pour Visual Studio, le compilateur de Microsoft).
Pour **GCC** il s'agit de `-std=c++0x` pour les versions antérieures à **GCC 4.7** et `-std=c++11` pour les versions suivantes.

Selon la version de **GCC** dont vous disposez, ajoutez la ligne suivante dans votre `CMakeLists.txt`
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # for gcc >= 4.7
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x") # for gcc < 4.7
