/*
struct X1 {
  int vi;
  float vf;
};

double pack1 (struct X1 *px, int n) {
  double acc = 0;
  int i;
  for (i=0;i<n;i++)
    acc += foo(px[i].vf, px[i].vi);
  return acc;
}
*/

.text

.globl pack1

pack1:

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp


movq %r12, (%rsp)
movq %r13, 8(%rsp)
movq %r14, 16(%rsp)


movl $0, %r10d
cvtsi2sd %r10d, %xmm0
movsd %xmm0, 24(%rsp)

movq %rdi, %r12 /* *px */
movl %esi, %r13d /* n */
movl $0, %r14d /* i */


loop:

movl %r14d, %r11d
cmp %r11d, %r13d /* compara n com i */
jle fim
movslq %r14d, %r10
shl $3, %r10
addq %r12, %r10
movl (%r10), %edi
movss 4(%r10), %xmm0
cvtss2sd %xmm0, %xmm0
call foo
addsd 24(%rsp), %xmm0
movsd %xmm0, 24(%rsp)
addl $1, %r14d
jmp loop


fim:


movq (%rsp), %r12
movq 8(%rsp), %r13
movq 16(%rsp), %r14

movq %rbp, %rsp
popq %rbp
ret
