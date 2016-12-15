#include <stdio.h>

int add(int i1, int i2, int i3);

int fat (int n);

void foo (int a[], int n);

int main(void)
{
	int a[10] = {1,2,3,0,4,0, 10, 5, 0, 7};
	int n = 10;
	int i;
	foo(a,n);
	for(i=0;i < n; i++)
	{
		printf("%d\n", a[i]);
	}
}
