/*
double foo3 (double *a, int n) {
  int i;
  double r = 0.0;
  for (i=0; i<n; i++) {
    r += sin(*a);
    a++;
  }
  return r;
}
*/

.text

.globl foo3

foo3:

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

movq %r12, (%rsp)
movq %r13, 8(%rsp)
movq %r14, 16(%rsp)

movq %rdi, %r12 /*  double *a */
movl %esi, %r13d /*  int n */
movl $0, %r14d

movl $0, %r10d
cvtsi2sd %r10d, %xmm0
movsd %xmm0, 24(%rsp)


loop:

cmp %r13d, %r14d
jge fim
movsd (%r12), %xmm0
call sin
movsd 24(%rsp), %xmm1
addsd %xmm1, %xmm0
movsd %xmm0, 24(%rsp)
addl $1, %r14d
addq $8, %r12
jmp loop

fim:

movsd 24(%rsp), %xmm0

movq (%rsp), %r12
movq 8(%rsp), %r13
movq 16(%rsp), %r14

movq %rbp, %rsp
popq %rbp
ret
