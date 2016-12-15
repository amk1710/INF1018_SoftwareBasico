/*
int add (int a, int b, int c) {
  return a+b+c;
}
*/

.text
.global add

add:

pushq %rbp
movq %rsp, %rbp


addl %esi, %edi
addl %edx, %edi
movl %edi, %eax


movq %rbp, %rsp
popq %rbp
ret

