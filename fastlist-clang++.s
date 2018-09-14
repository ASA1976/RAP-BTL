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
	leal	(,%edx,4), %esi
	leal	NodePool+8(%esi,%esi,2), %edi
	movl	%ecx, NodePool+12(%esi,%esi,2)
	movl	%edi, 16(%esp)          # 4-byte Spill
	movl	%edi, (%ecx)
	je	.LBB0_44
# %bb.6:
	decl	%eax
	movw	%ax, NodePool
	movzwl	%ax, %ecx
	movzwl	NodePool+44(%ecx,%ecx), %ecx
	jmp	.LBB0_7
.LBB0_44:
	movzwl	NodePool+4, %ecx
	movl	%ecx, %esi
	incl	%esi
	movw	%si, NodePool+4
.LBB0_7:
	movl	16(%esp), %esi          # 4-byte Reload
	movzwl	%cx, %ebx
	shll	$2, %ebx
	leal	NodePool+8(%ebx,%ebx,2), %ecx
	movl	$0, (%esi)
	leal	(%edx,%edx,2), %esi
	movb	$66, NodePool+16(%ebx,%ebx,2)
	movl	$0, NodePool+8(%ebx,%ebx,2)
	movl	$0, NodePool+12(%ebx,%ebx,2)
	movl	NodePool+12(,%esi,4), %edi
	leal	NodePool+12(,%esi,4), %edx
	movl	%edx, 20(%esp)          # 4-byte Spill
	testl	%edi, %edi
	je	.LBB0_9
# %bb.8:
	movl	$0, (%edi)
.LBB0_9:
	leal	NodePool+12(%ebx,%ebx,2), %edx
	movl	16(%esp), %ebx          # 4-byte Reload
	leal	NodePool+16(,%esi,4), %ebp
	testl	%edi, %edi
	movb	$65, NodePool+16(,%esi,4)
	movl	%edx, 24(%esp)          # 4-byte Spill
	movl	20(%esp), %edx          # 4-byte Reload
	movl	$0, (%ebx)
	movl	%ecx, (%edx)
	movl	%ebx, (%ecx)
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
	movl	$.L.str.3, (%esp)
	movl	%edi, (%eax)
	movsbl	(%ebp), %eax
	movl	%eax, 4(%esp)
	calll	printf
	cmpl	$0, NodePool+12(,%esi,4)
	je	.LBB0_20
# %bb.18:
	movl	16(%esp), %esi          # 4-byte Reload
	.p2align	4, 0x90
.LBB0_19:                               # =>This Inner Loop Header: Depth=1
	movl	$44, (%esp)
	calll	putchar
	movl	4(%esi), %esi
	movsbl	8(%esi), %eax
	movl	$.L.str.3, (%esp)
	movl	%eax, 4(%esp)
	calll	printf
	cmpl	$0, 4(%esi)
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
	movl	16(%esp), %eax          # 4-byte Reload
	movl	%eax, (%ebx)
.LBB0_25:
	testl	%edi, %edi
	je	.LBB0_26
# %bb.27:
	movl	(%edi), %esi
	testl	%esi, %esi
	je	.LBB0_28
# %bb.29:
	movl	%ebp, %ebx
	movl	$0, 4(%esi)
	movl	$0, (%edi)
	jmp	.LBB0_30
.LBB0_26:
	movl	16(%esp), %edi          # 4-byte Reload
	xorl	%esi, %esi
	movl	%ebp, %ebx
	jmp	.LBB0_31
.LBB0_28:
	xorl	%ebx, %ebx
	xorl	%ebp, %ebp
.LBB0_30:
	movl	16(%esp), %eax          # 4-byte Reload
	movl	%eax, 4(%edi)
	movl	%edi, (%eax)
.LBB0_31:
	testl	%ebp, %ebp
	jne	.LBB0_33
	jmp	.LBB0_34
	.p2align	4, 0x90
.LBB0_32:                               #   in Loop: Header=BB0_33 Depth=1
	movl	$44, (%esp)
	calll	putchar
	movl	4(%ebp), %ebp
.LBB0_33:                               # =>This Inner Loop Header: Depth=1
	movsbl	8(%ebp), %eax
	movl	$.L.str.3, (%esp)
	movl	%eax, 4(%esp)
	calll	printf
	cmpl	$0, 4(%ebp)
	jne	.LBB0_32
.LBB0_34:
	movl	$.L.str.2, (%esp)
	calll	puts
	testl	%esi, %esi
	je	.LBB0_35
# %bb.36:
	testl	%edi, %edi
	movl	%edi, 4(%esi)
	je	.LBB0_38
# %bb.37:
	movl	%esi, (%edi)
.LBB0_38:
	testl	%ebx, %ebx
	jne	.LBB0_39
	jmp	.LBB0_43
.LBB0_35:
	movl	%edi, %ebx
	testl	%ebx, %ebx
	je	.LBB0_43
.LBB0_39:
	movzwl	NodePool, %edi
	movl	4(%ebx), %ecx
	movl	$NodePool+8, %eax
	subl	%eax, %ebx
	shrl	$2, %ebx
	imull	$-1431655765, %ebx, %esi # imm = 0xAAAAAAAB
	leal	1(%edi), %edx
	testl	%ecx, %ecx
	movw	%si, NodePool+44(%edi,%edi)
	je	.LBB0_40
	.p2align	4, 0x90
.LBB0_41:                               # =>This Inner Loop Header: Depth=1
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
	jne	.LBB0_41
	jmp	.LBB0_42
.LBB0_40:
	movl	%edx, %esi
.LBB0_42:
	movw	%si, NodePool
.LBB0_43:
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
