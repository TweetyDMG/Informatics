#include <stdio.h>
#include <math.h>
#include <locale.h>

double sinOverX(double x);

int main() {
    setlocale(LC_CTYPE, "RUS");
    double epsilon;
    printf("Введите значение погрешности epsilon: ");
    scanf("%lf", &epsilon);

    double x = 1.0; // Начальное значение x
    double targetValue = 1.0;
    double difference;

    printf("     x    | sin(x)/x | Difference\n");
    printf(" ---------|----------|-----------\n");

    do {
        double result = sinOverX(x);
        difference = fabs(result - targetValue);
        printf(" %.6lf | %.6lf | %.6lf\n", x, result, difference);
        x /= 2.0; // Уменьшаем x вдвое для приближения к нулю
    } while (difference >= epsilon);

    printf("\nДостигнута погрешность менее %.6lf\n", epsilon);

    return 0;
}

double sinOverX(double x) {
    if (x == 0) return 1; // Для случая x = 0

    return sin(x) / x;
}
