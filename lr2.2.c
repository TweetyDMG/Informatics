#include <stdio.h>
#include <math.h>
#include <locale.h>

double factorial(int n);
double function(double x, int k);
double series(double x, double epsilon);


int main(void)
{
	
	double xn = 1;
	double xk = 3;
	double dx = 0.1;

	printf("___________________________________________________________\n");
	printf("|    x    |    eps1    |    f1    |    eps2    |    f2    |\n");
	printf("|         |    0.1     |          |  0.000001  |          |\n");
	for (double x = xn; x <= xk; x += dx) {
		double result1 = series(x, 0.1);
		double result2 = series(x, 0.000001);
		printf("");
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

double series(double x, double epsilon)
{
	double result = 0.0;
	double term = 1.0;
	int k = 0;

	while (fabs(term) > epsilon)
	{
		result += term;
		k++;
		term = function(x, k);
	}
	return result;
}
