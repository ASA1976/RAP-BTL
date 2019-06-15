	.text
	.file	"test_extern.cpp"
	.globl	_Z10TestExternRKN10invocation10InvocativeIvJEEE # -- Begin function _Z10TestExternRKN10invocation10InvocativeIvJEEE
	.p2align	4, 0x90
	.type	_Z10TestExternRKN10invocation10InvocativeIvJEEE,@function
_Z10TestExternRKN10invocation10InvocativeIvJEEE: # @_Z10TestExternRKN10invocation10InvocativeIvJEEE
	.cfi_startproc
# %bb.0:
	subl	$12, %esp
	.cfi_def_cfa_offset 16
	movl	16(%esp), %eax
	movl	4(%eax), %ecx
	movl	%ecx, (%esp)
	calll	*(%eax)
	addl	$12, %esp
	.cfi_def_cfa_offset 4
	retl
.Lfunc_end0:
	.size	_Z10TestExternRKN10invocation10InvocativeIvJEEE, .Lfunc_end0-_Z10TestExternRKN10invocation10InvocativeIvJEEE
	.cfi_endproc
                                        # -- End function
	.globl	_Z10TestExternRKSt8functionIFvvEE # -- Begin function _Z10TestExternRKSt8functionIFvvEE
	.p2align	4, 0x90
	.type	_Z10TestExternRKSt8functionIFvvEE,@function
_Z10TestExternRKSt8functionIFvvEE:      # @_Z10TestExternRKSt8functionIFvvEE
	.cfi_startproc
# %bb.0:
	subl	$12, %esp
	.cfi_def_cfa_offset 16
	movl	16(%esp), %eax
	cmpl	$0, 8(%eax)
	je	.LBB1_1
# %bb.2:
	addl	$12, %esp
	.cfi_def_cfa_offset 4
	jmpl	*12(%eax)               # TAILCALL
.LBB1_1:
	.cfi_def_cfa_offset 16
	calll	_ZSt25__throw_bad_function_callv
.Lfunc_end1:
	.size	_Z10TestExternRKSt8functionIFvvEE, .Lfunc_end1-_Z10TestExternRKSt8functionIFvvEE
	.cfi_endproc
                                        # -- End function

	.ident	"clang version 7.0.1 (tags/RELEASE_701/final)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
