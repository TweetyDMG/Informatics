#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int number1_1, number1_2, number2;
    double quotient, root_result;
    printf("\nЗадание 1\n");
    printf("Введите первое число для первого выражения: ");
    scanf("%d", &number1_1);
    printf("Введите второе число для первого выражения: ");
    scanf("%d", &number1_2);
    printf("Введите приблизительное частное этих чисел: ");
    scanf("%lf", &quotient);
    printf("Введите число для второго выражения: ");
    scanf("%d", &number2);
    printf("Введите приблизительный результат при вычислении корня из %d: ", number2);
    scanf("%lf", &root_result);
    system("cls");
    printf("\nКакое выражение точнее: 1) %d/%d=%.3lf или 2) sqrt(%d) = %.3lf\n", number1_1, number1_2, quotient, number2, root_result);
    printf("Значения выражений с большим количеством десятичных знаков:\n");
    double exactValue1 = number1_1*1. / number1_2;
    double exactValue2 = sqrt(number2);
    printf("1) %d/%d = %lf\n", number1_1, number1_2, exactValue1);
    printf("2) sqrt(%d) = %lf\n", number2, exactValue2);
    printf("Предельные абсолютные погрешности, округляя их с избытком:\n");
    double absoluteError1 = fabs(exactValue1 - quotient);
    double absoluteError2 = fabs(exactValue2 - root_result);
    printf("1) %lf\n", absoluteError1);
    printf("2) %lf\n", absoluteError2);
    printf("Предельные абсолютные погрешности составляют в %:\n");
    double relativeError1 = absoluteError1 / exactValue1;
    double relativeError2 = absoluteError2 / exactValue2;
    printf("1) %lf\n", relativeError1);
    printf("2) %lf\n", relativeError2);
    if (relativeError1 < relativeError2)
        printf("Выражение %d/%d=%.3lf более точное\n", number1_1, number1_2, quotient);
    else
        printf("Выражение sqrt(%d) = %.3lf более точное\n", number2, root_result);
}
