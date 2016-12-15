#include <stdio.h>
#include <stdlib.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}


int main (void) {
  short s = 0x0A0B;
  dump(&s, sizeof(s));
  return 0;
}

