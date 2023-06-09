
#include "Discriminant.h"
#include "Roots.h"
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
double a, b, c, x1, x2, disc;

int main(int argc, char *argv[]) {
    
    int num_roots;

    // Запитуємо коефіцієнти від користувача
    if (argc == 4){
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
    }
    if (argc == 1){
        printf("Enter the coefficients a: ");
        scanf("%lf", &a);
        printf("Enter the coefficients b: ");
        scanf("%lf", &b);
        printf("Enter the coefficients c: ");
        scanf("%lf", &c);
    } 
    if (argc == 2){
        a = atof(argv[1]);
        printf("Enter the coefficients b: ");
        scanf("%lf", &b);
        printf("Enter the coefficients c: ");
        scanf("%lf", &c);
    }
    if (argc == 3){
        a = atof(argv[1]);
        b = atof(argv[2]);
        printf("Enter the coefficients c: ");
        scanf("%lf", &c);
    }
    printf("Entered coefficients: a = %lf, b = %lf, c = %lf\n", a, b, c);
    // scanf("%lf %lf %lf", &a, &b, &c);

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
        return 2;
    }
}
