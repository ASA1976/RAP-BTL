	.text
	.file	"processing.cpp"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	subl	$1052, %esp             # imm = 0x41C
	.cfi_def_cfa_offset 1056
	leal	24(%esp), %eax
	movl	$1024, 8(%esp)          # imm = 0x400
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	calll	memset
	movl	$_ZL11PrintStringPv, %eax
	movl	$.L.str, 32(%esp)
	movl	$_ZL11PrintStringPv, 36(%esp)
	movl	$_ZZ4mainE4Size, 40(%esp)
	movl	$_ZL12PrintNaturalPv, 44(%esp)
	movw	$3, 28(%esp)
	movl	$.L.str.1, 48(%esp)
	movl	$_ZL11PrintStringPv, 52(%esp)
	movl	$.L.str, (%esp)
	calll	*%eax
	movl	40(%esp), %eax
	movl	%eax, (%esp)
	calll	*44(%esp)
	movl	48(%esp), %eax
	movl	%eax, (%esp)
	calll	*52(%esp)
	xorl	%eax, %eax
	addl	$1052, %esp             # imm = 0x41C
	retl
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZL11PrintStringPv
	.type	_ZL11PrintStringPv,@function
_ZL11PrintStringPv:                     # @_ZL11PrintStringPv
# %bb.0:
	jmp	puts                    # TAILCALL
.Lfunc_end1:
	.size	_ZL11PrintStringPv, .Lfunc_end1-_ZL11PrintStringPv
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZL12PrintNaturalPv
	.type	_ZL12PrintNaturalPv,@function
_ZL12PrintNaturalPv:                    # @_ZL12PrintNaturalPv
# %bb.0:
	subl	$12, %esp
	movl	16(%esp), %eax
	movzwl	(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.L.str.3
	calll	printf
	addl	$28, %esp
	retl
.Lfunc_end2:
	.size	_ZL12PrintNaturalPv, .Lfunc_end2-_ZL12PrintNaturalPv
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Hello world!"
	.size	.L.str, 13

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Goodbye"
	.size	.L.str.1, 8

	.type	_ZZ4mainE4Size,@object  # @_ZZ4mainE4Size
	.section	.rodata,"a",@progbits
	.p2align	1
_ZZ4mainE4Size:
	.short	1024                    # 0x400
	.size	_ZZ4mainE4Size, 2

	.type	.L.str.3,@object        # @.str.3
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.3:
	.asciz	"%u\n"
	.size	.L.str.3, 4


	.ident	"clang version 6.0.1 (tags/RELEASE_601/final)"
	.section	".note.GNU-stack","",@progbits
