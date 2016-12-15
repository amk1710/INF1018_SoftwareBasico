#include <stdio.h>
int nums[] = {10, -21, -30, 45};
int main() {
  int i, *p;
  for (i = 0, p = nums; i != 4; i++, p++)
    if (((*p % 2) == 0) && (*p > 0))
      printf("%d\n", *p);
  return 0;
}
