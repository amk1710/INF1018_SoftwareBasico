/*
int foo (int x) {
  return x+1;
}
*/

.text
.globl foo
foo:

movl %edi, %eax
addl $1, %eax
ret
