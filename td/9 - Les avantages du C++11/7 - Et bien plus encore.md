---
goal:Un aperçu des autre nouveautés du C++11
---
La norme du C++11 apporte beaucoup d'autres nouveautés :
* [une vrai modèle de mémoire](http://en.wikipedia.org/wiki/C%2B%2B11#Multithreading_memory_model) qui définit un comportement non ambigu en présence d'exécutions concurrentes,
    * std::thread, std::atomic, std::thread::hardware_concurrency(), future/promise...
* le mot clef `nullptr` [un type fort pour remplacer NULL](http://en.wikipedia.org/wiki/C%2B%2B11#Null_pointer_constant),
* [des assertions vérifiées lors de la compilation](http://en.wikipedia.org/wiki/C%2B%2B11#Static_assertions) et non à l'exécution,
* [des tuples](http://en.wikipedia.org/wiki/C%2B%2B11#Tuple_types),
* [des conteneurs hashés](http://en.wikipedia.org/wiki/C%2B%2B11#Hash_tables),
* [des expressions rationelles](http://en.wikipedia.org/wiki/C%2B%2B11#Regular_expressions),
* [des fonctions pour gérer le temps](http://en.cppreference.com/w/cpp/chrono),
* [un ensemble de pointeurs intelligents](http://en.wikipedia.org/wiki/C%2B%2B11#General-purpose_smart_pointers),
* [des foncteurs et des enveloppes de foncteurs](http://en.wikipedia.org/wiki/C%2B%2B11#Polymorphic_wrappers_for_function_objects),
* [des templates variadiques](http://en.wikipedia.org/wiki/C%2B%2B11#Variadic_templates) _mon préféré..._,
* [et biens d'autres choses...](http://en.wikipedia.org/wiki/C%2B%2B11)