#include <stdio.h>

struct X1 {
  long l1;
  int i1;
  int i2;
} x1 = {0xe1e2e3e4e5e6e7e8, 0x01020304, 0xf1f2f3f4};

struct X2 {
  int i1;
  long l1;
  int i2;
} x2 = {0x01020304, 0xe1e2e3e4e5e6e7e8,0xf1f2f3f4};




void dump (void *p, int n) {
  int n2 = n;
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
	printf("%d\n\n", n2);
}

int main(void) {

printf("\nx1:\n");
    dump(&x1, sizeof(x1));
printf("\nx2:\n");
    dump(&x2, sizeof(x2));

  return 0;
}
