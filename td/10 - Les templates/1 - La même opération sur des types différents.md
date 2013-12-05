---
goal:Initiations aux templates
---
Les templates sont une manière de demander au compilateur de générer du code pour nous.

Un `template` - 'patron' en français - est donc un modèle que le compilateur va instancier pendant la phase de compilation.

    template<typename T>
    T get_max(const T a, const T b) {
      return a < b ? b : a;
    }
    
    int main() {
      cout << get_max(2, 3) << endl;     // creates get_max<int>
      cout << get_max(2.1, 3.2) << endl; // creates get_max<double>
      cout << get_max('a', 'z') << endl; // creates get_max<char>
      return EXIT_SUCCESS;
    }

* Recopiez ce code et appelez `get_max(2.5, 3)`, que se passe-t-il ?
* Que pouvez-vous faire pour réparer ?

Une implémentation générique correcte des fonctions `min` et `max` est en fait [particulièrement difficile](http://www.drdobbs.com/generic-min-and-max-redivivus/184403774).
