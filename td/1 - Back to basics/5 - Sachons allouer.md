---
goal:Revenir sur l'allocation dynamique de mémoire et le passage par adresse.
notions:malloc,free,passage par adresse
---
Toujours dans nos fichiers de fonction, vous allez créer trois fonctions, la première `initTable` devra allouer un tableau d'entiers (une seule dimension) qui sera destiné à contenir toutes les tables de multiplication des entiers entre deux bornes passées en paramètres. Cette fonction devra renvoyer le tableau. La seconde fonction `fillTable` devra remplir le tableau, elle prendra en paramètre les deux bornes et le tableau. Enfin la dernière fonction `deleteTable` devra libérer la mémoire du tableau, et passer la valeur du pointeur à `NULL`. Elle devra pour cela prendre en paramètre un pointeur sur le tableau. Adaptez la fonction `printTable` pour qu'elle affiche le tableau. Donnez un exemple d'utilisation dans la fonction `main`.
