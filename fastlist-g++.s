	.file	"fastlist.cpp"
	.text
	.type	_ZN8junctionL7AccountItcEET_RKNS_8JunctiveIS1_T0_EE, @function
_ZN8junctionL7AccountItcEET_RKNS_8JunctiveIS1_T0_EE:
.LFB134:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	12(%eax), %eax
	ret
	.cfi_endproc
.LFE134:
	.size	_ZN8junctionL7AccountItcEET_RKNS_8JunctiveIS1_T0_EE, .-_ZN8junctionL7AccountItcEET_RKNS_8JunctiveIS1_T0_EE
	.type	_ZN8junction11consecutionL7SucceedItcEEbRNS_8JunctiveIT_T0_EERKS3_, @function
_ZN8junction11consecutionL7SucceedItcEEbRNS_8JunctiveIT_T0_EERKS3_:
.LFB138:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %ebx
	movl	20(%esp), %edi
	movl	(%ebx), %esi
	testl	%esi, %esi
	je	.L10
	movw	(%edi), %cx
	cmpw	$1, %cx
	jbe	.L11
	movl	4(%esi), %eax
	testl	%eax, %eax
	je	.L12
	movl	$1, %edx
.L5:
	incl	%edx
	cmpw	%cx, %dx
	je	.L4
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	.L5
	movb	$0, %al
	jmp	.L2
.L11:
	movl	%esi, %eax
.L4:
	movl	4(%eax), %edx
	movl	%edx, (%ebx)
	testl	%edx, %edx
	je	.L7
	movl	$0, (%edx)
.L8:
	movl	8(%ebx), %edx
	movl	%edx, 4(%eax)
	testl	%edx, %edx
	je	.L9
	movl	%eax, (%edx)
.L9:
	movl	%esi, 8(%ebx)
	movw	(%edi), %ax
	subw	%ax, 12(%ebx)
	movb	$1, %al
.L2:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
.L7:
	.cfi_restore_state
	movl	$0, 4(%ebx)
	jmp	.L8
.L10:
	movb	$0, %al
	jmp	.L2
.L12:
	movb	$0, %al
	jmp	.L2
	.cfi_endproc
.LFE138:
	.size	_ZN8junction11consecutionL7SucceedItcEEbRNS_8JunctiveIT_T0_EERKS3_, .-_ZN8junction11consecutionL7SucceedItcEEbRNS_8JunctiveIT_T0_EERKS3_
	.type	_ZN8junction11consecutionL7ConcedeItcEEbRNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS4_EEEERKS3_, @function
_ZN8junction11consecutionL7ConcedeItcEEbRNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS4_EEEERKS3_:
.LFB139:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	20(%esp), %ebx
	movl	24(%esp), %esi
	movl	28(%esp), %edi
	movl	(%esi), %ebp
	movw	(%edi), %cx
	cmpw	$1, %cx
	jbe	.L25
	movl	4(%ebp), %eax
	testl	%eax, %eax
	je	.L26
	movl	$1, %edx
.L18:
	incl	%edx
	cmpw	%cx, %dx
	je	.L16
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	.L18
	movb	$0, %al
	jmp	.L15
.L25:
	movl	%ebp, %eax
.L16:
	movl	0(%ebp), %edx
	testl	%edx, %edx
	je	.L20
	movl	4(%eax), %ecx
	movl	%ecx, 4(%edx)
.L21:
	movl	4(%eax), %edx
	testl	%edx, %edx
	je	.L22
	movl	(%esi), %ecx
	movl	(%ecx), %ecx
	movl	%ecx, (%edx)
.L23:
	movl	8(%ebx), %edx
	movl	%edx, 4(%eax)
	testl	%edx, %edx
	je	.L24
	movl	%eax, (%edx)
.L24:
	movl	(%esi), %eax
	movl	%eax, 8(%ebx)
	movw	(%edi), %ax
	subw	%ax, 12(%ebx)
	movb	$1, %al
.L15:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
.L20:
	.cfi_restore_state
	movl	4(%eax), %edx
	movl	%edx, (%ebx)
	jmp	.L21
.L22:
	movl	(%esi), %edx
	movl	(%edx), %edx
	movl	%edx, 4(%ebx)
	jmp	.L23
.L26:
	movb	$0, %al
	jmp	.L15
	.cfi_endproc
.LFE139:
	.size	_ZN8junction11consecutionL7ConcedeItcEEbRNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS4_EEEERKS3_, .-_ZN8junction11consecutionL7ConcedeItcEEbRNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS4_EEEERKS3_
	.type	_ZN8junction11consecutionL6RecedeItcEEbRNS_8JunctiveIT_T0_EERKS3_, @function
_ZN8junction11consecutionL6RecedeItcEEbRNS_8JunctiveIT_T0_EERKS3_:
.LFB140:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %ebx
	movl	20(%esp), %edi
	movl	4(%ebx), %esi
	testl	%esi, %esi
	je	.L37
	movw	(%edi), %cx
	cmpw	$1, %cx
	jbe	.L38
	movl	(%esi), %eax
	testl	%eax, %eax
	je	.L39
	movl	$1, %edx
.L32:
	incl	%edx
	cmpw	%cx, %dx
	je	.L31
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	.L32
	movb	$0, %al
	jmp	.L29
.L38:
	movl	%esi, %eax
.L31:
	movl	(%eax), %edx
	movl	%edx, 4(%ebx)
	testl	%edx, %edx
	je	.L34
	movl	$0, 4(%edx)
	movl	$0, (%eax)
.L35:
	movl	8(%ebx), %edx
	movl	%edx, 4(%esi)
	testl	%edx, %edx
	je	.L36
	movl	%esi, (%edx)
.L36:
	movl	%eax, 8(%ebx)
	movw	(%edi), %ax
	subw	%ax, 12(%ebx)
	movb	$1, %al
.L29:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
.L34:
	.cfi_restore_state
	movl	$0, (%ebx)
	jmp	.L35
.L37:
	movb	$0, %al
	jmp	.L29
.L39:
	movb	$0, %al
	jmp	.L29
	.cfi_endproc
