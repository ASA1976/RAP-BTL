	.text
	.file	"zero.cpp"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
# %bb.0:
	subl	$20, %esp
	pushl	$71
	pushl	$.L.str
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
	.asciz	"'%c'\n"
	.size	.L.str, 6


	.ident	"clang version 7.0.1 (tags/RELEASE_701/final)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
