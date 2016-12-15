 /*
#include <stdio.h>
#define LIM 1

int filtro(int x, int lim);

int nums[5] = {3,-5,7,8,-2};

int main() {
  int i;
  int *p = nums;
  for (i = 0; i < 5; i++) {
    printf("%d\n", filtro(*p,LIM));
    p++;
  }
  return 0;
}
*/



 .data
  nums: .int 3, -5, 7, 8, -2
  s1:   .string " %d\n"

  .text
  .globl main
  main:
  /* prologo */
     pushq %rbp
     movq  %rsp, %rbp
     subq  $16, %rsp
     movq  %rbx, -8(%rbp)
     movq  %r12, -16(%rbp)

  /* coloque seu codigo aqui */
	movq $nums, %r12
	movl $0, %ebx
	
L1:
	cmp $5, %ebx
	jge L2
	movl (%r12), %edi
	movl $1, %esi
	call filtro
	movq $s1, %rdi
	movl %eax, %esi
	call printf
	addq $4, %r12
	addl $1, %ebx
	jmp L1
	

L2:

  /* finalizacao */
     movq -8(%rbp), %rbx
     movq -16(%rbp), %r12
     leave
     ret
