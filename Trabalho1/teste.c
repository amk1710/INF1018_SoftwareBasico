#include <stdio.h>


#include "code.h"


struct X1 {
  int i0;
  int i1;
  int i2;
} x1 = {500, 0x0010, -23};

struct X2 {
  int i1;
  int l;
  int i2;
  int i3;
  int l2;
  int i4;
  long l3;
} x2 = {500, -50,-23, -17, 677, -43, 12345232147483648};

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
	FILE* fp = fopen("arq.bin", "wb");
	FILE* fd;	
	int n = 0;
	char* c1 = "iii";
	char* c2 = "iiiiiil";
	char* c3 = "iil";
	char* c4 = "i"; 
	code(c1, &x1, fp);
	code(c2, &x2, fp);
	code(c3, &x3, fp);
	code(c4, &teste, fp);
	fclose(fp);
	fd = fopen("arq.bin", "rb");
	decode(fd);
	fclose(fd);
	return 0;
}

