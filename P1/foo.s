/*
int foo (int *v1, int n) {
int s = 0;
int i;
for (i=0;i<n;i++) {
if ((v1[i] < 0) || (v1[i] > i))
s += v1[i];
}
return s;
}
*/

.text
.global foo

foo:

pushq %rbp
movq %rsp, %rbp

movl $0, %eax
movl $0, %r10d

loop:

cmp %r10d, %esi
jge fim

cmp $0, (%rax)
jmp faz
cmp (%rax), %r10d
jmp faz

volta:
inc %r10d
addq $4, %rax
jmp loop

faz:
addl (%rax), %eax
jmp volta







fim:

movq %rbp, %rsp
popq %rbp
ret
