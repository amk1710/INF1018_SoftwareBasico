#include <stdio.h>
unsigned int a(unsigned int x)
{
  unsigned int a = x&0xFF;
  return a;
}
unsigned int b(unsigned int x)
{
  unsigned int b = x|0x000000FF;
  return b;
}
int main(void) {
  unsigned int x = 0x87654321;
  unsigned int y, z;

  /* o byte menos significativo de x e os outros bits em 0 */
  y = a(x);

  /* o byte menos significativo com todos os bits em '1' 
     e os outros bytes com o mesmo valor dos bytes de x */
  z = b(x);

  printf("%08x %08x\n", y, z);
}


