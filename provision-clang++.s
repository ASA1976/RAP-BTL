	.text
	.file	"provision.cpp"
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
	movl	$16, 4(%esp)
	movl	$.L.str.1, (%esp)
	calll	printf
	movl	$2, 4(%esp)
	movl	$.L.str.2, (%esp)
	calll	printf
	movl	$0, 4(%esp)
	movl	$.L.str.2, (%esp)
	calll	printf
	movl	$16, 4(%esp)
	movl	$.L.str.3, (%esp)
	calll	printf
	movl	$2, 4(%esp)
	movl	$.L.str.4, (%esp)
	calll	printf
	movl	$0, 4(%esp)
	movl	$.L.str.4, (%esp)
	calll	printf
	movl	$16, 4(%esp)
	movl	$.L.str.5, (%esp)
	calll	printf
	movl	$1, 4(%esp)
	movl	$.L.str.6, (%esp)
	calll	printf
	movl	$0, 4(%esp)
	movl	$.L.str.6, (%esp)
	calll	printf
	movl	$10, (%esp)
	calll	putchar
	movl	$16, 4(%esp)
	movl	$.L.str.1, (%esp)
	calll	printf
	movl	$12, 4(%esp)
	movl	$4, (%esp)
	calll	aligned_alloc
	movl	%eax, %edi
	testl	%edi, %edi
	je	.LBB0_3
# %bb.1:
	movl	$0, 4(%edi)
	movl	$12, 4(%esp)
	movl	$4, (%esp)
	calll	aligned_alloc
	testl	%eax, %eax
	movl	%eax, 4(%edi)
	je	.LBB0_4
# %bb.2:
	movl	%edi, (%eax)
	movl	%edi, %esi
	movl	$0, (%edi)
	movw	$2, %bx
	xorl	%edi, %edi
	movl	$0, 4(%eax)
	jmp	.LBB0_6
.LBB0_3:
	xorl	%ebx, %ebx
	xorl	%edi, %edi
	jmp	.LBB0_5
.LBB0_4:
	movl	$0, 4(%edi)
	movl	$0, (%edi)
	xorl	%ebx, %ebx
.LBB0_5:
	xorl	%esi, %esi
.LBB0_6:
	movzwl	%bx, %ebp
	movl	$.L.str.2, (%esp)
	movl	%ebp, 4(%esp)
	calll	printf
	testl	%esi, %esi
	movl	%esi, %edx
	je	.LBB0_11
# %bb.7:
	movl	4(%edx), %esi
	cmpl	$2, %ebp
	jne	.LBB0_12
# %bb.8:
	testl	%esi, %esi
	je	.LBB0_17
# %bb.9:
	movl	%esi, %eax
	leal	4(%esi), %ecx
	movl	4(%esi), %esi
	testl	%esi, %esi
	jne	.LBB0_13
.LBB0_10:
	movl	%esi, %ebp
	movl	%edx, %esi
	xorl	%edx, %edx
	jmp	.LBB0_14
.LBB0_11:
	movl	$0, 20(%esp)            # 4-byte Folded Spill
	xorl	%esi, %esi
	jmp	.LBB0_18
.LBB0_12:
	leal	4(%edx), %ecx
	movl	%edx, %eax
	testl	%esi, %esi
	je	.LBB0_10
.LBB0_13:
	movl	%esi, %ebp
	movl	$0, (%esi)
	movl	%edx, %esi
.LBB0_14:
	testl	%edi, %edi
	movl	%edi, (%ecx)
	je	.LBB0_16
# %bb.15:
	movl	%eax, (%edi)
.LBB0_16:
	movl	%esi, %edi
	xorl	%ebx, %ebx
	movl	%ebp, %esi
	movl	%edx, 20(%esp)          # 4-byte Spill
	jmp	.LBB0_18
.LBB0_17:
	movw	$2, %bx
	movl	%edx, 20(%esp)          # 4-byte Spill
	movl	%edx, %esi
.LBB0_18:
	movzwl	%bx, %ebp
	movl	$.L.str.2, (%esp)
	movl	%ebp, 4(%esp)
	calll	printf
	movl	$16, 4(%esp)
	movl	$.L.str.3, (%esp)
	calll	printf
	testl	%edi, %edi
	je	.LBB0_23
# %bb.19:
	movl	4(%edi), %eax
	movl	%ebp, 24(%esp)          # 4-byte Spill
	leal	4(%edi), %ebp
	testl	%eax, %eax
	je	.LBB0_25
# %bb.20:
	movl	$0, (%eax)
	movl	$0, (%ebp)
	movl	4(%eax), %edx
	testl	%edx, %edx
	je	.LBB0_22
# %bb.21:
	movl	$0, (%edx)
.LBB0_22:
	movl	$0, 4(%eax)
	movl	%eax, 4(%edi)
	jmp	.LBB0_28
.LBB0_23:
	movl	$12, 4(%esp)
	movl	$4, (%esp)
	calll	aligned_alloc
	movl	%eax, %edi
	testl	%edi, %edi
	je	.LBB0_64
# %bb.24:
	movl	%ebp, 24(%esp)          # 4-byte Spill
	movl	%edi, %ebp
	addl	$4, %ebp
	jmp	.LBB0_26
.LBB0_25:
	movl	$0, 4(%edi)
.LBB0_26:
	movl	$0, (%ebp)
	movl	$12, 4(%esp)
	movl	$4, (%esp)
	calll	aligned_alloc
	testl	%eax, %eax
	movl	%eax, (%ebp)
	je	.LBB0_45
