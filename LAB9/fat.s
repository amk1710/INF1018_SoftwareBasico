/*
int fat (int n) {
  if (n==0) return 1;
  else return n*fat(n-1);
}
*/
.text
.global fat

fat:

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp
movq %rbx, -8(%rbp)

cmp $0, %edi
jne els
movl $1, %eax 
jmp fim

els:
movl %edi, %ebx
subl $1, %edi
call fat
imull %ebx, %eax


fim:

movq -8(%rbp), %rbx
movq %rbp, %rsp
popq %rbp
ret
