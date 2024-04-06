#include <stdio.h>
#include <math.h>
#include <locale.h>

double calculateSum(int n);

int main() {
    setlocale(LC_CTYPE, "RUS");

    int n;
    printf("Введите натуральное число n: ");
    scanf("%d", &n);

    double result = calculateSum(n);
    printf("Сумма a_k * b_k для k от 1 до %d: %.6f\n", n, result);

    return 0;
}

double calculateSum(int n) {
    double ak, bk;
    double sum = 0;
    double a = 1, b = 1; // a1 = b1 = 1

    for (int k = 2; k <= n; k++) {
        ak = 0.5 * (sqrt(b) + 0.5 * a);
        bk = 2 * pow(a, 2) + b;
        sum += a * b;
        a = ak;
        b = bk;
    }

    return sum;
}
