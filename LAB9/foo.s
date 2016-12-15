/*
void foo (int a[], int n) {
  int i;
  int s = 0;
  for (i=0; i<n; i++) {
    s += a[i];
    if (a[i] == 0) {
      a[i] = s;
      s = 0;
    }
  }
}
*/

.text
.global foo

foo:

pushq %rbp
movq %rsp, %rbp

movl $0, %r10d
movq $0, %r11

loop:

cmp %r11d, %esi
jle fim


movslq %r11d,%r8
shlq $2, %r8
addq %rdi, %r8 

addl (%r8), %r10d
cmpl $0,(%r8)
jne els

movl %r10d, (%r8)
movl $0, %r10d

els:

addl $1, %r11d
jmp loop


fim:

movq %rbp, %rsp
pop %rbp
ret
