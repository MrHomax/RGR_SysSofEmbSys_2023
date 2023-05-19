
#include "Discriminant.h"
#include "Roots.h"
#include <stdio.h>
//#include <math.h>

int main() {
    double a, b, c, x1, x2, disc;
    int num_roots;

    // Запитуємо коефіцієнти від користувача
    printf("Enter the coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Обчислюємо корені рівняння
    disc = discriminant(a, b, c);
    roots(a, b, c, disc, &num_roots, &x1, &x2);

    // Виводимо результат
    if (num_roots == 2) {
        printf("The equation has two real roots: x1 = %lf, x2 = %lf\n", x1, x2);
        return 0;
    } else if (num_roots == 1) {
        printf("The equation has one real root: x = %lf\n", x1);
        return 1;
    } else {
        printf("The equation does not have real roots\n");
        return -1;
    }
}
