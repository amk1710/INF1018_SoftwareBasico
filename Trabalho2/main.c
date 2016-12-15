#include <stdio.h>
#include <stdlib.h>

typedef int (*funcp) ();

funcp compila (FILE *f);

void libera (void *p);


int main(void)
{

	
//	retorno de constante
	FILE *f = fopen("retc.txt", "r");
	funcp function = compila(f);
	int i = (*function)();
	printf("\n 1? : %d\n", i);
	libera(function);
	fclose(f);

//	retorno de parametro
	f = fopen("retp.txt", "r");
	function = compila(f);
	i = (*function)(10);
	printf("\n 10?: %d\n", i);
	libera(function);
	fclose(f);

//	f(a, b, c) = a*(b + c)
	f = fopen("f.txt", "r");
	function = compila(f);
	i = (*function)(10, 5, 7);
	printf("\n 120?: %d\n", i);
	libera(function);
	fclose(f);

//	maior de tres numeros
	f = fopen("maiorn.txt", "r");
	function = compila(f);
	i = (*function)(10, 2, 7);
	printf("\n 10?: %d\n", i);
	libera(function);
	fclose(f);

//	fatorial
	f = fopen("fatorial.txt", "r");
	function = compila(f);
	i = (*function)(4);
	printf("\n 24?: %d\n", i);
	libera(function);
	fclose(f);

//	50 linhas
	f = fopen("50l.txt", "r");
	function = compila(f);
	i = (*function)(1);
	printf("\n 50?: %d\n", i);
	libera(function);
	fclose(f);

//	maxsize
	f = fopen("maxsize.txt", "r");
	function = compila(f);
	i = (*function)(-27);
	printf("\n -27?: %d\n", i);
	libera(function);
	fclose(f);

//	teto da distancia ate origem
	f = fopen("d2o.txt", "r");
	function = compila(f);
	i = (*function)(-3, 4);
	printf("\n 5?: %d\n", i);
	libera(function);
	fclose(f);

//	dentro do circulo?
	f = fopen("dentro.txt", "r");
	function = compila(f);
	i = (*function)(0, 0, 1);
	printf("\n 1?: %d\n", i);
	i = (*function)(-1, 0, 0);
	printf("\n 0?: %d\n", i);
	libera(function);
	fclose(f);
//	max jump
	f = fopen("maxjump.txt", "r");
	function = compila(f);
	i = (*function)(7);
	printf("\n 7?: %d\n", i);
	libera(function);
	fclose(f);

// max var
	f = fopen("maxvar.txt", "r");
	function = compila(f);
	i = (*function)(0);
	printf("\n 20?: %d\n", i);
	libera(function);
	fclose(f);

	
	return 0;
}
