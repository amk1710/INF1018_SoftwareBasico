/*

#include <stdio.h>
#include "dados.h"

int main() {
  int i;
  St *p = dados;
  int max = 0;
  for (i = 0; i <3; i++) {
     if (p->cc && p->ci > max)
       max = p->ci;
     p++;
  }
  printf("%d\n",max);
  return 0;
}
*/



.data
Sf:  .string "%d\n"    # string de formato para printf

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/********************************************************/

	movl $0x00, %r10d
	movl $0x00, %eax
	movq $dados, %r12

L1:
	cmpl $3, %r10d
	jge L3
	
	
	movq %r12, %r13
	cmpb $1,(%r13)
	jne L2
	addq $4, %r13
	cmpl %eax, (%r13)
	jle L2
	movl (%r13), %eax

L2:

	addq $8, %r12
	addl $1, %r10d
	jmp L1

L3:


/*************************************************************/
/* este trecho imprime o valor de %rax (estraga %rax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl   $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/


/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret      
/***************************************************************/

