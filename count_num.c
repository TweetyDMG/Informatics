#include <stdio.h> 
#include <locale.h> 
#include <math.h> 
#include <Windows.h>
#include <ctype.h>

void doubleToString(double number, char* result, int* decimalCount);
void trimTrailingZeros(char* str);

int main()
{
    setlocale(LC_CTYPE, "rus");

    //есть число 0.5178. Найти предельные относительную и абсолютную погрешности. Все цифры верные
    double inputNumber = 0.05178;

    // Максимальная длина строки для вещественного числа
    const int maxLength = 50;
    char resultString[100];

    // Количество цифр после запятой
    int decimalCount;

    // Вызов функции для перевода вещественного числа в строку
    // и подсчета цифр после запятой
    doubleToString(inputNumber, resultString, &decimalCount);

    printf("Результат: %s\n", resultString);
    printf("Количество цифр после запятой: %d\n", decimalCount);

    return 0;
}

void trimTrailingZeros(char* str) {
    int length = strlen(str);

    // Находим позицию точки (запятой) в строке
    char* decimalPoint = strchr(str, '.');

    if (decimalPoint != NULL) {
        // Начинаем с конца строки и двигаемся к началу, удаляя нули
        int i = length - 1;
        while (i > decimalPoint - str && str[i] == '0') {
            str[i] = '\0';
            i--;
        }

        // Если последний символ после точки - ноль, удаляем и точку
        if (str[i] == '.') {
            str[i] = '\0';
        }
    }
}

void doubleToString(double number, char* result, int* decimalCount) {
    // Перевод вещественного числа в строку с использованием snprintf
    int len = snprintf(result, 50, "%.15f", number);

    // Парсинг строки обратно в число для удаления лишних нулей
    double parsedNumber = strtod(result, NULL);

    // Перевод отпарсенного числа обратно в строку
    snprintf(result, len + 1, "%.15f", parsedNumber);

    // Обрезаем нули в конце строки
    trimTrailingZeros(result);

    // Поиск символа точки (запятой)
    char* decimalPoint = strchr(result, '.');

    // Подсчет количества цифр после запятой
    *decimalCount = (decimalPoint != NULL) ? strlen(decimalPoint + 1) : 0;
}
