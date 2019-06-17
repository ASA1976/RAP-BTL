	.text
	.file	"test_stdfunction.cpp"
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
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 0, __gxx_personality_v0
	.cfi_lsda 0, .Lexception0
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
	movl	$12, (%esp)
	calll	_Znwj
	movl	$_ZN3$_13runEv, (%eax)
	movl	%eax, 16(%esp)
	movl	$_ZNSt17_Function_handlerIFvvESt5_BindIFM3$_1FvvES2_EEE9_M_invokeERKSt9_Any_data, 28(%esp)
	movl	$0, 4(%eax)
	movl	$_ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation, 24(%esp)
	movl	$.L.str.1, (%esp)
	calll	puts
.Ltmp0:
	leal	16(%esp), %edi
	movl	$3, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	calll	_ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation
.Ltmp1:
# %bb.1:
	movl	$_ZNSt17_Function_handlerIFvvE3$_0E9_M_invokeERKSt9_Any_data, 28(%esp)
	movl	$_ZNSt14_Function_base13_Base_managerI3$_0E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, 24(%esp)
.Ltmp3:
	movl	%edi, (%esp)
	calll	_Z10TestExternRKSt8functionIFvvEE
.Ltmp4:
# %bb.2:
	movl	24(%esp), %eax
	testl	%eax, %eax
	je	.LBB1_4
# %bb.3:
.Ltmp9:
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	movl	$3, 8(%esp)
	calll	*%eax
.Ltmp10:
.LBB1_4:
	movl	$_ZNSt17_Function_handlerIFvvE3$_2E9_M_invokeERKSt9_Any_data, 28(%esp)
	movl	$_ZNSt14_Function_base13_Base_managerI3$_2E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, 24(%esp)
.Ltmp12:
	movl	%edi, (%esp)
	calll	_Z10TestExternRKSt8functionIFvvEE
.Ltmp13:
# %bb.5:
	movl	24(%esp), %eax
	testl	%eax, %eax
	je	.LBB1_7
# %bb.6:
.Ltmp18:
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	movl	$3, 8(%esp)
	calll	*%eax
.Ltmp19:
.LBB1_7:
	movl	$_Z5Test3v, 16(%esp)
	movl	$_ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data, 28(%esp)
	movl	$_ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, 24(%esp)
.Ltmp21:
	movl	%edi, (%esp)
	calll	_Z10TestExternRKSt8functionIFvvEE
.Ltmp22:
# %bb.8:
	movl	24(%esp), %eax
	testl	%eax, %eax
	je	.LBB1_10
# %bb.9:
.Ltmp27:
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	movl	$3, 8(%esp)
	calll	*%eax
.Ltmp28:
.LBB1_10:
	movl	$12, (%esp)
	calll	_Znwj
	movl	$_ZN3$_13runEv, (%eax)
	movl	%eax, 16(%esp)
	movl	$_ZNSt17_Function_handlerIFvvESt5_BindIFM3$_1FvvES2_EEE9_M_invokeERKSt9_Any_data, 28(%esp)
	movl	$0, 4(%eax)
	movl	$_ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation, 24(%esp)
.Ltmp30:
	movl	%edi, (%esp)
	calll	_Z10TestExternRKSt8functionIFvvEE
.Ltmp31:
# %bb.11:
	movl	24(%esp), %eax
	testl	%eax, %eax
	je	.LBB1_13
# %bb.12:
.Ltmp36:
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	movl	$3, 8(%esp)
	calll	*%eax
.Ltmp37:
.LBB1_13:
	xorl	%eax, %eax
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_def_cfa_offset 4
	retl
.LBB1_19:
	.cfi_def_cfa_offset 48
.Ltmp38:
	jmp	.LBB1_15
.LBB1_18:
.Ltmp29:
	jmp	.LBB1_15
.LBB1_17:
.Ltmp20:
	jmp	.LBB1_15
.LBB1_16:
.Ltmp11:
	jmp	.LBB1_15
.LBB1_26:
.Ltmp32:
	movl	%eax, %esi
	movl	24(%esp), %eax
	testl	%eax, %eax
	je	.LBB1_28
# %bb.27:
.Ltmp33:
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	movl	$3, 8(%esp)
	calll	*%eax
