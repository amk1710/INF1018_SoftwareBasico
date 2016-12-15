#include <stdio.h>

unsigned char codigo[6] = {0xe8, 0x00, 0x00, 0x00, 0x00, 0xc3};

typedef int (*funcp) (int x);

int add (int x) {
  return x+1;
}

int main(void)
{
	int i;
	funcp f = (funcp)codigo;
	long int p = (long int)&add;
	p -= (long int)&codigo[5];
	codigo[1] = (unsigned char) p;
	codigo[2] = (unsigned char) (p >> 8);
	codigo[3] = (unsigned char) (p >> 16);
	codigo[4] = (unsigned char) (p >> 24);
	i = (*f)(10);
	printf("%d\n", i);
	return 0;
}