# %bb.27:
	xorl	%edx, %edx
.LBB0_28:
	movl	%edi, (%eax)
	movl	20(%esp), %ecx          # 4-byte Reload
	movl	(%ebp), %eax
	testl	%ecx, %ecx
	movl	$0, 4(%eax)
	movl	%ecx, (%edi)
	je	.LBB0_30
# %bb.29:
	movl	%edi, 4(%ecx)
	jmp	.LBB0_31
.LBB0_30:
	movl	%edi, %esi
.LBB0_31:
	movswl	%bx, %ebx
	movl	%edi, 20(%esp)          # 4-byte Spill
	movl	%edx, %edi
	addl	$2, %ebx
	movzwl	%bx, %ebp
.LBB0_32:
	movl	%ebp, 4(%esp)
	movl	$.L.str.4, (%esp)
	calll	printf
	testl	%esi, %esi
	je	.LBB0_46
# %bb.33:
	movl	4(%esi), %ecx
	movzwl	%bx, %eax
	cmpl	$2, %eax
	jb	.LBB0_40
# %bb.34:
	movw	$1, %dx
	.p2align	4, 0x90
.LBB0_35:                               # =>This Inner Loop Header: Depth=1
	movl	%ecx, %eax
	testl	%eax, %eax
	je	.LBB0_46
# %bb.36:                               #   in Loop: Header=BB0_35 Depth=1
	movl	4(%eax), %ecx
	incl	%edx
	cmpw	%bx, %dx
	jb	.LBB0_35
# %bb.37:
	leal	4(%eax), %edx
	testl	%ecx, %ecx
	jne	.LBB0_41
.LBB0_38:
	movl	$0, 20(%esp)            # 4-byte Folded Spill
	jmp	.LBB0_42
.LBB0_46:
	movl	%edi, %esi
	jmp	.LBB0_47
.LBB0_40:
	leal	4(%esi), %edx
	movl	%esi, %eax
	testl	%ecx, %ecx
	je	.LBB0_38
.LBB0_41:
	movl	$0, (%ecx)
.LBB0_42:
	testl	%edi, %edi
	movl	%edi, (%edx)
	je	.LBB0_44
# %bb.43:
	movl	%eax, (%edi)
.LBB0_44:
	xorl	%ebx, %ebx
.LBB0_47:
	movzwl	%bx, %ebp
	movl	$.L.str.4, (%esp)
	movl	%ebp, 4(%esp)
	calll	printf
	movl	$16, 4(%esp)
	movl	$.L.str.5, (%esp)
	calll	printf
	testl	%esi, %esi
	je	.LBB0_51
# %bb.48:
	movl	4(%esi), %edi
	testl	%edi, %edi
	je	.LBB0_53
# %bb.49:
	movl	$0, (%edi)
	jmp	.LBB0_53
.LBB0_51:
	movl	$12, 4(%esp)
	movl	$4, (%esp)
	calll	aligned_alloc
	movl	%eax, %esi
	testl	%esi, %esi
	je	.LBB0_65
# %bb.52:
	xorl	%edi, %edi
.LBB0_53:
	movl	$0, 4(%esi)
	movl	20(%esp), %eax          # 4-byte Reload
	testl	%eax, %eax
	movl	%eax, (%esi)
	je	.LBB0_56
# %bb.55:
	movl	%esi, 4(%eax)
.LBB0_56:
	incl	%ebx
	movzwl	%bx, %ebp
.LBB0_57:
	movl	%ebp, 4(%esp)
	movl	$.L.str.6, (%esp)
	calll	printf
	movl	(%esi), %eax
	movl	4(%esi), %ecx
	testl	%eax, %eax
	je	.LBB0_59
# %bb.58:
	movl	%ecx, 4(%eax)
	movl	4(%esi), %ecx
.LBB0_59:
	testl	%ecx, %ecx
	je	.LBB0_61
# %bb.60:
	movl	%eax, (%ecx)
.LBB0_61:
	testl	%edi, %edi
	movl	%edi, 4(%esi)
	je	.LBB0_63
# %bb.62:
	movl	%esi, (%edi)
.LBB0_63:
	decl	%ebx
	movl	$.L.str.6, (%esp)
	movzwl	%bx, %eax
	movl	%eax, 4(%esp)
	calll	printf
	xorl	%eax, %eax
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
.LBB0_45:
	movl	$0, (%ebp)
	movl	24(%esp), %ebp          # 4-byte Reload
	movl	$0, (%edi)
	jmp	.LBB0_32
.LBB0_64:
	xorl	%edi, %edi
	jmp	.LBB0_32
.LBB0_65:
	xorl	%edi, %edi
	jmp	.LBB0_57
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        # -- End function
	.type	.L.str.1,@object        # @.str.1
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.1:
	.asciz	"Stack limit: %u\n"
	.size	.L.str.1, 17

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Stack size: %u\n"
	.size	.L.str.2, 16

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"Queue limit: %u\n"
	.size	.L.str.3, 17

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"Queue size: %u\n"
	.size	.L.str.4, 16

	.type	.L.str.5,@object        # @.str.5
.L.str.5:
	.asciz	"Pool limit: %u\n"
	.size	.L.str.5, 16

	.type	.L.str.6,@object        # @.str.6
.L.str.6:
	.asciz	"Pool size: %u\n"
	.size	.L.str.6, 15


	.ident	"clang version 6.0.1 (tags/RELEASE_601/final)"
	.section	".note.GNU-stack","",@progbits
