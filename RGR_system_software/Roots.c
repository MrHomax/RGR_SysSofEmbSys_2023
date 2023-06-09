#include <math.h>
#include "Roots.h"

// Функція для обчислення коренів рівняння
void roots(double a, double b, double c, double disc, int* num_roots, double* x1, double* x2) {

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