.Ltmp34:
	jmp	.LBB1_28
.LBB1_32:
.Ltmp35:
	jmp	.LBB1_15
.LBB1_24:
.Ltmp23:
	movl	%eax, %esi
	movl	24(%esp), %eax
	testl	%eax, %eax
	je	.LBB1_28
# %bb.25:
.Ltmp24:
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	movl	$3, 8(%esp)
	calll	*%eax
.Ltmp25:
	jmp	.LBB1_28
.LBB1_31:
.Ltmp26:
	jmp	.LBB1_15
.LBB1_22:
.Ltmp14:
	movl	%eax, %esi
	movl	24(%esp), %eax
	testl	%eax, %eax
	je	.LBB1_28
# %bb.23:
.Ltmp15:
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	movl	$3, 8(%esp)
	calll	*%eax
.Ltmp16:
	jmp	.LBB1_28
.LBB1_30:
.Ltmp17:
	jmp	.LBB1_15
.LBB1_20:
.Ltmp5:
	movl	%eax, %esi
	movl	24(%esp), %eax
	testl	%eax, %eax
	je	.LBB1_28
# %bb.21:
.Ltmp6:
	movl	%edi, 4(%esp)
	movl	%edi, (%esp)
	movl	$3, 8(%esp)
	calll	*%eax
.Ltmp7:
.LBB1_28:
	movl	%esi, (%esp)
	calll	_Unwind_Resume
	subl	$4, %esp
.LBB1_29:
.Ltmp8:
	jmp	.LBB1_15
.LBB1_14:
.Ltmp2:
.LBB1_15:
	movl	%eax, (%esp)
	calll	__clang_call_terminate
	subl	$4, %esp
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.p2align	2
GCC_except_table1:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	0                       # @TType Encoding = absptr
	.uleb128 .Lttbase0-.Lttbaseref0
.Lttbaseref0:
	.byte	1                       # Call site Encoding = uleb128
	.uleb128 .Lcst_end0-.Lcst_begin0
