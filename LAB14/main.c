#include <stdio.h>

double foo(double a, float b);

int main(void)
{
	double a = 25.5;
	float b = 11.0;
	double f = foo(a,b);
	printf("\n%lf", f);
	return 0;
}
