/*
#include <stdio.h>
int nums[] = {10, -21, -30, 45};
int main() {
  int i, *p;
  for (i = 0, p = nums; i != 4; i++, p++)
    if (((*p % 2) == 0) && (*p > 0))
      printf("%d\n", *p);
  return 0;
}
*/

.data
nums:    .int 10, -21, -30, 45

Sf:  .string "%d\n"    /* primeira string de formato para printf */

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/

	movl $0, %ebx
	movq $nums, %r12
	
L1:

	testl $0x01,(%r12)
	jne L2
	movl (%r12), %ecx
	cmpl $0x00, %ecx
	jg L2
	movl (%r12), %eax
	
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */


L2:

	addl $1, %ebx
	addq $4, %r12


/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
/***************************************************************/


