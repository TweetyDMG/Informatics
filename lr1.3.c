#include <stdio.h> 
#include <locale.h> 
#include <math.h> 
#include <Windows.h>
#include <ctype.h>

int main()
{
    setlocale(LC_CTYPE, "rus");
    double originalNumber, roundedNumber;
    int decimalPlaces;
    printf("Введите вещественное число: ");
    scanf("%lf", &originalNumber);
    printf("До скольки знаков после запятой округлить число: ");
    scanf("%d", &decimalPlaces);
    roundedNumber = round(originalNumber * pow(10, decimalPlaces)) / pow(10, decimalPlaces);
    double absoluteError = fabs(originalNumber - roundedNumber);
    double relativeError = (absoluteError / fabs(originalNumber)) * 100
    printf("Введенное число: %.7f\n", originalNumber);
    printf("Округленное число: %.7f\n", roundedNumber);
    printf("Абсолютная погрешность: %.7f\n", absoluteError);
    printf("Относительная погрешность: %.7f%%\n", relativeError);

    return 0;
}