.LFE140:
	.size	_ZN8junction11consecutionL6RecedeItcEEbRNS_8JunctiveIT_T0_EERKS3_, .-_ZN8junction11consecutionL6RecedeItcEEbRNS_8JunctiveIT_T0_EERKS3_
	.type	_ZN8junctionL5EmptyItcEEbRNS_8JunctiveIT_T0_EE, @function
_ZN8junctionL5EmptyItcEEbRNS_8JunctiveIT_T0_EE:
.LFB141:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	4(%edx), %eax
	testl	%eax, %eax
	je	.L45
	movl	8(%edx), %ecx
	movl	%ecx, 4(%eax)
	testl	%ecx, %ecx
	je	.L44
	movl	4(%edx), %eax
	movl	%eax, (%ecx)
.L44:
	movl	(%edx), %eax
	movl	%eax, 8(%edx)
	movb	$1, %al
.L43:
	movl	$0, 4(%edx)
	movl	$0, (%edx)
	movw	$0, 12(%edx)
	ret
.L45:
	movb	$0, %al
	jmp	.L43
	.cfi_endproc
.LFE141:
	.size	_ZN8junctionL5EmptyItcEEbRNS_8JunctiveIT_T0_EE, .-_ZN8junctionL5EmptyItcEEbRNS_8JunctiveIT_T0_EE
	.type	_ZN8junctionL4FreeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EE, @function
_ZN8junctionL4FreeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EE:
.LFB142:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %ecx
	movl	8(%ecx), %edx
	testl	%edx, %edx
	je	.L49
	movl	4(%edx), %esi
	movl	NodePool, %ebx
	leal	1(%ebx), %eax
	movw	%ax, NodePool
	andl	$65535, %ebx
	subl	$NodePool+8, %edx
	sarl	$2, %edx
	leal	(%edx,%edx,4), %eax
	movl	%eax, %edi
	sall	$4, %edi
	addl	%edi, %eax
	movl	%eax, %edi
	sall	$8, %edi
	addl	%edi, %eax
	movl	%eax, %edi
	sall	$16, %edi
	addl	%edi, %eax
	leal	(%edx,%eax,2), %eax
	movw	%ax, NodePool+44(%ebx,%ebx)
	decw	14(%ecx)
	movl	%esi, 8(%ecx)
	testl	%esi, %esi
	je	.L48
	movl	$0, (%esi)
.L48:
	cmpl	$0, 8(%ecx)
	setne	%al
.L46:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
.L49:
	.cfi_restore_state
	movb	$0, %al
	jmp	.L46
	.cfi_endproc
.LFE142:
	.size	_ZN8junctionL4FreeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EE, .-_ZN8junctionL4FreeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EE
	.type	_ZN8junctionL7IsEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, @function
_ZN8junctionL7IsEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_:
.LFB143:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	8(%esp), %eax
	movl	(%eax), %eax
	cmpl	%eax, (%edx)
	sete	%al
	ret
	.cfi_endproc
.LFE143:
	.size	_ZN8junctionL7IsEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, .-_ZN8junctionL7IsEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.type	_ZN8junctionL10IsNotEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, @function
_ZN8junctionL10IsNotEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_:
.LFB144:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	8(%esp), %eax
	movl	(%eax), %eax
	cmpl	%eax, (%edx)
	setne	%al
	ret
	.cfi_endproc
.LFE144:
	.size	_ZN8junctionL10IsNotEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, .-_ZN8junctionL10IsNotEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.type	_ZN8junctionL8IsLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, @function
_ZN8junctionL8IsLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_:
.LFB145:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	8(%esp), %edx
	movl	(%edx), %edx
	cmpl	%edx, %eax
	je	.L57
	movl	4(%eax), %eax
	testl	%eax, %eax
	je	.L58
	cmpl	%eax, %edx
	je	.L61
.L55:
	movl	4(%eax), %eax
	testl	%eax, %eax
	je	.L62
	cmpl	%eax, %edx
	jne	.L55
	movb	$1, %al
	ret
.L62:
	ret
.L57:
	movb	$0, %al
	ret
.L58:
	movb	$0, %al
	ret
.L61:
	movb	$1, %al
	ret
	.cfi_endproc
.LFE145:
	.size	_ZN8junctionL8IsLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, .-_ZN8junctionL8IsLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.type	_ZN8junctionL9IsGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, @function
_ZN8junctionL9IsGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_:
.LFB146:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	8(%esp), %edx
	movl	(%edx), %edx
	cmpl	%edx, %eax
	je	.L67
	movl	(%eax), %eax
	testl	%eax, %eax
	je	.L68
	cmpl	%eax, %edx
	je	.L71
.L65:
	movl	(%eax), %eax
	testl	%eax, %eax
	je	.L72
	cmpl	%eax, %edx
	jne	.L65
	movb	$1, %al
	ret
.L72:
	ret
.L67:
	movb	$0, %al
	ret
.L68:
	movb	$0, %al
	ret
.L71:
	movb	$1, %al
	ret
	.cfi_endproc
.LFE146:
	.size	_ZN8junctionL9IsGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, .-_ZN8junctionL9IsGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.type	_ZN8junctionL12IsNotGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, @function
_ZN8junctionL12IsNotGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_:
.LFB147:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	8(%esp), %edx
	movl	(%edx), %edx
	cmpl	%edx, %eax
	je	.L77
	movl	4(%eax), %eax
	testl	%eax, %eax
	je	.L78
	cmpl	%eax, %edx
	je	.L81
.L75:
	movl	4(%eax), %eax
	testl	%eax, %eax
	je	.L82
	cmpl	%eax, %edx
	jne	.L75
	movb	$1, %al
	ret
.L82:
	ret
.L77:
	movb	$1, %al
	ret
.L78:
	movb	$0, %al
	ret
.L81:
	movb	$1, %al
	ret
	.cfi_endproc
.LFE147:
	.size	_ZN8junctionL12IsNotGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, .-_ZN8junctionL12IsNotGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.type	_ZN8junctionL11IsNotLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, @function
