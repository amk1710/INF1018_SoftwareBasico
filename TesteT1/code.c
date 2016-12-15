/* André Mazal Krauss 1410386, 3WB professora Ana */


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

unsigned long zigzag_l(long l)
{
	unsigned long z = l << 1;
	if(l<0) z = ~z;
	return z;
}

void valor_i(int n, FILE* f)   /*grava varint*/
{
	unsigned int z = zigzag_i(n);
	char s;
	if(z == 0)
	{
		s = 0;
		fwrite(&s, 1, 1,f);
	}
	while(z!=0)
	{
		s = z & 0x7F; /* s recebe os ultimos 7 bits de z*/
		z = z >> 7;   /* "anda" z para a direita 7 bits, os que já estão em s*/
		if(z!=0) s = s | 0x80; 
		/* se z!=0, ainda ha mais valor a ser gravado, e isso é indicado com o bit*/
		fwrite(&s, 1, 1, f);
	}	
}


void valor_l(long n, FILE *f) /*grava varlong. Processo analogo a varint*/
{
	unsigned long  z = zigzag_l(n);
	char s;if(z == 0)
	{
		s = 0;
		fwrite(&s, 1, 1,f);
	}
	while(z!=0)
	{
		s = z & 0x7F;
		z = z >> 7;
		if(z!=0) s = s | 0x80;
		fwrite(&s, 1, 1, f);
	}	
}



int grava_i(int *i, FILE* f)
{
	char chave = 0x81; /* chave para inteiros*/
	fwrite(&chave, 1, 1, f);	
	valor_i(*i, f); /*funcao que obtem e grava o varint */
	return 0;
}

int grava_l(long *l, FILE *f)
{
	char chave = 0x82; /* chave para longs*/
	fwrite(&chave, 1, 1, f);	
	valor_l(*l, f); /*funcao que obtem e grava o varlong */
	return 0;
}

int grava_u_i(int *i, FILE* f) /* grava um inteiro que é o ultimo da estrutura. Mesmo processo, outra chave*/
{
	char chave = 0x01;
	fwrite(&chave, 1, 1, f);	
	valor_i(*i, f);
	return 0;
}

int grava_u_l(long *l, FILE *f) /* analogo a grava_u_i*/
{
	char chave = 0x02;
	fwrite(&chave, 1, 1, f);	
	valor_l(*l, f);
	return 0;
}

int code(char * desc, void* v, FILE* f)
{
	void *p = v;
	int len = strlen(desc);
	int i;
	char inicio = 0xFF;
	fwrite(&inicio, 1,1,f); /* inicio da estrutura*/
	for(i = 0; i < len;i++)
	{
		if(desc[i] == 'i')
		{
			
			if(i+1 == len)
			{
				grava_u_i(p,f);
			}
			else
			{
				grava_i(p,f);
				p+= sizeof(int);
			}
		}
		else if(desc[i] == 'l')
		{
			if((unsigned long)p % 8 != 0) p+=sizeof(int);
			if(i + 1 == len)
			{
				grava_u_l(p,f);
			}
			else
			{
				grava_l(p,f);
				p+= sizeof(long);
			}
		}
	}
	return 0;
}


int deszigzag_i(unsigned int z)
{
	int n = z >>  1;
  	if (z & 0x01){/* negativos sempre mapeados para impares! */
    		n = ~n;
    	}
    	return n;
}

long deszigzag_l(unsigned long z)
{
	long n = z >>  1;
  	if (z & 0x01){ /* negativos sempre mapeados para impares! */
    		n = ~n;
    	}
    	return n;
}

void dec_int(unsigned char* buffer, int *i) /*  recebe o buffer e o contador i na posicao de um varint. os grava e soma de acordo no contador*/
{
	int cont = 0;
	unsigned int valor = 0;
	int temp;
	printf("<int> ");
	while(buffer[*i] & (unsigned char)0x80) /* ve se naquele char esta setado o bit que indica que nao eh o ultimo byte. enquanto nao eh o ultimo, vai somando*/
	{
		temp = buffer[*i]&(unsigned char) 0x7F; /* temp recebe o byte no buffer, mas o bit que indica que ha outros bytes e mudado pra 0 */
		temp = temp << cont*7; /* desloca 7*o numero de bytes ja lidos */
		valor+=temp;
		*i = *i +1;
		cont++;
	}
	temp = buffer[*i]&(unsigned char) 0x7F; /* somando o ultimo byte*/
	temp = temp << cont*7;
	*i = *i+1;
	valor+=temp;
	valor = deszigzag_i(valor);
	printf("%d\n", valor);
		
}

void dec_long(unsigned char* buffer, int *i) /* processo analogo a dec_int*/
{
	int cont = 0;
	long valor = 0;
	long temp;
	printf("<long> ");
	while(buffer[*i] & (unsigned char)0x80)
	{
		temp = buffer[*i]&(unsigned char) 0x7F;
		temp = temp << cont*7;
		valor+=temp;
		*i = *i +1;
		cont++;
	}
	temp = buffer[*i]&(unsigned char) 0x7F;
	temp = temp << cont*7;
	*i = *i+1;
	valor+=temp;
	valor = deszigzag_l(valor);
	printf("%ld\n", valor);
}

int decode (FILE *f)
{
	int fTam;
	unsigned char *buffer;
	int lidos;
	int i = 0;
	int a = 1; /* num da struct*/
	
	// le todo o arquivo e o armazena no buffer
	fseek(f, 0, SEEK_END);
	fTam = ftell(f);
	rewind(f);
	buffer = (unsigned char*) malloc(sizeof(char)*fTam);
	if(buffer == NULL) return -1;
	lidos = fread(buffer, 1, fTam, f);
	if(lidos != fTam) return -1;
	
	
	while(i < fTam && buffer[i] == (unsigned char)0xff) /* enquanto ve que ha outra struct, continua*/
	{
		printf("-----------------------------------------\n");
		printf("%d: \n", a); /* num da struct*/
		a++;
		i++;
		while(buffer[i] != (unsigned char) 0x01 && buffer[i] != (unsigned char) 0x02) /* enquanto nao chega na ultima variavel na struct, chama de acordo as funcoes de descodificar int ou long*/
		{
			if(buffer[i] == (unsigned char) 0x81) 
			{
				i++;
				dec_int(buffer, &i);
			}
			else if(buffer[i] == (unsigned char) 0x82)
			{
				i++;
				dec_long(buffer, &i);
			}
			
		}
		// ultimos da struct
		if(buffer[i] == (unsigned char)0x01)
		{
			i++;
			dec_int(buffer, &i);
		}
		else if(buffer[i] == (unsigned char)0x02)
		{
			i++;
			dec_long(buffer, &i);
		}
	}
	return 0;
}


