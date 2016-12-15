.text

.globl myopen, myread, myclose, mywrite

myopen:

movq $2, %rax

movl %edx, tamBufferAberto

//movq %rdi, %rdi

//movq %rsi, %rsi

syscall

ret

myread:

//movl %edi, %edi

//movq %rsi, %rsi

movl tamBufferAberto, %edx

movq $0, %rax

syscall
ret

myclose:

movq $3, %rax

//movl %edi, %edi

syscall
ret

mywrite:

movq $1, %rax
syscall
ret




