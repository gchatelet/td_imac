---
goal:Composition des forces
notion:Design Pattern composite
---
Écrivez une classe `Composite` qui prendra en paramètre un `std::vector<Force*>` et qui implémente la méthode `Force::get` en retournant la somme des forces.

    TEST(Composite, Check) {
        const Gravity gravity;
        std::vector<const Force*> forces;
        forces.push_back(&gravity);
        forces.push_back(&gravity);
        const Composite composite(forces);
        EXPECT_EQ(composite.get(Point2D(), 0), Point2D(0, -9.81) * 2);
    }