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
  char p[] = "aa_ _\n_$";
  dump(&p, sizeof(p));
  return 0;
}

