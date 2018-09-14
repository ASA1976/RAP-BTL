	.text
	.file	"sortints.cpp"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	pushl	%edi
	.cfi_def_cfa_offset 16
	pushl	%esi
	.cfi_def_cfa_offset 20
	subl	$28, %esp
	.cfi_def_cfa_offset 48
	.cfi_offset %esi, -20
	.cfi_offset %edi, -16
	.cfi_offset %ebx, -12
	.cfi_offset %ebp, -8
	movl	48(%esp), %eax
	movl	52(%esp), %esi
	cmpl	$2, %eax
	je	.LBB0_1
# %bb.4:
	cmpl	$3, %eax
	jne	.LBB0_7
# %bb.5:
	subl	$8, %esp
	.cfi_adjust_cfa_offset 8
	pushl	$.L.str
	.cfi_adjust_cfa_offset 4
	pushl	8(%esi)
	.cfi_adjust_cfa_offset 4
	calll	fopen
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	movl	%eax, %ebp
	testl	%ebp, %ebp
	jne	.LBB0_2
# %bb.6:
	subl	$4, %esp
	.cfi_adjust_cfa_offset 4
	pushl	8(%esi)
	.cfi_adjust_cfa_offset 4
	pushl	$.L.str.1
	.cfi_adjust_cfa_offset 4
	pushl	stderr
	.cfi_adjust_cfa_offset 4
	calll	fprintf
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	movl	$-3, %edi
	jmp	.LBB0_54
.LBB0_1:
	movl	stdout, %ebp
.LBB0_2:
	subl	$8, %esp
	.cfi_adjust_cfa_offset 8
	pushl	$.L.str.2
	.cfi_adjust_cfa_offset 4
	pushl	4(%esi)
	.cfi_adjust_cfa_offset 4
	calll	fopen
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	movl	%eax, %edi
	testl	%edi, %edi
	je	.LBB0_3
# %bb.8:
	subl	$12, %esp
	.cfi_adjust_cfa_offset 12
	pushl	%edi
	.cfi_adjust_cfa_offset 4
	calll	feof
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	testl	%eax, %eax
	je	.LBB0_9
.LBB0_52:
	xorl	%edi, %edi
	cmpl	stdout, %ebp
	je	.LBB0_54
# %bb.53:
	subl	$12, %esp
	.cfi_adjust_cfa_offset 12
	pushl	%ebp
	.cfi_adjust_cfa_offset 4
	calll	fclose
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	jmp	.LBB0_54
.LBB0_9:
	leal	16(%esp), %esi
	xorl	%ebx, %ebx
	movl	$0, 4(%esp)             # 4-byte Folded Spill
	movl	$0, 12(%esp)            # 4-byte Folded Spill
	movl	%ebp, 8(%esp)           # 4-byte Spill
	movl	%edi, 24(%esp)          # 4-byte Spill
.LBB0_10:                               # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_23 Depth 2
                                        #       Child Loop BB0_29 Depth 3
                                        #       Child Loop BB0_26 Depth 3
	subl	$4, %esp
	.cfi_adjust_cfa_offset 4
	pushl	%esi
	.cfi_adjust_cfa_offset 4
	pushl	$.L.str.5
	.cfi_adjust_cfa_offset 4
	pushl	%edi
	.cfi_adjust_cfa_offset 4
	calll	fscanf
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	cmpl	$1, %eax
	jne	.LBB0_47
# %bb.11:                               #   in Loop: Header=BB0_10 Depth=1
	movzwl	%bx, %edx
	cmpl	$681, %edx              # imm = 0x2A9
	je	.LBB0_12
# %bb.14:                               #   in Loop: Header=BB0_10 Depth=1
	movl	4(%esp), %eax           # 4-byte Reload
	testl	%eax, %eax
	je	.LBB0_15
# %bb.21:                               #   in Loop: Header=BB0_10 Depth=1
	movl	%ebx, 20(%esp)          # 4-byte Spill
	movl	8(%eax), %ebx
	movl	16(%esp), %eax
	cmpl	%eax, %ebx
	je	.LBB0_31
# %bb.22:                               #   in Loop: Header=BB0_10 Depth=1
	movl	20(%esp), %ecx          # 4-byte Reload
	xorl	%ebp, %ebp
	leal	-1(%ecx), %edi
	movl	4(%esp), %ecx           # 4-byte Reload
	.p2align	4, 0x90
