#include <ctype.h>
#include <stdio.h>

int string2num (char *s, int b) {
  int a = 0;
  for (; *s; s++)
    a = a*b + (*s - '0');
  return a;
}

int main (void) {
  printf("==> %d\n", string2num("1234", 10));
  printf("==> %d\n", string2num("1234",10) + 1);
  printf("==> %d\n", string2num("1234",10) + string2num("1",10));
  printf("==>%d\n", string2num("777", 8));
  printf("==>%d\n", string2num("777", 10));
  return 0;
}
