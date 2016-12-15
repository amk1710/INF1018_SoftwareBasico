/*
struct X {
  int vi;
  double vd;
  struct X *next;
};

double pack (struct X *px) {
  double acc = 0;
  while (px != NULL) {
    acc += foo(px->vd, px->vi);
    px = px->next;
  }
  return acc;
}
*/

.text

.globl pack

pack:

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

movq %r12, (%rsp)

movq %rdi, %r12

movl $0, %r10d
cvtsi2sd %r10d, %xmm0

loop:
cmp $0, %r12
je fim
movsd %xmm0, 8(%rsp)
movsd 8(%r12), %xmm0
movl (%r12), %edi
call foo
movsd 8(%rsp), %xmm1
addsd %xmm1, %xmm0
movq 16(%r12), %r10
movq %r10, %r12
jmp loop


fim:

movq (%rsp), %r12

movq %rbp, %rsp
popq %rbp
ret
