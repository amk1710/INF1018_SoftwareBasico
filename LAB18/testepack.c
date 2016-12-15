#include <stdio.h>

double foo (double a, int b);

struct X {
  int vi;
  double vd;
  struct X *next;
};

double pack (struct X *px);

struct X x3 = {1, 77567678.57345, NULL};
struct X x2 = {-1, 77567678.57345, &x3};
struct X x1 = {5, 35.7, &x2};

int main(void){
	double d = pack(&x1);
	printf("%f\n", d);
	return 0;
}