.LBB0_23:                               #   Parent Loop BB0_10 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_29 Depth 3
                                        #       Child Loop BB0_26 Depth 3
	cmpl	%eax, %ebx
	jge	.LBB0_27
# %bb.24:                               #   in Loop: Header=BB0_23 Depth=2
	testw	%di, %di
	je	.LBB0_33
# %bb.25:                               #   in Loop: Header=BB0_23 Depth=2
	movl	%edi, %ebx
	movl	%edi, %esi
	andl	$65534, %ebx            # imm = 0xFFFE
	andl	$1, %esi
	shrl	%ebx
	addl	%esi, %ebx
	xorl	$1, %esi
	subl	%ebx, %edi
	movl	%edi, %ebp
	subl	%esi, %ebp
	testw	%bx, %bx
	je	.LBB0_30
	.p2align	4, 0x90
.LBB0_26:                               #   Parent Loop BB0_10 Depth=1
                                        #     Parent Loop BB0_23 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movl	4(%ecx), %ecx
	decw	%bx
	jne	.LBB0_26
	jmp	.LBB0_30
	.p2align	4, 0x90
.LBB0_27:                               #   in Loop: Header=BB0_23 Depth=2
	testw	%bp, %bp
	je	.LBB0_33
# %bb.28:                               #   in Loop: Header=BB0_23 Depth=2
	movl	%ebp, %ebx
	movl	%ebp, %esi
	andl	$65534, %ebx            # imm = 0xFFFE
	andl	$1, %esi
	shrl	%ebx
	addl	%esi, %ebx
	xorl	$1, %esi
	subl	%ebx, %ebp
	movl	%ebp, %edi
	subl	%esi, %edi
	testw	%bx, %bx
	je	.LBB0_30
	.p2align	4, 0x90
.LBB0_29:                               #   Parent Loop BB0_10 Depth=1
                                        #     Parent Loop BB0_23 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movl	(%ecx), %ecx
	decw	%bx
	jne	.LBB0_29
.LBB0_30:                               #   in Loop: Header=BB0_23 Depth=2
	movl	8(%ecx), %ebx
	cmpl	%eax, %ebx
	jne	.LBB0_23
	jmp	.LBB0_31
.LBB0_15:                               #   in Loop: Header=BB0_10 Depth=1
	movzwl	NodePool, %eax
	testw	%ax, %ax
	je	.LBB0_17
# %bb.16:                               #   in Loop: Header=BB0_10 Depth=1
	decl	%eax
	movw	%ax, NodePool
	movzwl	%ax, %eax
	movzwl	NodePool+8180(%eax,%eax), %eax
	jmp	.LBB0_18
.LBB0_33:                               #   in Loop: Header=BB0_10 Depth=1
	cmpl	%eax, 8(%ecx)
	jge	.LBB0_41
# %bb.34:                               #   in Loop: Header=BB0_10 Depth=1
	movl	4(%ecx), %ecx
	testl	%ecx, %ecx
	je	.LBB0_35
.LBB0_41:                               #   in Loop: Header=BB0_10 Depth=1
	movzwl	NodePool, %edx
	movl	8(%esp), %ebp           # 4-byte Reload
	testw	%dx, %dx
	je	.LBB0_43
# %bb.42:                               #   in Loop: Header=BB0_10 Depth=1
	decl	%edx
	movw	%dx, NodePool
	movzwl	%dx, %edx
	movzwl	NodePool+8180(%edx,%edx), %edx
	jmp	.LBB0_44
.LBB0_17:                               #   in Loop: Header=BB0_10 Depth=1
	movzwl	NodePool+4, %eax
	movl	%eax, %ecx
	incl	%ecx
	movw	%cx, NodePool+4
.LBB0_18:                               #   in Loop: Header=BB0_10 Depth=1
	movl	16(%esp), %edx
	movzwl	%ax, %ecx
	shll	$2, %ecx
	leal	NodePool+8(%ecx,%ecx,2), %eax
	movl	%edx, NodePool+16(%ecx,%ecx,2)
	movl	12(%esp), %edx          # 4-byte Reload
	movl	%edx, NodePool+8(%ecx,%ecx,2)
	movl	$0, NodePool+12(%ecx,%ecx,2)
	testl	%edx, %edx
	movl	%eax, %ecx
	je	.LBB0_20
