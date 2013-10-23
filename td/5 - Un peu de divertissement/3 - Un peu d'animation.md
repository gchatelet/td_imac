---
goal:Prise en main de la classe ConsoleScreen.
---
- Téléchargez les fichiers [ConsoleScreen.hpp](/td_imac/src/ConsoleScreen.hpp) et [ConsoleScreen.cpp](/td_imac/src/ConsoleScreen.cpp).
- Écrivez une fonction main qui instancie celle classe et affiche le caractère 'X' au centre du buffer.
- Maintenant crée une `Particule` à la position (0.5,0.5) et affichez un 'X' à la position de cette particule. Regardez la documentation du header pour vous aider.
- Faites maintenant une boucle infinie. À chaque itération :
    - Appelez la méthode `UpdateEuler` sur la particule avec une force appropriée.
    - Placez un 'X' sur la position de la particule dans le buffer.
    - Affichez le buffer.
    - Mettez en pause le programme pendant 40ms grace à la fonction `usleep`.
    - Effacez le buffer.

Vous devriez voir se déplacer la particule à l'écran.