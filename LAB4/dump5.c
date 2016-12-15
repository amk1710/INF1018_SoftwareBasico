#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  signed char sc_positivo = 3;
  unsigned int ui_positivo = sc_positivo;
  signed char sc_negativo = -1;
  unsigned int ui_negativo = sc_negativo;
  printf("sc_positivo=%d, ui_positivo=%u \n", sc_positivo, ui_positivo);
  printf("dump de sc_positivo: \n");
  dump(&sc_positivo, sizeof(sc_positivo));
  printf("dump de ui_positivo: \n");
  dump(&ui_positivo, sizeof(ui_positivo));

  printf("sc_negativo=%d, ui_negativo=%u \n", sc_negativo, ui_negativo);
  printf("dump de sc_negativo: \n");
  dump(&sc_negativo, sizeof(sc_negativo));
  printf("dump de ui_negativo: \n");
  dump(&ui_negativo, sizeof(ui_negativo));
  return 0;
}
