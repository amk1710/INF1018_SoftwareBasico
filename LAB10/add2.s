/*
int add2 (struct X *x) {
  if (x == NULL) return 0;
  else return x->val + add2(x->next);
}
*/

.text
.global add

add:

push %rbp
movq %rsp, %rbp
subq $16, %rsp

cmp $0, %rdi
je els
movl (%rdi), %r10d
movl %r10d, 8(%rsp)
movq 8(%rdi), %rdi
call add
movl 8(%rsp), %r10d
addl %r10d, %eax
jmp fim


els:

movl $0, %eax


fim:


movq %rbp, %rsp
popq %rbp
ret


