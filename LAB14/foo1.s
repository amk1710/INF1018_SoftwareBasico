/*
float foo1 (float a, float b) {
  return sin(a) + b;
}
*/

.text
.globl foo1

foo1:

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp


cvtss2sd %xmm1, %xmm1
cvtss2sd %xmm0, %xmm0

movsd %xmm1, 8(%rsp)

call sin

addsd 8(%rsp), %xmm0

cvtsd2ss %xmm0, %xmm0

movq %rbp, %rsp
popq %rbp
ret
