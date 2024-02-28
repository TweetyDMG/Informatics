#include <stdio.h> 
#include <locale.h> 
#include <math.h> 
#include <Windows.h>
#include <ctype.h>

int main()
{
    setlocale(LC_CTYPE, "rus");

    //есть число 0.5178. Найти предельные относительную и абсолютную погрешности. Все цифры верные
    double originalNumber, roundedNumber;
    int decimalPlaces;

    // Ввод вещественного числа от пользователя
    printf("Введите вещественное число: ");
    scanf("%lf", &originalNumber);

    // Ввод количества знаков после запятой для округления
    printf("До скольки знаков после запятой округлить число: ");
    scanf("%d", &decimalPlaces);

    // Округление введенного числа
    roundedNumber = round(originalNumber * pow(10, decimalPlaces)) / pow(10, decimalPlaces);

    // Расчет абсолютной и относительной погрешностей
    double absoluteError = fabs(originalNumber - roundedNumber);
    double relativeError = (absoluteError / fabs(originalNumber)) * 100;

    // Вывод результатов
    printf("Введенное число: %.7f\n", originalNumber);
    printf("Округленное число: %.7f\n", roundedNumber);
    printf("Абсолютная погрешность: %.7f\n", absoluteError);
    printf("Относительная погрешность: %.7f%%\n", relativeError);

    return 0;
}
