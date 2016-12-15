/*

int f (int x) { return x+2; }

void map2 (int* um, int * outro, int n) {
  int i;
  for (i=0; i<n; i++)
    *(outro+i) = f(*(um+i));
}

*/

.text
.global map2

f:
push %rbp
movq %rsp, %rbp

addl $2, %edi
movl %edi, %eax

movq %rbp, %rsp
pop %rbp
ret



map2:

push %rbp
movq %rsp, %rbp

subq $32, %rsp
movq %rbx, -32(%rbp)
movq %r12, -24(%rbp)
movq %r13, -16(%rbp)
movq %r14, -8(%rbp)

movl $0, %r12d
movq %rdi, %rbx
movq %rsi, %r13
movl %edx, %r14d

loop:

cmp %r14d, %r12d
jge fim
movl (%rbx), %edi
call f
movl %eax, (%r13)
addl $1, %r12d
addq $4, %rbx
addq $4, %r13
jmp loop



fim:

movq -32(%rbp), %rbx
movq -24(%rbp), %r12
movq -16(%rbp), %r13
movq -8(%rbp), %r14

movq %rbp, %rsp
pop %rbp
ret
