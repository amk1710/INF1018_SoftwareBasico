#include <stdio.h>
#include <math.h>

double foo2(float a, float b);

int main(void)
{
	float a = M_PI_2;
	float b = M_PI;
	double f = foo2(a,b);
	printf("\n%lf", f);
	return 0;
}
