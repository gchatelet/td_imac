---
goal:Acquérir les bases mathématiques nécessaires à la compréhension du TD.
notions:Cinématique du point.
---
Pour ce TD nous allons nous restreindre à la [cinématique du point](http://fr.wikipedia.org/wiki/Cin%C3%A9matique#Cin.C3.A9matique_du_point) en deux dimensions dont le mouvement est régi par la définition de l'accélération.
<p>
  `a(t)=del/del_tv(t)`
</p>
<p>
  `v(t)=del/del_tp(t)`
</p>

Ainsi pour connaître la position d'un point à un instant _t_ il suffit de connaître l'accélération qu'il subit et d'intégrer dans le temps.
<p>
  `v(t)=int_0^ta(t)del_t`
</p>
<p>
  `p(t)=int_0^tv(t)del_t`
</p>

Il est souvent difficile de résoudre ces intégrales de manière exacte nous allons donc utiliser des méthodes d'intégration numérique. Les trois classiques sont :
- [Euler](http://fr.wikipedia.org/wiki/M%C3%A9thode_d%27Euler)
- [Verlet](http://fr.wikipedia.org/wiki/Int%C3%A9gration_de_Verlet)
- [Runge-Kutta](http://fr.wikipedia.org/wiki/M%C3%A9thodes_de_Runge-Kutta)

`Euler` et `Verlet` sont des approximations à l'ordre 0 et 1 de la méthode généralisée de `Runge-Kutta`.
Dans le cas d'une accélération constante (gravité), `Verlet` donne la réponse exacte.
La méthode d'`Euler` - quant à elle - donne la réponse exacte seulement dans le cas d'une accélération nulle, elle est donc à proscrire car elle introduit un biais qui rend la simulation instable.

Code pour l'intégration d'`Euler`
    // Mets à jour la position et la velocité avec la méthode d'Euler
    void UpdateEuler(const Point2D& force, const float dt, 
                     Point2D& vel, Point2D& pos) {
        vel = vel + force * dt;
        pos = pos + vel * dt;
    }

Code pour l'intégration de `Verlet`
    // Mets à jour la position et la velocité avec la méthode de Verlet
    void UpdateVerlet(const Point2D& force, const float dt, 
                      Point2D& vel, Point2D& pos) {
        const Point2D oldVel = vel;
        vel = vel + force * dt;
        pos = pos + (oldVel + vel) * 0.5 * dt;
    }