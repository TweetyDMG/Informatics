#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
    setlocale(LC_CTYPE, "RUS");

    double number;
    double precision;

    printf("Введите число: ");
    scanf("%lf", &number);

    printf("Введите точность погрешности в процентах: ");
    scanf("%lf", &precision);

    precision = precision / 100.0;
    int valid_digits = -log10(precision);

    printf("Число с учетом верных цифр: %.*f\n", valid_digits, number);

    system("pause");
    return 0;
}

