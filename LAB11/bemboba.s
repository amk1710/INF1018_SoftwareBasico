/*
int bemboba (int num) {
  int local[4];
  int *a;
  int i;

  for (i=0,a=local;i<4;i++) {
    *a = num;
    a++;
  }
  return addl (local, 4);
}
*/

.text

.globl bemboba

bemboba:

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

movl $0,%r10d
leaq -16(%rbp), %r9

loop:
cmp $4, %r10d
jge fim
movl %edi, (%r9)
addq $4, %r9
addl $1, %r10d
JMP loop

fim:
leaq -16(%rbp), %rdi
movl $4, %esi
call addl

movq %rbp, %rsp
popq %rbp
ret
