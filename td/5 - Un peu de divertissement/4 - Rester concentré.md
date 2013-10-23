---
goal:Garder la particule à l'intérieur de la fenêtre.
---
- Ajoutez une fonction membre `void KeepInBox()` qui empêche la particule de sortir de l'espace [0,1]².
    - pour ce faire vous inverserez la composante de la vitesse qui ferait sortir la particule.
- Ajoutez quelques tests pour vérifiez le comportement.
- Maintenant dans la boucle infinie, Appelez `KeepInBox()` après `UpdateEuler`.

La particule devrait rebondir sur les parois de la fenêtre.
