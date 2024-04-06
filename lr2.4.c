#include <stdio.h>
#include <math.h>
#include <locale.h>

double nextTerm(double a, double x);
double sqrtCubeRoot(double a);

int main() {
    setlocale(LC_CTYPE, "RUS");

    double a;
    printf("Введите число a: ");
    scanf("%lf", &a);

    double result = sqrtCubeRoot(a);
    printf("Предел последовательности sqrt(a, 3) при a = %.2f: %.6f\n", a, result);

    return 0;
}

double nextTerm(double a, double x) {
    return (2.0 / 3.0) * (x + (a / (2 * pow(x, 2))));
}

double sqrtCubeRoot(double a) {
    double x0 = a / 3.0; // Начальное значение x0
    double x = x0;
    double prevX;

    do {
        prevX = x;
        x = nextTerm(a, prevX);
    } while (fabs(x - prevX) >= 0.000001); // Проверяем точность

    return x;
}
