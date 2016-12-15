#include<stdio.h>

unsigned char switch_byte(unsigned char x)
{
	unsigned char m1 = x & 0x0f;
	unsigned char m2 = x & 0xf0;
	m1 <<= 4;
	m2 >>= 4;
	return m1+m2;
}

unsigned char rotate_left(unsigned char x, int n)
{
	unsigned char t1 = x<<n;
	unsigned char t2 = x>>(8-n);
	return t1|t2;
}

int main(void)
{
	unsigned char c1 = switch_byte(0x14);
	unsigned char c2 = rotate_left(0x72,1);
	unsigned char c3 = rotate_left(0xb1,2);
	unsigned char c4 = rotate_left(0x2c,7);
	printf("%2x\n",c1);
	printf("%2x\n",c2);
	printf("%2x\n",c3);
	printf("%2x\n",c4);	
	return 0;
}
