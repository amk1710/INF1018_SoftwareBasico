#include <stdio.h>

double foo (double a, int b);

int main(void){
	double d = foo(-27.573, 100);
	printf("%f\n", d);
	return 0;
}
