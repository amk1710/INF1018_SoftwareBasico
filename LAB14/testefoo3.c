#include <stdio.h>
#include <math.h>

double foo3(double *a, int n);

int main(void)
{
	double v[5] = {M_PI_2, M_PI_2, M_PI_2, M_PI_2, M_PI};
	int n = 5;
	double f = foo3(v, n);
	printf("\n%lf", f);
	return 0;
}
