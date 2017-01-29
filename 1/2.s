	.file	"2.cpp"
	.text
.Ltext0:
	.section	.rodata
.LC0:
	.string	"A:"
.LC1:
	.string	"B:"
.LC2:
	.string	"C:"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.file 1 "2.cpp"
	.loc 1 24 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
.LBB2:
	.loc 1 25 0
	call	__cpu_indicator_init
	.loc 1 27 0
	call	_Z12matrix_allocv
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_Z16randomize_matrixPPf
	.loc 1 28 0
	movl	$.LC0, %edi
	call	puts
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_Z12print_matrixPPf
	.loc 1 29 0
	call	_Z12matrix_allocv
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_Z16randomize_matrixPPf
	.loc 1 30 0
	movl	$.LC1, %edi
	call	puts
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_Z12print_matrixPPf
	.loc 1 31 0
	call	_Z12matrix_allocv
	movq	%rax, -32(%rbp)
	.loc 1 32 0
	movl	$16, %eax
	movq	%rax, %rsi
	movl	$16, %edi
	call	aligned_alloc
	movq	%rax, -24(%rbp)
.LBB3:
	.loc 1 34 0
	movl	$0, -52(%rbp)
	jmp	.L2
.L3:
	.loc 1 125 0 discriminator 2
	movl	-52(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	leaq	(%rdx,%rax), %rsi
	.loc 1 128 0 discriminator 2
	movl	-52(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rcx
	.loc 1 141 0 discriminator 2
	movq	-40(%rbp), %rdx
#APP
# 141 "2.cpp" 1
	movl (%edx), %eax;movups (%eax), %xmm0;movl 8(%edx), %eax;movups (%eax), %xmm1;movl 16(%edx), %eax;movups (%eax), %xmm2;movl 24(%edx), %eax;movups (%eax), %xmm3;movl 32(%edx), %eax;movups (%eax), %xmm4;movl 40(%edx), %eax;movups (%eax), %xmm5;movl 0(%ecx), %eax;movl %eax, 0(%rdx);movl %eax, 4(%rdx);movl %eax, 8(%rdx);movl %eax, 12(%rdx);movups (%rdx), %xmm6;mulps %xmm6, %xmm0;movl 4(%ecx), %eax;movl %eax, 0(%rdx);movl %eax, 4(%rdx);movl %eax, 8(%rdx);movl %eax, 12(%rdx);movups (%rdx), %xmm6;mulps %xmm6, %xmm1;movl 8(%ecx), %eax;movl %eax, 0(%rdx);movl %eax, 4(%rdx);movl %eax, 8(%rdx);movl %eax, 12(%rdx);movups (%rdx), %xmm6;mulps %xmm6, %xmm2;movl 12(%ecx), %eax;movl %eax, 0(%rdx);movl %eax, 4(%rdx);movl %eax, 8(%rdx);movl %eax, 12(%rdx);movups (%rdx), %xmm6;mulps %xmm6, %xmm3;movl 16(%ecx), %eax;movl %eax, 0(%rdx);movl %eax, 4(%rdx);movl %eax, 8(%rdx);movl %eax, 12(%rdx);movups (%rdx), %xmm6;mulps %xmm6, %xmm4;movl 20(%ecx), %eax;movl %eax, 0(%rdx);movl %eax, 4(%rdx);movl %eax, 8(%rdx);movl %eax, 12(%rdx);movups (%rdx), %xmm6;mulps %xmm6, %xmm5;addps %xmm5, %xmm4;addps %xmm4, %xmm3;addps %xmm3, %xmm2;addps %xmm2, %xmm1;addps %xmm1, %xmm0;movups %xmm0, (%rcx);
# 0 "" 2
#NO_APP
	movq	%rcx, (%rsi)
	movq	%rdx, -24(%rbp)
	.loc 1 34 0 discriminator 2
	addl	$1, -52(%rbp)
.L2:
	.loc 1 34 0 is_stmt 0 discriminator 1
	cmpl	$1, -52(%rbp)
	jle	.L3
.LBE3:
	.loc 1 144 0 is_stmt 1
	movl	$.LC2, %edi
	call	puts
	.loc 1 145 0
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_Z12print_matrixPPf
	.loc 1 155 0
	movl	$0, %eax
.LBE2:
	.loc 1 156 0
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.globl	_Z12matrix_allocv
	.type	_Z12matrix_allocv, @function
_Z12matrix_allocv:
.LFB3:
	.loc 1 159 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
.LBB4:
	.loc 1 160 0
	movl	$48, %eax
	movq	%rax, %rsi
	movl	$16, %edi
	call	aligned_alloc
	movq	%rax, -24(%rbp)
.LBB5:
	.loc 1 161 0
	movl	$0, -28(%rbp)
	jmp	.L6
.L7:
	.loc 1 162 0 discriminator 2
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	$24, %eax
	movq	%rax, %rsi
	movl	$16, %edi
	call	aligned_alloc
	movq	%rax, (%rbx)
	.loc 1 161 0 discriminator 2
	addl	$1, -28(%rbp)
.L6:
	.loc 1 161 0 is_stmt 0 discriminator 1
	cmpl	$5, -28(%rbp)
	jle	.L7
.LBE5:
	.loc 1 165 0 is_stmt 1
	movq	-24(%rbp), %rax
.LBE4:
	.loc 1 166 0
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_Z12matrix_allocv, .-_Z12matrix_allocv
	.globl	_Z16randomize_matrixPPf
	.type	_Z16randomize_matrixPPf, @function
_Z16randomize_matrixPPf:
.LFB4:
	.loc 1 169 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
.LBB6:
.LBB7:
	.loc 1 170 0
	movl	$0, -8(%rbp)
	jmp	.L10
.L13:
.LBB8:
.LBB9:
	.loc 1 171 0
	movl	$0, -4(%rbp)
	jmp	.L11
.L12:
	.loc 1 172 0 discriminator 2
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	leaq	(%rax,%rdx), %rcx
	movl	-8(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, (%rcx)
	.loc 1 171 0 discriminator 2
	addl	$1, -4(%rbp)
.L11:
	.loc 1 171 0 is_stmt 0 discriminator 1
	cmpl	$5, -4(%rbp)
	jle	.L12
.LBE9:
.LBE8:
	.loc 1 170 0 is_stmt 1
	addl	$1, -8(%rbp)
.L10:
	.loc 1 170 0 is_stmt 0 discriminator 1
	cmpl	$5, -8(%rbp)
	jle	.L13
.LBE7:
.LBE6:
	.loc 1 175 0 is_stmt 1
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_Z16randomize_matrixPPf, .-_Z16randomize_matrixPPf
	.section	.rodata
.LC3:
	.string	"%5.1f "
	.text
	.globl	_Z12print_matrixPPf
	.type	_Z12print_matrixPPf, @function
_Z12print_matrixPPf:
.LFB5:
	.loc 1 178 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
.LBB10:
.LBB11:
	.loc 1 179 0
	movl	$0, -8(%rbp)
	jmp	.L15
.L18:
.LBB12:
.LBB13:
	.loc 1 180 0
	movl	$0, -4(%rbp)
	jmp	.L16
.L17:
	.loc 1 181 0 discriminator 2
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	$.LC3, %edi
	movl	$1, %eax
	call	printf
	.loc 1 180 0 discriminator 2
	addl	$1, -4(%rbp)
.L16:
	.loc 1 180 0 is_stmt 0 discriminator 1
	cmpl	$5, -4(%rbp)
	jle	.L17
.LBE13:
	.loc 1 183 0 is_stmt 1
	movl	$10, %edi
	call	putchar
.LBE12:
	.loc 1 179 0
	addl	$1, -8(%rbp)
.L15:
	.loc 1 179 0 is_stmt 0 discriminator 1
	cmpl	$5, -8(%rbp)
	jle	.L18
.LBE11:
.LBE10:
	.loc 1 185 0 is_stmt 1
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_Z12print_matrixPPf, .-_Z12print_matrixPPf
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x24e
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF17
	.byte	0x4
	.long	.LASF18
	.long	.LASF19
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF9
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF10
	.uleb128 0x2
	.byte	0x4
	.byte	0x4
	.long	.LASF11
	.uleb128 0x4
	.long	.LASF14
	.byte	0x1
	.byte	0x18
	.long	0x57
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x10d
	.uleb128 0x5
	.quad	.LBB2
	.quad	.LBE2-.LBB2
	.uleb128 0x6
	.string	"a"
	.byte	0x1
	.byte	0x1b
	.long	0x10d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x6
	.string	"b"
	.byte	0x1
	.byte	0x1d
	.long	0x10d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x6
	.string	"c"
	.byte	0x1
	.byte	0x1f
	.long	0x10d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x7
	.long	.LASF12
	.byte	0x1
	.byte	0x20
	.long	0x113
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x5
	.quad	.LBB3
	.quad	.LBE3-.LBB3
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x22
	.long	0x57
	.uleb128 0x3
	.byte	0x91
	.sleb128 -68
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0x113
	.uleb128 0x8
	.byte	0x8
	.long	0x81
	.uleb128 0x9
	.long	.LASF20
	.byte	0x1
	.byte	0x9e
	.long	.LASF21
	.long	0x10d
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x17d
	.uleb128 0x5
	.quad	.LBB4
	.quad	.LBE4-.LBB4
	.uleb128 0x7
	.long	.LASF13
	.byte	0x1
	.byte	0xa0
	.long	0x10d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x5
	.quad	.LBB5
	.quad	.LBE5-.LBB5
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0xa1
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xa
	.long	.LASF15
	.byte	0x1
	.byte	0xa8
	.long	.LASF22
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x1e9
	.uleb128 0xb
	.long	.LASF16
	.byte	0x1
	.byte	0xa8
	.long	0x10d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x5
	.quad	.LBB7
	.quad	.LBE7-.LBB7
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0xaa
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x5
	.quad	.LBB9
	.quad	.LBE9-.LBB9
	.uleb128 0x6
	.string	"j"
	.byte	0x1
	.byte	0xab
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xc
	.long	.LASF23
	.byte	0x1
	.byte	0xb1
	.long	.LASF24
	.quad	.LFB5
	.quad	.LFE5-.LFB5
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xb
	.long	.LASF16
	.byte	0x1
	.byte	0xb1
	.long	0x10d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x5
	.quad	.LBB11
	.quad	.LBE11-.LBB11
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0xb3
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x5
	.quad	.LBB13
	.quad	.LBE13-.LBB13
	.uleb128 0x6
	.string	"j"
	.byte	0x1
	.byte	0xb4
	.long	0x57
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF24:
	.string	"_Z12print_matrixPPf"
.LASF18:
	.string	"2.cpp"
.LASF15:
	.string	"randomize_matrix"
.LASF11:
	.string	"float"
.LASF1:
	.string	"unsigned char"
.LASF0:
	.string	"long unsigned int"
.LASF12:
	.string	"temp"
.LASF2:
	.string	"short unsigned int"
.LASF22:
	.string	"_Z16randomize_matrixPPf"
.LASF21:
	.string	"_Z12matrix_allocv"
.LASF14:
	.string	"main"
.LASF17:
	.string	"GNU C++ 4.8.4 -msse -mtune=generic -march=x86-64 -ggdb -O0 -fstack-protector"
.LASF3:
	.string	"unsigned int"
.LASF10:
	.string	"long long unsigned int"
.LASF13:
	.string	"result"
.LASF19:
	.string	"/home/artifaqiq/AVP/labs/1"
.LASF7:
	.string	"sizetype"
.LASF9:
	.string	"long long int"
.LASF20:
	.string	"matrix_alloc"
.LASF16:
	.string	"matrix"
.LASF23:
	.string	"print_matrix"
.LASF5:
	.string	"short int"
.LASF6:
	.string	"long int"
.LASF8:
	.string	"char"
.LASF4:
	.string	"signed char"
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
