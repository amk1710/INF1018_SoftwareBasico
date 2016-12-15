/*
struct X {
  int val;
  struct X *next;
};

int add (struct X *x) {
  int a = 0;
  for (; x != NULL; x = x->next)
    a += x->val;
  return a;
}
*/

.text

.global add

add:

pushq %rbp
movq %rsp, %rbp

movl $0, %eax

loop:

cmp $0, %rdi
je fim

addl (%rdi), %eax
addq $8, %rdi
movq (%rdi), %rdi
jmp loop



fim:

movq %rbp, %rsp
popq %rbp
ret


