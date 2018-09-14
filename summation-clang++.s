	.text
	.file	"summation.cpp"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
# %bb.0:
	subl	$12, %esp
	pushl	$10
	pushl	$9
	pushl	$0
	pushl	$.L.str
	calll	printf
	addl	$8, %esp
	pushl	$0
	pushl	$.L.str.1
	calll	printf
	addl	$8, %esp
	pushl	$1
	pushl	$.L.str.1
	calll	printf
	addl	$8, %esp
	pushl	$3
	pushl	$.L.str.1
	calll	printf
	addl	$8, %esp
	pushl	$6
	pushl	$.L.str.1
	calll	printf
	addl	$8, %esp
	pushl	$10
	pushl	$.L.str.1
	calll	printf
	addl	$8, %esp
	pushl	$15
	pushl	$.L.str.1
	calll	printf
	addl	$8, %esp
	pushl	$21
	pushl	$.L.str.1
	calll	printf
	addl	$8, %esp
	pushl	$28
	pushl	$.L.str.1
	calll	printf
	addl	$8, %esp
	pushl	$36
	pushl	$.L.str.1
	calll	printf
	addl	$8, %esp
	pushl	$45
	pushl	$.L.str.1
	calll	printf
	addl	$16, %esp
	xorl	%eax, %eax
	addl	$12, %esp
	retl
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Sigma( %d <= i => %d := |%u| ) i\n"
	.size	.L.str, 34

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Sum = %d\n"
	.size	.L.str.1, 10


	.ident	"clang version 6.0.1 (tags/RELEASE_601/final)"
	.section	".note.GNU-stack","",@progbits
