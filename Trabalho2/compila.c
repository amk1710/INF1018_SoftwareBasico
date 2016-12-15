/* André Mazal Krauss 1410386 Prof. Ana */


#include <stdlib.h>
#include <stdio.h>


typedef int (*funcp) ();

static int pos = 0;
//a posição do vetor de unsigned char que será a função.


union intchar{
	int i;
	unsigned char c[4];
};
typedef union intchar Intchar; /* usado para usar pedaços de inteiros em comandos */


static int ses[50]; /* usado para guardar as posições no vetor area dos if's que nao foram tratados no primeiro momento */

static int alocada[20]; /* usado para informar quais variaveis devem ser alocadas na pilha */

static int posdalinha[50]; /* usado para guardar em que posição do vetor começa cada linha do programa */


static void varpc1_2_r10d(char *varpc, unsigned char *area){ /* move varpc1 para r10d */
	Intchar constante;
	int varnum;
	switch(varpc[0]){
		case '$': /* constante */
			constante.i = atoi(&varpc[1]);
			area[pos] = 0x41;	 /* movl para %r10d */
			area[pos+1] = 0xba;
			area[pos+2] = constante.c[0];
			area[pos+3] = constante.c[1];
			area[pos+4] = constante.c[2];
			area[pos+5] = constante.c[3];
			pos += 6;
			break;	
		case 'v': /* variavel local */
			//      movl -((varnum+1)*4)(%rbp), %r10d
			varnum = atoi(&varpc[1]);
			area[pos] = 0x44;
			area[pos+1] = 0x8b;
			area[pos+2] = 0x55;
			area[pos+3] = (unsigned char)(0x100 - (varnum+1)*4);
			pos += 4;
			break;

		case 'p': /* parametro */
			// movl de %edi, %esi ou %edx para %r10d
			area[pos] = 0x41;
			area[pos+1] = 0x89;
			switch(varpc[1]){
				case '0':
					area[pos+2] = 0xfa;
					break;
				case '1':
					area[pos+2] = 0xf2;
					break;
				case '2':
					area[pos+2] = 0xd2;
					break;
			}
			pos += 3;
			break;
	}		
	return;
}

static void varpc2_2_r11d(char *varpc, unsigned char *area){ /* move varpc2 para r11d */
	Intchar constante;
	int varnum;
	switch(varpc[0]){
		case '$': /* constante */
			constante.i = atoi(&varpc[1]);
			area[pos] = 0x41;	 /* movl para %r11d */
			area[pos+1] = 0xbb;
			area[pos+2] = constante.c[0];
			area[pos+3] = constante.c[1];
			area[pos+4] = constante.c[2];
			area[pos+5] = constante.c[3];
			pos += 6;
			break;	
		case 'v': /* variavel local */
			//      movl -((varnum+1)*4)(%rbp), %r11d
			varnum = atoi(&varpc[1]);
			area[pos] = 0x44;
			area[pos+1] = 0x8b;
			area[pos+2] = 0x5d;
			area[pos+3] = (unsigned char)(0x100 - (varnum+1)*4);
			pos += 4;
			break;

		case 'p': /* parametro */
			// movl de %edi, %esi ou %edx para %r11d
			area[pos] = 0x41;
			area[pos+1] = 0x89;
			switch(varpc[1]){
				case '0':
					area[pos+2] = 0xfb;
					break;
				case '1':
					area[pos+2] = 0xf3;
					break;
				case '2':
					area[pos+2] = 0xd3;
					break;
			}
			pos += 3;
			break;
	}		
	return;
}



