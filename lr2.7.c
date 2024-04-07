#include <stdio.h>
#include <math.h>
#include <locale.h>

double calculateLimit(int n);

int main() {
    setlocale(LC_CTYPE, "RUS");
    double epsilon;
    printf("Введите значение погрешности epsilon: ");
    scanf("%lf", &epsilon);

    double targetValue = 2.71828182845904; // e
    int n = 1;
    double difference;

    printf(" n    |  1 + 1/n  | Difference\n");
    printf("---------------------------\n");

    do {
        double result = calculateLimit(n);
        difference = fabs(result - targetValue);
        printf("%3d   | %8.6f  | %8.6f\n", n, result, difference);
        n++;
    } while (difference >= epsilon);

    printf("\nДостигнута погрешность менее %.6f при n = %d\n", epsilon, n - 1);

    return 0;
}

double calculateLimit(int n) {
    return pow((1 + 1.0 / n), n);
}
