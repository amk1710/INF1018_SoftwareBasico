
bufbomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000400578 <_init>:
  400578:	48 83 ec 08          	sub    $0x8,%rsp
  40057c:	48 8b 05 75 1a 20 00 	mov    0x201a75(%rip),%rax        # 601ff8 <_DYNAMIC+0x1d0>
  400583:	48 85 c0             	test   %rax,%rax
  400586:	74 05                	je     40058d <_init+0x15>
  400588:	e8 83 00 00 00       	callq  400610 <__gmon_start__@plt>
  40058d:	48 83 c4 08          	add    $0x8,%rsp
  400591:	c3                   	retq   

Disassembly of section .plt:

00000000004005a0 <puts@plt-0x10>:
  4005a0:	ff 35 62 1a 20 00    	pushq  0x201a62(%rip)        # 602008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4005a6:	ff 25 64 1a 20 00    	jmpq   *0x201a64(%rip)        # 602010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4005ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004005b0 <puts@plt>:
  4005b0:	ff 25 62 1a 20 00    	jmpq   *0x201a62(%rip)        # 602018 <_GLOBAL_OFFSET_TABLE_+0x18>
  4005b6:	68 00 00 00 00       	pushq  $0x0
  4005bb:	e9 e0 ff ff ff       	jmpq   4005a0 <_init+0x28>

00000000004005c0 <system@plt>:
  4005c0:	ff 25 5a 1a 20 00    	jmpq   *0x201a5a(%rip)        # 602020 <_GLOBAL_OFFSET_TABLE_+0x20>
  4005c6:	68 01 00 00 00       	pushq  $0x1
  4005cb:	e9 d0 ff ff ff       	jmpq   4005a0 <_init+0x28>

