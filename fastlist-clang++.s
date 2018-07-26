	.text
	.file	"fastlist.cpp"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
# %bb.0:
	pushl	%ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$28, %esp
	movzwl	NodePool, %eax
	testw	%ax, %ax
	je	.LBB0_1
# %bb.3:
	leal	-1(%eax), %ecx
	movw	%cx, NodePool
	movzwl	%cx, %edx
	movzwl	NodePool+44(%edx,%edx), %esi
	shll	$2, %esi
	testw	%dx, %dx
	leal	NodePool+8(%esi,%esi,2), %ecx
	movl	$0, NodePool+12(%esi,%esi,2)
	je	.LBB0_2
# %bb.4:
	addl	$-2, %eax
	movw	%ax, NodePool
	movzwl	%ax, %edx
	movzwl	NodePool+44(%edx,%edx), %edx
	jmp	.LBB0_5
.LBB0_1:
	movzwl	NodePool+4, %eax
	leal	1(%eax), %ecx
	shll	$2, %eax
	movw	%cx, NodePool+4
	leal	NodePool+8(%eax,%eax,2), %ecx
	movl	$0, NodePool+12(%eax,%eax,2)
.LBB0_2:
	movzwl	NodePool+4, %edx
	movl	%edx, %eax
	incl	%eax
	movw	%ax, NodePool+4
	xorl	%eax, %eax
.LBB0_5:
	movzwl	%dx, %edx
	testw	%ax, %ax
	leal	(,%edx,4), %edi
	leal	NodePool+8(%edi,%edi,2), %esi
	movl	%ecx, NodePool+12(%edi,%edi,2)
	movl	%esi, (%ecx)
	je	.LBB0_45
# %bb.6:
	decl	%eax
	movw	%ax, NodePool
	movzwl	%ax, %ecx
	movzwl	NodePool+44(%ecx,%ecx), %ecx
	jmp	.LBB0_7
.LBB0_45:
	movzwl	NodePool+4, %ecx
	movl	%ecx, %edi
	incl	%edi
	movw	%di, NodePool+4
.LBB0_7:
	movzwl	%cx, %ebx
	leal	(%edx,%edx,2), %ebp
	movl	$0, (%esi)
	shll	$2, %ebx
	leal	NodePool+12(,%ebp,4), %edx
	movb	$66, NodePool+16(%ebx,%ebx,2)
	movl	$0, NodePool+8(%ebx,%ebx,2)
	movl	$0, NodePool+12(%ebx,%ebx,2)
	leal	NodePool+8(%ebx,%ebx,2), %ecx
	movl	%edx, 20(%esp)          # 4-byte Spill
	movl	NodePool+12(,%ebp,4), %edi
	testl	%edi, %edi
	je	.LBB0_9
# %bb.8:
	movl	$0, (%edi)
.LBB0_9:
	leal	NodePool+12(%ebx,%ebx,2), %edx
	leal	NodePool+16(,%ebp,4), %ebx
	testl	%edi, %edi
	movb	$65, NodePool+16(,%ebp,4)
	movl	$0, (%esi)
	movl	%ebx, 24(%esp)          # 4-byte Spill
	movl	20(%esp), %ebx          # 4-byte Reload
	movl	%ecx, (%ebx)
	movl	%esi, (%ecx)
	je	.LBB0_13
# %bb.10:
	movl	4(%edi), %ebx
	leal	4(%edi), %eax
	testl	%ebx, %ebx
	je	.LBB0_12
# %bb.11:
	movl	$0, (%ebx)
.LBB0_12:
	movl	$0, (%eax)
	jmp	.LBB0_17
.LBB0_13:
	testw	%ax, %ax
	je	.LBB0_15
# %bb.14:
	decl	%eax
	movw	%ax, NodePool
	movzwl	%ax, %eax
	movzwl	NodePool+44(%eax,%eax), %eax
	jmp	.LBB0_16
.LBB0_15:
	movzwl	NodePool+4, %eax
	movl	%eax, %edi
	incl	%edi
	movw	%di, NodePool+4
.LBB0_16:
	movzwl	%ax, %eax
	xorl	%ebx, %ebx
	shll	$2, %eax
	leal	NodePool+8(%eax,%eax,2), %edi
	leal	NodePool+12(%eax,%eax,2), %eax
.LBB0_17:
	movb	$67, 8(%edi)
	movl	%ecx, (%edi)
	movl	$0, (%eax)
	movl	24(%esp), %eax          # 4-byte Reload
	movl	%edi, (%edx)
	movl	$.L.str.3, (%esp)
	movsbl	(%eax), %eax
	movl	%eax, 4(%esp)
	calll	printf
	cmpl	$0, NodePool+12(,%ebp,4)
	je	.LBB0_20
# %bb.18:
	movl	20(%esp), %ebp          # 4-byte Reload
	.p2align	4, 0x90
