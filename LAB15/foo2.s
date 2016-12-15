/*
int foo (int x) {
  return add(x);
}
*/

.text
.globl foo

foo:

call add
ret