static void retorno(char *varpc, unsigned char* area){
	Intchar constante;
	int varnum;
	switch(varpc[0]){
		case '$': /* constante */
			constante.i = atoi(&varpc[1]);
			area[pos] = 0xb8;	 /* movl para %eax */
			area[pos+1] = constante.c[0];
			area[pos+2] = constante.c[1];
			area[pos+3] = constante.c[2];
			area[pos+4] = constante.c[3];
			pos += 5;
			break;	
		case 'v': /* variavel local */
		//      movl -((varnum+1)*4)(%rbp), %eax
			varnum = atoi(&varpc[1]);
			area[pos] = 0x8b;
			area[pos+1] = 0x45;
			area[pos+2] = (unsigned char)(0x100 - (varnum+1)*4); /* posição da variavel na pilha é -(4*n)(%rbp) */
			pos += 3;
			break;

		case 'p': /* parametro */
			area[pos] = 0x89; /* movl ___, %eax */
			switch(varpc[1]){
				case '0': /* edi */
					area[pos+1] = 0xf8;
					break;
				case '1': /* esi */
					area[pos+1] = 0xf0;
					break;
				case '2': /* edx */
					area[pos+1] = 0xd0;
					break;
			}
			pos += 2;
			break;
	}
	
	/* desaloca a pilha */
	area[pos] = 0x48;
	area[pos+1] = 0x89;
	area[pos+2] = 0xec;
	area[pos+3] = 0x5d;
	pos += 4;
	
	area[pos] = 0xc3; /* ret */
	pos += 1;		
	return;	
}

static void atribuicao(char *var, char * varpc1, char op, char *varpc2, unsigned char* area){
	
	int varnum = atoi(&var[1]);
	
	alocada[varnum] = 1;
	
	varpc1_2_r10d(varpc1, area); /* move varpc1 para %r10d */
	varpc2_2_r11d(varpc2, area); /* move varpc2 para %r11d */	
	switch(op){
		case '+': /* %r10d += %r11d */
			area[pos] = 0x45;
			area[pos+1] = 0x01;
			area[pos+2] = 0xda;
			pos += 3;
			break;
		case '-': /* %r10d -= %r11d */
			area[pos] = 0x45;
			area[pos+1] = 0x29;
			area[pos+2] = 0xda;
			pos += 3;
			break;
		case '*': /* %r10d *= %r11d */
			area[pos] = 0x45;
			area[pos+1] = 0x0f;
			area[pos+2] = 0xaf;
			area[pos+3] = 0xd3;
			pos += 4;
			break;
	}
	// move %r10d para variavel
	
	area[pos] = 0x44;
	area[pos+1] = 0x89;
	area[pos+2] = 0x55;
	area[pos+3] = (unsigned char)(0x100 - (varnum+1)*4);
	pos += 4; 

	return;
}


// função se recebe uma instrução if e a posição que ela começa no vetor. Os if's ocupam sempre o mesmo tamanho no vetor para programas de até 50 linhas, o que permite que sua construção seja adiada até o resto do programa ser construído. Isso foi necessário porque as demais instruções ocupam números variáveis de posições no vetor.
static void se(char *var, int n1, int n2, int n3, unsigned char *area, int tpos){
	int varnum;
	Intchar descn1; 
	Intchar descn2;
	Intchar descn3; /* deslocamentos para linhas n1, n2 e n3 */
	
	//movl -((varnum+1)*4)(%rbp), %r10d
	
	varnum = atoi(&var[1]);	
	
	area[tpos] = 0x44;
	area[tpos+1] = 0x8b;
	area[tpos+2] = 0x55;
	area[tpos+3] = (unsigned char)(0x100 - (varnum+1)*4);
	tpos += 4;
	//********
	

	// os offsets para cada linha para que deve ser desviado o fluxo. Offset = posdalinha(posdalinha[n - 1] - a posiçao em que está o if(tpos + n) - tamanho da instrução if(6).
	descn1.i = posdalinha[n1-1] - (tpos + 10) -6;
	descn2.i = posdalinha[n2-1] - (tpos + 16) -6;
	descn3.i = posdalinha[n3-1] - (tpos + 4) -6; 
		
	//cmp $0, %r10d
	area[tpos] = 0x41;
	area[tpos+1] = 0x83;
	area[tpos+2] = 0xfa;
	area[tpos+3] = 0x00;
	
	//jg para n3
	area[tpos+4] = 0x0f;
	area[tpos+5] = 0x8f;
	area[tpos+6] = descn3.c[0];
	area[tpos+7] = descn3.c[1];
	area[tpos+8] = descn3.c[2];
	area[tpos+9] = descn3.c[3];
	
	//jl para n1	
	area[tpos+10] = 0x0f;
	area[tpos+11] = 0x8c;
	area[tpos+12] = descn1.c[0];
	area[tpos+13] = descn1.c[1];
	area[tpos+14] = descn1.c[2];
	area[tpos+15] = descn1.c[3];
	
	
	//je para n2	
	area[tpos+16] = 0x0f;
	area[tpos+17] = 0x84;
	area[tpos+18] = descn2.c[0];
	area[tpos+19] = descn2.c[1];
	area[tpos+20] = descn2.c[2];
	area[tpos+21] = descn2.c[3];
	
	tpos += 22;
	
	
	
	return;
}




