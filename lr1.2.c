#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
    setlocale(LC_CTYPE, "RUS");

    double number;
    double precision;

    printf("\nВведите число: ");
    scanf("%lf", &number);

    printf("Введите точность погрешности в процентах: ");
    scanf("%lf", &precision);
    system("clear");

    printf("\nОкругление сомнительных цифр числа %.3lf, оставляя верные знаки. Определение абсолютной погрешности числа %.3lf\n", number, number);
    precision = precision / 100.0;
    printf("Перевод процентного значения в число: %lf\n", precision);
    int valid_digits = -log10(precision);
    printf("Количество верных цифр после запятой = log10(%lf) = %d\n", precision, valid_digits);
    printf("Число с учетом верных цифр: %.*f\n", valid_digits, number);

    double absolute_error = pow(10, -valid_digits) / 2.0;
    printf("Абсолютная погрешность: %.*f\n", valid_digits, absolute_error);

    system("pause");
    return 0;
}
