#include <stdio.h>
#include <stdlib.h>
#include "code.h"

static char arqok[] = "TD00";
static char mostraok[] = "SD00";
static char linha[128];

int main(int argc, char *argv[]) {
  FILE *entrada, *mostra;
  int i, first, last;
  int tam;

  /* Obtém primeiro e último teste */
  if (argc < 3) {
    printf("Uso: %s <primeiro teste> <ultimo teste>\n", argv[0]);
    return 1;
  }
  if ((first = atoi(argv[1])) == 0) {
    printf(">>> Erro em %s: primeiro teste (%s) invalido\n", argv[0], argv[1]);
    return 1;
  }
  if ((last = atoi(argv[2])) == 0) {
    printf(">>> Erro em %s: ultimo teste (%s) invalido\n", argv[0], argv[2]);
    return 1;
  }
  if (first > last) {
    printf(">>> Erro em %s: intervalo de teste (%s-%s) invalido\n", 
            argv[0], argv[1], argv[2]);
    return 1;
  }
 
  for (i = first; i <= last; i++) {
    sprintf(mostraok, "SD%d", i);
    sprintf(arqok, "TD%d", i);
    printf("\n***** Teste %d (%s) *****\n", i, arqok);
    if ((mostra = fopen(mostraok, "r")) == NULL) {
      perror(">>> Falha na abertura do arquivo exemplo\n");
      exit(1);
    }
    if ((entrada = fopen(arqok, "rb")) == NULL) {
      perror(">>> Falha na abertura do arquivo de entrada\n");
      exit(1);
    }
    while ((tam = fread(linha, 1, 128, mostra)) > 0)
      fwrite(linha, 1, tam, stdout);
    printf("\n");
    decode(entrada);
    fclose(entrada);
    fclose(mostra);
  }
  return 0;
}
