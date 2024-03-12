#include <stdio.h>
#include <math.h>
#include <locale.h>

double factorial(int n);
double function(double x, int k);


int main(void)
{
	
	double xn = 1;
	double xk = 3;
	double dx = 0.1;
	for (double x = xn; x <= xk; x += dx)
	{
		double result = 0.0;

		for (int k = 0; k < 10; k++) {
			result += function(x, k);
		}
		printf("%.2lf\t\t%.6lf\n", x, result);
	}
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