00000000004005d0 <printf@plt>:
  4005d0:	ff 25 52 1a 20 00    	jmpq   *0x201a52(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  4005d6:	68 02 00 00 00       	pushq  $0x2
  4005db:	e9 c0 ff ff ff       	jmpq   4005a0 <_init+0x28>

00000000004005e0 <__libc_start_main@plt>:
  4005e0:	ff 25 4a 1a 20 00    	jmpq   *0x201a4a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  4005e6:	68 03 00 00 00       	pushq  $0x3
  4005eb:	e9 b0 ff ff ff       	jmpq   4005a0 <_init+0x28>

00000000004005f0 <strcmp@plt>:
  4005f0:	ff 25 42 1a 20 00    	jmpq   *0x201a42(%rip)        # 602038 <_GLOBAL_OFFSET_TABLE_+0x38>
  4005f6:	68 04 00 00 00       	pushq  $0x4
  4005fb:	e9 a0 ff ff ff       	jmpq   4005a0 <_init+0x28>

0000000000400600 <signal@plt>:
  400600:	ff 25 3a 1a 20 00    	jmpq   *0x201a3a(%rip)        # 602040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400606:	68 05 00 00 00       	pushq  $0x5
  40060b:	e9 90 ff ff ff       	jmpq   4005a0 <_init+0x28>

0000000000400610 <__gmon_start__@plt>:
  400610:	ff 25 32 1a 20 00    	jmpq   *0x201a32(%rip)        # 602048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400616:	68 06 00 00 00       	pushq  $0x6
  40061b:	e9 80 ff ff ff       	jmpq   4005a0 <_init+0x28>

0000000000400620 <_IO_getc@plt>:
  400620:	ff 25 2a 1a 20 00    	jmpq   *0x201a2a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400626:	68 07 00 00 00       	pushq  $0x7
  40062b:	e9 70 ff ff ff       	jmpq   4005a0 <_init+0x28>

0000000000400630 <exit@plt>:
  400630:	ff 25 22 1a 20 00    	jmpq   *0x201a22(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400636:	68 08 00 00 00       	pushq  $0x8
  40063b:	e9 60 ff ff ff       	jmpq   4005a0 <_init+0x28>

Disassembly of section .text:

0000000000400640 <_start>:
  400640:	31 ed                	xor    %ebp,%ebp
  400642:	49 89 d1             	mov    %rdx,%r9
  400645:	5e                   	pop    %rsi
  400646:	48 89 e2             	mov    %rsp,%rdx
  400649:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40064d:	50                   	push   %rax
  40064e:	54                   	push   %rsp
  40064f:	49 c7 c0 f0 09 40 00 	mov    $0x4009f0,%r8
  400656:	48 c7 c1 80 09 40 00 	mov    $0x400980,%rcx
  40065d:	48 c7 c7 e1 08 40 00 	mov    $0x4008e1,%rdi
  400664:	e8 77 ff ff ff       	callq  4005e0 <__libc_start_main@plt>
  400669:	f4                   	hlt    
  40066a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400670 <deregister_tm_clones>:
  400670:	b8 6f 20 60 00       	mov    $0x60206f,%eax
  400675:	55                   	push   %rbp
  400676:	48 2d 68 20 60 00    	sub    $0x602068,%rax
  40067c:	48 83 f8 0e          	cmp    $0xe,%rax
  400680:	48 89 e5             	mov    %rsp,%rbp
  400683:	76 1b                	jbe    4006a0 <deregister_tm_clones+0x30>
  400685:	b8 00 00 00 00       	mov    $0x0,%eax
  40068a:	48 85 c0             	test   %rax,%rax
  40068d:	74 11                	je     4006a0 <deregister_tm_clones+0x30>
  40068f:	5d                   	pop    %rbp
  400690:	bf 68 20 60 00       	mov    $0x602068,%edi
  400695:	ff e0                	jmpq   *%rax
  400697:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40069e:	00 00 
  4006a0:	5d                   	pop    %rbp
  4006a1:	c3                   	retq   
  4006a2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  4006a9:	1f 84 00 00 00 00 00 

00000000004006b0 <register_tm_clones>:
  4006b0:	be 68 20 60 00       	mov    $0x602068,%esi
  4006b5:	55                   	push   %rbp
  4006b6:	48 81 ee 68 20 60 00 	sub    $0x602068,%rsi
  4006bd:	48 c1 fe 03          	sar    $0x3,%rsi
  4006c1:	48 89 e5             	mov    %rsp,%rbp
  4006c4:	48 89 f0             	mov    %rsi,%rax
  4006c7:	48 c1 e8 3f          	shr    $0x3f,%rax
  4006cb:	48 01 c6             	add    %rax,%rsi
  4006ce:	48 d1 fe             	sar    %rsi
  4006d1:	74 15                	je     4006e8 <register_tm_clones+0x38>
  4006d3:	b8 00 00 00 00       	mov    $0x0,%eax
  4006d8:	48 85 c0             	test   %rax,%rax
  4006db:	74 0b                	je     4006e8 <register_tm_clones+0x38>
  4006dd:	5d                   	pop    %rbp
  4006de:	bf 68 20 60 00       	mov    $0x602068,%edi
  4006e3:	ff e0                	jmpq   *%rax
  4006e5:	0f 1f 00             	nopl   (%rax)
  4006e8:	5d                   	pop    %rbp
  4006e9:	c3                   	retq   
  4006ea:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004006f0 <__do_global_dtors_aux>:
  4006f0:	80 3d 81 19 20 00 00 	cmpb   $0x0,0x201981(%rip)        # 602078 <completed.6940>
  4006f7:	75 11                	jne    40070a <__do_global_dtors_aux+0x1a>
  4006f9:	55                   	push   %rbp
  4006fa:	48 89 e5             	mov    %rsp,%rbp
  4006fd:	e8 6e ff ff ff       	callq  400670 <deregister_tm_clones>
  400702:	5d                   	pop    %rbp
  400703:	c6 05 6e 19 20 00 01 	movb   $0x1,0x20196e(%rip)        # 602078 <completed.6940>
  40070a:	f3 c3                	repz retq 
  40070c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400710 <frame_dummy>:
  400710:	bf 20 1e 60 00       	mov    $0x601e20,%edi
  400715:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400719:	75 05                	jne    400720 <frame_dummy+0x10>
  40071b:	eb 93                	jmp    4006b0 <register_tm_clones>
  40071d:	0f 1f 00             	nopl   (%rax)
  400720:	b8 00 00 00 00       	mov    $0x0,%eax
  400725:	48 85 c0             	test   %rax,%rax
  400728:	74 f1                	je     40071b <frame_dummy+0xb>
  40072a:	55                   	push   %rbp
  40072b:	48 89 e5             	mov    %rsp,%rbp
  40072e:	ff d0                	callq  *%rax
  400730:	5d                   	pop    %rbp
  400731:	e9 7a ff ff ff       	jmpq   4006b0 <register_tm_clones>

0000000000400736 <valid>:
  400736:	55                   	push   %rbp
  400737:	48 89 e5             	mov    %rsp,%rbp
  40073a:	48 83 ec 10          	sub    $0x10,%rsp
  40073e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  400742:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400746:	be 10 0a 40 00       	mov    $0x400a10,%esi
  40074b:	48 89 c7             	mov    %rax,%rdi
  40074e:	e8 9d fe ff ff       	callq  4005f0 <strcmp@plt>
  400753:	85 c0                	test   %eax,%eax
  400755:	0f 94 c0             	sete   %al
  400758:	0f b6 c0             	movzbl %al,%eax
  40075b:	c9                   	leaveq 
  40075c:	c3                   	retq   

000000000040075d <danger>:
  40075d:	55                   	push   %rbp
  40075e:	48 89 e5             	mov    %rsp,%rbp
  400761:	bf 1a 0a 40 00       	mov    $0x400a1a,%edi
  400766:	e8 45 fe ff ff       	callq  4005b0 <puts@plt>
  40076b:	bf 37 0a 40 00       	mov    $0x400a37,%edi
  400770:	e8 4b fe ff ff       	callq  4005c0 <system@plt>
  400775:	90                   	nop
  400776:	5d                   	pop    %rbp
  400777:	c3                   	retq   

0000000000400778 <protect>:
  400778:	55                   	push   %rbp
  400779:	48 89 e5             	mov    %rsp,%rbp
  40077c:	48 83 ec 10          	sub    $0x10,%rsp
  400780:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  400784:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  400788:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  40078c:	48 89 c7             	mov    %rax,%rdi
  40078f:	e8 a2 ff ff ff       	callq  400736 <valid>
  400794:	85 c0                	test   %eax,%eax
  400796:	74 11                	je     4007a9 <protect+0x31>
  400798:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  40079c:	48 89 c7             	mov    %rax,%rdi
  40079f:	b8 00 00 00 00       	mov    $0x0,%eax
  4007a4:	e8 b4 ff ff ff       	callq  40075d <danger>
  4007a9:	90                   	nop
  4007aa:	c9                   	leaveq 
  4007ab:	c3                   	retq   

00000000004007ac <smoke>:
  4007ac:	55                   	push   %rbp
  4007ad:	48 89 e5             	mov    %rsp,%rbp
  4007b0:	bf 45 0a 40 00       	mov    $0x400a45,%edi
  4007b5:	e8 f6 fd ff ff       	callq  4005b0 <puts@plt>
  4007ba:	bf 00 00 00 00       	mov    $0x0,%edi
  4007bf:	e8 6c fe ff ff       	callq  400630 <exit@plt>

00000000004007c4 <fizz>:
  4007c4:	55                   	push   %rbp
  4007c5:	48 89 e5             	mov    %rsp,%rbp
  4007c8:	48 83 ec 10          	sub    $0x10,%rsp
  4007cc:	89 7d fc             	mov    %edi,-0x4(%rbp)
  4007cf:	81 7d fc 04 03 02 01 	cmpl   $0x1020304,-0x4(%rbp)
  4007d6:	75 16                	jne    4007ee <fizz+0x2a>
  4007d8:	8b 45 fc             	mov    -0x4(%rbp),%eax
  4007db:	89 c6                	mov    %eax,%esi
  4007dd:	bf 60 0a 40 00       	mov    $0x400a60,%edi
  4007e2:	b8 00 00 00 00       	mov    $0x0,%eax
  4007e7:	e8 e4 fd ff ff       	callq  4005d0 <printf@plt>
  4007ec:	eb 14                	jmp    400802 <fizz+0x3e>
  4007ee:	8b 45 fc             	mov    -0x4(%rbp),%eax
  4007f1:	89 c6                	mov    %eax,%esi
  4007f3:	bf 80 0a 40 00       	mov    $0x400a80,%edi
  4007f8:	b8 00 00 00 00       	mov    $0x0,%eax
  4007fd:	e8 ce fd ff ff       	callq  4005d0 <printf@plt>
  400802:	bf 00 00 00 00       	mov    $0x0,%edi
  400807:	e8 24 fe ff ff       	callq  400630 <exit@plt>

000000000040080c <Gets>:
  40080c:	55                   	push   %rbp
  40080d:	48 89 e5             	mov    %rsp,%rbp
  400810:	48 83 ec 20          	sub    $0x20,%rsp
  400814:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  400818:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40081c:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  400820:	eb 11                	jmp    400833 <Gets+0x27>
  400822:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400826:	48 8d 50 01          	lea    0x1(%rax),%rdx
  40082a:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
  40082e:	8b 55 f4             	mov    -0xc(%rbp),%edx
  400831:	88 10                	mov    %dl,(%rax)
  400833:	48 8b 05 46 18 20 00 	mov    0x201846(%rip),%rax        # 602080 <infile>
  40083a:	48 89 c7             	mov    %rax,%rdi
  40083d:	e8 de fd ff ff       	callq  400620 <_IO_getc@plt>
  400842:	89 45 f4             	mov    %eax,-0xc(%rbp)
  400845:	83 7d f4 ff          	cmpl   $0xffffffff,-0xc(%rbp)
  400849:	74 06                	je     400851 <Gets+0x45>
  40084b:	83 7d f4 0a          	cmpl   $0xa,-0xc(%rbp)
  40084f:	75 d1                	jne    400822 <Gets+0x16>
  400851:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400855:	48 8d 50 01          	lea    0x1(%rax),%rdx
  400859:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
  40085d:	c6 00 00             	movb   $0x0,(%rax)
  400860:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  400864:	c9                   	leaveq 
  400865:	c3                   	retq   

0000000000400866 <bushandler>:
  400866:	55                   	push   %rbp
  400867:	48 89 e5             	mov    %rsp,%rbp
  40086a:	48 83 ec 10          	sub    $0x10,%rsp
  40086e:	89 7d fc             	mov    %edi,-0x4(%rbp)
  400871:	bf a0 0a 40 00       	mov    $0x400aa0,%edi
  400876:	e8 35 fd ff ff       	callq  4005b0 <puts@plt>
  40087b:	bf c0 0a 40 00       	mov    $0x400ac0,%edi
  400880:	e8 2b fd ff ff       	callq  4005b0 <puts@plt>
  400885:	bf 00 00 00 00       	mov    $0x0,%edi
  40088a:	e8 a1 fd ff ff       	callq  400630 <exit@plt>

000000000040088f <seghandler>:
  40088f:	55                   	push   %rbp
  400890:	48 89 e5             	mov    %rsp,%rbp
  400893:	48 83 ec 10          	sub    $0x10,%rsp
  400897:	89 7d fc             	mov    %edi,-0x4(%rbp)
  40089a:	bf d8 0a 40 00       	mov    $0x400ad8,%edi
  40089f:	e8 0c fd ff ff       	callq  4005b0 <puts@plt>
  4008a4:	bf c0 0a 40 00       	mov    $0x400ac0,%edi
  4008a9:	e8 02 fd ff ff       	callq  4005b0 <puts@plt>
  4008ae:	bf 00 00 00 00       	mov    $0x0,%edi
  4008b3:	e8 78 fd ff ff       	callq  400630 <exit@plt>

00000000004008b8 <illegalhandler>:
  4008b8:	55                   	push   %rbp
  4008b9:	48 89 e5             	mov    %rsp,%rbp
  4008bc:	48 83 ec 10          	sub    $0x10,%rsp
  4008c0:	89 7d fc             	mov    %edi,-0x4(%rbp)
  4008c3:	bf 00 0b 40 00       	mov    $0x400b00,%edi
  4008c8:	e8 e3 fc ff ff       	callq  4005b0 <puts@plt>
  4008cd:	bf c0 0a 40 00       	mov    $0x400ac0,%edi
  4008d2:	e8 d9 fc ff ff       	callq  4005b0 <puts@plt>
  4008d7:	bf 00 00 00 00       	mov    $0x0,%edi
  4008dc:	e8 4f fd ff ff       	callq  400630 <exit@plt>

00000000004008e1 <main>:
  4008e1:	55                   	push   %rbp
  4008e2:	48 89 e5             	mov    %rsp,%rbp
  4008e5:	48 83 ec 10          	sub    $0x10,%rsp
  4008e9:	89 7d fc             	mov    %edi,-0x4(%rbp)
  4008ec:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  4008f0:	be 8f 08 40 00       	mov    $0x40088f,%esi
  4008f5:	bf 0b 00 00 00       	mov    $0xb,%edi
  4008fa:	e8 01 fd ff ff       	callq  400600 <signal@plt>
  4008ff:	be 66 08 40 00       	mov    $0x400866,%esi
  400904:	bf 07 00 00 00       	mov    $0x7,%edi
  400909:	e8 f2 fc ff ff       	callq  400600 <signal@plt>
  40090e:	be b8 08 40 00       	mov    $0x4008b8,%esi
  400913:	bf 04 00 00 00       	mov    $0x4,%edi
  400918:	e8 e3 fc ff ff       	callq  400600 <signal@plt>
  40091d:	48 8b 05 4c 17 20 00 	mov    0x20174c(%rip),%rax        # 602070 <stdin@@GLIBC_2.2.5>
  400924:	48 89 05 55 17 20 00 	mov    %rax,0x201755(%rip)        # 602080 <infile>
  40092b:	b8 00 00 00 00       	mov    $0x0,%eax
  400930:	e8 11 00 00 00       	callq  400946 <getbuf>
  400935:	bf 30 0b 40 00       	mov    $0x400b30,%edi
  40093a:	e8 71 fc ff ff       	callq  4005b0 <puts@plt>
  40093f:	b8 00 00 00 00       	mov    $0x0,%eax
  400944:	c9                   	leaveq 
  400945:	c3                   	retq   

0000000000400946 <getbuf>:
  400946:	55                   	push   %rbp
  400947:	48 89 e5             	mov    %rsp,%rbp
  40094a:	48 83 ec 20          	sub    $0x20,%rsp
  40094e:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  400952:	48 89 c6             	mov    %rax,%rsi
  400955:	bf 54 0b 40 00       	mov    $0x400b54,%edi
  40095a:	b8 00 00 00 00       	mov    $0x0,%eax
  40095f:	e8 6c fc ff ff       	callq  4005d0 <printf@plt>
  400964:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  400968:	48 89 c7             	mov    %rax,%rdi
  40096b:	e8 9c fe ff ff       	callq  40080c <Gets>
  400970:	b8 01 00 00 00       	mov    $0x1,%eax
  400975:	c9                   	leaveq 
  400976:	c3                   	retq   
  400977:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40097e:	00 00 

0000000000400980 <__libc_csu_init>:
  400980:	41 57                	push   %r15
  400982:	41 56                	push   %r14
  400984:	41 89 ff             	mov    %edi,%r15d
  400987:	41 55                	push   %r13
  400989:	41 54                	push   %r12
  40098b:	4c 8d 25 7e 14 20 00 	lea    0x20147e(%rip),%r12        # 601e10 <__frame_dummy_init_array_entry>
  400992:	55                   	push   %rbp
  400993:	48 8d 2d 7e 14 20 00 	lea    0x20147e(%rip),%rbp        # 601e18 <__init_array_end>
  40099a:	53                   	push   %rbx
  40099b:	49 89 f6             	mov    %rsi,%r14
  40099e:	49 89 d5             	mov    %rdx,%r13
  4009a1:	4c 29 e5             	sub    %r12,%rbp
  4009a4:	48 83 ec 08          	sub    $0x8,%rsp
  4009a8:	48 c1 fd 03          	sar    $0x3,%rbp
  4009ac:	e8 c7 fb ff ff       	callq  400578 <_init>
  4009b1:	48 85 ed             	test   %rbp,%rbp
  4009b4:	74 20                	je     4009d6 <__libc_csu_init+0x56>
  4009b6:	31 db                	xor    %ebx,%ebx
  4009b8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4009bf:	00 
  4009c0:	4c 89 ea             	mov    %r13,%rdx
  4009c3:	4c 89 f6             	mov    %r14,%rsi
  4009c6:	44 89 ff             	mov    %r15d,%edi
  4009c9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4009cd:	48 83 c3 01          	add    $0x1,%rbx
  4009d1:	48 39 eb             	cmp    %rbp,%rbx
  4009d4:	75 ea                	jne    4009c0 <__libc_csu_init+0x40>
  4009d6:	48 83 c4 08          	add    $0x8,%rsp
  4009da:	5b                   	pop    %rbx
  4009db:	5d                   	pop    %rbp
  4009dc:	41 5c                	pop    %r12
  4009de:	41 5d                	pop    %r13
  4009e0:	41 5e                	pop    %r14
  4009e2:	41 5f                	pop    %r15
  4009e4:	c3                   	retq   
  4009e5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4009ec:	00 00 00 00 

00000000004009f0 <__libc_csu_fini>:
  4009f0:	f3 c3                	repz retq 

Disassembly of section .fini:

00000000004009f4 <_fini>:
  4009f4:	48 83 ec 08          	sub    $0x8,%rsp
  4009f8:	48 83 c4 08          	add    $0x8,%rsp
  4009fc:	c3                   	retq   