.Lcst_begin0:
	.uleb128 .Lfunc_begin0-.Lfunc_begin0 # >> Call Site 1 <<
	.uleb128 .Ltmp0-.Lfunc_begin0   #   Call between .Lfunc_begin0 and .Ltmp0
	.byte	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp0-.Lfunc_begin0   # >> Call Site 2 <<
	.uleb128 .Ltmp1-.Ltmp0          #   Call between .Ltmp0 and .Ltmp1
	.uleb128 .Ltmp2-.Lfunc_begin0   #     jumps to .Ltmp2
	.byte	1                       #   On action: 1
	.uleb128 .Ltmp3-.Lfunc_begin0   # >> Call Site 3 <<
	.uleb128 .Ltmp4-.Ltmp3          #   Call between .Ltmp3 and .Ltmp4
	.uleb128 .Ltmp5-.Lfunc_begin0   #     jumps to .Ltmp5
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp9-.Lfunc_begin0   # >> Call Site 4 <<
	.uleb128 .Ltmp10-.Ltmp9         #   Call between .Ltmp9 and .Ltmp10
	.uleb128 .Ltmp11-.Lfunc_begin0  #     jumps to .Ltmp11
	.byte	1                       #   On action: 1
	.uleb128 .Ltmp12-.Lfunc_begin0  # >> Call Site 5 <<
	.uleb128 .Ltmp13-.Ltmp12        #   Call between .Ltmp12 and .Ltmp13
	.uleb128 .Ltmp14-.Lfunc_begin0  #     jumps to .Ltmp14
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp18-.Lfunc_begin0  # >> Call Site 6 <<
	.uleb128 .Ltmp19-.Ltmp18        #   Call between .Ltmp18 and .Ltmp19
	.uleb128 .Ltmp20-.Lfunc_begin0  #     jumps to .Ltmp20
	.byte	1                       #   On action: 1
	.uleb128 .Ltmp21-.Lfunc_begin0  # >> Call Site 7 <<
	.uleb128 .Ltmp22-.Ltmp21        #   Call between .Ltmp21 and .Ltmp22
	.uleb128 .Ltmp23-.Lfunc_begin0  #     jumps to .Ltmp23
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp27-.Lfunc_begin0  # >> Call Site 8 <<
	.uleb128 .Ltmp28-.Ltmp27        #   Call between .Ltmp27 and .Ltmp28
	.uleb128 .Ltmp29-.Lfunc_begin0  #     jumps to .Ltmp29
	.byte	1                       #   On action: 1
	.uleb128 .Ltmp28-.Lfunc_begin0  # >> Call Site 9 <<
	.uleb128 .Ltmp30-.Ltmp28        #   Call between .Ltmp28 and .Ltmp30
	.byte	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp30-.Lfunc_begin0  # >> Call Site 10 <<
	.uleb128 .Ltmp31-.Ltmp30        #   Call between .Ltmp30 and .Ltmp31
	.uleb128 .Ltmp32-.Lfunc_begin0  #     jumps to .Ltmp32
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp36-.Lfunc_begin0  # >> Call Site 11 <<
	.uleb128 .Ltmp37-.Ltmp36        #   Call between .Ltmp36 and .Ltmp37
	.uleb128 .Ltmp38-.Lfunc_begin0  #     jumps to .Ltmp38
	.byte	1                       #   On action: 1
	.uleb128 .Ltmp33-.Lfunc_begin0  # >> Call Site 12 <<
	.uleb128 .Ltmp34-.Ltmp33        #   Call between .Ltmp33 and .Ltmp34
	.uleb128 .Ltmp35-.Lfunc_begin0  #     jumps to .Ltmp35
	.byte	1                       #   On action: 1
	.uleb128 .Ltmp24-.Lfunc_begin0  # >> Call Site 13 <<
	.uleb128 .Ltmp25-.Ltmp24        #   Call between .Ltmp24 and .Ltmp25
	.uleb128 .Ltmp26-.Lfunc_begin0  #     jumps to .Ltmp26
	.byte	1                       #   On action: 1
	.uleb128 .Ltmp15-.Lfunc_begin0  # >> Call Site 14 <<
	.uleb128 .Ltmp16-.Ltmp15        #   Call between .Ltmp15 and .Ltmp16
	.uleb128 .Ltmp17-.Lfunc_begin0  #     jumps to .Ltmp17
	.byte	1                       #   On action: 1
	.uleb128 .Ltmp6-.Lfunc_begin0   # >> Call Site 15 <<
	.uleb128 .Ltmp7-.Ltmp6          #   Call between .Ltmp6 and .Ltmp7
	.uleb128 .Ltmp8-.Lfunc_begin0   #     jumps to .Ltmp8
	.byte	1                       #   On action: 1
	.uleb128 .Ltmp7-.Lfunc_begin0   # >> Call Site 16 <<
	.uleb128 .Lfunc_end1-.Ltmp7     #   Call between .Ltmp7 and .Lfunc_end1
	.byte	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
.Lcst_end0:
	.byte	1                       # >> Action Record 1 <<
                                        #   Catch TypeInfo 1
	.byte	0                       #   No further actions
	.p2align	2
                                        # >> Catch TypeInfos <<
	.long	0                       # TypeInfo 1
.Lttbase0:
	.p2align	2
                                        # -- End function
	.text
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
	.section	.text.__clang_call_terminate,"axG",@progbits,__clang_call_terminate,comdat
	.hidden	__clang_call_terminate  # -- Begin function __clang_call_terminate
	.weak	__clang_call_terminate
	.p2align	4, 0x90
	.type	__clang_call_terminate,@function
__clang_call_terminate:                 # @__clang_call_terminate
# %bb.0:
	subl	$12, %esp
	movl	16(%esp), %eax
	movl	%eax, (%esp)
	calll	__cxa_begin_catch
	calll	_ZSt9terminatev
.Lfunc_end3:
	.size	__clang_call_terminate, .Lfunc_end3-__clang_call_terminate
                                        # -- End function
	.text
	.p2align	4, 0x90         # -- Begin function _ZNSt17_Function_handlerIFvvE3$_0E9_M_invokeERKSt9_Any_data
	.type	_ZNSt17_Function_handlerIFvvE3$_0E9_M_invokeERKSt9_Any_data,@function
