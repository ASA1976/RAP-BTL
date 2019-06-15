	.text
	.file	"test_invocative.cpp"
	.globl	_Z5Test3v               # -- Begin function _Z5Test3v
	.p2align	4, 0x90
	.type	_Z5Test3v,@function
_Z5Test3v:                              # @_Z5Test3v
# %bb.0:
	subl	$12, %esp
	movl	$.L.str, (%esp)
	calll	puts
	addl	$12, %esp
	retl
.Lfunc_end0:
	.size	_Z5Test3v, .Lfunc_end0-_Z5Test3v
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushl	%edi
	.cfi_def_cfa_offset 8
	pushl	%esi
	.cfi_def_cfa_offset 12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	.cfi_offset %esi, -12
	.cfi_offset %edi, -8
	movl	$.L.str.1, (%esp)
	calll	puts
	movl	$.L.str.2, (%esp)
	calll	puts
	movl	$.L.str, (%esp)
	calll	puts
	leal	24(%esp), %edi
	leal	16(%esp), %esi
	movl	$_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_, 24(%esp)
	movl	$Test1, 16(%esp)
	movl	%esi, 28(%esp)
	movl	%edi, (%esp)
	calll	_Z10TestExternRKN10invocation10InvocativeIvJEEE
	movl	$_ZN10invocation15InvokeProcedureI3$_1vJEEET0_PKvDpT1_, 24(%esp)
	movl	$Test2, 16(%esp)
	movl	%esi, 28(%esp)
	movl	%edi, (%esp)
	calll	_Z10TestExternRKN10invocation10InvocativeIvJEEE
	movl	$_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_, 24(%esp)
	movl	$_Z5Test3v, 16(%esp)
	movl	%esi, 28(%esp)
	movl	%edi, (%esp)
	calll	_Z10TestExternRKN10invocation10InvocativeIvJEEE
	xorl	%eax, %eax
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_def_cfa_offset 4
	retl
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_
	.type	_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_,@function
_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_: # @"_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_"
# %bb.0:
	subl	$12, %esp
	movl	$.L.str.1, (%esp)
	calll	puts
	addl	$12, %esp
	retl
.Lfunc_end2:
	.size	_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_, .Lfunc_end2-_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZN10invocation15InvokeProcedureI3$_1vJEEET0_PKvDpT1_
	.type	_ZN10invocation15InvokeProcedureI3$_1vJEEET0_PKvDpT1_,@function
_ZN10invocation15InvokeProcedureI3$_1vJEEET0_PKvDpT1_: # @"_ZN10invocation15InvokeProcedureI3$_1vJEEET0_PKvDpT1_"
# %bb.0:
	subl	$12, %esp
	movl	$.L.str.2, (%esp)
	calll	puts
	addl	$12, %esp
	retl
.Lfunc_end3:
	.size	_ZN10invocation15InvokeProcedureI3$_1vJEEET0_PKvDpT1_, .Lfunc_end3-_ZN10invocation15InvokeProcedureI3$_1vJEEET0_PKvDpT1_
                                        # -- End function
	.section	.text._ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_,"axG",@progbits,_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_,comdat
	.weak	_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_ # -- Begin function _ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_
	.p2align	4, 0x90
	.type	_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_,@function
_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_: # @_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_
	.cfi_startproc
# %bb.0:
	movl	4(%esp), %eax
	jmpl	*(%eax)                 # TAILCALL
.Lfunc_end4:
	.size	_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_, .Lfunc_end4-_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Test3"
	.size	.L.str, 6

	.type	Test1,@object           # @Test1
	.local	Test1
	.comm	Test1,1,1
	.type	Test2,@object           # @Test2
	.local	Test2
	.comm	Test2,1,1
	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Test1"
	.size	.L.str.1, 6

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Test2"
	.size	.L.str.2, 6


	.ident	"clang version 7.0.1 (tags/RELEASE_701/final)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym _Z5Test3v
	.addrsig_sym _ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_
	.addrsig_sym _ZN10invocation15InvokeProcedureI3$_1vJEEET0_PKvDpT1_
	.addrsig_sym _ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_
	.addrsig_sym Test1
	.addrsig_sym Test2