funcp compila (FILE *f)
{
	funcp funcao;
	char cmd[4]; /* recebe comandos sb */
	char varpc1[12]; /* 12 = número de digitos de maxint + '\n' + '$' */
	char varpc2[12];
	char op; /* recebe um operador */
	int tpos; /* usado para voltar no vetor de char sem perder pos */
	int n1, n2, n3; /* as linhas para onde se desvia o fluxo em um if */
	int nlinhas;
	int retornoleitura;
	Intchar bvar; /* usado para calcular os bytes necessários para variaveis usadas */
	int protelado; /* numero de if's protelados */
	unsigned char *area = (unsigned char*) malloc(1300 * sizeof(unsigned char));
// 1300 = 50 * 26.  26 é o número de posições necessárias para a maior instrução, um if. 50 é o número máximo de linhas.
	for(nlinhas = 0; nlinhas < 20; nlinhas++) { alocada[nlinhas] = 0; }
	for(nlinhas = 0; nlinhas < 50; nlinhas++) { ses[nlinhas] = -1; }
	pos = 0;
	nlinhas = 0;
	protelado = 0;	
	//inicialização
	area[0] = 0x55; /* pushq %rbp */
	area[1] = 0x48; /* movq %rsp, %rbp */
	area[2] = 0x89;
	area[3] = 0xe5; /* */
	area[4] = 0x48; /* sub $x, %rsp */
	area[5] = 0x83;
	area[6] = 0xec;
	area[7] = 0x00; /* será mudado depois para o valor correto conforme o número de variáveis usadas */
	
	pos += 8;
	
	retornoleitura = fscanf(f, "%s", cmd);
	
	while(retornoleitura != EOF && nlinhas <= 50){
		switch(cmd[0]){
			case 'r': /* retorno */
				posdalinha[nlinhas] = pos;
				fscanf(f, "%s", varpc1);
				retorno(varpc1, area);
				
				nlinhas++;
				break;
			case 'v': /* atribuição */
				posdalinha[nlinhas] = pos;
				fscanf(f, "%s", varpc1); /* lê o '=' */
				fscanf(f, "%s %c %s", varpc1, &op, varpc2);
				atribuicao(cmd, varpc1, op, varpc2, area);
				nlinhas++;
				break;
			case 'i': /* if */
				
				posdalinha[nlinhas] = pos;
				ses[protelado] = pos;
				fscanf(f, "%s %d %d %d", varpc1, &n1, &n2, &n3);
				
				pos += 26; /* tamanho do comando if */
				protelado++;
				nlinhas++;
				break;
			default: /* comando não reconhecido */
				printf("Comando não reconhecido %s na linha %d \n", cmd, nlinhas);

		}
		retornoleitura = fscanf(f, "%s", cmd);
	}
	rewind(f);
	fscanf(f, "%s", cmd);
	protelado = 0;
	
	// corrige os if's
	while(ses[protelado] != -1){
		while(cmd[0] != 'i'){
			fscanf(f, "%s", cmd);
		}
		fscanf(f, "%s %d %d %d", varpc1, &n1, &n2, &n3);
		fscanf(f, "%s", cmd);
		tpos = ses[protelado];
		protelado++;
		se(varpc1, n1, n2, n3, area, tpos);
	}
	
	// corrige o sub $0, %rsp
	
	for(bvar.i = 20; bvar.i > 0 && alocada[bvar.i] != 1; bvar.i = bvar.i - 1){
	
	}
	bvar.i = bvar.i * 4;
	
	while(bvar.i % 16 != 0){
		bvar.i = bvar.i + 4;
	}
		
	area[7] = bvar.c[0];
	
	//****
	
	area = realloc(area, (pos-1)*sizeof(unsigned char)); /* muda o tamanho da memoria alocada para o tamanho necessário */
	funcao = (funcp)area;
	return funcao;
}



void libera (void *p)
{
	free(p);
}
