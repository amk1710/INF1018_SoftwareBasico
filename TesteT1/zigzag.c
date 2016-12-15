#include <stdio.h>

unsigned int zigzag_i(int i)
{
	unsigned int z = i << 1;
	if(i < 0) z = ~z;
	return z;
}

int main(void)
{
	int i = -2147483648;
	int i2 = 2147483647;
	unsigned u = zigzag_i(i);
	unsigned u2 = zigzag_i(i2);
	printf("%u \n %u \n", u, u2);
	return 0;
}