# %bb.19:                               #   in Loop: Header=BB0_10 Depth=1
	xorl	%ecx, %ecx
	movl	%eax, 4(%edx)
.LBB0_20:                               #   in Loop: Header=BB0_10 Depth=1
	movl	%ecx, 4(%esp)           # 4-byte Spill
	incl	%ebx
	movl	%eax, 12(%esp)          # 4-byte Spill
	jmp	.LBB0_47
.LBB0_43:                               #   in Loop: Header=BB0_10 Depth=1
	movzwl	NodePool+4, %edx
	movl	%edx, %esi
	incl	%esi
	movw	%si, NodePool+4
.LBB0_44:                               #   in Loop: Header=BB0_10 Depth=1
	movzwl	%dx, %edx
	leal	(,%edx,4), %edi
	movl	%eax, NodePool+16(%edi,%edi,2)
	leal	NodePool+8(%edi,%edi,2), %esi
	movl	(%ecx), %ebx
	movl	%esi, %eax
	testl	%ebx, %ebx
	je	.LBB0_46
# %bb.45:                               #   in Loop: Header=BB0_10 Depth=1
	movl	4(%esp), %eax           # 4-byte Reload
	movl	%esi, 4(%ebx)
.LBB0_46:                               #   in Loop: Header=BB0_10 Depth=1
	movl	%ebx, (%esi)
	movl	20(%esp), %ebx          # 4-byte Reload
	movl	24(%esp), %edi          # 4-byte Reload
	leal	(%edx,%edx,2), %edx
	movl	%eax, 4(%esp)           # 4-byte Spill
	movl	%ecx, NodePool+12(,%edx,4)
	movl	%esi, (%ecx)
	leal	16(%esp), %esi
	incl	%ebx
	.p2align	4, 0x90
.LBB0_47:                               #   in Loop: Header=BB0_10 Depth=1
	subl	$12, %esp
	.cfi_adjust_cfa_offset 12
	pushl	%edi
	.cfi_adjust_cfa_offset 4
	calll	feof
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	testl	%eax, %eax
	je	.LBB0_10
	jmp	.LBB0_48
.LBB0_35:                               #   in Loop: Header=BB0_10 Depth=1
	movzwl	NodePool, %ecx
	movl	8(%esp), %ebp           # 4-byte Reload
	movl	24(%esp), %edi          # 4-byte Reload
	movl	20(%esp), %ebx          # 4-byte Reload
	leal	16(%esp), %esi
	testw	%cx, %cx
	je	.LBB0_37
# %bb.36:                               #   in Loop: Header=BB0_10 Depth=1
	decl	%ecx
	movw	%cx, NodePool
	movzwl	%cx, %ecx
	movzwl	NodePool+8180(%ecx,%ecx), %ecx
	jmp	.LBB0_38
.LBB0_37:                               #   in Loop: Header=BB0_10 Depth=1
	movzwl	NodePool+4, %ecx
	movl	%ecx, %edx
	incl	%edx
	movw	%dx, NodePool+4
.LBB0_38:                               #   in Loop: Header=BB0_10 Depth=1
	movzwl	%cx, %edx
	shll	$2, %edx
	movl	%eax, NodePool+16(%edx,%edx,2)
	movl	12(%esp), %eax          # 4-byte Reload
	leal	NodePool+8(%edx,%edx,2), %ecx
	movl	%eax, NodePool+8(%edx,%edx,2)
	movl	$0, NodePool+12(%edx,%edx,2)
	movl	%eax, %edx
	movl	%ecx, %eax
	testl	%edx, %edx
	je	.LBB0_40
# %bb.39:                               #   in Loop: Header=BB0_10 Depth=1
	movl	4(%esp), %eax           # 4-byte Reload
	movl	%ecx, 4(%edx)
.LBB0_40:                               #   in Loop: Header=BB0_10 Depth=1
	incl	%ebx
	movl	%ecx, 12(%esp)          # 4-byte Spill
	movl	%eax, 4(%esp)           # 4-byte Spill
	jmp	.LBB0_47
.LBB0_31:
	subl	$4, %esp
	.cfi_adjust_cfa_offset 4
	pushl	%edx
	.cfi_adjust_cfa_offset 4
	pushl	$.L.str.7
	.cfi_adjust_cfa_offset 4
	pushl	stderr
	.cfi_adjust_cfa_offset 4
	calll	fprintf
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	movl	8(%esp), %eax           # 4-byte Reload
	movl	$-5, %edi
	cmpl	stdout, %eax
	je	.LBB0_54
