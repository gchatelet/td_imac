---
goal:Opérations simples avec un vecteur
notions:std::vector, push_back(), size()
---
Récupérez le texte d'[Hamlet](http://erdani.com/tdpl/hamlet.txt) et utilisez un `std::ifstream` pour lire chacun des mots du fichier. Vous les ajouterez dans un `std::vector<string>`.

Affichez le nombre de mots que contient le vecteur après avoir lu le fichier. Vérfiez que votre programme affiche le bon résultat en utilisant l'utilitaire Linux `wc`

    ~> wc -w hamlet.txt
    31956 hamlet.txt