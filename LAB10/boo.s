/*
struct X {
  int val1;
  int val2;
};

void boo (struct X *px, int n, int val) {
  while (n--) {
    px->val2 = f(px->val1, val);
    px++;
  }
}


*/

.text
.global boo

boo:

push %rbp
movq %rsp, %rbp
subq $16, %rsp
movq %rbx, -8(%rbp)
movq %r12, -16(%rbp)


movq %rdi, %rbx
movl %esi, %r12d


loop:

cmp $0, %r12d
je fim



movl (%rbx), %edi
movl %edx, %esi
call f
movl %eax, 4(%rbx)
addq $8, %rbx
subl $1, %r12d
jmp loop



fim:

movq -8(%rbp), %rbx
movq -16(%rbp), %r12

movq %rbp, %rsp
pop %rbp
ret
