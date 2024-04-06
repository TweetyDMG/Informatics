#include <stdio.h>
#include <math.h>
#include <locale.h>

double factorial(int n);
double function(double x, int k);
double series(double x, double epsilon, int* numTerms);

int main(void)
{

	double xn = 1.;
	double xk = 3.;
	double dx = 0.1;
	double totalRate1 = 0, totalRate2 = 0;
	int numPoints1 = 0, numPoints2 = 0;

	printf(" __________________________________________________________________\n");
	printf(" |   x  |  eps1 |   f1   |  rate1  |    eps2    |   f2   |  rate2 |\n");
	printf(" |      |  0.1  |        |         |  0.000001  |        |        |\n");
	printf(" |------|-------|--------|---------|------------|--------|--------|\n");
	for (double x = xn; x <= xk; x += dx) {
		int numTerms1, numTerms2;
		double result1 = series(x, 0.1, &numTerms1);
		double result2 = series(x, 0.000001, &numTerms2);
		double rate1 = (result1 != 0) ? fabs(log(fabs(result1)) / log(numTerms1)) : 0;
		double rate2 = (result2 != 0) ? fabs(log(fabs(result2)) / log(numTerms2)) : 0;
		if (isnan(result1) || result1 <= 0) result1 = NAN;
		if (isnan(result2) || result2 <= 0) result2 = NAN;
		if (!isnan(rate1)) {
			totalRate1 += rate1;
			numPoints1++;
		}
		if (!isnan(rate2)) {
			totalRate2 += rate2;
			numPoints2++;
		}
		printf(" | %4.2f |       | %6.4f | %7.5f |            | %6.4f | %6.4f |\n", x, result1, rate1, result2, rate2);
	}
	printf(" ------------------------------------------------------------------\n");
	printf(" |Total |       |        | %7.5f |            |        | %6.4f |\n", totalRate1 / numPoints1, totalRate2 / numPoints2);
	printf(" ------------------------------------------------------------------\n");
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

double series(double x, double epsilon, int* numTerms)
{
	double result = 0.0;
	double term = 1.0;
	int k = 0;
	*numTerms = 0; 
	int maxIterations = 50000;


	while (fabs(term) > epsilon && k < maxIterations) 
	{
		result += term;
		k++;
		term = function(x, k);
		(*numTerms)++;
	}
	return result;
}
