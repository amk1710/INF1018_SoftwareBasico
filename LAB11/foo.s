//terminado como monitor em 2016.2

/*
int foo (int a[], int tam) {
  int i;
  int b[tam];
  for (i = 0; i<tam; i++)
    b[i] = calcula (&(a[i]), tam-i);
  return calcula (b, tam);
}
*/

.text
.globl foo

foo:

pushq %rbp
movq %rsp, %rbp

// %r10 vira o proximo multiplo de 16 que comporta 4*tam
movslq %esi, %r11
movq $0, %r10
shl $2, %r11

ehmult:

cmpq %r11, %r10
JGE fimehmult
addq $16, %r10
JMP ehmult

fimehmult:

//********************

subq %r10, %rsp /* aloca espaço para vetor */ 
sub $32, %rsp   /* aloca espaço para calee-saved's*/
movq %r12, -8(%rbp)
movq %r13, -16(%rbp)
movq %r14, -24(%rbp)
movq %r15, -32(%rbp)

//vetor b comeca em %rsp e termina em %rsp+tam*4

movl %esi, %r13d /* %r13d = tam */
movl $0, %r12d /* i = 0 */
movq %rdi, %r14 /* %r14 = a */

for:
	//fim de for?
	cmpl %r13d, %r12d
	jge fim
	
	
	// b[i] = calcula (&(a[i]), tam-i):
	
		movq %r14, %rdi /* passa a[0] como primeiro parâmetro */
		movslq %r12d, %r15 /* calcula offset = i*4 */
		shl $2, %r15
		addq %r15, %rdi /* soma offset no primeiro parâmetro -> &a[i] */
		movl %r13d, %esi /* parâmetro 2 recebe tam - i */
		subl %r12d, %esi
		
		call calcula
		
		movq %rsp, %r10 /* %r10 = b */
		addq %r15, %r10 /* %r10 += offset */
		movl %eax, (%r10) /* b[i] =  calcula (&(a[i]), tam-i)*/
		
	//incremento
	inc %r12d
	jmp for

fim:

//chama calcula (b, tam);

movq %rsp, %rdi
movl %r13d, %esi

call calcula

movq -8(%rbp) , %r12
movq -16(%rbp), %r13
movq -24(%rbp), %r14
movq -32(%rbp), %r15



//*************
movq %rbp, %rsp
popq %rbp
ret
