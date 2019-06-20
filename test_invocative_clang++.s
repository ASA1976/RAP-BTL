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
	movl	$.L.str.2, (%esp)
	calll	puts
	movl	$.L.str.3, (%esp)
	calll	puts
	movl	$.L.str, (%esp)
	calll	puts
	movl	$.L.str.1, (%esp)
	calll	puts
	leal	8(%esp), %edi
	leal	24(%esp), %esi
	movl	$_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_, 8(%esp)
	movl	$Test1, 24(%esp)
	movl	%esi, 12(%esp)
	movl	%edi, (%esp)
	calll	_Z10TestExternRKN10invocation10InvocativeIvJEEE
	movl	$_ZN10invocation15InvokeProcedureI3$_2vJEEET0_PKvDpT1_, 8(%esp)
	movl	$Test2, 24(%esp)
	movl	%esi, 12(%esp)
	movl	%edi, (%esp)
	calll	_Z10TestExternRKN10invocation10InvocativeIvJEEE
	movl	$_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_, 8(%esp)
	movl	$_Z5Test3v, 24(%esp)
	movl	%esi, 12(%esp)
	movl	%edi, (%esp)
	calll	_Z10TestExternRKN10invocation10InvocativeIvJEEE
	movl	$_ZN3$_13runEv, 8(%esp)
	movl	$0, 12(%esp)
	movl	$_ZN10invocation12InvokeMethodI3$_1MS1_FvvEvJEEET1_PKvDpT2_, 24(%esp)
	movl	$Test4, 16(%esp)
	movl	%edi, 28(%esp)
	movl	%esi, (%esp)
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
	.p2align	4, 0x90         # -- Begin function _ZN3$_13runEv
	.type	_ZN3$_13runEv,@function
_ZN3$_13runEv:                          # @"_ZN3$_13runEv"
# %bb.0:
	subl	$12, %esp
	movl	$.L.str.1, (%esp)
	calll	puts
	addl	$12, %esp
	retl
.Lfunc_end2:
	.size	_ZN3$_13runEv, .Lfunc_end2-_ZN3$_13runEv
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_
	.type	_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_,@function
_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_: # @"_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_"
# %bb.0:
	subl	$12, %esp
	movl	$.L.str.2, (%esp)
	calll	puts
	addl	$12, %esp
	retl
.Lfunc_end3:
	.size	_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_, .Lfunc_end3-_ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZN10invocation15InvokeProcedureI3$_2vJEEET0_PKvDpT1_
	.type	_ZN10invocation15InvokeProcedureI3$_2vJEEET0_PKvDpT1_,@function
_ZN10invocation15InvokeProcedureI3$_2vJEEET0_PKvDpT1_: # @"_ZN10invocation15InvokeProcedureI3$_2vJEEET0_PKvDpT1_"
# %bb.0:
	subl	$12, %esp
	movl	$.L.str.3, (%esp)
	calll	puts
	addl	$12, %esp
	retl
.Lfunc_end4:
	.size	_ZN10invocation15InvokeProcedureI3$_2vJEEET0_PKvDpT1_, .Lfunc_end4-_ZN10invocation15InvokeProcedureI3$_2vJEEET0_PKvDpT1_
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZN10invocation12InvokeMethodI3$_1MS1_FvvEvJEEET1_PKvDpT2_
	.type	_ZN10invocation12InvokeMethodI3$_1MS1_FvvEvJEEET1_PKvDpT2_,@function
_ZN10invocation12InvokeMethodI3$_1MS1_FvvEvJEEET1_PKvDpT2_: # @"_ZN10invocation12InvokeMethodI3$_1MS1_FvvEvJEEET1_PKvDpT2_"
	.cfi_startproc
# %bb.0:
	subl	$12, %esp
	.cfi_def_cfa_offset 16
	movl	16(%esp), %edx
	movl	8(%edx), %ecx
	movl	(%edx), %eax
	addl	4(%edx), %ecx
	testb	$1, %al
	je	.LBB5_2
# %bb.1:
	movl	(%ecx), %edx
	movl	-1(%edx,%eax), %eax
.LBB5_2:
	movl	%ecx, (%esp)
	calll	*%eax
	addl	$12, %esp
	.cfi_def_cfa_offset 4
	retl
.Lfunc_end5:
	.size	_ZN10invocation12InvokeMethodI3$_1MS1_FvvEvJEEET1_PKvDpT2_, .Lfunc_end5-_ZN10invocation12InvokeMethodI3$_1MS1_FvvEvJEEET1_PKvDpT2_
	.cfi_endproc
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
.Lfunc_end6:
	.size	_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_, .Lfunc_end6-_ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_
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
	.type	Test4,@object           # @Test4
	.local	Test4
	.comm	Test4,1,1
	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Test4"
	.size	.L.str.1, 6

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Test1"
	.size	.L.str.2, 6

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"Test2"
	.size	.L.str.3, 6


	.ident	"clang version 7.0.1 (tags/RELEASE_701/final)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym _Z5Test3v
	.addrsig_sym _ZN3$_13runEv
	.addrsig_sym _ZN10invocation15InvokeProcedureI3$_0vJEEET0_PKvDpT1_
	.addrsig_sym _ZN10invocation15InvokeProcedureI3$_2vJEEET0_PKvDpT1_
	.addrsig_sym _ZN10invocation12InvokeMethodI3$_1MS1_FvvEvJEEET1_PKvDpT2_
	.addrsig_sym _ZN10invocation15InvokeProcedureIFvvEvJEEET0_PKvDpT1_
	.addrsig_sym Test1
	.addrsig_sym Test2
	.addrsig_sym Test4
