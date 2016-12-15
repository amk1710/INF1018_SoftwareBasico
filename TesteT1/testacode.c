#include <stdio.h>
#include <stdlib.h>
#include "code.h"

static char arqdados[] = "DADOS00";
static char arqsaida[] = "SAIDA00";
static char arqok[] = "OK00";
static unsigned char buff[1024];
static char campos[16];

/* preenche a estrutura de teste */
static void preenche_buff(FILE *f) {
  int c, tam = 0;
  unsigned char *pb = buff;
  char *pc = campos;

  while ((c = fgetc(f)) != 'F') {
    if (c == 'i') {
      *pc++ = 'i';
      fscanf(f, "%x", (int *)pb);
      pb += 4;
      tam += 4;
    }
    else if (c == 'l') {
      *pc++ = 'l';
      if (((unsigned long)pb) & 0x07) {
        pb += 4;
        tam += 4;
      }
      fscanf(f, "%lx", (long *)pb);
      pb += 8;
      tam += 8;
    }
    else {
     fprintf(stderr, "Erro no arquivo de teste! (%c)\n", c);
     exit(1);
    }
    fgetc(f); /* para limpar o \n */
  }
  fgetc(f); /* para limpar o \n */
  *pc = '\0';
}

/* Compara dois arquivos binarios */
int compara(FILE *arq1, FILE *arq2) {
  unsigned char b1, b2;
  int off = 0;

  while (fread(&b1, 1, 1, arq1) == 1) {
    if (fread(&b2, 1, 1, arq2) != 1) {
      printf("offset %d: fim de arquivo inesperado\n", off);
      return 0;
    }
    if (b1 != b2) {
      printf("offset %d: correto = %02x encontrado = %02x\n", off, b1, b2);
      return 0;
    }
    off++;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  FILE *dadost, *saida, *saidaok;
  int c, i, first, last;
  int ntestes, nok;

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
 
  ntestes = 0;
  nok = 0;
  for (i = first; i <= last; i++) {
    ntestes++;
    sprintf(arqdados, "DADOS%d", i);
    sprintf(arqsaida, "SAIDA%d", i);
    sprintf(arqok, "OK%d", i);
    printf("\nTeste %d (%s -> %s):\n", i, arqdados, arqsaida);
    printf("--------------------------\n");
    
    /* Abre os arquivos */
    if ((dadost = fopen(arqdados, "r")) == NULL) {
      perror(">>> Falha na abertura do arquivo de dados");
      exit(1);
    }
    if ((saida = fopen(arqsaida, "wb")) == NULL) {
      perror(">>> Falha na abertura do arquivo de saida");
      exit(1);
    }
    if ((saidaok = fopen(arqok, "rb")) == NULL) {
      perror(">>> Falha na abertura do arquivo de comparacao");
      exit(1);
    }

    while ((c = fgetc(dadost)) != EOF) {
      /* Lê os dados de teste preenchendo a estrutura correspondente */
      fgetc(dadost); /* para limpar o \n */
      preenche_buff(dadost);

      /* Codifica a estrutura */
      if (code(campos, buff, saida) == -1) {
        printf("Falha na geração do arquivo de saida (%s)...\n",arqsaida);
        exit(1);
      }
    }
    fclose(dadost);
    fclose(saida);
    printf("Comparando com %s -> ", arqok);
    if ((saida = fopen(arqsaida, "rb")) == NULL) {
      perror(">>> Falha na abertura do arquivo de saida");
      exit(1);
    }
    if (compara(saidaok, saida)) {
      printf("ok!\n");
      nok++;
    }
    fclose(saida);
    fclose(saidaok);
  }
  printf("\n>>>>> Numero de testes = %d  Testes corretos = %d\n\n", ntestes, nok);
  return 0;
}
