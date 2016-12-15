#include <stdio.h>
#include <string.h>
#include "code.h"
#include <math.h>

#include <stdlib.h>


unsigned int zigzag_i(int i)
{
	unsigned int z = i << 1;
	if(i < 0) z = ~z;
	return z;
}

long zigzag_l(long l)
{
	unsigned long z = l << 1;
	if(l<0) z = ~z;
	return z;
}

unsigned int valor_i(int n, FILE* f)   /*grava varint*/
{
	unsigned int z = zigzag_i(n);
	char s;
	while(z!=0)
	{
		s = z & 0x7F;
		z = z >> 7;
		if(z!=0) s = s | 0x80;
		fwrite(&s, 1, 1, f);
	}	
}


void valor_l(long int n, FILE *f) /*grava varlong*/
{
	unsigned long int z = zigzag_l(n);
	char s;
	while(z!=0)
	{
		s = z & 0x7F;
		z = z >> 7;
		if(z!=0) s = s | 0x80;
		fwrite(&s, 1, 1, f);
	}	
}



int grava_i(int* i, FILE* f)
{
	char chave = 0x81;
	fwrite(&chave, 1, 1, f);	
	valor_i(i, f);
	return 0;
}

int grava_l(long l, FILE *f)
{
	char chave = 0x82;
	fwrite(&chave, 1, 1, f);	
	valor_l(l, f);
	return 0;
}

int grava_u_i(int* i, FILE* f)
{
	char chave = 0x01;
	fwrite(&chave, 1, 1, f);	
	valor_i(i, f);
	return 0;
}

int grava_u_l(long l, FILE *f)
{
	char chave = 0x02;
	fwrite(&chave, 1, 1, f);	
	valor_l(l, f);
	return 0;
}


int main(void)
{
	FILE* fp = fopen("arq.bin", "wb");
	long l = 500;
	char c = 0xFF;
	char c2 = 0xCD;
	char c3 = 0xAB;
	int i = fwrite(&c, 1, 1, fp);
	printf("%d\n", i);
	fwrite(&c2, 1, 1, fp);
	fwrite(&c3, 1, 1, fp);
	grava_l(l, fp);
	fclose(fp);	
	return 0;
}