_ZNSt17_Function_handlerIFvvE3$_0E9_M_invokeERKSt9_Any_data: # @"_ZNSt17_Function_handlerIFvvE3$_0E9_M_invokeERKSt9_Any_data"
# %bb.0:
	subl	$12, %esp
	movl	$.L.str.2, (%esp)
	calll	puts
	addl	$12, %esp
	retl
.Lfunc_end4:
	.size	_ZNSt17_Function_handlerIFvvE3$_0E9_M_invokeERKSt9_Any_data, .Lfunc_end4-_ZNSt17_Function_handlerIFvvE3$_0E9_M_invokeERKSt9_Any_data
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZNSt14_Function_base13_Base_managerI3$_0E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
	.type	_ZNSt14_Function_base13_Base_managerI3$_0E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation,@function
_ZNSt14_Function_base13_Base_managerI3$_0E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation: # @"_ZNSt14_Function_base13_Base_managerI3$_0E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation"
# %bb.0:
	movl	12(%esp), %ecx
	movl	4(%esp), %eax
	cmpl	$1, %ecx
	je	.LBB5_3
# %bb.1:
	testl	%ecx, %ecx
	jne	.LBB5_4
# %bb.2:
	movl	$_ZTI3$_0, (%eax)
	xorl	%eax, %eax
	retl
.LBB5_3:
	movl	8(%esp), %ecx
	movl	%ecx, (%eax)
.LBB5_4:
	xorl	%eax, %eax
	retl
.Lfunc_end5:
	.size	_ZNSt14_Function_base13_Base_managerI3$_0E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, .Lfunc_end5-_ZNSt14_Function_base13_Base_managerI3$_0E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZNSt17_Function_handlerIFvvE3$_2E9_M_invokeERKSt9_Any_data
	.type	_ZNSt17_Function_handlerIFvvE3$_2E9_M_invokeERKSt9_Any_data,@function
_ZNSt17_Function_handlerIFvvE3$_2E9_M_invokeERKSt9_Any_data: # @"_ZNSt17_Function_handlerIFvvE3$_2E9_M_invokeERKSt9_Any_data"
# %bb.0:
	subl	$12, %esp
	movl	$.L.str.3, (%esp)
	calll	puts
	addl	$12, %esp
	retl
.Lfunc_end6:
	.size	_ZNSt17_Function_handlerIFvvE3$_2E9_M_invokeERKSt9_Any_data, .Lfunc_end6-_ZNSt17_Function_handlerIFvvE3$_2E9_M_invokeERKSt9_Any_data
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZNSt14_Function_base13_Base_managerI3$_2E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
	.type	_ZNSt14_Function_base13_Base_managerI3$_2E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation,@function
_ZNSt14_Function_base13_Base_managerI3$_2E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation: # @"_ZNSt14_Function_base13_Base_managerI3$_2E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation"
# %bb.0:
	movl	12(%esp), %ecx
	movl	4(%esp), %eax
	cmpl	$1, %ecx
	je	.LBB7_3
# %bb.1:
	testl	%ecx, %ecx
	jne	.LBB7_4
# %bb.2:
	movl	$_ZTI3$_2, (%eax)
	xorl	%eax, %eax
	retl
.LBB7_3:
	movl	8(%esp), %ecx
	movl	%ecx, (%eax)
.LBB7_4:
	xorl	%eax, %eax
	retl
.Lfunc_end7:
	.size	_ZNSt14_Function_base13_Base_managerI3$_2E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation, .Lfunc_end7-_ZNSt14_Function_base13_Base_managerI3$_2E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
                                        # -- End function
	.section	.text._ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data,"axG",@progbits,_ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data,comdat
	.weak	_ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data # -- Begin function _ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data
	.p2align	4, 0x90
	.type	_ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data,@function
_ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data: # @_ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data
	.cfi_startproc
# %bb.0:
	movl	4(%esp), %eax
	jmpl	*(%eax)                 # TAILCALL
.Lfunc_end8:
	.size	_ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data, .Lfunc_end8-_ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data
	.cfi_endproc
                                        # -- End function
	.section	.text._ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation,"axG",@progbits,_ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation,comdat
	.weak	_ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation # -- Begin function _ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation
	.p2align	4, 0x90
	.type	_ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation,@function
_ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation: # @_ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation
	.cfi_startproc
