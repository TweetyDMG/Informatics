#include <stdio.h> 
#include <locale.h> 
#include <math.h> 
#include <Windows.h>
#include <ctype.h>

int doubleToString(double number, char* result, int* decimalCount);
int trimTrailingZeros(char* str);
double countAbsoluteError(double decimalCount);

int main()
{
    setlocale(LC_CTYPE, "rus");
    double origNum = 0.001;
    const int maxLength = 50;
    char resultString[100];
    int decimalCount;
    printf("Введите вещественное число: ");
    scanf("%lf", &origNum);
    doubleToString(origNum, resultString, &decimalCount);
    double absErr = countAbsoluteError(decimalCount);
    double relErr = absErr/origNum;
    if (absErr == 1) {
        printf("Ваше число не имеет значащих цифр после запятой/точки.\n");
        return 1;
    }
    printf("Число %lf имеет %d значащих(-щую) цифр(-у) после запятой\n", origNum, decimalCount);
    printf("Абсолютная погрешность: %lf\n", absErr);
    printf("Относительная погрешность: %lf\n", relErr);

    return 0;
}

int trimTrailingZeros(char* str) {
    int length = strlen(str);
    char* decimalPoint = strchr(str, '.');

    if (decimalPoint != NULL) {
        int i = length - 1;
        while (i > decimalPoint - str && str[i] == '0') {
            str[i] = '\0';
            i--;
        }
        if (str[i] == '.') {
            str[i] = '\0';
        }
    }
    return 0;
}

int doubleToString(double number, char* result, int* decimalCount) {
    int len = snprintf(result, 50, "%.15f", number);
    double parsedNumber = strtod(result, NULL);
    snprintf(result, len + 1, "%.15f", parsedNumber);
    trimTrailingZeros(result);
    char* decimalPoint = strchr(result, '.');
    *decimalCount = (decimalPoint != NULL) ? strlen(decimalPoint + 1) : 0;
    return 0;
}

double countAbsoluteError(double decimalCount) {
    if (decimalCount == 1) return 0.05;
    if (decimalCount == 2) return 0.005;
    if (decimalCount == 3) return 0.0005;
    if (decimalCount == 4) return 0.00005;
    if (decimalCount == 5) return 0.000005;
    if (decimalCount == 6) return 0.0000005;
    if (decimalCount == 0) return 1;
}
