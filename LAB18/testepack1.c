#include <stdio.h>

double foo (double a, int b);

struct X {
  int vi;
  float vf;
};

double pack1 (struct X *px, int n);


struct X v[3] = {{ -1, 27.75}, {1, 32.0}, {4, 1.5}};

int main(void){
	double d = pack1(v, 3);
	printf("%f\n", d);
	return 0;
}