.LBB0_19:                               # =>This Inner Loop Header: Depth=1
	movl	$44, (%esp)
	calll	putchar
	movl	(%ebp), %ebp
	movsbl	8(%ebp), %eax
	movl	$.L.str.3, (%esp)
	movl	%eax, 4(%esp)
	calll	printf
	cmpl	$0, 4(%ebp)
	leal	4(%ebp), %ebp
	jne	.LBB0_19
.LBB0_20:
	movl	$.L.str, (%esp)
	calll	puts
	movl	20(%esp), %eax          # 4-byte Reload
	movl	(%eax), %ebp
	testl	%ebp, %ebp
	je	.LBB0_21
# %bb.22:
	movl	$0, (%ebp)
	jmp	.LBB0_23
.LBB0_21:
	xorl	%edi, %edi
.LBB0_23:
	movl	20(%esp), %eax          # 4-byte Reload
	testl	%ebx, %ebx
	movl	%ebx, (%eax)
	je	.LBB0_25
# %bb.24:
	movl	%esi, (%ebx)
.LBB0_25:
	testl	%edi, %edi
	je	.LBB0_26
# %bb.27:
	movl	(%edi), %ebx
	testl	%ebx, %ebx
	je	.LBB0_28
# %bb.29:
	movl	$0, 4(%ebx)
	movl	$0, (%edi)
	jmp	.LBB0_30
.LBB0_26:
	xorl	%ebx, %ebx
	movl	%esi, %edi
	testl	%ebp, %ebp
	jne	.LBB0_32
	jmp	.LBB0_35
.LBB0_28:
	xorl	%ebp, %ebp
.LBB0_30:
	movl	%esi, 4(%edi)
	movl	%edi, (%esi)
	testl	%ebp, %ebp
	je	.LBB0_35
.LBB0_32:
	movsbl	8(%ebp), %eax
	movl	$.L.str.3, (%esp)
	movl	%eax, 4(%esp)
	calll	printf
	cmpl	$0, 4(%ebp)
	je	.LBB0_35
# %bb.33:
	movl	%ebp, %esi
	addl	$4, %esi
	.p2align	4, 0x90
.LBB0_34:                               # =>This Inner Loop Header: Depth=1
	movl	$44, (%esp)
	calll	putchar
	movl	(%esi), %esi
	movsbl	8(%esi), %eax
	movl	$.L.str.3, (%esp)
	movl	%eax, 4(%esp)
	calll	printf
	cmpl	$0, 4(%esi)
	leal	4(%esi), %esi
	jne	.LBB0_34
.LBB0_35:
	movl	$.L.str.2, (%esp)
	calll	puts
	testl	%ebx, %ebx
	je	.LBB0_36
# %bb.37:
	testl	%edi, %edi
	movl	%edi, 4(%ebx)
	je	.LBB0_39
# %bb.38:
	movl	%ebx, (%edi)
.LBB0_39:
	testl	%ebp, %ebp
	jne	.LBB0_40
	jmp	.LBB0_44
.LBB0_36:
	movl	%edi, %ebp
	testl	%ebp, %ebp
	je	.LBB0_44
.LBB0_40:
	movzwl	NodePool, %edi
	movl	4(%ebp), %ecx
	movl	$NodePool+8, %eax
	subl	%eax, %ebp
	shrl	$2, %ebp
	imull	$-1431655765, %ebp, %esi # imm = 0xAAAAAAAB
	leal	1(%edi), %edx
	testl	%ecx, %ecx
	movw	%si, NodePool+44(%edi,%edi)
	je	.LBB0_41
	.p2align	4, 0x90
.LBB0_42:                               # =>This Inner Loop Header: Depth=1
	movl	$0, (%ecx)
	leal	1(%edx), %esi
	movzwl	%dx, %edx
	movl	4(%ecx), %edi
	subl	%eax, %ecx
	shrl	$2, %ecx
	imull	$-1431655765, %ecx, %ecx # imm = 0xAAAAAAAB
	movw	%cx, NodePool+44(%edx,%edx)
	movl	%esi, %edx
	testl	%edi, %edi
	movl	%edi, %ecx
	jne	.LBB0_42
	jmp	.LBB0_43
.LBB0_41:
	movl	%edx, %esi
.LBB0_43:
	movw	%si, NodePool
.LBB0_44:
	xorl	%eax, %eax
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        # -- End function
	.type	NodePool,@object        # @NodePool
	.bss
	.globl	NodePool
	.p2align	2
NodePool:
	.zero	52
	.size	NodePool, 52

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	" (should read 'A','B','C')"
	.size	.L.str, 27

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	" (should read 'B')"
	.size	.L.str.2, 19

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"'%c'"
	.size	.L.str.3, 5


	.ident	"clang version 6.0.1 (tags/RELEASE_601/final)"
	.section	".note.GNU-stack","",@progbits
