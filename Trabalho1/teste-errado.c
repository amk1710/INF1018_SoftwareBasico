#include <stdio.h>


#include "code.h"

int code_errado(char * desc, void* v, FILE* f);

struct X1 {
  int i0;
  int i1;
  int i2;
} x1 = {500, 0x0010, -23};

struct X2 {
  int i1;
  long l;
  int i2;
} x2 = {500, -50,-23};

struct X3 {
 	int i1;
 	int i2;
	long l;
  
} x3 = {-23 ,500, -50};

struct t{
	int i1;
} teste = {500};


int main(void)
{
	FILE * ferrado = fopen("arq.txt", "wb");
	int n = 0;
	char* c1 = "iii";
	char* c2 = "ili";
	char* c3 = "iil";
	char* c4 = "i"; 
	code_errado(c1, &x1, ferrado);
	code_errado(c2, &x2, ferrado);
	code_errado(c3, &x3, ferrado);
	code_errado(c4, &teste, ferrado);
	fclose(ferrado);
	//fp = fopen("arq.txt", "rb");
	//decode(fp);
	return 0;
}

