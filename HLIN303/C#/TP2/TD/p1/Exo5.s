	.file	"Exo5.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Il y a %i param\303\250tres pass\303\251s \303\240 la ligne de commande.\n"
.LC1:
	.string	"Parametre %i : %s\n"
	.align 8
.LC2:
	.string	"Variable Environnement %i : %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, -8(%rbp)
	jmp	.L2
.L3:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -8(%rbp)
.L2:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L3
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L4:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
