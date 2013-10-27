#include "Point2D.hpp"

#include <cstdlib>
#include <cstdio>

int main(int argc, char **argv) {
    Point2D a(1, 0), b(0, 1), c;
    c = a + b;
    printf("result is [%f, %f]", c.x, c.y);
    return EXIT_SUCCESS;
}
