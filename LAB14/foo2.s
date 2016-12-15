/*
double foo2 (float a, float b) {
  return sin(a) + cos(b);
}
*/

.text

.globl foo2

foo2:

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

cvtss2sd %xmm0, %xmm0
cvtss2sd %xmm1, %xmm1

movsd %xmm1, (%rsp)
call sin
movsd %xmm0, 8(%rsp)
movsd (%rsp), %xmm0
call cos
addsd 8(%rsp), %xmm0

movq %rbp, %rsp
popq %rbp
ret
