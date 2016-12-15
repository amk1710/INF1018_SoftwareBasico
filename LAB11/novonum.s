/*
int novonum(void) {
  int minhalocal;
  printf("numero: ");
  scanf("%d",&minhalocal);
  return minhalocal;
}
*/

.text

.globl novonum

Sf: .string "%d"

novonum:

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

movq $Sf, %rdi
leaq -4(%rbp), %rsi
call scanf
movl -4(%rbp), %eax

movq %rbp, %rsp
popq %rbp
ret