# %bb.32:
	subl	$12, %esp
	.cfi_adjust_cfa_offset 12
	pushl	%eax
	.cfi_adjust_cfa_offset 4
	calll	fclose
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	jmp	.LBB0_54
.LBB0_7:
	subl	$4, %esp
	.cfi_adjust_cfa_offset 4
	pushl	(%esi)
	.cfi_adjust_cfa_offset 4
	pushl	$.L.str.4
	.cfi_adjust_cfa_offset 4
	pushl	stderr
	.cfi_adjust_cfa_offset 4
	calll	fprintf
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	movl	$-1, %edi
	jmp	.LBB0_54
.LBB0_3:
	subl	$4, %esp
	.cfi_adjust_cfa_offset 4
	pushl	4(%esi)
	.cfi_adjust_cfa_offset 4
	pushl	$.L.str.3
	.cfi_adjust_cfa_offset 4
	pushl	stderr
	.cfi_adjust_cfa_offset 4
	calll	fprintf
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	movl	$-2, %edi
	jmp	.LBB0_54
.LBB0_12:
	subl	$4, %esp
	.cfi_adjust_cfa_offset 4
	pushl	$681                    # imm = 0x2A9
	.cfi_adjust_cfa_offset 4
	pushl	$.L.str.6
	.cfi_adjust_cfa_offset 4
	pushl	stderr
	.cfi_adjust_cfa_offset 4
	calll	fprintf
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	cmpl	stdout, %ebp
	movl	$-4, %edi
	je	.LBB0_54
# %bb.13:
	subl	$12, %esp
	.cfi_adjust_cfa_offset 12
	pushl	%ebp
	.cfi_adjust_cfa_offset 4
	calll	fclose
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
.LBB0_54:
	movl	%edi, %eax
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
.LBB0_48:
	movl	4(%esp), %eax           # 4-byte Reload
	testl	%eax, %eax
	je	.LBB0_52
# %bb.49:
	subl	$4, %esp
	.cfi_adjust_cfa_offset 4
	pushl	8(%eax)
	.cfi_adjust_cfa_offset 4
	pushl	$.L.str.10
	.cfi_adjust_cfa_offset 4
	pushl	%ebp
	.cfi_adjust_cfa_offset 4
	movl	%eax, %esi
	calll	fprintf
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
	jmp	.LBB0_51
	.p2align	4, 0x90
.LBB0_50:                               #   in Loop: Header=BB0_51 Depth=1
	subl	$4, %esp
	.cfi_adjust_cfa_offset 4
	pushl	8(%esi)
	.cfi_adjust_cfa_offset 4
	pushl	$.L.str.10
	.cfi_adjust_cfa_offset 4
	pushl	%ebp
	.cfi_adjust_cfa_offset 4
	calll	fprintf
	addl	$16, %esp
	.cfi_adjust_cfa_offset -16
.LBB0_51:                               # =>This Inner Loop Header: Depth=1
	movl	4(%esi), %esi
	testl	%esi, %esi
	jne	.LBB0_50
	jmp	.LBB0_52
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	NodePool,@object        # @NodePool
	.bss
	.globl	NodePool
	.p2align	2
NodePool:
	.zero	9544
	.size	NodePool, 9544

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"w"
	.size	.L.str, 2

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Could not write to file '%s'\n"
	.size	.L.str.1, 30

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"r"
	.size	.L.str.2, 2

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"Could not read from file '%s'\n"
	.size	.L.str.3, 31

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"%s input_file_path ?output_file_path?\n"
	.size	.L.str.4, 39

	.type	.L.str.5,@object        # @.str.5
.L.str.5:
	.asciz	"%d"
	.size	.L.str.5, 3

	.type	.L.str.6,@object        # @.str.6
.L.str.6:
	.asciz	"Maximum number of integers is %u\n"
	.size	.L.str.6, 34

	.type	.L.str.7,@object        # @.str.7
.L.str.7:
	.asciz	"Error composing set currently containing %u integers\n"
	.size	.L.str.7, 54

	.type	.L.str.10,@object       # @.str.10
.L.str.10:
	.asciz	"%d\n"
	.size	.L.str.10, 4


	.ident	"clang version 6.0.1 (tags/RELEASE_601/final)"
	.section	".note.GNU-stack","",@progbits
