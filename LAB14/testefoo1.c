#include <stdio.h>
#include <math.h>

float foo1(float a, float b);

int main(void)
{
	float a = M_PI_2;
	float b = 11.0;
	float f = foo1(a,b);
	printf("\n%f", f);
	return 0;
}