_ZN8junctionL11IsNotLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_:
.LFB148:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	movl	8(%esp), %edx
	movl	(%edx), %edx
	cmpl	%edx, %eax
	je	.L87
	movl	(%eax), %eax
	testl	%eax, %eax
	je	.L88
	cmpl	%eax, %edx
	je	.L91
.L85:
	movl	(%eax), %eax
	testl	%eax, %eax
	je	.L92
	cmpl	%eax, %edx
	jne	.L85
	movb	$1, %al
	ret
.L92:
	ret
.L87:
	movb	$1, %al
	ret
.L88:
	movb	$0, %al
	ret
.L91:
	movb	$1, %al
	ret
	.cfi_endproc
.LFE148:
	.size	_ZN8junctionL11IsNotLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_, .-_ZN8junctionL11IsNotLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.type	_ZN8junctionL18BeginReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_, @function
_ZN8junctionL18BeginReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_:
.LFB149:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %eax
	movl	16(%esp), %ebx
	movl	8(%esp), %edx
	movl	(%edx), %edx
	movl	%edx, (%eax)
	cmpw	$0, (%ebx)
	je	.L94
	movl	$0, %edx
.L95:
	movl	(%eax), %ecx
	movl	4(%ecx), %ecx
	movl	%ecx, (%eax)
	incl	%edx
	cmpw	%dx, (%ebx)
	ja	.L95
.L94:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE149:
	.size	_ZN8junctionL18BeginReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_, .-_ZN8junctionL18BeginReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_
	.type	_ZN8junctionL21TraverseReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_, @function
_ZN8junctionL21TraverseReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_:
.LFB150:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	12(%esp), %eax
	movl	16(%esp), %ebx
	cmpw	$0, (%ebx)
	je	.L99
	movl	$0, %edx
.L100:
	movl	(%eax), %ecx
	movl	4(%ecx), %ecx
	movl	%ecx, (%eax)
	incl	%edx
	cmpw	%dx, (%ebx)
	ja	.L100
.L99:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE150:
	.size	_ZN8junctionL21TraverseReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_, .-_ZN8junctionL21TraverseReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_
	.type	_ZN8junctionL15IncrementBeginsItcEEbRKNS_8JunctiveIT_T0_EERKS2_, @function
_ZN8junctionL15IncrementBeginsItcEEbRKNS_8JunctiveIT_T0_EERKS2_:
.LFB152:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	.L106
	movl	8(%esp), %edx
	movw	(%edx), %dx
	testw	%dx, %dx
	je	.L107
	cmpl	$0, 4(%eax)
	je	.L108
	movl	$0, %eax
.L105:
	incl	%eax
	cmpw	%dx, %ax
	jne	.L105
	movb	$1, %al
	ret
.L106:
	movb	$0, %al
	ret
.L107:
	movb	$1, %al
	ret
.L108:
	movb	$0, %al
	ret
	.cfi_endproc
.LFE152:
	.size	_ZN8junctionL15IncrementBeginsItcEEbRKNS_8JunctiveIT_T0_EERKS2_, .-_ZN8junctionL15IncrementBeginsItcEEbRKNS_8JunctiveIT_T0_EERKS2_
	.type	_ZN8junctionL20IncrementTraversableItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEERKS2_, @function
_ZN8junctionL20IncrementTraversableItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEERKS2_:
.LFB153:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	(%eax), %edx
	movl	12(%esp), %eax
	movw	(%eax), %cx
	testw	%cx, %cx
	je	.L114
	movl	4(%edx), %edx
	testl	%edx, %edx
	je	.L115
	movl	$0, %eax
.L112:
	incl	%eax
	cmpw	%cx, %ax
	je	.L117
	movl	4(%edx), %edx
	testl	%edx, %edx
	jne	.L112
	movb	$0, %al
	ret
.L117:
	movb	$1, %al
	ret
.L114:
	movb	$1, %al
	ret
.L115:
	movb	$0, %al
	ret
	.cfi_endproc
.LFE153:
	.size	_ZN8junctionL20IncrementTraversableItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEERKS2_, .-_ZN8junctionL20IncrementTraversableItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEERKS2_
	.type	_ZN8junctionL8ContainsItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE, @function
_ZN8junctionL8ContainsItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE:
.LFB154:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	.L122
	movl	8(%esp), %edx
	movl	(%edx), %edx
	cmpl	%edx, %eax
	je	.L125
.L120:
	movl	4(%eax), %eax
	testl	%eax, %eax
	je	.L126
	cmpl	%edx, %eax
	jne	.L120
	movb	$1, %al
	ret
.L126:
	ret
.L122:
	movb	$0, %al
	ret
.L125:
	movb	$1, %al
	ret
	.cfi_endproc
.LFE154:
	.size	_ZN8junctionL8ContainsItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE, .-_ZN8junctionL8ContainsItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE
	.type	_ZN8junctionL14CountIncrementItcEET_RKNS_8JunctiveIS1_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE, @function
_ZN8junctionL14CountIncrementItcEET_RKNS_8JunctiveIS1_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE:
.LFB155:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	(%eax), %eax
	movl	4(%eax), %edx
	testl	%edx, %edx
	je	.L130
	movl	$0, %eax
.L129:
	incl	%eax
	movl	4(%edx), %edx
	testl	%edx, %edx
	jne	.L129
	ret
.L130:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE155:
	.size	_ZN8junctionL14CountIncrementItcEET_RKNS_8JunctiveIS1_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE, .-_ZN8junctionL14CountIncrementItcEET_RKNS_8JunctiveIS1_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE
	.type	_ZN8junctionL6GoReadItcEEN8location12ConferentialIKT0_EERKNS_8JunctiveIT_S3_EERKNS1_8PositiveINS_10JunctionalIS3_EEEE, @function
_ZN8junctionL6GoReadItcEEN8location12ConferentialIKT0_EERKNS_8JunctiveIT_S3_EERKNS1_8PositiveINS_10JunctionalIS3_EEEE:
.LFB151:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	12(%esp), %edx
	movl	(%edx), %edx
	addl	$8, %edx
	movl	%edx, (%eax)
	ret	$4
	.cfi_endproc