# %bb.0:
	movl	12(%esp), %edx
	movl	8(%esp), %ecx
	movl	4(%esp), %eax
	cmpl	$2, %edx
	je	.LBB9_4
# %bb.1:
	cmpl	$1, %edx
	je	.LBB9_5
# %bb.2:
	testl	%edx, %edx
	jne	.LBB9_6
# %bb.3:
	movl	$_ZTIPFvvE, (%eax)
	xorl	%eax, %eax
	retl
.LBB9_4:
	movl	(%ecx), %ecx
.LBB9_5:
	movl	%ecx, (%eax)
.LBB9_6:
	xorl	%eax, %eax
	retl
.Lfunc_end9:
	.size	_ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation, .Lfunc_end9-_ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation
	.cfi_endproc
                                        # -- End function
	.text
	.p2align	4, 0x90         # -- Begin function _ZNSt17_Function_handlerIFvvESt5_BindIFM3$_1FvvES2_EEE9_M_invokeERKSt9_Any_data
	.type	_ZNSt17_Function_handlerIFvvESt5_BindIFM3$_1FvvES2_EEE9_M_invokeERKSt9_Any_data,@function
_ZNSt17_Function_handlerIFvvESt5_BindIFM3$_1FvvES2_EEE9_M_invokeERKSt9_Any_data: # @"_ZNSt17_Function_handlerIFvvESt5_BindIFM3$_1FvvES2_EEE9_M_invokeERKSt9_Any_data"
	.cfi_startproc
# %bb.0:
	subl	$12, %esp
	.cfi_def_cfa_offset 16
	movl	16(%esp), %eax
	movl	(%eax), %ecx
	movl	(%ecx), %eax
	movl	4(%ecx), %edx
	leal	8(%ecx,%edx), %ecx
	testb	$1, %al
	je	.LBB10_2
# %bb.1:
	movl	(%ecx), %edx
	movl	-1(%edx,%eax), %eax
.LBB10_2:
	movl	%ecx, (%esp)
	calll	*%eax
	addl	$12, %esp
	.cfi_def_cfa_offset 4
	retl
.Lfunc_end10:
	.size	_ZNSt17_Function_handlerIFvvESt5_BindIFM3$_1FvvES2_EEE9_M_invokeERKSt9_Any_data, .Lfunc_end10-_ZNSt17_Function_handlerIFvvESt5_BindIFM3$_1FvvES2_EEE9_M_invokeERKSt9_Any_data
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90         # -- Begin function _ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation
	.type	_ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation,@function
_ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation: # @"_ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation"
	.cfi_startproc
# %bb.0:
	pushl	%edi
	.cfi_def_cfa_offset 8
	pushl	%esi
	.cfi_def_cfa_offset 12
	pushl	%eax
	.cfi_def_cfa_offset 16
	.cfi_offset %esi, -12
	.cfi_offset %edi, -8
	movl	24(%esp), %eax
	cmpl	$3, %eax
	ja	.LBB11_7
# %bb.1:
	movl	20(%esp), %edi
	movl	16(%esp), %esi
	jmpl	*.LJTI11_0(,%eax,4)
.LBB11_2:
	movl	$_ZTISt5_BindIFM3$_1FvvES0_EE, (%esi)
	jmp	.LBB11_7
.LBB11_3:
	movl	(%edi), %eax
	movl	%eax, (%esi)
	jmp	.LBB11_7
.LBB11_4:
	movl	$12, (%esp)
	calll	_Znwj
	movl	(%edi), %ecx
	movl	8(%ecx), %edx
	movl	%edx, 8(%eax)
	movsd	(%ecx), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, (%eax)
	movl	%eax, (%esi)
	jmp	.LBB11_7
.LBB11_5:
	movl	(%esi), %eax
	testl	%eax, %eax
	je	.LBB11_7
# %bb.6:
	movl	%eax, (%esp)
	calll	_ZdlPv
.LBB11_7:
	xorl	%eax, %eax
	addl	$4, %esp
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_def_cfa_offset 4
	retl
.Lfunc_end11:
	.size	_ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation, .Lfunc_end11-_ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation
	.cfi_endproc
	.section	.rodata,"a",@progbits
	.p2align	2
