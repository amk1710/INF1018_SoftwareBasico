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

void valor_i(int n, char* str)
{
	strcpy(str, "            ");
	if( strlen(str) != 12) return;
	int i=0;
	unsigned int z = zigzag_i(n);
	unsigned short s;
	while(z!=0)
	{
		s = z & 0x7F; /* s = ultimos sete bytes de z*/
		z = z >> 7;
		if(z != 0) s = s|0x80;
		str[12] = '\0';
		str[i] = ' ';
		sprintf((str + i*sizeof(char)), "%02x ", s);
		i+=3;
	}
	str[i-1] = '\0';

}


void valor_l(long int n, char* str)
{
	strcpy(str, "                       ");
	if( strlen(str) != 23) return;
	int i=0;
	unsigned long int z = zigzag_l(n);
	unsigned short s;
	while(z!=0)
	{
		s = z & 0x7F; /* s = ultimos sete bits de z*/
		z = z >> 7;
		if(z != 0) s = s|0x80;
		str[23] = '\0';
		str[i] = ' ';
		sprintf((str + i*sizeof(char)), "%02x ", s);
		i+=3;
	}
	str[i-1] = '\0';
}



int grava_i(int* i, FILE* f)
{
	char varint[12];
	fprintf(f, "81 "); /* chave*/
	valor_i(*i, varint);
	fprintf(f,"%s ", varint);
	return 0;
}

int grava_l(long* l, FILE *f)
{
	char varlong[23];
	fprintf(f,"82 "); /* chave*/
	valor_l(*l, varlong);
	fprintf(f, "%s ", varlong);
	return 0;
}

int grava_u_i(int* i, FILE* f)
{
	char varint[12];
	fprintf(f,"01 "); /* chave*/
	valor_i(*i, varint);
	fprintf(f,"%s\n", varint);
	return 0;
}

int grava_u_l(long* l, FILE *f)
{
	char varlong[23];
	fprintf(f, "02 "); /* chave*/
	valor_l(*l, varlong);
	fprintf(f, "%s\n", varlong);
	return 0;
}



int code_errado(char * desc, void* v, FILE* f)
{
	void *p = v;
	int len = strlen(desc);
	int i;
	fprintf(f, "FF ");
	for(i = 0; i < len;i++)
	{
		if(desc[i] == 'i')
		{
			
			if(i+1 < len && desc[i+1] == 'i')
			{
				grava_i(p, f);
				p += sizeof(int);
				grava_i(p, f);
				i++;
				p+=sizeof(int);
			}
			else if(i+1 < len && desc[i+1] == 'l')
			{
				grava_i(p, f);
				p += sizeof(long);
			}
			else if(i+1 == len)
			{
				grava_u_i(p,f);
			}
		}
		else if(desc[i] == 'l')
		{
			if(i+1 < len)
			{
				grava_l(p, f);
				p+=sizeof(long);
			}
			if(i+1 == len)
			{
				grava_u_l(p,f);
			} 
		}
	}
	return 0;
}




//int decode(FILE* f)
//{
//	char tipo[2];
//	while()
//	{
//		if(fscanf(f, "%s", tipo) == 0) return -1;
//		printf("%d\n", strcmp(tipo, "FF"));
//		if(strcmp(tipo, "FF") != 0) return -1;
//		printf("----------------------------");
//	}
//	return 0;
//}