.LFE151:
	.size	_ZN8junctionL6GoReadItcEEN8location12ConferentialIKT0_EERKNS_8JunctiveIT_S3_EERKNS1_8PositiveINS_10JunctionalIS3_EEEE, .-_ZN8junctionL6GoReadItcEEN8location12ConferentialIKT0_EERKNS_8JunctiveIT_S3_EERKNS1_8PositiveINS_10JunctionalIS3_EEEE
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"'%c'"
	.text
	.type	_Z17DisplayCharactersIN8junction8JunctiveItcEEN8location8PositiveINS0_10JunctionalIcEEEEtEbRKT_RKN10trajection11DirectionalIS9_T0_T1_KcEE, @function
_Z17DisplayCharactersIN8junction8JunctiveItcEEN8location8PositiveINS0_10JunctionalIcEEEEtEbRKT_RKN10trajection11DirectionalIS9_T0_T1_KcEE:
.LFB166:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$52, %esp
	.cfi_def_cfa_offset 72
	movl	%eax, %ebx
	movl	%edx, %esi
	movw	$0, 32(%esp)
	leal	32(%esp), %eax
	pushl	%eax
	.cfi_def_cfa_offset 76
	pushl	%ebx
	.cfi_def_cfa_offset 80
	call	*4(%edx)
	movb	%al, 27(%esp)
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	testb	%al, %al
	je	.L133
	movl	(%esi), %eax
	movl	4(%eax), %eax
	movw	$0, 26(%esp)
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	leal	30(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	leal	28(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 76
	pushl	%ebx
	.cfi_def_cfa_offset 80
	call	*%eax
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	leal	12(%esp), %ebp
	leal	20(%esp), %edi
.L135:
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	movl	(%esi), %eax
	pushl	%edi
	.cfi_def_cfa_offset 72
	pushl	%ebx
	.cfi_def_cfa_offset 76
	pushl	%ebp
	.cfi_def_cfa_offset 80
	call	*12(%eax)
	.cfi_def_cfa_offset 76
	movl	24(%esp), %eax
	movsbl	(%eax), %eax
	movl	%eax, (%esp)
	pushl	$.LC0
	.cfi_def_cfa_offset 80
	call	printf
	movw	$1, 44(%esp)
	addl	$12, %esp
	.cfi_def_cfa_offset 68
	leal	32(%esp), %eax
	pushl	%eax
	.cfi_def_cfa_offset 72
	pushl	%edi
	.cfi_def_cfa_offset 76
	pushl	%ebx
	.cfi_def_cfa_offset 80
	call	*8(%esi)
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	testb	%al, %al
	je	.L133
	subl	$12, %esp
	.cfi_def_cfa_offset 76
	pushl	$44
	.cfi_def_cfa_offset 80
	call	putchar
	movl	(%esi), %eax
	movl	8(%eax), %eax
	movw	$1, 46(%esp)
	addl	$12, %esp
	.cfi_def_cfa_offset 68
	leal	34(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	pushl	%edi
	.cfi_def_cfa_offset 76
	pushl	%ebx
	.cfi_def_cfa_offset 80
	call	*%eax
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	jmp	.L135
.L133:
	movb	11(%esp), %al
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE166:
	.size	_Z17DisplayCharactersIN8junction8JunctiveItcEEN8location8PositiveINS0_10JunctionalIcEEEEtEbRKT_RKN10trajection11DirectionalIS9_T0_T1_KcEE, .-_Z17DisplayCharactersIN8junction8JunctiveItcEEN8location8PositiveINS0_10JunctionalIcEEEEtEbRKT_RKN10trajection11DirectionalIS9_T0_T1_KcEE
	.type	_ZN8junctionL11InstantiateItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS2_, @function
_ZN8junctionL11InstantiateItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS2_:
.LFB133:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %edx
	movl	20(%esp), %ebx
	xorl	%eax, %eax
	movw	14(%edx), %ax
	xorl	%ecx, %ecx
	movw	12(%edx), %cx
	subl	%ecx, %eax
	xorl	%ecx, %ecx
	movw	(%ebx), %cx
	cmpl	%ecx, %eax
	jl	.L142
.L138:
	movb	$1, %al
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
.L139:
	.cfi_restore_state
	movl	NodePool+4, %eax
	leal	1(%eax), %ecx
	movw	%cx, NodePool+4
.L140:
	andl	$65535, %eax
	leal	(%eax,%eax), %ecx
	leal	(%ecx,%eax), %esi
	leal	NodePool+8(,%esi,4), %edi
	incw	14(%edx)
	movl	8(%edx), %esi
	addl	%ecx, %eax
	movl	%esi, NodePool+12(,%eax,4)
	testl	%esi, %esi
	je	.L141
	movl	%edi, (%esi)
.L141:
	movl	%edi, 8(%edx)
	xorl	%eax, %eax
	movw	14(%edx), %ax
	xorl	%ecx, %ecx
	movw	12(%edx), %cx
	subl	%ecx, %eax
	xorl	%ecx, %ecx
	movw	(%ebx), %cx
	cmpl	%ecx, %eax
	jge	.L138
.L142:
	movl	NodePool, %eax
	testw	%ax, %ax
	je	.L139
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
	jmp	.L140
	.cfi_endproc
.LFE133:
	.size	_ZN8junctionL11InstantiateItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS2_, .-_ZN8junctionL11InstantiateItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS2_
	.type	_ZN8junction11consecutionL6AccedeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_, @function
_ZN8junction11consecutionL6AccedeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_:
.LFB135:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	8(%edx), %eax
	testl	%eax, %eax
	je	.L146
	movl	4(%eax), %ecx
	movl	%ecx, 8(%edx)
	testl	%ecx, %ecx
	je	.L147
	movl	$0, (%ecx)
.L147:
	movl	$0, 4(%eax)
.L148:
	movl	8(%esp), %ecx
	movb	(%ecx), %cl
	movb	%cl, 8(%eax)
	movl	$0, (%eax)
	movl	(%edx), %ecx
	movl	%ecx, 4(%eax)
	testl	%ecx, %ecx
	je	.L150
	movl	%eax, (%ecx)
.L151:
	movl	%eax, (%edx)
	incw	12(%edx)
	movb	$1, %al
	ret
.L152:
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
.L149:
	andl	$65535, %eax
	leal	(%eax,%eax,2), %eax
	leal	NodePool+8(,%eax,4), %eax
	incw	14(%edx)
	jmp	.L148
.L150:
	movl	%eax, 4(%edx)
	jmp	.L151
.L146:
	movl	NodePool, %eax
	testw	%ax, %ax
	jne	.L152
	movl	NodePool+4, %eax
	leal	1(%eax), %ecx
	movw	%cx, NodePool+4
	jmp	.L149
	.cfi_endproc
.LFE135:
	.size	_ZN8junction11consecutionL6AccedeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_, .-_ZN8junction11consecutionL6AccedeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_
	.type	_ZN8junction11consecutionL7ProceedItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_, @function
_ZN8junction11consecutionL7ProceedItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_:
.LFB137:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	8(%edx), %eax
	testl	%eax, %eax
	je	.L157
	movl	4(%eax), %ecx
	movl	%ecx, 8(%edx)
	testl	%ecx, %ecx
	je	.L158
	movl	$0, (%ecx)
.L158:
	movl	$0, 4(%eax)
.L159:
	movl	8(%esp), %ecx
	movb	(%ecx), %cl
	movb	%cl, 8(%eax)
	movl	4(%edx), %ecx
	movl	%ecx, (%eax)
	movl	$0, 4(%eax)
	movl	4(%edx), %ecx
	testl	%ecx, %ecx
	je	.L161
	movl	%eax, 4(%ecx)
.L162:
	movl	%eax, 4(%edx)
	incw	12(%edx)
	movb	$1, %al
	ret
.L163:
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
.L160:
	andl	$65535, %eax
	leal	(%eax,%eax,2), %eax
	leal	NodePool+8(,%eax,4), %eax
	incw	14(%edx)
	jmp	.L159
.L161:
	movl	%eax, (%edx)
	jmp	.L162
.L157:
	movl	NodePool, %eax
	testw	%ax, %ax
	jne	.L163
	movl	NodePool+4, %eax
	leal	1(%eax), %ecx
	movw	%cx, NodePool+4
	jmp	.L160
	.cfi_endproc
.LFE137:
	.size	_ZN8junction11consecutionL7ProceedItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_, .-_ZN8junction11consecutionL7ProceedItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_
	.type	_ZN8junction11consecutionL7PrecedeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS4_EEEERKS4_, @function
_ZN8junction11consecutionL7PrecedeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS4_EEEERKS4_:
.LFB136:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	movl	12(%esp), %ecx
	movl	8(%edx), %eax
	testl	%eax, %eax
	je	.L168
	movl	4(%eax), %ebx
	movl	%ebx, 8(%edx)
	testl	%ebx, %ebx
	je	.L169
	movl	$0, (%ebx)
.L169:
	movl	$0, 4(%eax)
.L170:
	movl	16(%esp), %ebx
	movb	(%ebx), %bl
	movb	%bl, 8(%eax)
	movl	(%ecx), %ebx
	movl	(%ebx), %ebx
	testl	%ebx, %ebx
	je	.L172
	movl	%eax, 4(%ebx)
.L173:
	movl	(%ecx), %ebx
	movl	(%ebx), %ebx
	movl	%ebx, (%eax)
	movl	(%ecx), %ecx
	movl	%ecx, 4(%eax)
	movl	%eax, (%ecx)
	incw	12(%edx)
	movb	$1, %al
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
.L174:
	.cfi_restore_state
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
.L171:
	andl	$65535, %eax
	leal	(%eax,%eax,2), %eax
	leal	NodePool+8(,%eax,4), %eax
	incw	14(%edx)
	jmp	.L170
.L172:
	movl	%eax, (%edx)
	jmp	.L173
.L168:
	movl	NodePool, %eax
	testw	%ax, %ax
	jne	.L174
	movl	NodePool+4, %eax
	leal	1(%eax), %ebx
	movw	%bx, NodePool+4
	jmp	.L171
	.cfi_endproc
.LFE136:
	.size	_ZN8junction11consecutionL7PrecedeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS4_EEEERKS4_, .-_ZN8junction11consecutionL7PrecedeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS4_EEEERKS4_
	.type	_ZN8junction11consecutionL7PrecedeINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKNS5_INS6_ISA_EEEERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSK_RKSL_ST_, @function
_ZN8junction11consecutionL7PrecedeINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKNS5_INS6_ISA_EEEERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSK_RKSL_ST_:
.LFB131:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	64(%esp), %ebx
	movl	72(%esp), %eax
	movl	(%eax), %ecx
	movl	%ecx, 4(%esp)
	movl	80(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 24(%esp)
	leal	12(%esp), %eax
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	leal	28(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	pushl	84(%esp)
	.cfi_def_cfa_offset 76
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	*12(%ecx)
	.cfi_def_cfa_offset 76
	movl	24(%esp), %edx
	movl	8(%ebx), %esi
	addl	$12, %esp
	.cfi_def_cfa_offset 64
	testl	%esi, %esi
	je	.L180
	movl	4(%esi), %eax
	movl	%eax, 8(%ebx)
	testl	%eax, %eax
	je	.L181
	movl	$0, (%eax)
.L181:
	movl	$0, 4(%esi)
.L182:
	movb	(%edx), %al
	movb	%al, 8(%esi)
	movl	%esi, %edi
	movl	$1, %ebp
	movl	%esi, 8(%esp)
	movl	4(%esp), %esi
	jmp	.L189
.L195:
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
.L183:
	andl	$65535, %eax
	leal	(%eax,%eax,2), %eax
	leal	NodePool+8(,%eax,4), %esi
	incw	14(%ebx)
	jmp	.L182
.L186:
	movl	$0, 4(%eax)
.L187:
	movb	(%edx), %cl
	movb	%cl, 8(%eax)
	movl	%eax, 4(%edi)
	movl	%edi, (%eax)
	movl	4(%edi), %edi
	incl	%ebp
.L189:
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	movl	(%esi), %eax
	movl	(%eax), %eax
	pushl	92(%esp)
	.cfi_def_cfa_offset 76
	leal	36(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 80
	call	*4(%eax)
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	testb	%al, %al
	je	.L184
	movl	72(%esp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %eax
	movw	$1, 30(%esp)
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	leal	34(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	leal	32(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 76
	pushl	88(%esp)
	.cfi_def_cfa_offset 80
	call	*%eax
	leal	28(%esp), %eax
	addl	$12, %esp
	.cfi_def_cfa_offset 68
	leal	28(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	pushl	84(%esp)
	.cfi_def_cfa_offset 76
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	*12(%esi)
	.cfi_def_cfa_offset 76
	movl	24(%esp), %edx
	movl	8(%ebx), %eax
	addl	$12, %esp
	.cfi_def_cfa_offset 64
	testl	%eax, %eax
	je	.L185
	movl	4(%eax), %ecx
	movl	%ecx, 8(%ebx)
	testl	%ecx, %ecx
	je	.L186
	movl	$0, (%ecx)
	jmp	.L186
.L193:
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
.L188:
	andl	$65535, %eax
	leal	(%eax,%eax,2), %eax
	leal	NodePool+8(,%eax,4), %eax
	incw	14(%ebx)
	jmp	.L187
.L184:
	movl	8(%esp), %esi
	testw	%bp, %bp
	je	.L179
	movl	68(%esp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	%eax, (%esi)
	testl	%eax, %eax
	je	.L191
	movl	%esi, 4(%eax)
.L192:
	movl	68(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%edi)
	movl	%edi, (%eax)
	addw	%bp, 12(%ebx)
	movb	$1, %al
.L179:
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
.L191:
	.cfi_restore_state
	movl	%esi, (%ebx)
	jmp	.L192
.L185:
	movl	NodePool, %eax
	testw	%ax, %ax
	jne	.L193
	movl	NodePool+4, %eax
	leal	1(%eax), %ecx
	movw	%cx, NodePool+4
	jmp	.L188
.L180:
	movl	NodePool, %eax
	testw	%ax, %ax
	jne	.L195
	movl	NodePool+4, %eax
	leal	1(%eax), %ecx
	movw	%cx, NodePool+4
	jmp	.L183
	.cfi_endproc
.LFE131:
	.size	_ZN8junction11consecutionL7PrecedeINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKNS5_INS6_ISA_EEEERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSK_RKSL_ST_, .-_ZN8junction11consecutionL7PrecedeINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKNS5_INS6_ISA_EEEERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSK_RKSL_ST_
	.type	_ZN8junction11consecutionL6AccedeINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSG_RKSH_SP_, @function
_ZN8junction11consecutionL6AccedeINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSG_RKSH_SP_:
.LFB130:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	64(%esp), %ebx
	movl	68(%esp), %eax
	movl	(%eax), %ecx
	movl	%ecx, 4(%esp)
	movl	76(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 24(%esp)
	leal	12(%esp), %eax
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	leal	28(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	pushl	80(%esp)
	.cfi_def_cfa_offset 76
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	*12(%ecx)
	.cfi_def_cfa_offset 76
	movl	24(%esp), %edx
	movl	8(%ebx), %edi
	addl	$12, %esp
	.cfi_def_cfa_offset 64
	testl	%edi, %edi
	je	.L201
	movl	4(%edi), %eax
	movl	%eax, 8(%ebx)
	testl	%eax, %eax
	je	.L202
	movl	$0, (%eax)
.L202:
	movl	$0, 4(%edi)
.L203:
	movb	(%edx), %al
	movb	%al, 8(%edi)
	movl	%edi, %esi
	movl	$1, %ebp
	movl	%edi, 8(%esp)
	movl	4(%esp), %edi
	jmp	.L210
.L216:
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
.L204:
	andl	$65535, %eax
	leal	(%eax,%eax,2), %eax
	leal	NodePool+8(,%eax,4), %edi
	incw	14(%ebx)
	jmp	.L203
.L207:
	movl	$0, 4(%eax)
.L208:
	movb	(%edx), %cl
	movb	%cl, 8(%eax)
	movl	%eax, 4(%esi)
	movl	%esi, (%eax)
	movl	4(%esi), %esi
	incl	%ebp
.L210:
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	movl	(%edi), %eax
	movl	(%eax), %eax
	pushl	88(%esp)
	.cfi_def_cfa_offset 76
	leal	36(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 80
	call	*4(%eax)
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	testb	%al, %al
	je	.L205
	movl	68(%esp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %eax
	movw	$1, 30(%esp)
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	leal	34(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	leal	32(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 76
	pushl	84(%esp)
	.cfi_def_cfa_offset 80
	call	*%eax
	leal	28(%esp), %eax
	addl	$12, %esp
	.cfi_def_cfa_offset 68
	leal	28(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	pushl	80(%esp)
	.cfi_def_cfa_offset 76
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	*12(%edi)
	.cfi_def_cfa_offset 76
	movl	24(%esp), %edx
	movl	8(%ebx), %eax
	addl	$12, %esp
	.cfi_def_cfa_offset 64
	testl	%eax, %eax
	je	.L206
	movl	4(%eax), %ecx
	movl	%ecx, 8(%ebx)
	testl	%ecx, %ecx
	je	.L207
	movl	$0, (%ecx)
	jmp	.L207
.L214:
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
.L209:
	andl	$65535, %eax
	leal	(%eax,%eax,2), %eax
	leal	NodePool+8(,%eax,4), %eax
	incw	14(%ebx)
	jmp	.L208
.L205:
	movl	8(%esp), %edi
	testw	%bp, %bp
	je	.L200
	movl	(%ebx), %eax
	movl	%eax, 4(%esi)
	testl	%eax, %eax
	je	.L212
	movl	%esi, (%eax)
.L213:
	movl	%edi, (%ebx)
	addw	%bp, 12(%ebx)
	movb	$1, %al
.L200:
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
.L212:
	.cfi_restore_state
	movl	%esi, 4(%ebx)
	jmp	.L213
.L206:
	movl	NodePool, %eax
	testw	%ax, %ax
	jne	.L214
	movl	NodePool+4, %eax
	leal	1(%eax), %ecx
	movw	%cx, NodePool+4
	jmp	.L209
.L201:
	movl	NodePool, %eax
	testw	%ax, %ax
	jne	.L216
	movl	NodePool+4, %eax
	leal	1(%eax), %ecx
	movw	%cx, NodePool+4
	jmp	.L204
	.cfi_endproc
.LFE130:
	.size	_ZN8junction11consecutionL6AccedeINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSG_RKSH_SP_, .-_ZN8junction11consecutionL6AccedeINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSG_RKSH_SP_
	.type	_ZN8junction11consecutionL7ProceedINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSG_RKSH_SP_, @function
_ZN8junction11consecutionL7ProceedINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSG_RKSH_SP_:
.LFB132:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	64(%esp), %ebx
	movl	68(%esp), %eax
	movl	(%eax), %ecx
	movl	%ecx, 4(%esp)
	movl	76(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 24(%esp)
	leal	12(%esp), %eax
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	leal	28(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	pushl	80(%esp)
	.cfi_def_cfa_offset 76
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	*12(%ecx)
	.cfi_def_cfa_offset 76
	movl	24(%esp), %edx
	movl	8(%ebx), %esi
	addl	$12, %esp
	.cfi_def_cfa_offset 64
	testl	%esi, %esi
	je	.L222
	movl	4(%esi), %eax
	movl	%eax, 8(%ebx)
	testl	%eax, %eax
	je	.L223
	movl	$0, (%eax)
.L223:
	movl	$0, 4(%esi)
.L224:
	movb	(%edx), %al
	movb	%al, 8(%esi)
	movl	%esi, %edi
	movl	$1, %ebp
	movl	%esi, 8(%esp)
	movl	4(%esp), %esi
	jmp	.L231
.L237:
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
.L225:
	andl	$65535, %eax
	leal	(%eax,%eax,2), %eax
	leal	NodePool+8(,%eax,4), %esi
	incw	14(%ebx)
	jmp	.L224
.L228:
	movl	$0, 4(%eax)
.L229:
	movb	(%edx), %cl
	movb	%cl, 8(%eax)
	movl	%eax, 4(%edi)
	movl	%edi, (%eax)
	movl	4(%edi), %edi
	incl	%ebp
.L231:
	subl	$8, %esp
	.cfi_def_cfa_offset 72
	movl	(%esi), %eax
	movl	(%eax), %eax
	pushl	88(%esp)
	.cfi_def_cfa_offset 76
	leal	36(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 80
	call	*4(%eax)
	addl	$16, %esp
	.cfi_def_cfa_offset 64
	testb	%al, %al
	je	.L226
	movl	68(%esp), %eax
	movl	(%eax), %eax
	movl	8(%eax), %eax
	movw	$1, 30(%esp)
	subl	$4, %esp
	.cfi_def_cfa_offset 68
	leal	34(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	leal	32(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 76
	pushl	84(%esp)
	.cfi_def_cfa_offset 80
	call	*%eax
	leal	28(%esp), %eax
	addl	$12, %esp
	.cfi_def_cfa_offset 68
	leal	28(%esp), %edx
	pushl	%edx
	.cfi_def_cfa_offset 72
	pushl	80(%esp)
	.cfi_def_cfa_offset 76
	pushl	%eax
	.cfi_def_cfa_offset 80
	call	*12(%esi)
	.cfi_def_cfa_offset 76
	movl	24(%esp), %edx
	movl	8(%ebx), %eax
	addl	$12, %esp
	.cfi_def_cfa_offset 64
	testl	%eax, %eax
	je	.L227
	movl	4(%eax), %ecx
	movl	%ecx, 8(%ebx)
	testl	%ecx, %ecx
	je	.L228
	movl	$0, (%ecx)
	jmp	.L228
.L235:
	decl	%eax
	movw	%ax, NodePool
	andl	$65535, %eax
	movw	NodePool+44(%eax,%eax), %ax
.L230:
	andl	$65535, %eax
	leal	(%eax,%eax,2), %eax
	leal	NodePool+8(,%eax,4), %eax
	incw	14(%ebx)
	jmp	.L229
.L226:
	movl	8(%esp), %esi
	testw	%bp, %bp
	je	.L221
	movl	4(%ebx), %eax
	movl	%eax, (%esi)
	testl	%eax, %eax
	je	.L233
	movl	%esi, 4(%eax)
.L234:
	movl	%edi, 4(%ebx)
	addw	%bp, 12(%ebx)
	movb	$1, %al
.L221:
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
.L233:
	.cfi_restore_state
	movl	%esi, (%ebx)
	jmp	.L234
.L227:
	movl	NodePool, %eax
	testw	%ax, %ax
	jne	.L235
	movl	NodePool+4, %eax
	leal	1(%eax), %ecx
	movw	%cx, NodePool+4
	jmp	.L230
.L222:
	movl	NodePool, %eax
	testw	%ax, %ax
	jne	.L237
	movl	NodePool+4, %eax
	leal	1(%eax), %ecx
	movw	%cx, NodePool+4
	jmp	.L225
	.cfi_endproc
.LFE132:
	.size	_ZN8junction11consecutionL7ProceedINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSG_RKSH_SP_, .-_ZN8junction11consecutionL7ProceedINS_8JunctiveItcEEN8location8PositiveINS_10JunctionalIcEEEEttcL_ZL15NodePoolAdjunctEEEbRNS2_IT2_T3_EERKN10trajection11DirectionalIKT_T0_T1_KSA_EERSG_RKSH_SP_
	.section	.rodata.str1.1
.LC1:
	.string	" (should read 'A','B','C')"
.LC2:
	.string	" (should read 'B')"
	.text
	.globl	main
	.type	main, @function
main:
.LFB124:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$32, %esp
	movl	$0, -36(%ebp)
	movl	$0, -32(%ebp)
	movl	$0, -28(%ebp)
	movw	$0, -24(%ebp)
	movw	$0, -22(%ebp)
	movw	$3, -10(%ebp)
	leal	-10(%ebp), %eax
	pushl	%eax
	leal	-36(%ebp), %ebx
	pushl	%ebx
	call	_ZN8junctionL11InstantiateItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS2_
	movb	$66, -11(%ebp)
	leal	-11(%ebp), %eax
	pushl	%eax
	pushl	%ebx
	call	_ZN8junction11consecutionL7ProceedItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_
	movb	$65, -12(%ebp)
	leal	-12(%ebp), %eax
	pushl	%eax
	pushl	%ebx
	call	_ZN8junction11consecutionL6AccedeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_
	movb	$67, -13(%ebp)
	leal	-13(%ebp), %eax
	pushl	%eax
	pushl	%ebx
	call	_ZN8junction11consecutionL7ProceedItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EERKS4_
	addl	$32, %esp
	movl	$_ZN8junctionL22ReadIncrementDirectionItcEE, %edx
	movl	%ebx, %eax
	call	_Z17DisplayCharactersIN8junction8JunctiveItcEEN8location8PositiveINS0_10JunctionalIcEEEEtEbRKT_RKN10trajection11DirectionalIS9_T0_T1_KcEE
	subl	$12, %esp
	pushl	$.LC1
	call	puts
	movw	$1, -16(%ebp)
	addl	$8, %esp
	leal	-16(%ebp), %eax
	pushl	%eax
	pushl	%ebx
	call	_ZN8junction11consecutionL7SucceedItcEEbRNS_8JunctiveIT_T0_EERKS3_
	movw	$1, -18(%ebp)
	addl	$8, %esp
	leal	-18(%ebp), %eax
	pushl	%eax
	pushl	%ebx
	call	_ZN8junction11consecutionL6RecedeItcEEbRNS_8JunctiveIT_T0_EERKS3_
	addl	$16, %esp
	movl	$_ZN8junctionL22ReadIncrementDirectionItcEE, %edx
	movl	%ebx, %eax
	call	_Z17DisplayCharactersIN8junction8JunctiveItcEEN8location8PositiveINS0_10JunctionalIcEEEEtEbRKT_RKN10trajection11DirectionalIS9_T0_T1_KcEE
	subl	$12, %esp
	pushl	$.LC2
	call	puts
	movl	%ebx, (%esp)
	call	_ZN8junctionL5EmptyItcEEbRNS_8JunctiveIT_T0_EE
	addl	$16, %esp
.L243:
	subl	$12, %esp
	pushl	%ebx
	call	_ZN8junctionL4FreeItcL_ZL15NodePoolAdjunctEEEbRNS_8JunctiveIT_T0_EE
	addl	$16, %esp
	testb	%al, %al
	jne	.L243
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE124:
	.size	main, .-main
	.section	.rodata
	.align 4
	.type	_ZN8junctionL22ReadIncrementDirectionItcEE, @object
	.size	_ZN8junctionL22ReadIncrementDirectionItcEE, 24
_ZN8junctionL22ReadIncrementDirectionItcEE:
	.long	_ZN8junctionL18ReadIncrementScaleItcEE
	.long	_ZN8junctionL15IncrementBeginsItcEEbRKNS_8JunctiveIT_T0_EERKS2_
	.long	_ZN8junctionL20IncrementTraversableItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEERKS2_
	.long	_ZN8junctionL8ContainsItcEEbRKNS_8JunctiveIT_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE
	.long	_ZN8junctionL7AccountItcEET_RKNS_8JunctiveIS1_T0_EE
	.long	_ZN8junctionL14CountIncrementItcEET_RKNS_8JunctiveIS1_T0_EERKN8location8PositiveINS_10JunctionalIS3_EEEE
	.align 4
	.type	_ZN8junctionL18ReadIncrementScaleItcEE, @object
	.size	_ZN8junctionL18ReadIncrementScaleItcEE, 16
_ZN8junctionL18ReadIncrementScaleItcEE:
	.long	_ZN8junctionL10ComparisonIcEE
	.long	_ZN8junctionL18BeginReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_
	.long	_ZN8junctionL21TraverseReadIncrementItcEERKN8location8PositiveINS_10JunctionalIT0_EEEERKNS_8JunctiveIT_S4_EERS6_RKSA_
	.long	_ZN8junctionL6GoReadItcEEN8location12ConferentialIKT0_EERKNS_8JunctiveIT_S3_EERKNS1_8PositiveINS_10JunctionalIS3_EEEE
	.align 4
	.type	_ZN8junctionL10ComparisonIcEE, @object
	.size	_ZN8junctionL10ComparisonIcEE, 8
_ZN8junctionL10ComparisonIcEE:
	.long	_ZN8junctionL8EqualityIcEE
	.long	_ZN8junctionL8RelationIcEE
	.align 4
	.type	_ZN8junctionL8RelationIcEE, @object
	.size	_ZN8junctionL8RelationIcEE, 16
_ZN8junctionL8RelationIcEE:
	.long	_ZN8junctionL8IsLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.long	_ZN8junctionL9IsGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.long	_ZN8junctionL12IsNotGreaterIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.long	_ZN8junctionL11IsNotLesserIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.align 4
	.type	_ZN8junctionL8EqualityIcEE, @object
	.size	_ZN8junctionL8EqualityIcEE, 8
_ZN8junctionL8EqualityIcEE:
	.long	_ZN8junctionL7IsEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.long	_ZN8junctionL10IsNotEqualIcEEbRKN8location8PositiveINS_10JunctionalIT_EEEES8_
	.globl	NodePool
	.bss
	.align 32
	.type	NodePool, @object
	.size	NodePool, 52
NodePool:
	.zero	52
	.ident	"GCC: (GNU) 8.1.1 20180626"
	.section	.note.GNU-stack,"",@progbits