.LJTI11_0:
	.long	.LBB11_2
	.long	.LBB11_3
	.long	.LBB11_4
	.long	.LBB11_5
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Test3"
	.size	.L.str, 6

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Test4"
	.size	.L.str.1, 6

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Test1"
	.size	.L.str.2, 6

	.type	_ZTS3$_0,@object        # @"_ZTS3$_0"
	.section	.rodata,"a",@progbits
_ZTS3$_0:
	.asciz	"3$_0"
	.size	_ZTS3$_0, 5

	.type	_ZTI3$_0,@object        # @"_ZTI3$_0"
	.p2align	3
_ZTI3$_0:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTS3$_0
	.size	_ZTI3$_0, 8

	.type	.L.str.3,@object        # @.str.3
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.3:
	.asciz	"Test2"
	.size	.L.str.3, 6

	.type	_ZTS3$_2,@object        # @"_ZTS3$_2"
	.section	.rodata,"a",@progbits
_ZTS3$_2:
	.asciz	"3$_2"
	.size	_ZTS3$_2, 5

	.type	_ZTI3$_2,@object        # @"_ZTI3$_2"
	.p2align	3
_ZTI3$_2:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTS3$_2
	.size	_ZTI3$_2, 8

	.type	_ZTSPFvvE,@object       # @_ZTSPFvvE
	.section	.rodata._ZTSPFvvE,"aG",@progbits,_ZTSPFvvE,comdat
	.weak	_ZTSPFvvE
_ZTSPFvvE:
	.asciz	"PFvvE"
	.size	_ZTSPFvvE, 6

	.type	_ZTSFvvE,@object        # @_ZTSFvvE
	.section	.rodata._ZTSFvvE,"aG",@progbits,_ZTSFvvE,comdat
	.weak	_ZTSFvvE
_ZTSFvvE:
	.asciz	"FvvE"
	.size	_ZTSFvvE, 5

	.type	_ZTIFvvE,@object        # @_ZTIFvvE
	.section	.rodata._ZTIFvvE,"aG",@progbits,_ZTIFvvE,comdat
	.weak	_ZTIFvvE
	.p2align	3
_ZTIFvvE:
	.long	_ZTVN10__cxxabiv120__function_type_infoE+8
	.long	_ZTSFvvE
	.size	_ZTIFvvE, 8

	.type	_ZTIPFvvE,@object       # @_ZTIPFvvE
	.section	.rodata._ZTIPFvvE,"aG",@progbits,_ZTIPFvvE,comdat
	.weak	_ZTIPFvvE
	.p2align	3
_ZTIPFvvE:
	.long	_ZTVN10__cxxabiv119__pointer_type_infoE+8
	.long	_ZTSPFvvE
	.long	0                       # 0x0
	.long	_ZTIFvvE
	.size	_ZTIPFvvE, 16

	.type	_ZTSSt5_BindIFM3$_1FvvES0_EE,@object # @"_ZTSSt5_BindIFM3$_1FvvES0_EE"
	.section	.rodata,"a",@progbits
	.p2align	4
_ZTSSt5_BindIFM3$_1FvvES0_EE:
	.asciz	"St5_BindIFM3$_1FvvES0_EE"
	.size	_ZTSSt5_BindIFM3$_1FvvES0_EE, 25

	.type	_ZTSSt17_Weak_result_typeIM3$_1FvvEE,@object # @"_ZTSSt17_Weak_result_typeIM3$_1FvvEE"
	.p2align	4
_ZTSSt17_Weak_result_typeIM3$_1FvvEE:
	.asciz	"St17_Weak_result_typeIM3$_1FvvEE"
	.size	_ZTSSt17_Weak_result_typeIM3$_1FvvEE, 33

	.type	_ZTSSt24_Weak_result_type_memfunIM3$_1FvvELb1EE,@object # @"_ZTSSt24_Weak_result_type_memfunIM3$_1FvvELb1EE"
	.p2align	4
_ZTSSt24_Weak_result_type_memfunIM3$_1FvvELb1EE:
	.asciz	"St24_Weak_result_type_memfunIM3$_1FvvELb1EE"
	.size	_ZTSSt24_Weak_result_type_memfunIM3$_1FvvELb1EE, 44

	.type	_ZTISt24_Weak_result_type_memfunIM3$_1FvvELb1EE,@object # @"_ZTISt24_Weak_result_type_memfunIM3$_1FvvELb1EE"
	.p2align	3
