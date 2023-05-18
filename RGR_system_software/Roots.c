#include "Roots.h"
#include "Discriminant.h"
#include <stdio.h>
#include <math.h>

// Функція для обчислення коренів рівняння
void roots(double a, double b, double c, int* num_roots, double* x1, double* x2) {
    double disc = discriminant(a, b, c);

    if (disc > 0) {
        *num_roots = 2;
        *x1 = (-b + sqrt(disc)) / (2*a);
        *x2 = (-b - sqrt(disc)) / (2*a);
    } else if (disc == 0) {
        *num_roots = 1;
        *x1 = -b / (2*a);
    } else {
        *num_roots = -1;
    }
}

