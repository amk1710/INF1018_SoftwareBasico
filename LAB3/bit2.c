#include<stdio.h>

int odd_ones(unsigned int x)
{
  unsigned int t = 0x01;
  unsigned int c;
  int r = 0;
  do
  {
    c = x & t;
		printf("%08x\n\n",t);
    if((c!=0)) r++;
    t <<= 1;
  } while(t!=0x00);
  printf("r: %d\n",r);
  if ((r & 0x01) == 0)return 0;
	else return r;
}

int main(void)
{
  unsigned int x1 = 0x01010101;
  unsigned int x2 = 0x01030101;
  int p1 = odd_ones(x1);
  int p2 = odd_ones(x2);
  printf("p1:%d\n p2:%d\n",p1,p2);
  return 0;
}
