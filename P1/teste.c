#include <stdio.h>


int foo (int *v1, int n);

int main(void)
{
	int vet[5] = {0, 1, -10, 20, 4};
	int ret = foo(vet, 5);
	printf("%d\n", ret);
	return 0;
}