_ZTISt24_Weak_result_type_memfunIM3$_1FvvELb1EE:
	.long	_ZTVN10__cxxabiv117__class_type_infoE+8
	.long	_ZTSSt24_Weak_result_type_memfunIM3$_1FvvELb1EE
	.size	_ZTISt24_Weak_result_type_memfunIM3$_1FvvELb1EE, 8

	.type	_ZTISt17_Weak_result_typeIM3$_1FvvEE,@object # @"_ZTISt17_Weak_result_typeIM3$_1FvvEE"
	.p2align	3
_ZTISt17_Weak_result_typeIM3$_1FvvEE:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTSSt17_Weak_result_typeIM3$_1FvvEE
	.long	_ZTISt24_Weak_result_type_memfunIM3$_1FvvELb1EE
	.size	_ZTISt17_Weak_result_typeIM3$_1FvvEE, 12

	.type	_ZTISt5_BindIFM3$_1FvvES0_EE,@object # @"_ZTISt5_BindIFM3$_1FvvES0_EE"
	.p2align	3
_ZTISt5_BindIFM3$_1FvvES0_EE:
	.long	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	_ZTSSt5_BindIFM3$_1FvvES0_EE
	.long	_ZTISt17_Weak_result_typeIM3$_1FvvEE
	.size	_ZTISt5_BindIFM3$_1FvvES0_EE, 12


	.ident	"clang version 7.0.1 (tags/RELEASE_701/final)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym _Z5Test3v
	.addrsig_sym __gxx_personality_v0
	.addrsig_sym _ZN3$_13runEv
	.addrsig_sym _ZNSt17_Function_handlerIFvvE3$_0E9_M_invokeERKSt9_Any_data
	.addrsig_sym _ZNSt14_Function_base13_Base_managerI3$_0E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
	.addrsig_sym _ZNSt17_Function_handlerIFvvE3$_2E9_M_invokeERKSt9_Any_data
	.addrsig_sym _ZNSt14_Function_base13_Base_managerI3$_2E10_M_managerERSt9_Any_dataRKS3_St18_Manager_operation
	.addrsig_sym _ZNSt17_Function_handlerIFvvEPS0_E9_M_invokeERKSt9_Any_data
	.addrsig_sym _ZNSt14_Function_base13_Base_managerIPFvvEE10_M_managerERSt9_Any_dataRKS4_St18_Manager_operation
	.addrsig_sym _ZNSt17_Function_handlerIFvvESt5_BindIFM3$_1FvvES2_EEE9_M_invokeERKSt9_Any_data
	.addrsig_sym _ZNSt14_Function_base13_Base_managerISt5_BindIFM3$_1FvvES2_EEE10_M_managerERSt9_Any_dataRKS8_St18_Manager_operation
	.addrsig_sym _Unwind_Resume
	.addrsig_sym _ZTVN10__cxxabiv117__class_type_infoE
	.addrsig_sym _ZTS3$_0
	.addrsig_sym _ZTI3$_0
	.addrsig_sym _ZTS3$_2
	.addrsig_sym _ZTI3$_2
	.addrsig_sym _ZTVN10__cxxabiv119__pointer_type_infoE
	.addrsig_sym _ZTSPFvvE
	.addrsig_sym _ZTVN10__cxxabiv120__function_type_infoE
	.addrsig_sym _ZTSFvvE
	.addrsig_sym _ZTIFvvE
	.addrsig_sym _ZTIPFvvE
	.addrsig_sym _ZTVN10__cxxabiv120__si_class_type_infoE
	.addrsig_sym _ZTSSt5_BindIFM3$_1FvvES0_EE
	.addrsig_sym _ZTSSt17_Weak_result_typeIM3$_1FvvEE
	.addrsig_sym _ZTSSt24_Weak_result_type_memfunIM3$_1FvvELb1EE
	.addrsig_sym _ZTISt24_Weak_result_type_memfunIM3$_1FvvELb1EE
	.addrsig_sym _ZTISt17_Weak_result_typeIM3$_1FvvEE
	.addrsig_sym _ZTISt5_BindIFM3$_1FvvES0_EE
