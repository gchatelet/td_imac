---
goal:Instanciation de structures templatées
---
De la même manière qu'une fonction peut être templatée, une `struct` ou une `class` peuvent également être templatées.

Créez une structure templatée `Point3D` qui comprendra les opérations suivantes :
- constructeur par defaut
- constructeur par copie
- assignation
- opérateurs binaires avec un scalaire : +, -, *, /
- opérateurs binaires avec une valeur de même type : +, -, *, /
- opérateurs unaires !, -

On pourra donc instancier ce `Point3D` avec différents types :
    Point3D<int>           point3d_i;
    Point3D<double>        point3d_d;
    Point3D<short>         point3d_s;
    Point3D<float>         point3d_f;
    Point3D<unsigned>      point3d_ui;
    Point3D<unsigned char> point3d_uc;

- Ecrivez des tests unitaires qui permettent de tester votre template.
- Maintenant rajouter un constructeur qui permet d'initialiser un Point3D avec un Point3D d'un autre type, par exemple :

        Point3D<int>           point3d_i;
        Point3D<double>        point3d_d(point3d_i);
