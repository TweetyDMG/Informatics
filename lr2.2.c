#include <stdio.h>
#include <math.h>
#include <locale.h>

double factorial(int n);
double function(double x, int k);
double series(double x, double epsilon);


int main(void)
{

	double xn = 1.;
	double xk = 3.;
	double dx = 0.1;

	printf("_______________________________________________\n");
	printf("|   x  |  eps1 |   f1   |    eps2    |   f2   |\n");
	printf("|      |  0.1  |        |  0.000001  |        |\n");
	printf("|------|-------|--------|------------|--------|\n");
	for (double x = xn; x <= xk; x += dx) {
		double result1 = series(x, 0.1);
		double result2 = series(x, 0.000001);
		// Проверка на NaN
		if (isnan(result1) || result1 <= 0) {
			result1 = NAN;
		}
		if (isnan(result2) || result2 <= 0) {
			result2 = NAN;
		}
		printf("| %4.2f |       | %6.4f |            | %6.4f |\n", x, result1, result2);
	}
	printf("______________________________________________________\n");
	return 0;
}

double function(double x, int k)
{
	return pow(-1, k) * pow(x, 2 * k) / factorial(k);
}

double factorial(int n)
{
	int r;
	for (r = 1; n > 1; r *= (n--));
	return r;
}

double series(double x, double epsilon)
{
	double result = 0.0;
	double term = 1.0;
	int k = 0;
	int maxIterations = 10000;

	while (fabs(term) > epsilon && k < maxIterations) 
	{
		result += term;
		k++;
		term = function(x, k);
	}
	return result;
}
