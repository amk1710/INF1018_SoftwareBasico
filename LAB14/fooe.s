/*
void fooe (int a[], double b[], int n) {
  int *pint;
  double *pdouble;

  for (pint = a, pdouble = b; n-- ; pint++, pdouble++) {
    *pdouble = (double)*pint * 2.0;
  }
}
*/

.text

.globl fooe

fooe:

loop:

cmp $0, %edx
je fim

movl (%rdi), %r10d
shl $1, %r10d

cvtsi2sd %r10d, %xmm0

movsd %xmm0, (%rsi)

addq $4, %rdi
addq $8, %rsi
subl $1, %edx

jmp loop


fim:

ret
