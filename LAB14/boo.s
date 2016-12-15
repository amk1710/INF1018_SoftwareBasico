/*
double boo (double v) {
  int a1[4] = {1,2,3,4};
  double a2[4];
  int i;

  fooe(a1, a2, 4);
  for (i = 0; i < 4; i++)
	{
		v += a2[i];
	}
  return v;
}
*/

.text

.globl boo

boo:

pushq %rbp
movq %rsp, %rbp
subq $64, %rsp


movl $1, (%rsp)
movl $2, 4(%rsp)
movl $3, 8(%rsp)
movl $4, 12(%rsp)

movsd %xmm0, 48(%rsp)

movq %rsp, %rdi
movq %rsp, %rsi
addq $16, %rsi

movl $4, %edx

call fooe

movl $0, %r10d
movsd 48(%rsp), %xmm0
movq %rsp, %rdi
addq $16, %rdi

loop:

cmp $4, %r10d
jge fim

movq %rdi, %rsi
movslq %r10d, %r11
shl $3, %r11
addq %r11, %rsi

addsd (%rsi), %xmm0

addl $1, %r10d

jmp loop

fim:

movq %rbp, %rsp
popq %rbp
ret








