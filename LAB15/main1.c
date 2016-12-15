#include <stdio.h>

unsigned char codigo[6] = {0x89, 0xf8, 0x83, 0xc0, 0x01, 0xc3};

typedef int (*funcp) (int x);


int main(void)
{
	funcp f = (funcp)codigo;
	int i = (*f)(10);
	printf("%d\n", i);
	return 0;
}
