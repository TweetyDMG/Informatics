#include <stdio.h> 
#include <locale.h> 
#include <math.h> 
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS 

int main()
{
	setlocale(LC_ALL, "rus");
		
	//есть число 0.5178. Найти предельные относительную и абсолютную погрешности. Все цифры верные
	double num = 0.5178;


	double firstNum = 0.5718;
	double decimalPart = fabs(firstNum - (int)firstNum);
	printf("%lf\n", decimalPart);
	int countNum = 0;
	while (decimalPart > 0)
	{
		decimalPart *= 10;
		decimalPart = fmod(decimalPart, 1.0);
		countNum++;
	}
	printf("%d", countNum);
		

	return 0;
}
