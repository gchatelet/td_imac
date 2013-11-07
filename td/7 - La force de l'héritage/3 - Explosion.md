---
goal:Une force dépendante du temps
notion:Héritage, polymorphisme
---
Écrivez une classe `Explode` qui implémente la méthode `Force::get`.
La force retournée par cette méthode est appliquée pendant 100ms toutes les 5s dans une direction que vous choisirez. Sa magnitude sera de 60.

Vérifiez que la classe fait passer le test suivant :

    TEST(Explode, Check) {
        Explode explode;
        // force entre 0 et 100ms
        EXPECT_EQ(explode.get(Point2D(), 0), Point2D(60,0)); 
        EXPECT_EQ(explode.get(Point2D(), 0.1), Point2D(60,0));
        // pas de force après 100ms
        EXPECT_EQ(explode.get(Point2D(), 0.101), Point2D());
        EXPECT_EQ(explode.get(Point2D(), 1), Point2D());
        // force après 5s entre 0 et 100ms
        EXPECT_EQ(explode.get(Point2D(), 5), Point2D(60,0)); 
        // plus de force après 100ms
        EXPECT_EQ(explode.get(Point2D(), 5.101), Point2D());
    }
